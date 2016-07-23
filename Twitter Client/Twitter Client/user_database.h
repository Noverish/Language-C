#include "graph.h"

struct _user_node {
	char* id;
	char* register_date;
	char* name;

	Vertex follower;
	Vertex following;
	Adj tweets;

	RBTNode rbtnode;
};
typedef struct _user_node* User_Node;

extern RBTNode user_database;
extern RBTNode rbt_nil;
extern int total_friendship;


//database initiation
void user_init_database();

//red_black_tree oerride method
void user_insert_node(char* id, char* register_date, char* name);
void user_remove_node(User_Node node);
User_Node user_search_node(char* id);
User_Node user_min_node();
User_Node user_max_node();
User_Node user_successor(User_Node node);
User_Node user_predecessor(User_Node node);
int user_database_size();
void user_database_print();
void user_database_check_error();


//application functinos
int get_tweet_number_of_user(User_Node node);
void tweet_print_top_5_most_users();
void user_tweet_print();
void user_friends_print();
void user_strongly_connected_component();