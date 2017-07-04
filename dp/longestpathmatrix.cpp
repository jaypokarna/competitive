#include<iostream>
#include<string.h>
#include<math.h>
#include<stdlib.h>

using namespace std;
int fun(int i ,int j);
int n,**arr,**fin;
int main()
{
  int i,j;
  cin>>n;
  arr = (int **)malloc(sizeof(int*)*n);
  fin = (int**)malloc(sizeof(int*)*n);
  for(i=0;i<n;i++)
  {
    arr[i] = (int*)malloc(sizeof(int)*n);
    fin[i] = (int*)malloc(sizeof(int)*n);
  }
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
        cin>>arr[i][j];
    }
  }
  /*memset(fin,-1,sizeof(fin));
  Why isn't memset working??
  */
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
        fin[i][j] = -1;
    }
  }
  int temp=0;
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      temp = max(temp , fun(i,j));
    }
  }
  cout<<temp;
  return 0;
}

int fun(int i ,int j)
{
  if(fin[i][j]!=-1)
  {
    return fin[i][j];
  }
  if((j+1<n)&&arr[i][j]+1 == arr[i][j+1])
  {
    fin[i][j] = 1 + fun(i,j+1);
    return fin[i][j];
  }
  else if((i+1<n)&&arr[i][j]+1 == arr[i+1][j])
  {
    fin[i][j] =  1+ fun(i+1,j);
    return fin[i][j];
  }
  else if(i>=1&&arr[i][j]+1 == arr[i-1][j])
  {
    return fin[i][j] = 1 + fun(i-1,j);
  }
  else if(j>=1&&arr[i][j]+1==arr[i][j-1])
  {
    return fin[i][j] = 1+fun(i,j-1);
  }
  return 1;
}
