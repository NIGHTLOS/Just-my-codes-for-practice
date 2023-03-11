#include<stdio.h>
#include<math.h>
void saddle_point(int a[100][100], int n, int m)
{
	int min = 0, max = 0;
	int c = 0;
	int count = 0;
	int i = 0;
	int t = 0;
	int j = 0;
	int b[4];
	int N = 0;
	for (i = 0; i < n; i++)
	{
		max = a[i][0];
		for (j = 1; j < m; j++)
		{
			if (max < a[i][j])
			{
				max = a[i][j];
			}
		}
		for (int k = 0; k < m; k++)
		{
			if (max == a[i][k])
			{
				b[t] = k;
				t++;
				N++;
			}
		}
		min = max;
		for (int x = 0; x < t; x++)
		{
			for (int K = 0; K < n; K++)
			{
				if (min > a[K][b[x]])
				{
					c++;
					break;
				}
			}
			if (c == 0)
			{
				printf("%d %d %d\n", i + 1, b[x] + 1, min);
			}
			else
			{
				count++;
			}
			c = 0;
		}
		t = 0;
	}
	if (count == N)
	{
		printf("No\n");
	}
}
int main()
{
	int n, m;
	int i = 0;
	int j = 0;
	int k = 0;
	int N = 0;
	int arr[100][100];
	while(scanf("%d%d", &n, &m)!= -1)
	{	
		N = n;
		for (j = 0; j < n; j++)
		{
			for (k = 0; k < m; k++)
			{
				scanf("%d", &arr[j][k]);
			}
		}
		saddle_point(arr, n, m);
	}
	return 0;
}

