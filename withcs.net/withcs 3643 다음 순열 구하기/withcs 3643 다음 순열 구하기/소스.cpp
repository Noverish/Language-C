#include <stdio.h>
char q_num[100];

void align(int x) {
	int small_num='9'+1;
	int small_num_loc;
	int change_start;
	int y;
	int trash;

	change_start=x;

	for(;q_num[x]!=0;x++) {
		if(q_num[x]>q_num[change_start]) {
			if(q_num[x]<small_num) {
				small_num=q_num[x];
				small_num_loc=x;
			}
		}
	}

	trash=q_num[change_start];
	q_num[change_start]=q_num[small_num_loc];
	q_num[small_num_loc]=trash;
	
	for(x=change_start+1;q_num[x]!=0;x++) {
		for(y=x+1;q_num[y]!=0;y++) {
			if(q_num[x]>q_num[y]) {
				trash=q_num[x];
				q_num[x]=q_num[y];
				q_num[y]=trash;
			}
		}
	}
}


int main() {

	int test_case;
	int test_num;
	int i, ch;

	scanf("%d",&test_case);

	for(;test_case>0;test_case--) {
		
		scanf("%d",&test_num);
		ch=getchar();
		scanf("%s", q_num);
		/*for(i=0;1;i++) {
			ch=getchar();
			q_num[i]=ch;
			if(ch=='\n'||ch==' ') break;
		}*/
		for(i=0;1;i++) if(q_num[i]==0) break;
		i--;
		for(;i>0;i--) {
			if(q_num[i-1]<q_num[i]) {
				align(i-1);
				printf("%d ",test_num);
				for(i=0;q_num[i]!=0;i++) {
					printf("%c",q_num[i]);
				}
				break;
			}
		}

		if(i==0) printf("%d BIGGEST",test_num);

		if(test_case!=1) printf("\n");
	}

	return 0;
}