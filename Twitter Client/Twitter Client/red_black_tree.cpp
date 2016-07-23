#include "essential.h"
#include "red_black_tree.h"

RBTNode rbt_nil;

void red_black_tree_init() {
	Nil = (RBTNode)malloc(sizeof(struct _rbt_node));
	Nil->parent = Nil->left = Nil->right = Nil;
	Nil->color = BLACK;
	Nil->data = NULL;
}

//red_black_tree base functions
void rbt_left_rotate(RBTNode* root, RBTNode parent) {
	RBTNode right_child = parent->right;
	parent->right = right_child->left;
	if (right_child->left != Nil) {
		right_child->left->parent = parent;
	}
	right_child->parent = parent->parent;

	if (parent->parent == NULL) {
		(*root) = right_child;
	}
	else {
		if (parent == parent->parent->left) {
			parent->parent->left = right_child;
		}
		else {
			parent->parent->right = right_child;
		}
	}
	right_child->left = parent;
	parent->parent = right_child;
}

void rbt_right_rotate(RBTNode* tree, RBTNode parent) {
	RBTNode left_child = parent->left;
	parent->left = left_child->right;
	if (left_child->right != Nil) {
		left_child->right->parent = parent;
	}
	left_child->parent = parent->parent;

	if (parent->parent == NULL) {
		(*tree) = left_child;
	}
	else {
		if (parent == parent->parent->left) {
			parent->parent->left = left_child;
		}
		else {
			parent->parent->right = left_child;
		}
	}
	left_child->right = parent;
	parent->parent = left_child;
}


//red_black_tree insert node
void rbt_insert_helper(RBTNode* tree, RBTNode node, CompareNode compare) {
	if (*tree == NULL)
		*tree = node;
	else {
		if (compare(node, *tree) < 0) {
			if ((*tree)->left == Nil) {
				(*tree)->left = node;
				node->parent = (*tree);
			}
			else
				rbt_insert_helper(&((*tree)->left), node, compare);
		}
		else {
			if ((*tree)->right == Nil) {
				(*tree)->right = node;
				node->parent = (*tree);
			}
			else
				rbt_insert_helper(&((*tree)->right), node, compare);
		}
	}
}

void rbt_insert_fixup(RBTNode* root, RBTNode node) {
	RBTNode uncle;

	while (node != *root && node->parent->color == RED) {
		if (node->parent == node->parent->parent->left) {
			uncle = node->parent->parent->right;
			if (uncle->color == RED) {
				node->parent->color = BLACK;
				uncle->color = BLACK;
				node->parent->parent->color = RED;
				node = node->parent->parent;
			}
			else {
				if (node == node->parent->right) {
					node = node->parent;
					rbt_left_rotate(root, node);
				}
				node->parent->color = BLACK;
				node->parent->parent->color = RED;
				rbt_right_rotate(root, node->parent->parent);
			}
		}
		else if (node->parent == node->parent->parent->right) {
			uncle = node->parent->parent->left;
			if (uncle->color == RED) {
				node->parent->color = BLACK;
				uncle->color = BLACK;
				node->parent->parent->color = RED;
				node = node->parent->parent;
			}
			else {
				if (node == node->parent->left) {
					node = node->parent;
					rbt_right_rotate(root, node);
				}
				node->parent->color = BLACK;
				node->parent->parent->color = RED;
				rbt_left_rotate(root, node->parent->parent);
			}
		}
	}
	(*root)->color = BLACK;
}

void rbt_insert(RBTNode* tree, RBTNode node, CompareNode compare) {
	rbt_insert_helper(tree, node, compare);

	node->color = RED;
	node->left = node->right = Nil;

	rbt_insert_fixup(tree, node);
}


//red_black_tree remove node
void rbt_transplant(RBTNode* root, RBTNode origin, RBTNode replace) {
	if (origin->parent == Nil || origin->parent == NULL)
		*root = replace;
	else if (origin == origin->parent->left)
		origin->parent->left = replace;
	else
		origin->parent->right = replace;
	if (replace != Nil)
		replace->parent = origin->parent;
}

void rbt_remove_fixup(RBTNode* T, RBTNode x) {
	while (x != *T && x->color == BLACK) {
		RBTNode w;
		if (x == x->parent->left) {
			w = x->parent->right;
			if (w->color == RED) {
				w->color = BLACK;
				x->parent->color = RED;
				rbt_left_rotate(T, x->parent);
				w = x->parent->right;
			}
			if (w->left->color == BLACK && w->right->color == BLACK) {
				w->color = RED;
				x = x->parent;
			}
			else {
				if (w->right->color == BLACK) {
					w->left->color = BLACK;
					w->color = RED;
					rbt_right_rotate(T, w);
					w = x->parent->right;
				}
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->right->color = BLACK;
				rbt_left_rotate(T, x->parent);
				x = *T;
			}
		}
		else {
			w = x->parent->left;
			if (w->color == RED) {
				w->color = BLACK;
				x->parent->color = RED;
				rbt_right_rotate(T, x->parent);
				w = x->parent->left;
			}
			if (w->left->color == BLACK && w->right->color == BLACK) {
				w->color = RED;
				x = x->parent;
			}
			else {
				if (w->left->color == BLACK) {
					w->right->color = BLACK;
					w->color = RED;
					rbt_left_rotate(T, w);
					w = x->parent->left;
				}
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->left->color = BLACK;
				rbt_right_rotate(T, x->parent);
				x = *T;
			}
		}
	}
	x->color = BLACK;
}

void rbt_remove(RBTNode* T, RBTNode z) {
	RBTNode x;
	RBTNode y = z;
	int y_origin_color = y->color;
	if (z->left == Nil) {
		x = z->right;
		rbt_transplant(T, z, z->right);
	}
	else if (z->right == Nil) {
		x = z->left;
		rbt_transplant(T, z, z->left);
	}
	else {
		y = rbt_min_node(z->right);
		y_origin_color = y->color;
		x = y->right;
		if (y->parent != z) {
			rbt_transplant(T, y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		rbt_transplant(T, z, y);
		y->left = z->left;
		y->left->parent = y;
		y->color = z->color;
	}

	free(z);

	if (y_origin_color == BLACK)
		rbt_remove_fixup(T, x);
}

//red_black_tree search node
RBTNode rbt_search_node(RBTNode tree, char* str, CompareStr compare_str) {
	if (tree == Nil)
		return NULL;

	if (compare_str(tree, str) > 0)
		return rbt_search_node(tree->left, str, compare_str);
	else if (compare_str(tree, str) < 0)
		return rbt_search_node(tree->right, str, compare_str);
	else
		return tree;
}

RBTNode rbt_min_node(RBTNode tree) {
	if (tree == Nil)
		return Nil;

	if (tree->left == Nil)
		return tree;
	else
		return rbt_min_node(tree->left);
}

RBTNode rbt_max_node(RBTNode tree) {
	if (tree == Nil)
		return Nil;

	if (tree->right == Nil)
		return tree;
	else
		return rbt_max_node(tree->right);
}

RBTNode rbt_successor(RBTNode x) {
	if (x->right != Nil) {
		return rbt_min_node(x->right);
	}
	RBTNode y = x->parent;
	while (y != NULL && x == y->right) {
		x = y;
		y = y->parent;
	}

	return y;
}

RBTNode rbt_predecessor(RBTNode x) {
	if (x->left != Nil) {
		return rbt_max_node(x->left);
	}
	RBTNode y = x->parent;
	while (y != NULL && x == y->left) {
		x = y;
		y = y->parent;
	}
	return y;
}


//red_black_tree application functions
int rbt_database_size(RBTNode root) {
	if (root == NULL || root == Nil)
		return 0;

	return rbt_database_size(root->left) + 1 + rbt_database_size(root->right);
}

void rbt_print(RBTNode tree, int level, int black_count, char* node_to_string(RBTNode)) {
	if (tree->color == BLACK)
		black_count++;

	if (tree->right != Nil)
		rbt_print(tree->right, level + 1, black_count, node_to_string);

	for (int i = 0; i < level; i++)
		printf(" ");
	if (tree->color == RED)
		SetColor(RED);
	else
		SetColor(GRAY);
	printf("%s", node_to_string(tree));
	SetColor(WHITE);

	if (tree->left == Nil && tree->right == Nil)
		printf("    ------%d\n", black_count);
	else
		printf("\n");

	if (tree->left != Nil)
		rbt_print(tree->left, level + 1, black_count, node_to_string);
}

void rbt_check_error(RBTNode parent, char* node_to_string(RBTNode)) {
	RBTNode left = parent->left;
	RBTNode right = parent->right;

	if (left != Nil) {
		if (left->parent != parent) {
			printf("parent : %s\n", node_to_string(parent));
			printf("left   : %s\n", node_to_string(left));
		}
		rbt_check_error(left, node_to_string);
	}

	if (right != Nil) {
		if (right->parent != parent) {
			printf("parent : %s\n", node_to_string(parent));
			printf("right   : %s\n", node_to_string(right));
		}
		rbt_check_error(right, node_to_string);
	}

	if (Nil->parent != Nil)
		printf("Nil parent is not Nil\n");
	if (Nil->left != Nil)
		printf("Nil left is not Nil\n");
	if (Nil->right != Nil)
		printf("Nil right is not Nil\n");
}