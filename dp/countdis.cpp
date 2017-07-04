/*
Here 1 ,2 is
different from 2,1.
*/

#include<iostream>
#include<string.h>
#include<math.h>
#include<stdlib.h>
using namespace std;

int main()
{
  int n,i;
  cin>>n;
  int arr[n+1];
  memset(arr,-1,4*(n+1));
  arr[0]=1;
  arr[1]=1;
  arr[2]=2;
  for(i=3;i<=n;i++)
  {
    arr[i] = arr[i-1]+arr[i-2]+arr[i-3];
  }
  cout<<arr[n];
  return 0;
}
