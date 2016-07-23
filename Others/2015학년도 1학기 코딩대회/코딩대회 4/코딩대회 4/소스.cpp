#include <stdio.h>

int copy_alpabet[30];
int relation[30];
int alpabet[30];

int find(int a) {
	int i;
	
	if(copy_alpabet[a]==0) {
		relation[a]=0x7fffffff;
		return 0;
	}

	for(i=0;i<26;i++) {
		if(copy_alpabet[a]==alpabet[i]) {
			relation[a]=i;
			return 0;
		}
	}
}

int main() {

	freopen("input.txt","r",stdin);

	
	int i;
	char ch;
	int number;
	char sen[100000];
	int sen_lenght;

	for(i=0;i<26;i++) {
		scanf("%c %d",&ch,&number);
		alpabet[ch-'a']=number;
		ch=getchar();
	}
	
	for(i=0;1;i++) {
		ch=getchar();
		if(ch==EOF)
			break;
		if('a'<=ch && ch<='z')
			copy_alpabet[ch-'a']++;
		sen[i]=ch;
	}

	sen_lenght=i;

	for(i=0;i<26;i++) {
		find(i);
	}

	for(i=0;i<sen_lenght;i++) {
		if('a'<= sen[i] && sen[i] <= 'z') {
			printf("%c",relation[sen[i]-'a']+'a');
		}
		else
			printf("%c",sen[i]);
	}


	return 0; 
}