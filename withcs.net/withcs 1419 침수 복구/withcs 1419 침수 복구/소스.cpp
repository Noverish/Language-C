#include <stdio.h>

int queue[10000][2];
int start=0,rear=0;
unsigned char land[150][150];
int max=0;

void queue_inject(int a, int b) {

	queue[rear][0]=a;
	queue[rear++][1]=b;
	land[a][b]='.';
}

int main()
{

	freopen("input.txt","r",stdin);

    int ch;
    int height, width, block_num;
    int i,j;
	int x, y;
    int pool_num=200; 
	/* pool_num�� 200���� ������ ������ �������� ���� W�� ���������� �������� ġȯ �Ұǵ�
	   ������ ǥ�õ� �������̸� ã���� 200���� ū���� ã���� ����*/

    scanf("%d %d %d",&height,&width,&block_num);

/*��� ���� .���� �ʱ�ȭ*/
    for(i=0;i<150;i++)
    {
        for(j=0;j<150;j++)
        {
            land[i][j]='.';
        }
    }

/*�� ������ �޴´�*/
	for(i=0;i<block_num;i++)
    {
		scanf("%d %d",&x,&y);
		land[x][y]='W';
        /*for(j=1;j<=width+1;j++)
        {
            ch=getchar();
            land[i][j]=ch;
        }*/
    }

/*W�� �������� �������� �ٲ۴�*/
    for(i=1;i<=height;i++)
    {
        for(j=1;j<=width;j++)
        {
            if(land[i][j]=='W')
            {
				queue_inject(i,j);
				land[i][j]=++pool_num;
				while(1) {
					/* ������ �������̸� ť�� ���� �ִ´�*/
				
					if(land[  queue[start][0]-1  ][  queue[start][1]    ]=='W')   queue_inject(  queue[start][0]-1, queue[start][1]    );
					
					if(land[  queue[start][0]    ][  queue[start][1]-1  ]=='W')   queue_inject(  queue[start][0],   queue[start][1]-1  );
					if(land[  queue[start][0]    ][  queue[start][1]+1  ]=='W')   queue_inject(  queue[start][0],   queue[start][1]+1  );
					
					if(land[  queue[start][0]+1  ][  queue[start][1]    ]=='W')   queue_inject(  queue[start][0]+1, queue[start][1]    );
					

					/* ������ �������� ������ �������̸� �����Ͽ� ���ڷ� �ٲ۴�*/
					
					if(land[  queue[start][0]-1  ][  queue[start][1]    ]>200)   land[  queue[start][0]  ][  queue[start][1]  ] = land[  queue[start][0]-1  ][  queue[start][1]    ];
					
					else if(land[  queue[start][0]    ][  queue[start][1]-1  ]>200)   land[  queue[start][0]  ][  queue[start][1]  ] = land[  queue[start][0]    ][  queue[start][1]-1  ];
					else if(land[  queue[start][0]    ][  queue[start][1]+1  ]>200)   land[  queue[start][0]  ][  queue[start][1]  ] = land[  queue[start][0]    ][  queue[start][1]+1  ];
					
					else if(land[  queue[start][0]+1  ][  queue[start][1]    ]>200)   land[  queue[start][0]  ][  queue[start][1]  ] = land[  queue[start][0]+1  ][  queue[start][1]    ];
					
					start++;

					if(start==rear) {
						if(max<start)
							max=start;
						start=0;
						rear=0;
						break;
					}
				}
			}
        }
    }

/*���������� �������� �ٲ� �� ������ ���*/
    /*for(i=1;i<=height+1;i++)
    {
        for(j=1;j<width;j++)
        {
            if(land[i][j]>200) printf("%d",land[i][j]);
            else printf("%3c",land[i][j]);

        }
		printf("\n");
    }*/

/*�������� �� ���*/
    printf("%d",max);

    return 0;
}
