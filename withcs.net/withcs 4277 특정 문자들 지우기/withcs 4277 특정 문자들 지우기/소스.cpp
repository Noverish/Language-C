#include <stdio.h>

int main() {

	int s1[100000]={0}, s2[100000]={0};
	int ch;
	int i;
	int ASCII[300]={0};


	for(i=0;1;i++) {
		ch=getchar();
		s1[i]=ch;
		if(ch=='\n') break;
	}

	for(i=0;1;i++) {
		ch=getchar();
		s2[i]=ch;
		if(ch==EOF) break;
	}

	for(i=0;s2[i]!=EOF;i++) {
		ASCII[s2[i]]++;
	}
	for(i=0;s1[i]!='\n';i++) {
		if(ASCII[s1[i]]!=0) s1[i] = 0;
	}

	for(i=0;s1[i]!='\n';i++) {
		if(s1[i]!=0) printf("%c",s1[i]);
	}




	return 0;
}