#include <stdio.h>

int main() {

	int ch, sen[1500];
	int i,j;

	for(i=0;1;i++) {
		ch=getchar();
		sen[i]=ch;
		if(ch==EOF) break;
	}

	for(i=0;sen[i]!=EOF;i++) {
		if(sen[i]=='\\') {
			i++;
			switch (sen[i])
			{
			case 'n' : {
				printf("\n");
				break;
					   }
			case 't' : {
				printf("\t");
				break;
					   }
			case 'b' : {
				printf("\b");
				break;
					   }
			default:
				printf("\\");
				printf("%c",sen[i]);
				break;
			}
		}
		else printf("%c",sen[i]);
	}

	return 0;
}