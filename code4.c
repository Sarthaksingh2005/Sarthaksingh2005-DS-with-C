/*
#include<stdio.h>
int lard(int arr[],int n)
{
    int max=arr[0];
 for(int i=0;i<n;i++)
 {
    if(arr[i]>max)
    {
        max=arr[i];
    }
 }
 return max;


}
int main()
{
 int n;
 printf("enter the size of array");
 scanf("%d",&n);
 int arr[n];
 for(int i=0;i<n;i++)
 {
    scanf("%d",&arr[i]);
 }
 int res=lard(arr,n);
 printf("%d",res);
 return 0; 
}
 */
#include<stdio.h>
int seclar(int arr[],int n)
{
    if(n<2)
    {
        return -1;
    }
    int small=arr[0];
    int secsmall=__INT_MAX__;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<small)
        {
            secsmall=small;
            small=arr[i];
        }
        else if(arr[i]<secsmall&&arr[i]!=small)
        { 
            secsmall=arr[i];
        }
    }
return secsmall;
}
int main()
{
    int n;
    printf("enter the size:");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int res=seclar(arr,n);
    printf("seclar element is %d",res);
    return 0;
}