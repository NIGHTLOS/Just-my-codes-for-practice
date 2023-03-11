#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdbool.h>
#include<stdlib.h>
#define SPACE 0 //空地
#define WALL 1  //墙
#define DEST 2   //目的地
#define BOX 3    //箱子
#define PLAYER 4  //玩家
#define ROWS 10  //地图行
#define COLS 10  //地图列
//72   上  w
//80   下  s
//75   左  a
//80   右  d
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
			//图形输出
			switch (map[i][k])
			{
			      case SPACE:
					  printf("  ");
					  break;
			      case WALL:
					  printf("墙");
				      break;
			      case DEST:
					  printf("地");
				      break;
				  case BOX:
					  printf("口");
					  break;
				  case PLAYER:
					  printf("您");
					  break;
				  case (PLAYER + DEST):
					  printf("额");
					  break;
				  case (BOX + DEST):
					  printf("对");
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
	//按键操作
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
	//创建地图 加载地图
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
	printf("==================推箱子=================\n");
	printf("玩法：使用w,s,d,f控制,按enter键开始...\n");
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
    printf("已退出,不是说好空格键吗...\n");
	return 0;
}
