struct _tweet_node {
	char* user_id;
	char* date;
	char* text;

	RBTNode rbtnode;
};
typedef struct _tweet_node* Tweet_Node;

extern RBTNode tweet_database;
extern RBTNode rbt_nil;

//database initiation
void tweet_init_database();

//red_black_tree override method
void tweet_insert_node(char* user_id, char* date, char* text);
void tweet_remove_node(Tweet_Node node);
Tweet_Node tweet_search_node(char* text);
Tweet_Node tweet_min_node();
Tweet_Node tweet_max_node();
Tweet_Node tweet_successor(Tweet_Node node);
Tweet_Node tweet_predecessor(Tweet_Node node);
int tweet_database_size();
void tweet_database_print();
void tweet_database_check_error();

//application functions
void tweet_print_top_5_most_words();

