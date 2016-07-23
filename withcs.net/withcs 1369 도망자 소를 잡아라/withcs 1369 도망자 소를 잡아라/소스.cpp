#include <stdio.h>
#include <math.h>

int man_loc, cow_loc;
int queue[1000000];
int front=0, end=0;
int on=0;
int index[1000000]={0};
int front_copy=0;

int find(int a,int b) {
	queue[end++]=a;
	index[a]=1;
	if(a>b)
		return a-b;
	if(a==b)
		return 0;

	while(1) {
		if(queue[front]*2==b) return index[queue[front]];
		else if(queue[front]-1==b) return index[queue[front]];
		else if(queue[front]+1==b) return index[queue[front]];
		else {
				if(queue[front]*2<900000) {
					if(index[queue[front]*2]==0) {
						queue[end++]=queue[front]*2;
						index[queue[front]*2]=index[queue[front]]+1;
					}
				}
				if(queue[front]-1>=0) {
					if(index[queue[front]-1]==0) {
						queue[end++]=queue[front]-1;
						index[queue[front]-1]=index[queue[front]]+1;
					}
				}
				if(queue[front]+1<900000) {
					if(index[queue[front]+1]==0) {
						queue[end++]=queue[front]+1;
						index[queue[front]+1]=index[queue[front]]+1;
					}
				}
				
				front++;
		}	
	}
}

int answer(int c) {

	/*if(c==0) return 0;
	if(c<0) return -c;
	c+=front_copy*100000;
	int d;
	d = log((double)2*c+1)/log(3.0);
	return d+1;*/

	return c;
}

int main() {
	int ans;

	scanf("%d %d",&man_loc,&cow_loc);
	
	ans=answer(find(man_loc,cow_loc));
	
	printf("%d\n",ans);

	return 0;
}