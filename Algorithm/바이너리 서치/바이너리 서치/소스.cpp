#include <stdio.h>
#include <string.h>

#define WORD_LENGHT 20

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

	return 0;
}