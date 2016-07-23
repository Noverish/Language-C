#include <stdio.h>
#include <string.h>

void main() {
	char character, sen[505];

	scanf("%c%*c",&character);
	
	gets(sen);

	printf("%d", strrchr(sen,character) - sen );
}