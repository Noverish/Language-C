#include <stdio.h>
#include <string.h>
#define WORD_LENGHT 16

char dictionary[120000][WORD_LENGHT];

int binary_search(int left, int right, char search[WORD_LENGHT]) {
	
	int pivot = (left+right)/2;

	if(left==right)
		if(strcmp(dictionary[pivot],search)!=0)
			return -1;
	if(left>right)
		return -1;

	if(strcmp(dictionary[pivot],search)>0)
		return binary_search(left,pivot-1,search);
	else if(strcmp(dictionary[pivot],search)<0)
		return binary_search(pivot+1,right,search);
	else
		return pivot;
}

int main() {

	freopen("input.txt","r",stdin);

	char two_word1[WORD_LENGHT], two_word2[WORD_LENGHT];
	int i,j;
	int word_num, word_lenght;

	for(i=0;scanf("%s",dictionary[i])!=EOF;i++);

	word_num=i;

	for(i=0;i<word_num;i++) {
		word_lenght=strlen(dictionary[i]);
		
		for(j=1;j<word_lenght-1;j++) {
			strncpy(two_word1,dictionary[i],j);
			two_word1[j]=0;
			strcpy(two_word2,dictionary[i]+j);
			if(binary_search(0,word_num-1,two_word1)>=0 && binary_search(0,word_num-1,two_word2)>=0) {
				printf("%s\n",dictionary[i]);
				break;
			}
		}
	}

	return 0;
}