#include <stdio.h>
#include <string.h>

int main() {

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	char word[100];
	int ch;
	int comment_on=0, lenght;
	int first_word=1;

	while(scanf("%s",word)!=EOF){

		ch=getchar();

		if(strcmp(word,"/*")==0) {
			comment_on=1;
			if(ch=='\n') {
				printf("%c",ch);
				first_word=1;
			}
			continue;
		}
		else if(strcmp(word,"*/")==0) {
			comment_on=0;
			if(ch=='\n') {
				printf("%c",ch);
				first_word=1;
			}
			continue;
		}

		if(first_word==1) {
			first_word=0;
		}
		else
			printf(" ");

		if(comment_on==1)
			printf("comment");
		else if(word[0]=='_')
			printf("id");
		else if(word[0]== '\'' && (('a'<=word[1] && word[1]<='z')||('A'<=word[1] && word[1]<='Z')) && word[2]=='\'' && word[3]==0)
			printf("char");
		else
			printf("normal");

		if(ch=='\n') {
			first_word=1;
			printf("\n");
		}
	}
	return 0;
}