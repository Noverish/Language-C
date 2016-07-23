#include <stdio.h>
#include <string.h>

char equation[2000];
char stack[2000];
int end=0, equation_end=0, first=0;
void strinput(char to[], char character) {
	int i;
	int to_lenght=strlen(to);
	for(i=to_lenght;i>=0;i--)
		to[i+1]=to[i];
	to[i]=character;
}

void push_equation(char some) {
	equation[equation_end++] = some;
}

void push_stack(char number) {
	stack[end++] = number;
}

char pop(void) {
	char a = stack[end];
	stack[end--]=0;
	return a;
}

void processing(char input) {
	char save=0;
	switch (input) {
	case '+' : 
	case '-' : 
	case '*' : 
	case '/' : {
		if(first==0) {
			save = pop();
			first=1;
		}
		push_equation(pop());
		push_equation(input);
		push_equation(save);
		break;
			   }
	default : {
		push_stack(input);
		break;
			  }
	}
}

int main() {

	freopen("input.txt", "r", stdin);

	char input;
	int i;
	while(1) {

		equation_end=0, end=0, first=0;
		for(i=0;i<2000;i++)
			equation[i]=stack[i]=0;

 		while(1) {
			scanf("%c",&input);
			if(input==' ')
				continue;
			processing(input);
			if(input=='\n'||input==EOF)
				break;
		}

		push_equation(0);
		printf("%s\n",equation);

		if(input==EOF)
			break;
	}

	

	return 0;
}