#include<stdio.h>
int binary_search_rec(int *arr,int L,int H,int se)
{
    if(L>H)
    {
        return -1;
    }
    int M;
    M=(L+H)/2;
    if(arr[M]==se)
    {
        return M;
    }
    else if(arr[M]>se)
    {
        H=M-1;
    }
    else
    {
        L=M+1;
    }
    return binary_search_rec(arr,L,H,se);
}
int main()
{
    int n,arr[100],i,se,result;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    scanf("%d",&se);
    result=binary_search_rec(arr,0,n-1,se);
    printf("%d",result);
}

