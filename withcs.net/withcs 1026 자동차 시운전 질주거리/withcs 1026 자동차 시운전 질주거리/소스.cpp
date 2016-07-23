#include <stdio.h>
#include <string.h>

struct time{
	double hour;
	double min;
	double second;
};

double time_gap(struct time *before, struct time *now) {
	double gap;
	
	(*now).hour-=1;
	(*now).min-=1;
	(*now).second+=60;
	(*now).min+=60;
	gap=3600*((*now).hour-(*before).hour)+60*((*now).min-(*before).min)+((*now).second-(*before).second);
	(*now).hour+=1;
	(*now).min+=1;
	(*now).second-=60;
	(*now).min-=60;
	(*before).hour=(*now).hour;
	(*before).min=(*now).min;
	(*before).second=(*now).second;
	return gap;
}

int main() {

	freopen("input.txt","r",stdin);

	struct time before = {0}, now;
	char sen[20], ch;
	double lenght=0, speed_wagon=0, change_speed, change_time;
	int i;

	while(1) {
		if(scanf("%s",sen)==EOF) break;
		ch=getchar();
		now.hour=10*(sen[0]-'0')+(sen[1]-'0');
		now.min=10*(sen[3]-'0')+(sen[4]-'0');
		now.second=10*(sen[6]-'0')+(sen[7]-'0');
		change_time=time_gap(&before,&now);

		if(ch==' ') {
			lenght+=change_time*speed_wagon/3600;
			scanf("%lf",&speed_wagon);
		}
		else {
			lenght+=change_time*speed_wagon/3600;
			printf("%s %.2lf km\n",sen,lenght);
		}
	}

	return 0;
}