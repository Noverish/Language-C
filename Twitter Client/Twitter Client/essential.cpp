#include "essential.h"

char* read_one_line(FILE* fp) {
	char* str = (char*)malloc(1000);
	char* tmp;

	do {
		tmp = fgets(str, 1000, fp);

		if (tmp == NULL)
			return NULL;

	} while (strcmp(str, "\n") == 0);

	str = trim(str);
	return str;
}

char *trim(char *str)
{
	char *end;

	// Trim leading space
	while (*str == ' '|| *str == '\t' || *str == '\n') str++;

	if (*str == 0)  // All spaces?
		return str;

	// Trim trailing space
	end = str + strlen(str) - 1;
	while (end > str && (*end == ' ' || *end == '\t' || *end == '\n')) end--;

	// Write new null terminator
	*(end + 1) = 0;

	return str;
}

void SetColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}