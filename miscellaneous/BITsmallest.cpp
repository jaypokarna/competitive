/*
Here the sum function will
return the minimum value in the
range 0 to index
*/


#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define forbidden -1
using namespace std;

void update(int bit[] , int val, int index);

int sum(int bit[] , int index);
int n;
int main()
{
  int i;
  cin>>n;
  int arr[n];
  for(i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  int bit[n+1];
  memset(bit,forbidden,sizeof(bit));
  for(i=0;i<n;i++)
  {
    update(bit,arr[i],i);
  }
  for(i=0;i<n;i++)
  {
    cout<<sum(bit,i)<<endl;
  }
  return 0;
}


void update(int bit[] , int val, int index)
{
  index++;
  while(index<=n)
  {
    bit[index]==forbidden ? bit[index] =val
    : bit[index] = min(bit[index] , val);
    index += (index&(-1*index));
  }
}

int sum(int bit[] , int index)
{
  int su= forbidden;
  index++;
  while(index>0)
  {
    su==forbidden ? su = bit[index] :
    su = min(bit[index] , su);
    index -= (index&(-1*index));
  }
  return su;
}
