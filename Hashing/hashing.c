#include<stdio.h>
#include<stdlib.h>

void insert(int arr[11][2],int n)
{
	int s=n%11;
	int count=0,j=s;
	while(1)
	{
		count++;
		if(arr[j][0]==0)
		{
		arr[j][0]=n;
		break;
		}
		else if(arr[j][1]==0)
		{
			arr[j][1]=n;
			break;
		}
		else if(count==11)
		{
			printf("Hashtable is full!!\n");
			break;
		}
		if(j==10)
			j=0;
		else
			j++;
		
	}
}
void display(int arr[11][2])
{
	for(int i=0;i<11;i++)
	{
		printf("%d ||  %d\n",arr[i][0],arr[i][1] );
	}
}
int main()
{
	int n;
	int arr[11][2];
	for(int i=0;i<11;i++)
	{
		for(int j=0;j<2;j++)
		{
			arr[i][j]=0;
		}
	}
	printf("Enter the no.of elements you want to insert: \n");
	scanf("%d",&n);
	int p[n];
	printf("Enter the elements :-\n");
	for(int i=0;i<n;i++)
	{
		scanf(p[n]);
		insert(arr,p[n]);
	}
	printf("\n");
	display(arr);
	
}


