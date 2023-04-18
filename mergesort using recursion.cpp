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
void merge_sort(int *arr,int L,int H)
{
    if(L<H)
    {
        int M;
        M=(L+H)/2;
        merge_sort(arr,L,M);
        merge_sort(arr,M+1,H);
        merge(arr,L,H,M);
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
    merge_sort(arr,0,n-1);
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
