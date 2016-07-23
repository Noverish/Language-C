#include <cstdio>
#include <cstring>
#include <algorithm>
#define WORD_LENGHT 100

using namespace std;

struct rest{
	int bench;
};

bool compare(rest A, rest B) {
	if(A.bench>B.bench)
		return 0;
	else if (A.bench<B.bench)
		return 1;
	else
		return 0;
}

int main() {

	freopen("input.txt","r",stdin);

	rest walk[1500];
	int i, mad_max;
	int bench_num;

	while(1) {
		mad_max=0;
		scanf("%d",&bench_num);

		if(bench_num==0)
			break;

		for(i=0;i<bench_num;i++)
			scanf("%d",&walk[i].bench);

		sort(walk,walk+bench_num,compare);

		for(i=0;i<bench_num-1;i++) {
			mad_max = (mad_max > (walk[i+1].bench-walk[i].bench)) ? mad_max : (walk[i+1].bench-walk[i].bench);
			if(mad_max>200) {
				printf("IMPOSSIBLE\n");
				break;
			}
		}
		if(i==bench_num-1){
			if(1522-walk[i].bench > 200)
				printf("IMPOSSIBLE\n");
			else
				printf("POSSIBLE\n");
		}
	}

	
	
	
	
	return 0;
}