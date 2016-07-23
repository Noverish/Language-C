#include <stdio.h>

int farm_martix[5000][5000];
int index[10000]={0};

void union_find(int x, int y) {
	int z;
	for(z=0;z<10000;z++) {
		if(index[z]==y) index[z]=x;
	}
}

int main(void) {

	int farm_num;
	int farm_dis[3][10000];
	int i,j, a=0;
	int min_dis=999999;
	int trash;

	scanf("%d",&farm_num);

	for(i=0;i<farm_num;i++) {
		for(j=0;j<farm_num;j++){
			scanf("%d",&farm_martix[i][j]);
		}
	}
	/* 행렬 형태의 정보를 간선 형태의 정보로 바꿈*/
	for(i=0;i<farm_num-1;i++) {
		for(j=i+1;j<farm_num;j++) {
			farm_dis[0][a]=i;
			farm_dis[1][a]=j;
			farm_dis[2][a]=farm_martix[i][j];
			a++;
		}
	}

	int farm_dis_num;
	farm_dis_num = a;
	/* 간선의 정보를 길이 순으로 배열*/
	for(i=0;i<farm_dis_num;i++) {
		for(j=i+1;j<farm_dis_num;j++)  {
			if(farm_dis[2][i]>farm_dis[2][j]) {
				for(a=0;a<3;a++) {
					trash=farm_dis[a][i];
					farm_dis[a][i]=farm_dis[a][j];
					farm_dis[a][j]=trash;
				}
			}
		}
	}
	for(i=0;i<10000;i++) index[i]=i; //모든 위치를 다른 집합에 포함시킨다

	int ans=0;

	
	for(i=0;i<farm_dis_num;i++) {
		if(index[farm_dis[0][i]]!=index[farm_dis[1][i]]){
			union_find(index[farm_dis[0][i]],index[farm_dis[1][i]]);
			ans+=farm_dis[2][i];
		}
	}
	
	printf("%d",ans);
	return 0;
}