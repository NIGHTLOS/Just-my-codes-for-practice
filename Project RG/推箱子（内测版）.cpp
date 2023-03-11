#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdbool.h>
#include<stdlib.h>
#define SPACE 0 //�յ�
#define WALL 1  //ǽ
#define DEST 2   //Ŀ�ĵ�
#define BOX 3    //����
#define PLAYER 4  //���
#define ROWS 10  //��ͼ��
#define COLS 10  //��ͼ��
//72   ��  w
//80   ��  s
//75   ��  a
//80   ��  d
int map[ROWS][COLS];
void show()
{
	system("cls");
	int i,k; 
	for (i = 0; i < ROWS; i++)
	{
		for (k = 0; k < COLS; k++)
		{
			//printf("%d ", map[i][k]);
			//ͼ�����
			switch (map[i][k])
			{
			      case SPACE:
					  printf("  ");
					  break;
			      case WALL:
					  printf("ǽ");
				      break;
			      case DEST:
					  printf("��");
				      break;
				  case BOX:
					  printf("��");
					  break;
				  case PLAYER:
					  printf("��");
					  break;
				  case (PLAYER + DEST):
					  printf("��");
					  break;
				  case (BOX + DEST):
					  printf("��");
					  break;
			}
		}
		printf("\n");
	}
}

void move()
{
	int r=-1,c=-1;
	int i,j;
	for(i=0;i<ROWS;i++)
	{
		for(j=0;j<COLS;j++)
		{
			if(map[i][j]==PLAYER||map[i][j]==PLAYER+DEST)
			{
			r=i;
			c=j;
			goto end;
		    }
		}
	}
end:;
	//��������
	int key= _getch();
	//printf("%d %c\n",key,key); 
	switch(key)
	{
		case 'w':
		if(map[r-1][c]==SPACE||map[r-1][c]==DEST)
		{
			map[r-1][c]+=PLAYER;
			map[r][c]-=PLAYER;
		}
		else if(map[r-1][c] == BOX)
		{
			if(map[r-2][c]==SPACE||map[r-2][c]==DEST)
			{
			map[r-2][c]+=BOX;
			map[r-1][c]-=BOX;
			map[r-1][c]+=PLAYER;
			map[r][c]-=PLAYER;
		    }
		}
		break;
		case 's':
		if(map[r+1][c]==SPACE||map[r+1][c]==DEST)
		{
			map[r+1][c]+=PLAYER;
			map[r][c]-=PLAYER;
		}
		else if(map[r+1][c] == BOX)
		{
			if(map[r+2][c]==SPACE||map[r+2][c]==DEST)
			{
			map[r+2][c]+=BOX;
			map[r+1][c]-=BOX;
			map[r+1][c]+=PLAYER;
			map[r][c]-=PLAYER;
		    }
		}
		break;
		case 'a':
		if(map[r][c-1]==SPACE||map[r][c-1]==DEST)
		{
			map[r][c-1]+=PLAYER;
			map[r][c]-=PLAYER;
		}
		else if(map[r][c-1] == BOX)
		{
			if(map[r][c-2]==SPACE||map[r][c-2]==DEST)
			{
			map[r][c-2]+=BOX;
			map[r][c-1]-=BOX;
			map[r][c-1]+=PLAYER;
			map[r][c]-=PLAYER;
		    }
		}
		break;
		case 'd':
		if(map[r][c+1]==SPACE||map[r][c+1]==DEST)
		{
			map[r][c+1]+=PLAYER;
			map[r][c]-=PLAYER;
		}
		else if(map[r][c+1] == BOX)
		{
			if(map[r][c+2]==SPACE||map[r][c+2]==DEST)
			{
			map[r][c+2]+=BOX;
			map[r][c+1]-=BOX;
			map[r][c+1]+=PLAYER;
			map[r][c]-=PLAYER;
		    }
		}
		break;
	}
}

void initmap()
{
	//������ͼ ���ص�ͼ
	int tmap[ROWS][COLS] =
	{
	{1,1,1,1,1,1,1,1,1,1},
	{1,4,2,0,0,0,0,0,0,1},
	{1,0,0,0,0,3,3,0,0,1},
	{1,0,0,3,0,0,0,0,0,1},
	{1,0,3,0,0,0,0,0,0,1},
	{1,0,0,3,0,0,0,0,2,1},
	{1,0,3,0,0,2,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,2,2,0,0,0,2,0,0,1},
	{1,1,1,1,1,1,1,1,1,1}
	};
	memcpy(map, tmap, sizeof(tmap));
}
int main()
{
	printf("==================������=================\n");
	printf("�淨��ʹ��w,s,d,f����,��enter����ʼ...\n");
	char ch; 
	scanf("%c",&ch);
	if(ch=='\n')
	{
	initmap();
	while(true)
	{
		show();
		move();
	}
    }
    else
    printf("���˳�,����˵�ÿո����...\n");
	return 0;
}
