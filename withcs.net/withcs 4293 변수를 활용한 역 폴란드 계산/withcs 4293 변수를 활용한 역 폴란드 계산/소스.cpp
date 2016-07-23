#include <stdio.h>
#include <string.h>
#include <ctype.h>

double stack[200];
int end=0;
double atof(char*);
int change[256];

void push(double number) {
	stack[end++] = number;
}

double pop(void) {
	return stack[--end];
}

int processing(char sen[]) {

	if(sen[1] == 0) {
		switch (sen[0])
		{
		case '+' : {
			push(pop() + pop());
			break;
				   }
		case '-' : {
			double save = pop();
			push(pop() - save);
			break;
				   }
		case '*' : {
			push(pop() * pop());
			break;
				   }
		case '/' : {
			double save = pop();
			push(pop() / save);
			break;
				   }
		case '%' : {
			double save = pop();
			push((int)pop() % (int)save);
			break;
				   }
		default: {
			push(change[sen[0]]);
			break;
				 }
		}
	}
	else
		push(atof(sen));
	return 0;
}

double atof(char s[]) {

	double val=0.0, power=1.0;
	int i,sign;

	for(i=0; isspace(s[i]) ; i++) ;

	sign = (s[i] == '-') ? -1 : 1;
	if(s[i] == '+' || s[i] == '-')
		i++;
	for(val = 0.0;isdigit(s[i]);i++)
		val = 10.0 * val + (s[i]-'0');
	if(s[i] == '.')
		i++;
	for(power = 1.0;isdigit(s[i]);i++) {
		val = 10.0 * val + (s[i]-'0');
		power *= 10.0;
	}
	return sign * val / power;
}

int main() {

	freopen("input.txt", "r", stdin);

	char scaning[10], ch;
	int i, number;

	for(i=0;i<26;i++) {
		scanf("%c %d%*c",&ch,&number);
		change[ch]=number;
	}


	while(scanf("%s",scaning)!=EOF) {
		processing(scaning);
	}

	printf("%lf",stack[0]);

	return 0;
}