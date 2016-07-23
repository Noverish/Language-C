#include <stdio.h>

char number1[15], number2[15];

int main() {

	int ans=0;
	int i;
	int ch;
	int strlen;

	for(i=0;1;i++) {
		ch=getchar();
		if(ch==' ') break;
		number1[i]=ch;
	}

	strlen=i;

	while(1) {
		ch=getchar();
		if(ch==0||ch==EOF||ch=='\r'||ch=='\n') break;
		
		for(i=0;i<strlen;i++) 
			ans+=(number1[i]-48)*(ch-48);
	}

	printf("%d",ans);

	return 0;
}