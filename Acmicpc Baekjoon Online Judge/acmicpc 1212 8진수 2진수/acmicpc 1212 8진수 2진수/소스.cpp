#include <stdio.h>

int main() {
	int ch;
	int nothing=0;
	int while_out=0;
	while (while_out==0){
		ch=getchar();
		if(nothing==0) {
			switch (ch)
			{
			case '0' : break;
			case '1' : {
				printf("1");
				break;
					}
			case '2' : {
				printf("10");
				break;
					 }
			case '3' : {
				printf("11");
				break;
					 }
			case '4' : {
				printf("100");
				break;
					 }
			case '5' : {
				printf("101");
				break;
					 }
			case '6' : {
				printf("110");
				break;
					 }
			case '7' : {
				printf("111");
				break;
					 }
			default: {
				while_out=1;
				break;
					 }
			}
		}
		else {
			switch (ch)
			{
			case '0' : {
				printf("000");
				break;
					}
			case '1' : {
				printf("001");
				break;
					}
			case '2' : {
				printf("010");
				break;
					 }
			case '3' : {
				printf("011");
				break;
					 }
			case '4' : {
				printf("100");
				break;
					 }
			case '5' : {
				printf("101");
				break;
					 }
			case '6' : {
				printf("110");
				break;
					 }
			case '7' : {
				printf("111");
				break;
					 }
			default: {
				while_out=1;
				break;
					 }
			}
		}
		nothing++;
	}

	return 0;
}