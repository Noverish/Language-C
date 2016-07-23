#include <stdio.h>
#include <string.h>

#define WORD_LENGHT 20

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

int binary_search(int left, int right, char (*dictionary)[WORD_LENGHT], char search[WORD_LENGHT]) {
	
	int pivot = (left+right)/2;

	if(left==right)
		if(strcmp(dictionary[pivot],search)!=0)
			return -1;
	if(left>right)
		return -1;

	if(strcmp(dictionary[pivot],search)>0)
		return binary_search(left,pivot-1,dictionary,search);
	else if(strcmp(dictionary[pivot],search)<0)
		return binary_search(pivot+1,right,dictionary,search);
	else
		return pivot;
}

int main() {

	freopen("input.txt","r",stdin);

	char name[50000][WORD_LENGHT], my_name[WORD_LENGHT];
	char ch;
	int i=0;
	int sen_num, name_num;
	int pivot=0;

	scanf("%d",&sen_num);

	for(;sen_num>0;sen_num--) {
		while(1) {
			scanf("%s",name[i]);
			i++;
			if((ch=getchar())=='\n')
				break;
		}
	}

	name_num=i-1;

	quick_sort(0,name_num,name);

	while(scanf("%s",my_name)!=EOF) {

		pivot = binary_search(0,name_num,name,my_name);

		if(pivot==-1)
			printf("no\n");
		else
			printf("yes\n");
	}
	return 0;
}