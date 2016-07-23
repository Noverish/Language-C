#include <stdio.h>
#include <string.h>

int main() {

	freopen("input.txt","r",stdin);

	char P1[80], P2[80];
	int i, test_case;
	int player1, player2;

	while(1) {

		gets(P1);
		gets(P2);
		test_case=strlen(P1);
		player1=player2=0;

		if(P1[0]=='E' && P2[0]=='E')
			break;

		for(i=0;i<test_case;i++) {
			switch (P1[i])
			{
			case 'R' : {
				if(P2[i]=='S')
					player1++;
				else if(P2[i]=='P')
					player2++;
				break;
					   }
			case 'S' : {
				if(P2[i]=='R')
					player2++;
				else if(P2[i]=='P')
					player1++;
				break;
					   }
			case 'P' : {
				if(P2[i]=='R')
					player1++;
				else if(P2[i]=='S')
					player2++;
				break;
					   }
			default:
				break;
			}
		}
		printf("P1: %d\nP2: %d\n",player1,player2);
	}

	return 0;
}