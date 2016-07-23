#include <stdio.h>
#include <math.h>

int player_health_tree[65538];
int player_winner_list[32769][15];
int player_winner_tree[65538];
int player_origin_health[32769];

int square2(int a) {
	int sum=1;
	int i;
	for(i=0;i<a;i++)
		sum*=2;
	return sum;
}

void fight(int match_num2, int add_health2) {

	int a=0;

	int order;
	int player_amount = square2(match_num2);
	int i;

	for(order=0 ; order < player_amount ; order++)
		player_winner_tree[player_amount+order]=order;

	for(order=0 ; order < player_amount ; order++)
		player_origin_health[order] = player_health_tree[player_amount+order];

	for(i=0;i<match_num2;i++, player_amount/=2) {
		for(order=0 ; order < player_amount ; order+=2) {
			if(player_health_tree[player_amount+order] >= player_health_tree[player_amount+order+1]) {

				player_health_tree[(player_amount+order)/2] = player_health_tree[player_amount+order] - player_health_tree[player_amount+order+1];
				player_winner_tree[(player_amount+order)/2] = player_winner_tree[player_amount+order];
				player_winner_list[ player_winner_tree[player_amount+order] ][i]=player_winner_tree[player_amount+order+1];
				
				if(player_origin_health[ player_winner_tree[player_amount+order] ] - player_health_tree[(player_amount+order)/2] >= add_health2)
					player_health_tree[(player_amount+order)/2]+=add_health2;
				else
					player_health_tree[(player_amount+order)/2]=player_origin_health[ player_winner_tree[player_amount+order] ];
			}
			else {
				player_health_tree[(player_amount+order)/2] = player_health_tree[player_amount+order+1] - player_health_tree[player_amount+order];
				player_winner_tree[(player_amount+order)/2] = player_winner_tree[player_amount+order+1];
				player_winner_list[ player_winner_tree[player_amount+order+1] ][i]=player_winner_tree[player_amount+order];
				
				if(player_origin_health[ player_winner_tree[player_amount+order+1] ] - player_health_tree[(player_amount+order)/2] >= add_health2)
					player_health_tree[(player_amount+order)/2]+=add_health2;
				else
					player_health_tree[(player_amount+order)/2]=player_origin_health[ player_winner_tree[player_amount+order+1] ];
			}
		}
	}
	printf("%d\n",player_winner_tree[1]+1);
	for(i=0;i<match_num2;i++) {
		printf("%d",player_winner_list[ player_winner_tree[1] ][i]+1);
		if(i!=match_num2-1)
			printf(" ");
	}
	printf("\n");
}

int main() {

	freopen("input.txt","r",stdin);

	int test_case, match_num, add_health;
	int i, square;
	scanf("%d",&test_case);

	for(;test_case>0;test_case--) {

		scanf("%d %d",&match_num, &add_health);

		square=square2(match_num);

		for(i=0;i<square;i++)
			scanf("%d",&player_health_tree[square+i]);

		fight(match_num, add_health);
		
	}
	return 0;
}