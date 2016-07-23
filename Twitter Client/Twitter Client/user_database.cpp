#include "essential.h"
#include "red_black_tree.h"
#include "user_database.h"
#include "tweet_database.h"
#include "graph.h"

RBTNode user_database;
int total_friendship;

//red_black_tree abstract method
int user_compare_node(RBTNode node1, RBTNode node2) {
	User_Node user1 = (User_Node)node1->data;
	User_Node user2 = (User_Node)node2->data;

	return strcmp(user1->id, user2->id);
}

int user_compare_str(RBTNode node, char* str) {
	User_Node tweet1 = (User_Node)node->data;
	return strcmp(tweet1->id, str);
}

char* user_node_to_string(RBTNode node) {
	User_Node user = (User_Node)node->data;
	
	char *str = (char*)malloc(1000);

	sprintf(str, "p:%p rbt:%p left:%p right:%p id:%s name:%s", user, user->rbtnode, node->left, node->right, user->id, user->name);

	return str;
}

void user_database_check_error2(User_Node node) {
	User_Node left = (User_Node)node->rbtnode->left->data;
	User_Node right = (User_Node)node->rbtnode->right->data;

	if (left != NULL) {
		user_database_check_error2(left);
	}

	if (node != node->rbtnode->data) {
		printf("%s\n", user_node_to_string(node->rbtnode));
	}

	if (right != NULL) {
		user_database_check_error2(right);
	}

}

//graph abstract method
char* user_vertex_to_string(Vertex vertex) {
	User_Node user = (User_Node)vertex->data;

	char *str = (char*)malloc(1000);

	sprintf(str, "name:%s", user->name);

	return str;
}

//database initiation
User_Node user_node_alloc(char* id, char* register_date, char* name) {
	User_Node node = (User_Node)malloc(sizeof(struct _user_node));
	RBTNode rbt = (RBTNode)malloc(sizeof(struct _rbt_node));
	Vertex friends = (Vertex)malloc(sizeof(struct _vertex));

	node->id = id;
	node->register_date = register_date;
	node->name = name;

	rbt->color = BLACK;
	rbt->parent = NULL;
	rbt->left = rbt->right = NULL;

	node->rbtnode = rbt;
	rbt->data = node;

	friends->data = node;
	friends->friends = NULL;
	friends->color = -1;
	friends->f = -1;
	friends->parent = NULL;

	node->follower = friends;
	friends->data = node;

	node->tweets = NULL;

	return node;
}

void read_user_data() {
	FILE* fp = fopen("database/user.txt", "r");

	if (fp != NULL) {
		char *id, *register_date, *name;

		while (1) {
			id = read_one_line(fp);
			register_date = read_one_line(fp);
			name = read_one_line(fp);

			if (id == NULL || register_date == NULL || name == NULL)
				break;

			user_insert_node(id, register_date, name);
		}
		fclose(fp);
	}
}

void read_frineds_data() {
	char* previous_user1 = "";
	char* previous_user2 = "";

	total_friendship = 0;

	FILE* fp = fopen("database/friend.txt", "r");

	if (fp != NULL) {
		char *user1, *user2;

		while (1) {
			user1 = read_one_line(fp);
			user2 = read_one_line(fp);

			if (user1 == NULL || user2 == NULL)
				break;

			if (strcmp(previous_user1, user1) != 0 || strcmp(previous_user2, user2) != 0) {
				User_Node user1_node = user_search_node(user1);
				User_Node user2_node = user_search_node(user2);

				if (user1_node == NULL || user2_node == NULL)
					continue;

				//add_friend(user1_node->friends, user2_node->friends);
				add_friend(user2_node->follower, user1_node->follower);
				total_friendship++;

				previous_user1 = user1;
				previous_user2 = user2;
			}
		}
		fclose(fp);
	}
}

void user_init_database() {
	read_user_data();

	read_frineds_data();
}


//red_black_tree oerride method
void user_insert_node(char* id, char* register_date, char* name) {
	User_Node node = user_node_alloc(id, register_date, name);
	if (user_database == NULL) {
		user_database = node->rbtnode;
		user_database->left = user_database->right = Nil;
	}
	else
		rbt_insert(&user_database, node->rbtnode, user_compare_node);
}

void user_remove_node(User_Node node) {
	if (strcmp(node->name, "Soyay") == 0)
		int a = 0;

	Adj tweet = node->tweets;
	while (tweet != NULL) {
		Adj adj = tweet->next;
		tweet_remove_node((Tweet_Node)tweet->data);
		tweet = adj;
	}



	User_Node now = (User_Node)rbt_min_node(user_database)->data;
	User_Node max = (User_Node)rbt_max_node(user_database)->data;

	do {
		Adj adj = now->follower->friends;
		if (adj != NULL) {
			if (adj->data == node) {
				now->follower->friends = adj->next;
				free(adj);
			}
			else {
				Adj parent = adj;
				while (adj->next != NULL) {
					adj = adj->next;
					if (adj->data == node) {
						parent->next = adj->next;
						free(adj);
						break;
					}
				}
			}
		}
		now = user_successor(now);
	} while (now != max);
	rbt_remove(&user_database, node->rbtnode);
	node->rbtnode = NULL;
}

User_Node user_search_node(char* id) {
	RBTNode node = rbt_search_node(user_database, id, user_compare_str);
	if (node == NULL)
		return NULL;
	else
		return (User_Node)node->data;
}

User_Node user_min_node() {
	return (User_Node)rbt_min_node(user_database)->data;
}

User_Node user_max_node() {
	return (User_Node)rbt_max_node(user_database)->data;
}

User_Node user_successor(User_Node node) {
	RBTNode rbt = rbt_successor(node->rbtnode);
	if (rbt == NULL)
		return NULL;
	else
		return (User_Node)rbt->data;
}

User_Node user_predecessor(User_Node node) {
	RBTNode rbt = rbt_predecessor(node->rbtnode);
	if (rbt == NULL)
		return NULL;
	else
		return (User_Node)rbt->data;
}

int user_database_size() {
	return rbt_database_size(user_database);
}

void user_database_print() {
	rbt_print(user_database, 0, 0, user_node_to_string);
}

void user_database_check_error() {
	rbt_check_error(user_database, user_node_to_string);
	
	user_database_check_error2((User_Node)user_database->data);
}


//application functinos
int get_tweet_number_of_user(User_Node node) {
	Adj tweet = node->tweets;
	int num;

	for (num = 0; tweet; num++, tweet = tweet->next);

	return num;
}

void tweet_print_top_5_most_users() {
	if (user_database == NULL || user_database == Nil) {
		printf("트윗 데이터베이스가 비어있습니다.\n");
		return;
	}

	char user[6][1000] = { "" };
	int maxNum[6] = { 0 };

	User_Node now = (User_Node)rbt_min_node(user_database)->data;
	User_Node max = (User_Node)rbt_max_node(user_database)->data;

	do {
		maxNum[5] = get_tweet_number_of_user(now);
		strcpy(user[5], now->name);

		for (int i = 0; i <5; i++)
			for (int j = i + 1; j < 6; j++)
				if (maxNum[i] < maxNum[j]) {
					int tmp = maxNum[i];
					maxNum[i] = maxNum[j];
					maxNum[j] = tmp;

					char tmpStr[100];
					strcpy(tmpStr, user[i]);
					strcpy(user[i], user[j]);
					strcpy(user[j], tmpStr);
				}

		maxNum[5]++;

		now = (User_Node)rbt_successor(now->rbtnode)->data;
	} while (now != max);

	for (int i = 0; i < 5; i++) {
		printf("%d위 : %-20s - %2d번\n", i + 1, user[i], maxNum[i]);
	}
}

void user_tweet_print() {
	User_Node node = (User_Node)rbt_max_node(user_database)->data;
	User_Node min = (User_Node)rbt_min_node(user_database)->data;

	do {
		printf("%s\n", node->name);

		Adj tweet = node->tweets;

		while (tweet != NULL) {
			printf("\t%s\n", ((Tweet_Node)tweet->data)->text);
			tweet = tweet->next;
		}

		node = (User_Node)rbt_predecessor(node->rbtnode)->data;
	} while (node != min);
}

void user_friends_print() {
	User_Node node = (User_Node)rbt_max_node(user_database)->data;
	User_Node min = (User_Node)rbt_min_node(user_database)->data;

	do {
		printf("%s\n", node->name);

		Adj friends = node->follower->friends;

		while (friends != NULL) {
			printf("\t%s\n", ((User_Node)friends->data)->name);
			friends = friends->next;
		}

		node = (User_Node)rbt_predecessor(node->rbtnode)->data;
	} while (node != min);
}

void user_strongly_connected_component() {
	int nelem = user_database_size();
	Vertex* graph = (Vertex*)malloc(sizeof(Vertex) * nelem);

	int i = 0;

	User_Node now = user_min_node();
	User_Node max = user_max_node();

	do {
		graph[i] = now->follower;

		if (now == max)
			break;

		now = user_successor(now);
		i++;
	} while (1);

	strongly_connected_compnent(graph, nelem, user_vertex_to_string);
}




