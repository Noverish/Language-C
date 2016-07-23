#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#define WORD_LENGHT 100

using namespace std;

struct word{
	char sen[WORD_LENGHT];
	int index;
};

word words[30000];

bool compare(word A, word B) {
	return strcmp(A.sen, B.sen) < 0;
}

bool compare_number(word A, word B) {
	if(A.index > B.index)
		return 1;
	else
		return 0;
}

int binary_search(int left, int right,char search[WORD_LENGHT]) {
	
	int pivot = (left+right)/2;

	if(left==right)
		if(strcmp(words[pivot].sen,search)!=0)
			return -1;
	if(left>right)
		return -1;

	if(strcmp(words[pivot].sen,search)>0)
		return binary_search(left,pivot-1,search);
	else if(strcmp(words[pivot].sen,search)<0)
		return binary_search(pivot+1,right,search);
	else
		return pivot;
}

int main() {

	freopen("input.txt","r",stdin);

	char input[WORD_LENGHT], comparing[WORD_LENGHT];
	int word_num=0;
	int i, ch, line_num=1, loc;
	int standard;

	while(1) {
		if(scanf("%s",input)==EOF)
			break;

		ch=getchar();

		if(strcmp(input,"//")==0) {
			if(ch!='\n') 
				gets(input);
		}
		else if(strcmp(input,"/*")==0) {
			while(1) {
				scanf("%s",input);
				ch=getchar();
				if(strcmp(input,"*/")==0)
					break;
			}
		}
		else {
			loc = binary_search(0,word_num,input);
			if(loc!=-1)
				words[loc].index++;
			else {
				strcpy(words[word_num].sen,input);
				words[word_num++].index=1;
				sort(words,words+word_num,compare);
			}
		}
	}
	
	sort(words,words+word_num,compare_number);

	for(i=0;i<word_num;) {
		for(standard=i;words[standard].index == words[i].index;i++);

		sort(words+standard, words+i, compare);

		for(i=standard;words[standard].index==words[i].index;i++) {
			printf("%s %d\n",words[i].sen,words[i].index);
		}
	}
	
	return 0;
}