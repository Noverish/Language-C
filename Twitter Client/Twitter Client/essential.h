#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include <Windows.h>

struct _adj {
	void* data;
	void* vertex;
	struct _adj* next;
};
typedef _adj* Adj;

struct _vertex {
	int f;
	int color;
	struct _vertex* parent;
	void* data;
	Adj friends;
};
typedef _vertex* Vertex;


//essential.cpp
char* read_one_line(FILE* fp);
char *trim(char *str);
void SetColor(int color);

//red_black_tree.cpp
void red_black_tree_init();

enum {
	BLACK, DARK_BLUE, DARK_GREEN, DARK_SKYBLUE, DARK_RED, DARK_VIOLET, DARK_YELLOW, GRAY, DARK_GRAY,
	BLUE, GREEN, SKYBLUE, RED, VIOLET, YELLOW, WHITE
};