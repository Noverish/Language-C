#include <stdio.h>
int is_it_ok(int a, int b) {
	int ok1, ok2;

	if('0'<=a&&a<='9') ok1=1;  
	else if('A'<=a&&a<='Z') ok1=2; 
	else if('a'<=a&&a<='z') ok1=3;
	else return 0;

	if('0'<=b&&b<='9') ok2=1;
	else if('A'<=b&&b<='Z') ok2=2; 
	else if('a'<=b&&b<='z') ok2=3;
	else return 0;

	if(a>b) return 0;
	if(ok1!=ok2) return 0;

	return 1;
}

int main() {

	int ch, sen[1500];
	int i,j;

	for(i=0;1;i++) {
		ch=getchar();
		sen[i]=ch;
		if(ch==EOF) break;
	}

	for(i=0;sen[i]!=EOF;i++) {
		
		if(sen[i]=='-') {
			if(  is_it_ok(sen[i-1],sen[i+1])  ) {
				if(sen[i+2]=='-') sen[i+2]=300;
				if(sen[i-1]==sen[i+1]) {
					i++;
					continue;
				}
				sen[i-1]++;
				for(;sen[i-1]<sen[i+1];sen[i-1]++) {
					printf("%c",sen[i-1]);
				}
				
			}
			else printf("-");
		}
		else {
			if(sen[i]==300) printf("-");
			else printf("%c",sen[i]);
		}
	}
	return 0;	
}