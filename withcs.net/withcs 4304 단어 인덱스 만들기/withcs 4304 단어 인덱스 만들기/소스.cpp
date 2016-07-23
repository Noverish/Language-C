#include <cstdio>
#include <cstring>
#include <algorithm>
#define WORD_LENGHT 100

using namespace std;

struct word{
	char sen[WORD_LENGHT];
	int index;
};

bool compare(word A, word B) {
	return strcmp(A.sen, B.sen) < 0;
}

bool compare_number(word A, word B) {
	if(A.index < B.index)
		return 1;
	else
		return 0;
}

int musi(char trash[]) {

	char word[WORD_LENGHT];
	strcpy(word,trash);

	int i;
	
	for(i=0;i<strlen(word);i++)
		if('A'<=word[i] && word[i]<='Z')
			word[i]=word[i]-'A'+'a';

	if(strcmp(word,"the")==0)
		return 1;
	else if(strcmp(word,"of")==0)
		return 1;
	else if(strcmp(word,"and")==0)
		return 1;
	else if(strcmp(word,"to")==0)
		return 1;
	else if(strcmp(word,"a")==0)
		return 1;
	else if(strcmp(word,"in")==0)
		return 1;
	else if(strcmp(word,"is")==0)
		return 1;
	else if(strcmp(word,"you")==0)
		return 1;
	else if(strcmp(word,"are")==0)
		return 1;
	else if(strcmp(word,"for")==0)
		return 1;
	else
		return 0;
}

int main() {

	freopen("input.txt","r",stdin);

	word words[30000];
	char input[WORD_LENGHT], comparing[WORD_LENGHT];
	int word_num=0;
	int i, ch, line_num=1;
	int standard;

	while(1) {
		if(scanf("%s",input)==EOF)
			break;

		ch=getchar();

		if(strcmp(input,"//")==0) {
			if(ch!='\n') 
				gets(input);
			line_num++;
		}
		else if(strcmp(input,"/*")==0) {
			if(ch=='\n') 
				line_num++;
			while(1) {
				scanf("%s",input);
				ch=getchar();
				if(ch=='\n')
					line_num++;
				if(strcmp(input,"*/")==0)
					break;
			}
		}
		else {
			if(musi(input)==0) {
				strcpy(words[word_num].sen,input);
				words[word_num++].index=line_num;
			}
			if(ch=='\n')
				line_num++;
		}
	}

	sort(words,words+word_num,compare);
	
	for(i=0;i<word_num;) {
		for(standard=i;strcmp(words[standard].sen, words[i].sen)==0;i++);

		sort(words+standard, words+i-1, compare_number);

		printf("%s %d", words[standard].sen, words[standard].index);
		for(i=standard+1;strcmp(words[standard].sen,words[i].sen)==0;i++) {
			if(words[i-1].index != words[i].index)
				printf(" %d",words[i].index);
		}
		printf("\n");
	}
	
	return 0;
}