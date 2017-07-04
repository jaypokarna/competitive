#include <iostream>
#include<math.h>

using namespace std;

int rabin(long long unsigned int n);
int modularexp(int base,int power,int divi);
int main()
{
  long long unsigned int n = 47;
  int t;
   t = rabin(n);
   cout<<t;
  return 0;
}

int rabin(long long unsigned int n)
{
  if(n==1)
  {
    return 0;
  }
  if(i&1==0)
  {
    return n==2;
  }
  long long unsigned int temp = n-1 ;
    // n=2^rs+1
  int r=0;
  while(temp%2 ==0)
  {
    temp /=2;
    r++;
  }
  long long int t;
  //a^s=1 (mod n)
  t = modularexp(2,temp,n);
  if(t==1)
  {
    return 1;
  }
  int i;
  for(i=0;i<r;i++)
  {
    t = modularexp(2,temp*pow(2,i),n);
    if((t + n)%n == n-1)
    {
      return 1;
    }
  }
  // a^(2^js)=-1 (mod n) for some 0<=j<=r-1
  return 0;
}

int modularexp(int base,int power,int divi)
{
  int res = 1;
  while(power>0)
  {
    if(power&1)
    {
      res = (res*base)%divi;
    }
    power = power>>1;
    base = base*base;
  }
  return res;
}
