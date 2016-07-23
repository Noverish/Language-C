#include <stdio.h>
#include <string.h>
#define WORD_LENGHT 15

int quick_sort(int left, int right, char (*sen)[WORD_LENGHT]) {

	char word[WORD_LENGHT]={0};
	int low = left+1;
	int high = right;
	int pivot = left;

	if(right <= left)
		return 0;

	while(low < high) {
		while (strcmp(sen[pivot],sen[low])>=0 && low<=right)
			low++;

		while (strcmp(sen[pivot],sen[high])<=0 && high>=left+1)
			high--;

		if(low <= high) {
			strcpy(word,sen[low]);
			strcpy(sen[low],sen[high]);
			strcpy(sen[high],word);
		}
	}
	if(strcmp(sen[pivot],sen[high])>0) {
		strcpy(word,sen[pivot]);
		strcpy(sen[pivot],sen[high]);
		strcpy(sen[high],word);
	}
	quick_sort(left,high-1,sen);
	quick_sort(high+1,right,sen);

	return 0;

}

int main() {

	freopen("input.txt","r",stdin);

	char words[100][WORD_LENGHT];
	int i=0;

	while(scanf("%s",words[i++])!=EOF);

	quick(0,i-2,words);

	return 0;
}