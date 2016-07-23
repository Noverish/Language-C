#include <stdio.h>

int main()
{

    int ch;
    int num_num[9];

    for (ch=0;ch<10;ch++)
        num_num[ch]=0;

    while(1)
    {
        ch=getchar();

		if(ch=='0')
			num_num[0]++;
		else if(ch=='1')
			num_num[1]++;
		else if(ch=='2')
			num_num[2]++;
		else if(ch=='3')
			num_num[3]++;
		else if(ch=='4')
			num_num[4]++;
		else if(ch=='5')
			num_num[5]++;
		else if(ch=='6')
			num_num[6]++;
		else if(ch=='7')
			num_num[7]++;
		else if(ch=='8')
			num_num[8]++;
		else if(ch=='9')
			num_num[9]++;


        if(ch==EOF)
        {
            break;

        }

    }
    for(ch=0;ch<10;ch++)
        printf("%d: %d\n",ch,num_num[ch]);
    return 0;
}
