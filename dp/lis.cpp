#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<math.h>
using namespace std;

int main()
{
  int i,n,j;
  cin>>n;
  int arr[n];
  for(i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  int lis[n];
  memset(lis,1,4*n);
  int temp=0;
  for(i=1;i<n;i++)
  {
    for(j=0;j<i;j++)
    {
      if(arr[i]>arr[j]&&lis[i] < lis[j]+1)
      {
        lis[i] = lis[j] + 1;
        temp = max(temp,lis[i]);
      }
    }
  }
  cout<<temp;
  return 0;
}
