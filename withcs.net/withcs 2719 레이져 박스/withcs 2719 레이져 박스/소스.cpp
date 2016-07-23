#include <stdio.h>
#define LEFT 0
#define RIGHT 1
#define UP 3
#define DOWN 4

int inside_box[60][60];
int now_loc_x, now_loc_y;

int move(int status) {
	switch (status) {

	case LEFT : {
		now_loc_x--;
		return 0;
				}
	case RIGHT : {
		now_loc_x++;
		return 0;
				 }
	case UP : {
		now_loc_y++;
		return 0;
			  }
	case DOWN : {
		now_loc_y--;
		return 0;
				}
	}
}

int turn(int status) {
	switch (status) {

	case LEFT : return UP;
	case RIGHT : return DOWN;
	case UP : return RIGHT;
	case DOWN : return LEFT;

	}
}

void shooting(int size_of_box) {
	int status;

	if(now_loc_x==0) status = RIGHT;
	else if(now_loc_y==0) status = UP;
	else if(now_loc_x==size_of_box+1) status = LEFT;
	else if(now_loc_y==size_of_box+1) status = DOWN;

	move(status);
	if(inside_box[now_loc_x][now_loc_y] == 1) status = turn(status);

	while(now_loc_x!=0 && now_loc_y!=0 && now_loc_x!=size_of_box+1 && now_loc_y!=size_of_box+1) {
		move(status);
		if(inside_box[now_loc_x][now_loc_y] == 1) status = turn(status);
	}
}

int main() {

	freopen("input.txt","r",stdin);

	int test_case, size_of_box, right_turnner_number;
	int loc_x[60], loc_y[60];
	int razer_in_x, razer_in_y;
	int i,j;
	
	scanf("%d",&test_case);

	for(;test_case>0;test_case--) {

		for(i=0;i<60;i++) {
			for(j=0;j<60;j++)
				inside_box[i][j]=0;
			loc_x[i]=0;
			loc_y[i]=0;
		}

		scanf("%d %d",&size_of_box,&right_turnner_number);

		for(i=0;i<right_turnner_number;i++) {
			scanf("%d %d",&loc_x[i],&loc_y[i]);
			inside_box[ loc_x[i] ][ loc_y[i] ] = 1;
		}

		scanf("%d %d",&razer_in_x,&razer_in_y);

		now_loc_x=razer_in_x;
		now_loc_y=razer_in_y;

		shooting(size_of_box);

		printf("%d %d\n",now_loc_x,now_loc_y);
	}

	return 0;
}