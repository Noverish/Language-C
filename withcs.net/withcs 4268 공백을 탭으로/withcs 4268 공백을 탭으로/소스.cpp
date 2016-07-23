#include <stdio.h>

int main() {
	int ch_loc=1; //지금 검색하는 문자의 위치 한 줄에 1부터 시작
	int ch;
	int sen[100000];
	int i;
	int change=0;
	/* 일단 모든 문자열을 받는다*/
	for(i=0;1;i++) {
		ch=getchar();
		sen[i]=ch;
		if(ch==EOF) break;
	}

	for(i=0;sen[i]!=EOF;i++) {
		if(sen[i]==' ') {
			switch (ch_loc%4) { //띄어쓰기의 위치에 따라 치환을 다르게 한다.
			case 0 : {
					if(sen[i]==' ') {
						sen[i]='\t';
						ch_loc+=1;
					}
					else ch_loc++;
					break;
				}
			case 1 : {
					if(sen[i]==' ' && sen[i+1]==' ' && sen[i+2]==' ' && sen[i+3]==' ') {
						sen[i]='\t';
						sen[i+1]=0;//띄어쓰기를 탭으로 바꾸면 원래 띄어쓰기가 있던 자리를 널 문자로 바꾼다. 문자열 출력할때를 위해
						sen[i+2]=0;
						sen[i+3]=0;
						ch_loc+=4;
						i+=3;
					}
					else if(sen[i]==' ' && sen[i+1]==' ' && sen[i+2]==' ' && sen[i+3]=='\t') {
						sen[i]='\t';
						sen[i+1]=0;
						sen[i+2]=0;
						sen[i+3]=0;
						ch_loc+=4;
						i+=3;
					}
					else if(sen[i]==' ' && sen[i+1]==' ' && sen[i+2]=='\t') {
						sen[i]='\t';
						sen[i+1]=0;
						sen[i+2]=0;
						ch_loc+=4;
						i+=2;
					}
					else if(sen[i]==' ' && sen[i+1]=='\t') {
						sen[i]='\t';
						sen[i+1]=0;
						ch_loc+=4;
						i+=1;
					}
					else ch_loc++;
					break;
				}
			case 2: {
					if(sen[i]==' ' && sen[i+1]==' ' && sen[i+2]==' ') {
						sen[i]='\t';
						sen[i+1]=0;
						sen[i+2]=0;
						ch_loc+=3;
						i+=2;
					}
					else if(sen[i]==' ' && sen[i+1]==' ' && sen[i+2]=='\t') {
						sen[i]='\t';
						sen[i+1]=0;
						sen[i+2]=0;
						ch_loc+=3;
						i+=2;
					}
					else if(sen[i]==' ' && sen[i+1]=='\t') {
						sen[i]='\t';
						sen[i+1]=0;
						ch_loc+=3;
						i+=1;
					}
					else ch_loc++;
					break;
				}
			case 3: {
					if(sen[i]==' ' && sen[i+1]==' ') {
						sen[i]='\t';
						sen[i+1]=0;
						ch_loc+=2;
						i+=1;
					}
					if(sen[i]==' ' && sen[i+1]=='\t') {
						sen[i]='\t';
						sen[i+1]=0;
						ch_loc+=2;
						i+=1;
					}
					else ch_loc++;
					break;
				}
			}
		}
		else if(sen[i]=='\t') {
			switch (ch_loc%4) { //탭의 위치에 따라 지금 검사하는 문자의 위치를 바꾼다.
			case 0 : {
					ch_loc+=1;
					break;
				}
			case 1 : {
					ch_loc+=4;
					break;
				}
			case 2: {
					ch_loc+=3;
					break;
				}
			case 3: {
					ch_loc+=2;
					break;
				}
			}
		}
		else if(sen[i]=='\n') ch_loc=1; //엔터를 치면 줄이 바뀌므로 ch_loc는 1로 초기화 된다.
		else ch_loc++; //검사가 끝나면 지금 검사하는 문자의 위치를 바꾼다.

	}
	/* 문자열 출력 */
	for(i=0;sen[i]!=EOF;i++) {
		if(sen[i]!=0) printf("%c",sen[i]); //널 문자는 출력하지 않는다.
	}
	

	return 0;
}