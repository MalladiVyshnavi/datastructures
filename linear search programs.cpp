#include<stdio.h>
int linearsearch(int *arr,int n,int se)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(arr[i]==se)
        {
            return i;
        }
    }
    return -1;
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
    result=linearsearch(arr,n,se);
    printf("%d",result);
}
