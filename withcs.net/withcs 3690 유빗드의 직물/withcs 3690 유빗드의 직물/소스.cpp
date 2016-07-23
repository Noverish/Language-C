#include <stdio.h>

int main() {
	freopen("input.txt","r",stdin);
	int base, kind_color, pattern_len, before_num;
	int pattern[105];
	int i, ch;
	long long string_num;

	while(1) {
		string_num=0;

		scanf("%d %d %d",&base,&kind_color,&pattern_len);

		if(base==0 && kind_color==0 && pattern_len==0)
			break;

		for(i=0;i<pattern_len;i++) {
			scanf("%d",&pattern[i]);
			ch=getchar();
			if(ch=='\n')
				break;
		}

		before_num=base;
		string_num+=before_num;

		for(i=0;i<kind_color-1;i++) {
			before_num+=pattern[i%pattern_len];
			string_num+=before_num;
		}

		printf("%lld\n",string_num);

	}

	return 0;
}