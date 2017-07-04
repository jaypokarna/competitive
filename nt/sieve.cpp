#include <iostream>
#include<math.h>
using namespace std;

void sieve(int n);

int main()
{
  int n=100;
  sieve(n);
  return 0;
}

void sieve(int n)
{
  int arr[n+1],i;
  for(i=0;i<=n;i++)
  {
    arr[i]=0;
  }
  for(i=2;i<n;i++)
  {
    if(arr[i]==0)
    {
      int j;
      for(j=2;j*i<=n;j++)
      {
        arr[j*i] = 1;
      }
    }
  }
  for(i=2;i<=n;i++)
  {
    if(arr[i]==0)
    {
      cout<<i<<" ";
    }
  }
}
