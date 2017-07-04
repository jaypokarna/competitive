#include <iostream>
#include<stdlib.h>
using namespace std;

int chineserem(int a[], int r[] ,int n);

int main()
{
  int n=2;
  int a[] = {29,31};
  int r[] = {0,-1};
  n = chineserem(a,r,n);
  cout<<n;
  return 0;
}

int chineserem(int a[], int r[] ,int n)
{
  int m[n],c[n],i,j;
  int max=1;
  for(i=0;i<n;i++)
  {
    max *= a[i];
  }
  for(i=0;i<n;i++)
  {
    m[i] = max/a[i];
  }
  for(i=0;i<n;i++)
  {
    for(j=0;j<m[i];j++)
    {
        if(m[i]*j%a[i] ==1)
        {
          c[i] = m[i]*j;
          break;
        }
    }
  }
  int temp = 0;
  for(i=0;i<n;i++)
  {
    temp += r[i]*c[i];
  }
  return ( temp + max)%max;
}
