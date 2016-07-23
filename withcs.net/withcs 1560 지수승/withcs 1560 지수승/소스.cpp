#include <stdio.h>
#include <string.h>
#define ARRAY_LEN 5000

int delete_point(char sen[], int *num) {

	int i, under=0;

	for(i=5;i>=0;i--) {
		if(sen[i]=='0')
			sen[i]=0;
		else break;
	}

	for(i=0;sen[i]!=0 && sen[i]!='.';i++) {
		*num = *num*10 + sen[i]-'0';
	}

	if(sen[i]==0)
		return 0;
	else if(sen[i]=='.')
		i++;

	for(;sen[i]!=0;i++) {
		*num = *num*10 + sen[i]-'0';
		under++;
	}

	return under;
}

int main() {
   
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int process[ARRAY_LEN];
	int answer[ARRAY_LEN];
	char number[7];
	int multi, under_point, num, i, j;
	int number_lenght;

	while(scanf("%s %d",number,&multi)!=EOF) {
		
		for(i=0;i<ARRAY_LEN;i++)
			answer[i]=process[i]=0;

		num=0;
		under_point=delete_point(number,&num);
		process[0]=1;

		for(i=1;i<=multi;i++) {
			for(j=0;j<=5*i && j<ARRAY_LEN;j++)
				process[j]*=num;
			for(j=0;j<=5*i && j<ARRAY_LEN;j++) {
				if(process[j]>10000) {
					process[j+1]+=process[j]/10000;
					process[j]%=10000;
				}
			}
		}

		for(i=0;i<=multi*6;i++) {
			for(j=0;j<4;j++) {
				answer[4*i+j] = process[i]%10;
				process[i]/=10;
			}
		}

		for(i=multi*6;i>=multi*under_point;i--)
			answer[i+1]=answer[i];
		answer[i+1]='.';
		for(i=multi*6;answer[i]==0;i--);
		for(;i>=0;i--) {
			if(answer[i]=='.')
				printf(".");
			else
				printf("%d",answer[i]);
		}
		printf("\n");
	}

    return 0;
}