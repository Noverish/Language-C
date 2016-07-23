#define Nil rbt_nil

struct _rbt_node {
	void* data;

	int color;

	struct _rbt_node* parent;
	struct _rbt_node* left;
	struct _rbt_node* right;
};

typedef struct _rbt_node* RBTNode;
typedef int(*CompareNode)(RBTNode, RBTNode);
typedef int(*CompareStr)(RBTNode, char*);

extern RBTNode rbt_nil;

//red_black_tree insert node
void rbt_insert(RBTNode* tree, RBTNode node, CompareNode compare);

//red_black_tree remove node
void rbt_remove(RBTNode* tree, RBTNode node);

//red_black_tree search node
RBTNode rbt_search_node(RBTNode tree, char* str, CompareStr compare_str);
RBTNode rbt_min_node(RBTNode tree);
RBTNode rbt_max_node(RBTNode tree);
RBTNode rbt_successor(RBTNode x);
RBTNode rbt_predecessor(RBTNode x);

//red_black_tree application functions
int rbt_database_size(RBTNode root);
void rbt_print(RBTNode tree, int level, int black_count, char* node_to_string(RBTNode));
void rbt_check_error(RBTNode parent, char* node_to_string(RBTNode));