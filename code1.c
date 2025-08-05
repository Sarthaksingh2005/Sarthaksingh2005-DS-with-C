//count of digit
/*
#include<stdio.h>
int countd(int n)
{
    int c=0;
    while(n>0)
    {
        int d=n%10;
        c=c+1;
        n=n/10;
    }
    return c;
}
int main()
{
    int a;
    printf("enter the number");
    scanf("%d",&a);
    int res=countd(a);
    printf("count is %d",res);
    return 0;
}
    */
//reverse a number
/*
#include<stdio.h>
int revc(int n)
{  int rev=0;
  while(n>0)
  {
    int d=n%10;
    rev=rev*10+d;
    n=n/10;
  }
  return rev;
}
int main()
{
  int a;
  printf("enter the number: ");
  scanf("%d",&a);
  int res=revc(a);
  printf("%d",res);
  return 0;
}
*/
//co-prime no
/*
#include<stdio.h>
int gcds(int a,int b)
{   
    while(b!=0)
    {
        int temp=a;
        b=a%b;
        temp=b;
    }
    return a;
    
}
int main()
{
    int a,b;
    printf("enter a and b:");
    scanf("%d %d",&a,&b);
    int res=gcds(a,b);
    if(res==1)
    {
        printf("co prime");
    }
    else
    {
        printf("not co prime");
    }
    return 0;
}*/
//gcd(with recursion)
/*
#include<stdio.h>
int gcd(int a,int b)
{
    if(b==0)
    {
        return a;
    }
    return gcd(b,a%b);
}
int main()
{
    int a,b;
    printf("enter two numbers: ");
    scanf("%d %d",&a,&b);
    int res=gcd(a,b);
    printf("%d",res);
    return 0;
}
*/
//print divisors
/*
#include<stdio.h>
#include<math.h>
int div(int n)
{
  for(int i=1;i<=sqrt(n);i++)
  {
    if(n%i==0)
    {
        printf("%d",i);
    }
    printf(" ");
  }
  for(int i=(int)sqrt(n);i>=1;i--)
  {
    if(n%i==0 && n/i!=i)
    {
        printf("%d",n/i);
    }
    printf(" ");
  }
  return 0;
}
int main()
{
    int n;
    printf("enter the number:");
    scanf("%d",&n);
    div(n);
}
*/
//prime
/*
#include<stdio.h>
#include<math.h>
int prime(int n)
{
    int c=0;
  for(int i=1;i<=sqrt(n);i++)
  {
    if(n%i==0)
    {
        c++;
    }
   
  }
  for(int i=(int)sqrt(n);i>=1;i--)
  {
    if(n%i==0 && n/i!=i)
    {
        c++;
    }
   
  }
  return c;
}
int main()
{
    int n;
    printf("enter the number:");
    scanf("%d",&n);
    int res=prime(n);
    if(res==2)
    {
        printf("prime");
    }
    else
    {
        printf("not prime");
    }
    return 0;
}
/*
