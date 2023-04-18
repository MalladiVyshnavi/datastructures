#include <stdio.h>
void selectionsort(int *arr,int n)
{
    int i,p,max,maxind,temp;
    for(p=0;p<n-1;p++)
    {
        maxind=0;
        max=arr[0];
        for(i=0;i<n-p;i++)
        {
            if(arr[i]>max)
            {
                max=arr[i];
                maxind=i;
            }
        }
        temp=arr[maxind];
        arr[maxind]=arr[i-1];
        arr[i-1]=temp;
    }
}
int main() 
{
    int arr[100],n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    selectionsort(arr,n);
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
