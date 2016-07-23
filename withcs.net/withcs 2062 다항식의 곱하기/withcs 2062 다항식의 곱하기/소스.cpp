#include <stdio.h>


int main() {

	freopen("input.txt","r",stdin);

	int test_case;

	scanf("%d",&test_case);

	for(;test_case>0;test_case--) {

		int f_x[1005], g_x[1005], h_x[1005], A_x[2010];
		int i,j;
		int f_x_height, g_x_height, h_x_height, A_x_height;

		for(i=0;i<1005;i++) 
			A_x[2*i] = A_x[2*i+1] = f_x[i] = g_x[i] = h_x[i] = 0;

		/*다항식 입력*/
		scanf("%d",&f_x_height);

		for(i=f_x_height-1;i>=0;i--)
			scanf("%d",&f_x[i]);


		scanf("%d",&g_x_height);

		for(i=g_x_height-1;i>=0;i--)
			scanf("%d",&g_x[i]);
		

		scanf("%d",&h_x_height);

		for(i=h_x_height-1;i>=0;i--)
			scanf("%d",&h_x[i]);
		

		/*실제 차수로 변환*/
		f_x_height--;
		g_x_height--;
		h_x_height--;
		

		A_x_height=f_x_height+g_x_height; // A_x의 차수 계산

		/*A_x 생성*/
		for(i=0;i<=f_x_height;i++)
			for(j=0;j<=g_x_height;j++)
				A_x[i+j] += f_x[i] * g_x[j];
		

		/*A_x를 modulo 2 함*/
		for(i=0;i<2010;i++)
			A_x[i]=A_x[i]%2;
		

		/*A_x를 h_x로 나눈다*/
		while(A_x_height>=h_x_height) {
			for(i=0;i<=h_x_height;i++) 
				A_x[ A_x_height-i ] = A_x[ A_x_height-i ]^h_x[ h_x_height-i ];
			
			/*A_x의 최고 차항의 차수를 찾는다*/
			for(i=A_x_height;1;i--)
				if(A_x[i]==1) {
					A_x_height=i;
					break;
				}
		}

		/*출력*/
		printf("%d",A_x_height+1);

		for(i=A_x_height;i>=0;i--)
			printf(" %d",A_x[i]);

		if(test_case!=1) printf("\n");


	}
	return 0;
}