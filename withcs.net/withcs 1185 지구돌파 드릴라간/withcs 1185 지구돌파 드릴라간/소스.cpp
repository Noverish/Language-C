#include <stdio.h>
#include <math.h>
#define PI 3.141592653589
#define R 6371009

struct coordinate {
	double x;
	double y;
	double z;
};

double lenght(struct coordinate A, struct coordinate B) {
	return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y)+(A.z-B.z)*(A.z-B.z));
}

int main() {

	struct coordinate point1, point2;
	int test_case;
	double point1_w, point1_g, point2_w, point2_g;
	double drill_len, drill_ho;
	double answer;

	scanf("%d",&test_case);

	for(;test_case>0;test_case--) {
		scanf("%lf %lf %lf %lf",&point1_w, &point1_g, &point2_w, &point2_g);

		point1_w=point1_w*(PI/180);
		point1_g=point1_g*(PI/180);
		point2_w=point2_w*(PI/180);
		point2_g=point2_g*(PI/180);

		point1.x=cos(point1_w)*cos(point1_g);
		point1.y=cos(point1_w)*sin(point1_g);
		point1.z=sin(point1_w);

		point2.x=cos(point2_w)*cos(point2_g);
		point2.y=cos(point2_w)*sin(point2_g);
		point2.z=sin(point2_w);

		drill_len=lenght(point1,point2);

		drill_ho=R*acos((2-drill_len*drill_len)/2);

		drill_len*=R;
		
		answer=drill_ho-drill_len;

		if(answer>0)
			printf("%.0lf\n",answer);
		else
			printf("%.0lf\n",-answer);
	}

	return 0;
}