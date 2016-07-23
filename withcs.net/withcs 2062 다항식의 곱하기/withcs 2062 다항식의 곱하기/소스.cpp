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

		/*���׽� �Է�*/
		scanf("%d",&f_x_height);

		for(i=f_x_height-1;i>=0;i--)
			scanf("%d",&f_x[i]);


		scanf("%d",&g_x_height);

		for(i=g_x_height-1;i>=0;i--)
			scanf("%d",&g_x[i]);
		

		scanf("%d",&h_x_height);

		for(i=h_x_height-1;i>=0;i--)
			scanf("%d",&h_x[i]);
		

		/*���� ������ ��ȯ*/
		f_x_height--;
		g_x_height--;
		h_x_height--;
		

		A_x_height=f_x_height+g_x_height; // A_x�� ���� ���

		/*A_x ����*/
		for(i=0;i<=f_x_height;i++)
			for(j=0;j<=g_x_height;j++)
				A_x[i+j] += f_x[i] * g_x[j];
		

		/*A_x�� modulo 2 ��*/
		for(i=0;i<2010;i++)
			A_x[i]=A_x[i]%2;
		

		/*A_x�� h_x�� ������*/
		while(A_x_height>=h_x_height) {
			for(i=0;i<=h_x_height;i++) 
				A_x[ A_x_height-i ] = A_x[ A_x_height-i ]^h_x[ h_x_height-i ];
			
			/*A_x�� �ְ� ������ ������ ã�´�*/
			for(i=A_x_height;1;i--)
				if(A_x[i]==1) {
					A_x_height=i;
					break;
				}
		}

		/*���*/
		printf("%d",A_x_height+1);

		for(i=A_x_height;i>=0;i--)
			printf(" %d",A_x[i]);

		if(test_case!=1) printf("\n");


	}
	return 0;
}