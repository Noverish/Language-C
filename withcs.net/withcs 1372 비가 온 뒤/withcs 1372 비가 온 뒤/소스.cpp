#include <stdio.h>

int queue[10000][2];
int start=0,rear=0;
unsigned char land[150][150];

void queue_inject(int a, int b) {

	queue[rear][0]=a;
	queue[rear++][1]=b;
	land[a][b]='w';
}

int main()
{

    int ch;
    int height, width;
    int i,j;
    int pool_num=200; 
	/* pool_num을 200으로 지정한 이유는 물웅덩이 마다 W를 물웅덩이의 순서수로 치환 할건데
	   주위에 표시된 물웅덩이를 찾을때 200보다 큰수를 찾도록 설계*/

    scanf("%d %d",&height,&width);
	ch=getchar();

/*모든 땅을 .으로 초기화*/
    for(i=0;i<150;i++)
    {
        for(j=0;j<150;j++)
        {
            land[i][j]='.';
        }
    }

/*땅 정보를 받는다*/
    for(i=1;i<=height;i++)
    {
		scanf("%s",land[i]);
        /*for(j=1;j<=width+1;j++)
        {
            ch=getchar();
            land[i][j]=ch;
        }*/
    }

/*W를 물웅덩이 순서수로 바꾼다*/
    for(i=1;i<=height;i++)
    {
        for(j=1;j<=width;j++)
        {
            if(land[i][j]=='W')
            {
				queue_inject(i,j);
				land[i][j]=++pool_num;
				while(1) {
					/* 인접한 물웅덩이를 큐에 집어 넣는다*/
					if(land[  queue[start][0]-1  ][  queue[start][1]-1  ]=='W')   queue_inject(  queue[start][0]-1, queue[start][1]-1  );
					if(land[  queue[start][0]-1  ][  queue[start][1]    ]=='W')   queue_inject(  queue[start][0]-1, queue[start][1]    );
					if(land[  queue[start][0]-1  ][  queue[start][1]+1  ]=='W')   queue_inject(  queue[start][0]-1, queue[start][1]+1  );
					if(land[  queue[start][0]    ][  queue[start][1]-1  ]=='W')   queue_inject(  queue[start][0],   queue[start][1]-1  );
					if(land[  queue[start][0]    ][  queue[start][1]+1  ]=='W')   queue_inject(  queue[start][0],   queue[start][1]+1  );
					if(land[  queue[start][0]+1  ][  queue[start][1]-1  ]=='W')   queue_inject(  queue[start][0]+1, queue[start][1]-1  );
					if(land[  queue[start][0]+1  ][  queue[start][1]    ]=='W')   queue_inject(  queue[start][0]+1, queue[start][1]    );
					if(land[  queue[start][0]+1  ][  queue[start][1]+1  ]=='W')   queue_inject(  queue[start][0]+1, queue[start][1]+1  );

					/* 현재의 물웅덩이 주위의 물웅덩이를 조사하여 숫자로 바꾼다*/
					if(     land[  queue[start][0]-1  ][  queue[start][1]-1  ]>200)   land[  queue[start][0]  ][  queue[start][1]  ] = land[  queue[start][0]-1  ][  queue[start][1]-1  ];
					else if(land[  queue[start][0]-1  ][  queue[start][1]    ]>200)   land[  queue[start][0]  ][  queue[start][1]  ] = land[  queue[start][0]-1  ][  queue[start][1]    ];
					else if(land[  queue[start][0]-1  ][  queue[start][1]+1  ]>200)   land[  queue[start][0]  ][  queue[start][1]  ] = land[  queue[start][0]-1  ][  queue[start][1]+1  ];
					else if(land[  queue[start][0]    ][  queue[start][1]-1  ]>200)   land[  queue[start][0]  ][  queue[start][1]  ] = land[  queue[start][0]    ][  queue[start][1]-1  ];
					else if(land[  queue[start][0]    ][  queue[start][1]+1  ]>200)   land[  queue[start][0]  ][  queue[start][1]  ] = land[  queue[start][0]    ][  queue[start][1]+1  ];
					else if(land[  queue[start][0]+1  ][  queue[start][1]-1  ]>200)   land[  queue[start][0]  ][  queue[start][1]  ] = land[  queue[start][0]+1  ][  queue[start][1]-1  ];
					else if(land[  queue[start][0]+1  ][  queue[start][1]    ]>200)   land[  queue[start][0]  ][  queue[start][1]  ] = land[  queue[start][0]+1  ][  queue[start][1]    ];
					else if(land[  queue[start][0]+1  ][  queue[start][1]+1  ]>200)   land[  queue[start][0]  ][  queue[start][1]  ] = land[  queue[start][0]+1  ][  queue[start][1]+1  ];
					start++;

					if(start==rear) break;
				}
			}
        }
    }

/*물웅덩이의 순서수로 바뀐 땅 정보를 출력*/
   /* for(i=1;i<=height;i++)
    {
        for(j=1;j<=width+1;j++)
        {
            if(land[i][j]>200) printf("%d",land[i][j]);
            else printf("%3c",land[i][j]);

        }
    }*/

/*물웅덩이 수 출력*/
    printf("%d",pool_num-200);

    return 0;
}
