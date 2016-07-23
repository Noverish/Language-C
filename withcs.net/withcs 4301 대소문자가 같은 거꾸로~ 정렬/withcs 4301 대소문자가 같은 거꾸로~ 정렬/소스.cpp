#include <stdio.h>
#include <string.h>

int swap(char *a, char *b) {
	char trash;

	trash=*a;
	*a=*b;
	*b=trash;

	return 0;
}

int strncmp1(char a, char b) {

	if(('A'<=a) && (a<='Z'))
		a=a-'A'+'a';
		
	if(('A'<=b) && (b<='Z'))
		b=b-'A'+'a';

	if(a<b)
		return 1;
	else
		return 0;
}

void sort(char string[]) {

	int i,j;
	int string_len=strlen(string)-1;
	
	for(i=0;i<=string_len-1;i++) {
		for(j=i+1;j<=string_len;j++) {
			if(strncmp1(string[i],string[j]))
				swap(&string[i],&string[j]);
		}
	}

	for(i=0;i<string_len-1;i++) {
		for(j=i+1;j<string_len;j++) {
			if((string[i]-string[j]=='A'-'a') || (string[i]-string[j]=='a'-'A'))
				if(string[i]<string[j])
					swap(&string[i],&string[j]);
		}
	}

}

int main() {
	
	freopen("input.txt","r",stdin);

	char sentence[500];

	while(gets(sentence)!=NULL) {
		sort(sentence);
		printf("%s\n",sentence);
	}
    return 0;
}