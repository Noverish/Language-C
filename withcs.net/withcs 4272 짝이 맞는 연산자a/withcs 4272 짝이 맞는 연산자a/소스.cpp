#include <stdio.h>
#include <string.h>
#define GALHO 1
#define BRACKET 2
#define BRACES 3

char sentence[1005];
char stack[100];
int stack_number;

int stacking(char letter) {

	switch (letter)
	{
	case '{' : {
		stack[stack_number++] = BRACES;
		break;
			   }
	case '[' : {
		stack[stack_number++] = BRACKET;
		break;
			   }
	case '(' : {
		stack[stack_number++] = GALHO;
		break;
			   }
	case '}' : {
		if(stack_number==0) return 1;
		if(stack[--stack_number] == BRACES)
			stack[stack_number]=NULL;
		else return 1;
		break;
			   }
	case ']' : {
		if(stack_number==0) return 1;
		if(stack[--stack_number] == BRACKET)
			stack[stack_number]=NULL;
		else return 1;
		break;
			   }
	case ')' : {
		if(stack_number==0) return 1;
		if(stack[--stack_number] == GALHO)
			stack[stack_number]=NULL;
		else return 1;
		break;
			   }
	default:
		break;
	}

	return 0;
}

int ignore(int i) {

	i++;
	for(;;i++) {
		if(sentence[i] == '\"' || sentence[i] == '\'') {
			if(sentence[i-1] == '\\') {
				continue;
			}
			else break;
		}
		if(sentence[i+1] == '*' && sentence[i+2] == '/') {
			i+=2;
			break;
		}
	}

	return i;
}

int main() {

	//freopen("input.txt","r",stdin);

	int test_case, array_length, skipping=0;
	int i,j;
	
	scanf("%d",&test_case);
	i=getchar();

	for(;test_case>0;test_case--) {

		stack_number = 0;
		for(j=0;j<1005;j++)
			stack[j] = sentence[j] = NULL;

		gets(sentence);

		array_length = strlen(sentence);

		for(i=0;i<array_length;i++) {
			if(sentence[i] == '\"' || sentence[i] == '\'' || (sentence[i] == '/' && sentence[i+1] == '*')) {
				i=ignore(i);
				continue;
			}
			else if(sentence[i] == '(' || sentence[i] == ')' || sentence[i] == '{' || sentence[i] == '}' || sentence[i] == '[' || sentence[i] == ']') {
				if(stacking(sentence[i]) == 1) {
					printf("N\n");
					skipping=1;
					break;
				}
			}
		}

		if(skipping==1) {
			skipping=0;
			continue;
		}

		if(stack_number>0) 
			printf("N\n");
		else 
			printf("Y\n");

		
	}

	return 0;
}