#include "essential.h"
#include "red_black_tree.h"
#include "tweet_database.h"
#include "user_database.h"

RBTNode tweet_database;

//red_black_tree abstract method
int compare_tweet_node(RBTNode node1, RBTNode node2) {
	Tweet_Node tweet1 = (Tweet_Node)node1->data;
	Tweet_Node tweet2 = (Tweet_Node)node2->data;
	return strcmp(tweet1->text, tweet2->text);
}

int compare_tweet_str(RBTNode node, char* str) {
	Tweet_Node tweet1 = (Tweet_Node)node->data;
	return strcmp(tweet1->text, str);
}

char* tweet_node_to_string(RBTNode node) {
	Tweet_Node tweet = (Tweet_Node)node->data;

	char *str = (char*)malloc(1000);

	sprintf(str, "p:%p rbt'datap:%p rbtp:%p left:%p right:%p parent:%p id:%s text:%s", tweet, tweet->rbtnode->data, tweet->rbtnode, node->left, node->right, node->parent, tweet->user_id, tweet->text);

	return str;
}


//database initiation
Tweet_Node tweet_node_alloc(char* user_id, char* date, char* text) {
	Tweet_Node node = (Tweet_Node)malloc(sizeof(struct _tweet_node));
	RBTNode rbt = (RBTNode)malloc(sizeof(struct _rbt_node));

	node->user_id = user_id;
	node->date = date;
	node->text = text;

	rbt->color = BLACK;
	rbt->parent = NULL;
	rbt->left = rbt->right = NULL;

	node->rbtnode = rbt;
	rbt->data = node;

	return node;
}

void read_tweet_data() {
	FILE* fp = fopen("database/word.txt", "r");

	if (fp != NULL) {
		char *user_id, *date, *text;

		while (1) {
			user_id = read_one_line(fp);
			date = read_one_line(fp);
			text = read_one_line(fp);

			if (user_id == NULL || date == NULL || text == NULL)
				break;

			tweet_insert_node(user_id, date, text);
		}
		fclose(fp);
	}
}

void tweet_init_database() {
	read_tweet_data();
}


//red_black_tree override method
void tweet_insert_node(char* user_id, char* date, char* text) {
	Tweet_Node node = tweet_node_alloc(user_id, date, text);

	if (tweet_database == NULL) {
		tweet_database = node->rbtnode;
		tweet_database->left = tweet_database->right = Nil;
	}
	else
		rbt_insert(&tweet_database, node->rbtnode, compare_tweet_node);

	User_Node user = user_search_node(node->user_id);

	Adj tweets = (Adj)malloc(sizeof(struct _adj));
	tweets->data = node;
	tweets->next = NULL;

	Adj origin_first = user->tweets;
	user->tweets = tweets;
	tweets->next = origin_first;
}

void tweet_remove_node(Tweet_Node tweet) {
	rbt_remove(&tweet_database, tweet->rbtnode);

	User_Node user = user_search_node(tweet->user_id);

	Adj adj = user->tweets;

	if (adj->data == tweet) {
		user->tweets = adj->next;
	}
	else {
		Adj parent = adj;
		adj = adj->next;

		while (adj != NULL) {
			if (adj->data == tweet) {
				parent->next = adj->next;
				break;
			}
			parent = parent->next;
			adj = adj->next;
		}
	}

	free(adj);
	free(tweet);

	tweet_database_check_error();
}

Tweet_Node tweet_search_node(char* text) {
	RBTNode node = rbt_search_node(tweet_database, text, compare_tweet_str);
	if (node == NULL)
		return NULL;
	else
		return (Tweet_Node)node->data;
}

Tweet_Node tweet_min_node() {
	return (Tweet_Node)rbt_min_node(tweet_database)->data;
}

Tweet_Node tweet_max_node() {
	return (Tweet_Node)rbt_max_node(tweet_database)->data;
}

Tweet_Node tweet_successor(Tweet_Node node) {
	RBTNode rbt = rbt_successor(node->rbtnode);
	if (rbt == NULL)
		return NULL;
	else
		return (Tweet_Node)rbt->data;
}

Tweet_Node tweet_predecessor(Tweet_Node node) {
	RBTNode rbt = rbt_predecessor(node->rbtnode);
	if (rbt == NULL)
		return NULL;
	else
		return (Tweet_Node)rbt->data;
}

int tweet_database_size() {
	return rbt_database_size(tweet_database);
}

void tweet_database_print() {
	rbt_print(tweet_database, 0, 0, tweet_node_to_string);
}

void tweet_database_check_error() {
	rbt_check_error(tweet_database, tweet_node_to_string);

	Tweet_Node now = (Tweet_Node)rbt_min_node(tweet_database)->data;
	Tweet_Node max = (Tweet_Node)rbt_max_node(tweet_database)->data;

	do {
		if (now != now->rbtnode->data) {

			printf("now:%p, now->rbt->data:%p\n", now, now->rbtnode->data);
			int a = 0;
		}

		if (now == max)
			break;
		else
			now = (Tweet_Node)rbt_successor(now->rbtnode)->data;
	} while (1);
}


//application functions
void tweet_print_top_5_most_words() {
	if (tweet_database == NULL || tweet_database == Nil) {
		printf("트윗 데이터베이스가 비어있습니다.\n");
		return;
	}

	char words[6][1000] = { "" };
	int maxNum[6] = { 0 };

	Tweet_Node now = (Tweet_Node)rbt_min_node(tweet_database)->data;
	Tweet_Node max = (Tweet_Node)rbt_max_node(tweet_database)->data;

	do {
		if (strcmp(words[5], now->text) == 0) {
			maxNum[5]++;
		}
		else {

			for (int i = 0; i <5; i++)
				for (int j = i + 1; j < 6; j++)
					if (maxNum[i] < maxNum[j]) {
						int tmp = maxNum[i];
						maxNum[i] = maxNum[j];
						maxNum[j] = tmp;

						char tmpStr[100];
						strcpy(tmpStr, words[i]);
						strcpy(words[i], words[j]);
						strcpy(words[j], tmpStr);
					}
			maxNum[5] = 0;

			strcpy(words[5], now->text);
			maxNum[5]++;
		}
		now = (Tweet_Node)rbt_successor(now->rbtnode)->data;
	} while (now != max);

	for (int i = 0; i < 5; i++) {
		printf("%d위 : %-20s - %2d번\n", i + 1, words[i], maxNum[i]);
	}
}