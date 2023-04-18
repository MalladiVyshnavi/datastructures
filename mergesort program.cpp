#include<stdio.h>
void merge(int *arr,int L, int H,int M)
{
	int i=L,j=M+1,k=0,res[H-L+1];
	while(i<=M && j<=H)
	{
		if(arr[i]>arr[j])
		{
			res[k++]=arr[j++];
		}
		else
		{
			res[k++]=arr[i++];
		}
	}
	while(i<=M)
	{
		res[k++]=arr[i++];
	}
	while(j<=H)
	{
		res[k++]=arr[j++];
	}
	k=0;
	for(i=L;i<=H;i++)
	{
		arr[i]=res[k];
		k++;
	}
}
void merge_sort(int *arr,int n)

{
    int i,L,H,M,p;
    for(p=2;p<=n;p=p*2)
    {
        for(i=0;i+p<=n;i=i+p)
        {
            L=i;
            H=p+i-1;
            M=(L+H)/2;
            merge(arr,L,H,M);
        }
    }
}
int main()
{
    int arr[100],i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    merge_sort(arr,n);
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
