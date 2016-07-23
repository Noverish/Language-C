#include "essential.h"
#include "red_black_tree.h"
#include "user_database.h"
#include "tweet_database.h"

User_Node find_above_users[10000];
int find_above_users_index;
User_Node delete_above_users[10000];
int delete_above_users_index;

void main_read_data_files() {
	SetColor(YELLOW);
	printf("Total users : %d\n", user_database_size());
	printf("Total friendship records : %d\n", total_friendship);
	printf("Total tweets : %d\n", tweet_database_size());
	SetColor(WHITE);
}

void main_display_statstics() {
	SetColor(YELLOW);
	int min = MAXINT;
	int max = 0;

	User_Node now_node = user_min_node();
	User_Node max_node = user_max_node();

	do {
		int friend_number = 0;
		Adj adj = now_node->follower->friends;
		for (; adj != NULL; friend_number++, adj = adj->next);

		if (friend_number > max)
			max = friend_number;

		if (friend_number < min)
			min = friend_number;

		now_node = user_successor(now_node);
	} while (now_node != max_node);

	printf("Average number of friends : %lf\n", (double)total_friendship/ user_database_size());
	printf("Minimum friends : %d\n", min);
	printf("Maximum number of friends : %d\n", max);

	long total_tweet = 0;
	min = MAXINT;
	max = 0;

	now_node = user_min_node();

	do {
		int tweet_number = 0;
		Adj adj = now_node->tweets;
		for (; adj != NULL; tweet_number++, adj = adj->next);

		if (tweet_number > max)
			max = tweet_number;

		if (tweet_number < min)
			min = tweet_number;

		total_tweet += tweet_number;
		now_node = user_successor(now_node);
	} while (now_node != max_node);

	printf("Average tweets per user : %lf\n", (double)total_tweet/ user_database_size());
	printf("Minium tweets per user : %d\n", min);
	printf("Maxium tweets per user : %d\n", max);
	SetColor(WHITE);
}

void main_find_users_who_tweeted_a_word(char* str) {
	if (tweet_search_node(str) == NULL) {
		SetColor(RED);
		printf("\n검색 결과가 없습니다.\n");
		SetColor(WHITE);
		return;
	}

	find_above_users_index = 0;
	Tweet_Node node = tweet_search_node(str);
	Tweet_Node prev = tweet_predecessor(node);

	for (; strcmp(node->text, prev->text) == 0;) {
		node = prev;
		prev = tweet_predecessor(prev);
	}

	do {
		char* id = node->user_id;
		User_Node user = user_search_node(id);

		printf("   id : %s\n", user->id);
		printf(" name : %s\n", user->name);
		printf("tweet : %s\n\n", node->text);

		find_above_users[find_above_users_index++] = user;

		prev = node;
		node = tweet_successor(node);
	} while (strcmp(node->text, prev->text) == 0);
}

void main_find_all_people_who_are_friends_of_the_above_users() {
	if (find_above_users_index == 0) {
		SetColor(RED);
		printf("\n검색 결과가 없습니다.\n");
		SetColor(WHITE);
		return;
	}

	printf("\n");
	for (int i = 0; i < find_above_users_index; i++) {
		User_Node node = find_above_users[i];
		Adj adj = node->follower->friends;

		
		printf("%s의 친구 : \n", node->name);
		if (adj == NULL) {
			printf("\t없습니다.\n");
		}
		else {
			for (; adj != NULL; adj = adj->next) {
				User_Node friend_node = (User_Node)adj->data;
				printf("\tid : %10s - name : %s\n", friend_node->id, friend_node->name);
			}
		}
		printf("\n");
	}
}

void main_delete_all_mentions_of_a_word(char* str) {
	if (tweet_search_node(str) == NULL) {
		SetColor(RED);
		printf("\n검색 결과가 없습니다.\n");
		SetColor(WHITE);
		return;
	}

	int check = 1;
	delete_above_users_index = 0;
	Tweet_Node node = tweet_search_node(str);
	Tweet_Node prev = tweet_predecessor(node);

	for (; prev != NULL && strcmp(node->text, prev->text) == 0;) {
		node = prev;
		prev = tweet_predecessor(prev);
	}

	Tweet_Node next = tweet_successor(node);
	do {
		char* id = node->user_id;
		User_Node user = user_search_node(id);
		
		printf("   id : %s\n", user->id);
		printf(" name : %s\n", user->name);
		printf("tweet : %s\n", node->text);

		if(strcmp(node->text, next->text) != 0) {
			check = 0;
		}

		tweet_remove_node(node);

		delete_above_users[delete_above_users_index++] = user;
		SetColor(RED);
		printf("삭제 완료\n\n");
		SetColor(WHITE);

		node = next;
		next = tweet_successor(next);
	} while (check || next==NULL);

}

void main_delete_all_users_who_mentioned_a_word() {
	for (int i = 0; i < delete_above_users_index; i++) {
		if ((unsigned int)delete_above_users[i]->id != 0xdddddddd) {
			User_Node user = delete_above_users[i];
			printf("   id : %s\n", user->id);
			printf(" name : %s\n", user->name);

			user_remove_node(delete_above_users[i]);
			free(delete_above_users[i]);

			SetColor(RED);
			printf("삭제 완료\n\n");
			SetColor(WHITE);
		}
	}
}

void main_find_strongly_connected_component() {
	user_strongly_connected_component();
}

int print_menu() {
	int input;

	while (true) {
		printf("\n");
		printf(" 0. Read data files\n");
		printf(" 1. display statistics\n");
		printf(" 2. Top 5 most tweeted words\n");
		printf(" 3. Top 5 most tweeted users\n");
		printf(" 4. Find users who tweeted a word(e.g., ’연세대’)\n");
		printf(" 5. Find all people who are friends of the above users\n");
		printf(" 6. Delete all mentions of a word\n");
		printf(" 7. Delete all users who mentioned a word\n");
		printf(" 8. Find strongly connected components\n");
		printf(" 9. Find shortest path from a given user\n");
		printf("10. print tweet database\n");
		printf("11. print user database\n");
		printf("12. print user's tweet\n");
		printf("13. print user's friends\n");
		printf("99. Quit\n");
		printf("Select Menu : ");

		scanf("%d", &input);
		printf("\n");

		if ((0 <= input && input <= 13) || input == 99) {
			return input;
		}
		else {
			system("cls");
			printf("\nWRONG INPUT! please try again\n\n");
		}
	}

}


int main() {

	red_black_tree_init();
	SetColor(GREEN);
	printf("유저 정보 로딩중....\n");
	user_init_database();
	printf("유저 정보 로드 완료!\n");
	printf("트윗 정보 로딩중....\n");
	tweet_init_database();
	printf("트윗 정보 로드 완료!\n");
	SetColor(WHITE);

	while (1) {
		int input = print_menu();
		switch (input) {
		case 0: {
			main_read_data_files();
			break;
		}
		case 1: {
			main_display_statstics();
			break;
		}
		case 2: {
			tweet_print_top_5_most_words();
			break;
		}
		case 3: {
			tweet_print_top_5_most_users();
			break;
		}
		case 4: {
			char sen[1000];
			printf("찾고자 하는 단어를 입력해 주세요 : ");
			scanf("%s", sen);
			main_find_users_who_tweeted_a_word(sen);
			break;
		}
		case 5: {
			main_find_all_people_who_are_friends_of_the_above_users();
			break;
		}
		case 6: {
			char sen[1000];
			printf("찾고자 하는 단어를 입력해 주세요 : ");
			scanf("%s", sen);
			main_delete_all_mentions_of_a_word(sen);
			break;
		}
		case 7: {
			main_delete_all_users_who_mentioned_a_word();
			break;
		}
		case 8: {
			main_find_strongly_connected_component();
			break;
		}
		case 10: {
			tweet_database_print();
			break;
		}
		case 11: {
			user_database_print();
			break;
		}
		case 12: {
			user_tweet_print();
			break;
		}
		case 13: {
			user_friends_print();
			break;
		}
		case 99: {
			break;
		}
		}

		if (input == 99) 
			break;
	}
	return 0;
}