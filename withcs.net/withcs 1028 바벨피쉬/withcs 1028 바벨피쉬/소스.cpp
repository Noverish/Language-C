#include <stdio.h>
#include <string.h>

char dictionary_nation[100000][15];
char dictionary_abroad[100000][15]; //�ܾ �����ϴ� �迭
char unknown_word[15];
char answer[15];
/* �� ��Ʈ �Լ�*/
void quick_sort(int start, int end) {

	if(start>=end) return;

	int left=start;
	int right=end;
	int pivot=left;
	int check, out_on=0;
	char swap[25];

	while(1) {
		while(1) {
			if(left>right) {
				out_on=1;
				break;
			}
			check = strcmp(dictionary_abroad[pivot],dictionary_abroad[left]);
			if(check<0) break;
			left++;
		}
		while(1) {
			if(left>right) {
				out_on=1;
				break;
			}
			check = strcmp(dictionary_abroad[pivot],dictionary_abroad[right]);
			if(check>0) break;
			right--;
		}
		if(out_on==1) {
			strcpy(swap,dictionary_abroad[pivot]);
			strcpy(dictionary_abroad[pivot],dictionary_abroad[right]);
			strcpy(dictionary_abroad[right],swap);

			strcpy(swap,dictionary_nation[pivot]);
			strcpy(dictionary_nation[pivot],dictionary_nation[right]);
			strcpy(dictionary_nation[right],swap);

			quick_sort(start,right-1);
			quick_sort(right+1,end);

			break;
		}

		strcpy(swap,dictionary_abroad[left]);
		strcpy(dictionary_abroad[left],dictionary_abroad[right]);
		strcpy(dictionary_abroad[right],swap);

		strcpy(swap,dictionary_nation[left]);
		strcpy(dictionary_nation[left],dictionary_nation[right]);
		strcpy(dictionary_nation[right],swap);
	}
}

void binary_search(int word_number) {

	int check, left=0, right=word_number;
	int pivot=(left+word_number)/2;
	int eh_print=pivot;
	
	while(1) {
		
		check=strcmp(unknown_word,dictionary_abroad[pivot]);
		if(check>0) {
			left=pivot+1;
			pivot=(left+right)/2;
		}
		else if(check<0) {
			right=pivot-1;
			pivot=(left+right)/2;
		}
		else {
			printf("%s\n",dictionary_nation[pivot]);
			return;
		}
		if(left-right==1 || left-right==-1 || left-right==0) {
			check=strcmp(unknown_word,dictionary_abroad[left]);
			if(check==0) { 
				printf("%s\n",dictionary_nation[left]);
				return;
			}
			check=strcmp(unknown_word,dictionary_abroad[right]);
			if(check==0) { 
				printf("%s\n",dictionary_nation[right]);
				return;
			}
			printf("eh\n");
			return;
		}
	}
}

int main() {

	//freopen("input.txt","r",stdin);

	int ch;
	int for_out=0;
	int i,j;
	int word_number;
	char dictionary[30]={0};
	/* ���� ������ �޴´�*/
	for(i=0;1;i++) {
		for(j=0;1;j++) {
			ch=getchar();
			if(ch==' ') break;
			if(ch=='\n') {
				for_out=1;
				break;
			}
			dictionary_nation[i][j]=ch;
		}
		if(for_out==1) break;
		for(j=0;1;j++) {
			ch=getchar();
			if(ch=='\n') break;
			dictionary_abroad[i][j]=ch;
		}
	}

	word_number=i-1;

	quick_sort(0,word_number);

	char * eoff;
	/*�ܱ��� �ܾ �޴´�*/
	while(1) {
	eoff = gets(unknown_word);
		if(eoff==0) break;
		binary_search(word_number);
	}

	return 0;
}