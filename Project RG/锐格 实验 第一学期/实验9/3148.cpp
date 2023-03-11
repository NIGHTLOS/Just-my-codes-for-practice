#include<stdio.h>
int Found(int *arr,int n,int key)                          
{
	int low=0;               
	int high=n-1;                
	int mid;                            
	while(low<=high)
	{
		mid=low+(high-low)/2;           
		if(key==arr[mid])             
			return mid+1;    
		else if(key<arr[mid])             
			low=mid+1;
		else                                 
			high=mid-1;
	}
	return -1;                            
}
int main()
{
	int arr[50]; 
	int n,k;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}   
	scanf("%d",&k);                  
	printf("%d\n",Found(arr,n,k));
	return 0;
}


