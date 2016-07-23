#include <stdio.h>

int candy[105];

struct answer {
	int horuragi_answer;
	int candy_answer;
};

void giving(int stu_num, struct answer *A) {

	int i, horuragi;
	int half_candy[105];

	for(i=0;i<stu_num-1;i++) {
		if(candy[i]!=candy[i+1])
			break;
	}
	if(i==stu_num-1) {
		(*A).horuragi_answer = 0;
		(*A).candy_answer = candy[i];
		return ;
	}

	for(horuragi=0;1;horuragi++) {
		for(i=0;i<stu_num;i++) {
			half_candy[i]=candy[i]/2;
			candy[i]-=half_candy[i];
		}

		for(i=0;i<stu_num;i++)
			candy[(i+1)%stu_num]+=half_candy[i%stu_num];

		for(i=0;i<stu_num;i++) {
			if(candy[i]%2==1)
				candy[i]++;
		}

		for(i=0;i<stu_num-1;i++) {
			if(candy[i]!=candy[i+1])
				break;
		}

		if(i==stu_num-1) {
			(*A).horuragi_answer = horuragi+1;
			(*A).candy_answer = candy[i];
			return ;
		}
	}
}

int main() {

	freopen("input.txt","r",stdin);
	
	struct answer * pans;
	struct answer ans;
	int student_num;
	int i;
	pans = &ans;

	while(1) {
		scanf("%d",&student_num);

		if(student_num==0)
			break;

		for(i=0;i<student_num;i++)
			scanf("%d",&candy[i]);

		giving(student_num,pans);

		printf("%d %d\n",ans.horuragi_answer,ans.candy_answer);
	}

	return 0;
}