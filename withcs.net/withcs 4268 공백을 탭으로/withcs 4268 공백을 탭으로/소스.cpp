#include <stdio.h>

int main() {
	int ch_loc=1; //���� �˻��ϴ� ������ ��ġ �� �ٿ� 1���� ����
	int ch;
	int sen[100000];
	int i;
	int change=0;
	/* �ϴ� ��� ���ڿ��� �޴´�*/
	for(i=0;1;i++) {
		ch=getchar();
		sen[i]=ch;
		if(ch==EOF) break;
	}

	for(i=0;sen[i]!=EOF;i++) {
		if(sen[i]==' ') {
			switch (ch_loc%4) { //������ ��ġ�� ���� ġȯ�� �ٸ��� �Ѵ�.
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
						sen[i+1]=0;//���⸦ ������ �ٲٸ� ���� ���Ⱑ �ִ� �ڸ��� �� ���ڷ� �ٲ۴�. ���ڿ� ����Ҷ��� ����
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
			switch (ch_loc%4) { //���� ��ġ�� ���� ���� �˻��ϴ� ������ ��ġ�� �ٲ۴�.
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
		else if(sen[i]=='\n') ch_loc=1; //���͸� ġ�� ���� �ٲ�Ƿ� ch_loc�� 1�� �ʱ�ȭ �ȴ�.
		else ch_loc++; //�˻簡 ������ ���� �˻��ϴ� ������ ��ġ�� �ٲ۴�.

	}
	/* ���ڿ� ��� */
	for(i=0;sen[i]!=EOF;i++) {
		if(sen[i]!=0) printf("%c",sen[i]); //�� ���ڴ� ������� �ʴ´�.
	}
	

	return 0;
}