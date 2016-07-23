#include <stdio.h>
#include <string.h>

int strncpy1(char sen[], int num, char str[]) {

	int i;
	int sen_len = strlen(sen);

	if(num>strlen(str))
		num=strlen(str);

	for(i=0;i<num;i++) {
		sen[i]=str[i];
	}

	if(i>sen_len)
		sen[i]=0;

	return 0;
}

int strncat1(char sen[], int num, char str[]) {

	int i;
	int strlen123 = strlen(sen);

	for(i=0;i<num;i++) {
		sen[i+strlen123]=str[i];
	}

	sen[i+strlen123]=0;

	return 0;
}

int strncmp1(char sen[], int num, char str[]) {

	int i;

	if(num>strlen(str))
		num=strlen(str);

	for(i=0;i<num;i++) {
		if(sen[i]==str[i])
			continue;
		else if(sen[i]>str[i]) 
			return 1;
		else if(sen[i]<str[i])
			return -1;
	}

	return 0;
}

int main() {

	//freopen("input.txt","r",stdin);
	
	char sen[100], kind_of_function[20], str[50];
	char ch;
	int number;
	
	gets(sen);

	while(scanf("%s",kind_of_function)!=EOF) {
		
		ch=getchar();
		scanf("%d",&number);
		ch=getchar();
		scanf("%s",str);

		if(strcmp(kind_of_function,"strncpy")==0) {
			strncpy1(sen,number,str);
		}
		else if(strcmp(kind_of_function,"strncat")==0) {
			strncat1(sen,number,str);
		}
		else if(strcmp(kind_of_function,"strncmp")==0) {
			printf("%d",strncmp1(sen,number,str));
			break;
		}
	}

	return 0;
}