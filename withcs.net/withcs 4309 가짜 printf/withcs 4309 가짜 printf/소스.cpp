#include <stdio.h>
#include <string.h>

int main() {

	freopen("input.txt","r",stdin);

	char scan[100];
	char ch;
	int i=0;

	char s[100];
	char c;
	double f;
	int d;
	long long lin;

	while(1) {

		
		scan[0]=getchar();
		for(i=1;(scan[i]=getchar())!='\"';i++);

		for(i=1;scan[i]!='\"';i++) {
			if(scan[i]=='%') {
				switch (scan[i+1])
				{
				case 's' : {
					scanf("%s",s);
					printf("%s",s);
					i++;
					break;
						   }
				case 'd' : {
					scanf("%d",&d);
					printf("%d",d);
					i++;
					break;
						   }
				case 'f' : {
					scanf("%lf",&f);
					printf("%lf",f);
					i++;
					break;
						   }
				case 'x' : {
					ch=getchar();
					ch=getchar();
					printf("%x",ch);
					i++;
					break;
						   }
				case 'X' : {
					ch=getchar();
					ch=getchar();
					printf("%X",ch);
					i++;
					break;
						   }
				case 'o' : {
					scanf("%d",&d);
					printf("%o",d);
					i++;
					break;
						   }
				case 'c' : {
					scanf("%d",&d);
					printf("%c",d);
					i++;
					break;
						   }
				case 'e' : {
					scanf("%lf",&f);
					printf("%e",f);
					i++;
					break;
						   }
				case 'u' : {
					scanf("%lld",&lin);
					printf("%u",lin);
					i++;
					break;
						   }
				}
			}
			else {
				printf("%c",scan[i]);
			}
		}
		printf("\n");
		if((ch=getchar())==EOF) break; // delete the enter('\n') from the input buffer.
	}
	return 0;
}