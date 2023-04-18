#include<stdio.h>
int linearsearch_rec(int *arr,int n,int i,int se)
{
    if(i==n)
    {
        return -1;
    }
        if(arr[i]==se)
        {
            return i;
        }
        linearsearch_rec(arr,n,i+1,se);
}
int main()
{
    int arr[100],i,n,se,result;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    scanf("%d",&se);
    result=linearsearch_rec(arr,n,0,se);
    printf("%d",result);
}
