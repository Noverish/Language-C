#include <stdio.h>
#include <string.h>
     
#define WORD_LENGHT 10
     
struct vocabulary {
    char word[WORD_LENGHT];
    int writed_number;
};
     
struct vocabulary save[10000]={0};
     
int quick_sort(int left, int right) {
     
    char word[WORD_LENGHT]={0};
    int tmp;
    int low = left+1;
    int high = right;
    int pivot = left;
     
    if(right <= left)
    	return 0;
     
    while(low < high) {
    	while (strcmp(save[pivot].word,save[low].word)>=0 && low<=right)
    		low++;
     
    	while (strcmp(save[pivot].word,save[high].word)<=0 && high>=left+1)
    		high--;
     
    	if(low <= high) {
    		strcpy(word,save[low].word);
    		strcpy(save[low].word,save[high].word);
    		strcpy(save[high].word,word);
     
    		tmp = save[low].writed_number;
    		save[low].writed_number = save[high].writed_number;
    		save[high].writed_number = tmp;
    	}
    }
    if(strcmp(save[pivot].word,save[high].word)>0) {
    	strcpy(word,save[pivot].word);
    	strcpy(save[pivot].word,save[high].word);
    	strcpy(save[high].word,word);
     
    	tmp = save[pivot].writed_number;
    	save[pivot].writed_number = save[high].writed_number;
    	save[high].writed_number = tmp;
    }
    quick_sort(left,high-1);
    quick_sort(high+1,right);
     
    return 0;
     
}
     
int main() {
     
    //freopen("input.txt","r",stdin);
     
    char input[1000];
    int ch, asdf[1000];
    int i=0,j,eof=0,save_index=0;
     
    while(eof!=EOF) {
     
    	for(j=0;j<1000;j++)
    			input[j]=0;
     
    	if(scanf("%s",input)==EOF) break;

		/*
		for(i=0;1;i++) {
  			ch=getchar();
  			input[i]=ch;
  			if(ch==' ' || ch=='\n' || ch==EOF) {
  				input[i]=NULL;
  				if(ch==EOF)
  					eof=EOF;
  				break;
			}
		}
		*/
     
    	if(input[0]==NULL) // check that there are no word in array 'input'
    		continue;
     
    	if(strcmp(input,"//")==0) {
    		while((ch=getchar())!='\n' && ch!=EOF);
    		if(ch==EOF)
    			break;
    		else
    			continue;
    	}
    	else if(strcmp(input,"/*")==0) {
    		for(i=0;1;i++) {
    			ch=getchar();
    			input[i]=ch;
     
    			if(ch==EOF) {
    				eof=EOF;
    				break;
    			}
    			if(input[i-1] == '*' && input[i] == '/') {
    				break;
    			}
    		}
    		if(eof==EOF)
    			break;
    		else
    			continue;
    	}
     
    	for(j=0;j<save_index;j++)
    		if(strncmp(input,save[j].word,6)==0) {
    			save[j].writed_number++;
    			break;
    		}
    	if(j==save_index) {
    		strncpy(save[save_index++].word,input,6);
    		save[j].writed_number++;
    	}
    }
     
    quick_sort(0,save_index-1);
     
    for(i=0;i<save_index;i++)
    	printf("%s %d\n", save[i].word, save[i].writed_number);
     
    return 0;
}