/*
Here the sum function will
return the sum of the
range 0 to index
*/

#include<iostream>
#include<stdlib.h>
#include<string.h>

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
  memset(bit,0,sizeof(bit));
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
    bit[index] += val;
    index += (index&(-1*index));
  }
}

int sum(int bit[] , int index)
{
  int sum=0;
  index++;
  while(index>0)
  {
    sum+=bit[index];
    index -= (index&(-1*index));
  }
  return sum;
}
