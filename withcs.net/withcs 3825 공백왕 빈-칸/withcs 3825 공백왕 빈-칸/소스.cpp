#include <stdio.h>
#include <string.h>
#define MAX_WORD_NUMBER_IN_LINE 180
#define MAX_WORD_LENGHT 80
#define MAX_LINE 10000

struct sentence{
	char words[MAX_WORD_NUMBER_IN_LINE][MAX_WORD_LENGHT];
};

struct sentence sen[MAX_LINE];

int main() {

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int i=0, j=0, k, ch;
	int max_len[MAX_WORD_NUMBER_IN_LINE]={0}, sen_num=0;
	int sen_order=0, word_order=0;

	while(1) {
		ch=getchar();
		if(ch==' ')
			continue;
		else if(ch=='\n') {
			sen_order++;
			word_order=0;
			continue;
		}
		else if(ch==EOF)
			break;
		else {
			i=0;
			sen[sen_order].words[word_order][i++]=ch;
			while(1) {
				ch=getchar();
				if(ch==' ') {
					word_order++;
					break;
				}
				else if(ch=='\n') {
					sen_order++;
					word_order=0;
					break;
				}
				else if(ch==EOF)
					break;
				else
					sen[sen_order].words[word_order][i++]=ch;
			}
		}

		if(ch==EOF)
			break;
	}

	sen_num=sen_order;
	for(j=0;j<=MAX_WORD_NUMBER_IN_LINE-1;j++) {
		for(i=0;i<=sen_num;i++) {
			max_len[j] = (max_len[j] > strlen(sen[i].words[j])) ? max_len[j] : strlen(sen[i].words[j]);
		}
	}

	for(i=0;i<=sen_num;i++) {
		for(j=0;j<=MAX_WORD_NUMBER_IN_LINE-1;j++) {
			if(strcmp(sen[i].words[j],"")!=0) {
				printf("%s",sen[i].words[j]);
				if(strcmp(sen[i].words[j+1],"")!=0) {
					for(k=0;k<=max_len[j]-strlen(sen[i].words[j]);k++)
						printf(" ");
				}
			}
		}
		if(i!=sen_num)
			printf("\n");
	}

	return 0;
}