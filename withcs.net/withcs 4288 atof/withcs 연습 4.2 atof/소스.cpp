#include <stdio.h>
#include <string.h>

int resolve_string(char resolving_string[]) {

	int division, power_number=0, status = 0;
	char number_part[15], answer[30];
	int i,j=0, end=0;

	division = strcspn(resolving_string,"Ee");

	if(resolving_string[division+1] == '+')
		status = 1;
	else
		status = -1;

	for(i=2;i<5;i++)
		power_number = power_number * 10 + (resolving_string[division+i]-'0');
	power_number *= status;


	if(resolving_string[0] == '-')
		j=1;
	for(i=0;i+j<division;i++) {
		number_part[end++] = resolving_string[i+j];
		if(i==0)
			i++;
	}
	number_part[end] = 0;


	for(end--;end>=0;end--) {
		if(number_part[end] == '0')
			number_part[end] = 0;
		else break;
	}

	if(resolving_string[0] == '-')
		printf("-");
	if(power_number<0) {
		printf("0.");
		power_number++;
		if(power_number<0) {
			for(;power_number<0;power_number++) {
				printf("0");
			}
		}
		printf("%s",number_part);
	}
	else {
		for(i=0;power_number>=0;power_number--) {
			printf("%c",number_part[i++]);
		}
		printf(".");
		printf("%s",(number_part+i));
	}

	printf("\n");

	return 0;
}

int main() {

	//("input.txt","r",stdin);

	int test_case,trash;
	char num[30];

	scanf("%d",&test_case);
	trash=getchar();

	for(;test_case>0;test_case--) {
		
		gets(num);

		resolve_string(num);

	}


	return 0;
}