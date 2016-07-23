#include <stdio.h>
int sackw=17;
int s[5]={3,4,7,8,9};
int v[5]={4,5,10,11,13};
int include[5]={0,0,0,0,0};



void sort(void) {
	float temp;
	int i,j;
	float r[5];
	for(i=0; i<5; i++){
		r[i]=(float)v[i]/(float)s[i];
		printf("r[%d]=%f ",i,r[i]);

	}
	for (i=0;i<4;i++)
		for(j=i+1;j<5;j++)
	if(r[i]<r[j]){
		temp=r[i];
		r[i]=r[2];
		r[2]=temp;

		temp=s[i];
		s[i]=s[j];
		s[j]=(int)temp;

		temp=v[i];
		v[i]=v[j];
		v[j]=(int)temp;
	}
}
void greedy(){
	int w=0;
	int i;
	for(i=0;i<5; i++){
		w=w+s[i];
		if(w<=sackw) include[i]=1;
		else break;

	}

}
void result(){
	int i=0;
	int val=0;
	while(include[i]==1){
		printf("s[%d]=%d \n",i,s[i]);
		val=val+v[i];
		i++;


	}
	printf("The Maximum Value is %d",val);
}

int main(){
	 //clrscr();
		sort();
	printf("\n");
	int k,l;
	for(k=0;k<5;k++){
		//printf("s[%d]=%d ",k,s[k]);
		printf("v[%d]=%d ", k,v[k]);
	}
	printf("\n");
	for(k=0;k<5;k++){
		printf("s[%d]=%d ",k,s[k]);
		//printf("v[%d]=%d ", k,v[k]);

	}
	printf("\n");
	   greedy();
	result();
}

