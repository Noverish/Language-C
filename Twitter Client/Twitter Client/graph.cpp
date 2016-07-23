#include "essential.h"
#include "graph.h"

int time;
vertex_to_string global_vts;
Vertex* global_graph;
int global_nelem;

void print_graph(Vertex vertex[], int nelem) {
	for (int i = 0; i < nelem; i++) {
		Vertex v = vertex[i];
		if(v->parent == NULL)
			printf("%-20s - color:%2d f:%4d\n", global_vts(v), v->color, v->f);
		else
			printf("%-20s - color:%2d f:%4d p:%s\n", global_vts(v), v->color, v->f, global_vts(v->parent));
	}
}

void add_friend(Vertex to, Vertex from) {
	Adj adj = (Adj)malloc(sizeof(struct _adj));

	adj->data = to->data;
	adj->next = NULL;
	adj->vertex = to;

	Adj fromFirst = from->friends;
	from->friends = adj;
	adj->next = fromFirst;
}

void vertex_visit(Vertex start) {
	start->color = GRAY;
	for (Adj adj = start->friends; adj != NULL; adj = adj->next) {
		Vertex vtx = (Vertex)adj->vertex;
		if (vtx->color == WHITE) {
			vtx->parent = start;
			vertex_visit(vtx);
		}
	}
	start->color = BLACK;
	start->f = ++time;
}

void DFS(Vertex graph[], int nelem) {
	for (int i = 0; i < nelem; i++) {
		graph[i]->color = WHITE;
		graph[i]->parent = NULL;
	}
	time = 0;
	for (int i = 0; i < nelem; i++) {
		if (graph[i]->color == WHITE)
			vertex_visit(graph[i]);
	}
}

Vertex* copy_grpah(Vertex graph[], int nelem) {
	Vertex* copy = (Vertex*)malloc(sizeof(struct _vertex) * nelem);

	for (int i = 0; i < nelem; i++) {
		Vertex v = (Vertex)malloc(sizeof(struct _vertex));
		v->color = graph[i]->color;
		v->data = graph[i]->data;
		v->f = graph[i]->f;
		v->parent = graph[i]->parent;
	}

	for (int i = 0; i < nelem; i++) {
		for (Adj adj = graph[i]->friends; adj != NULL; adj = adj->next) {
			Vertex origin_from, origin_to, new_from, new_to;

			origin_from = graph[i];
			origin_to = (Vertex)adj->vertex;
			new_from = copy[i];

			for (int j = 0; j < nelem; j++)
				if (copy[j]->data == origin_to->data)
					new_to = copy[j];

			add_friend(new_to, new_from);
		}
	}

	return copy;
}

Vertex* transpose_copy(Vertex* graph, int nelem) {
	Vertex* copy = (Vertex*)malloc(sizeof(Vertex) * nelem);

	for (int i = 0; i < nelem; i++) {
		Vertex v = (Vertex)malloc(sizeof(struct _vertex));
		v->color = graph[i]->color;
		v->data = graph[i]->data;
		v->f = graph[i]->f;
		v->parent = graph[i]->parent;
		v->friends = NULL;
		copy[i] = v;
	}

	for (int i = 0; i < nelem; i++) {
		for (Adj adj = graph[i]->friends; adj != NULL; adj = adj->next) {
			Vertex origin_from, origin_to, new_from, new_to;

			origin_from = graph[i];
			origin_to = (Vertex)adj->vertex;
			new_from = copy[i];

			for (int j = 0; j < nelem; j++)
				if (copy[j]->data == origin_to->data) {
					new_to = copy[j];
					add_friend(new_from, new_to);
				}
		
		}
	}

	return copy;
}

void sort_decrease_by_f(Vertex graph[], int nelem) {
	for (int i = 0; i < nelem - 1; i++)
		for (int j = i + 1; j < nelem; j++)
			if (graph[i]->f < graph[j]->f) {
				Vertex tmp = graph[i];
				graph[i] = graph[j];
				graph[j] = tmp;
			}
}

void print_scc(Vertex u, vertex_to_string vts) {
	printf("\t%s\n", vts(u));
	if (u->parent != NULL)
		print_scc(u->parent, vts);
}

void scc_find(Vertex u, vertex_to_string vts) {
	u->color = GRAY;
	int found = 0;
	for (Adj adj = u->friends; adj != NULL; adj = adj->next) {
		Vertex v = (Vertex)adj->vertex;
		if (v->color == WHITE) {
			found = 1;
			v->parent = u;
			scc_find(v, vts);
		}
	}
	if (found == 0) {
		print_graph(global_graph, global_nelem);
		printf("\nSCC: ");
		print_scc(u, vts);
	}
	u->color = BLACK;
}

void strongly_connected_compnent(Vertex graph[], int nelem, vertex_to_string vts) {
	global_vts = vts;
	DFS(graph, nelem);
	Vertex* transpose = transpose_copy(graph, nelem);
	sort_decrease_by_f(transpose, nelem);
	for (int i = 0; i < nelem; i++) {
		transpose[i]->color = WHITE;
		transpose[i]->parent = NULL;
	}
	global_graph = transpose;
	global_nelem = nelem;
	for (int i = 0; i < nelem; i++)
		if (transpose[i]->color == WHITE) {
			scc_find(transpose[i], vts);
		}
}



