#include<iostream>

using namespace std;

int main()
{
  int i,n,m,j,num;
  cin>>n;
  cin>>m;
  int arr[n][m];
  cin>>num;
  for(i=0;i<n;i++)
  {
    for(j=0;j<m;j++)
    {
      arr[i][j] =-1;
    }
  }
  for(i=0;i<num;i++)
  {
      int x,y;
      cin>>x>>y;
      arr[x][y]=0;
  }
  i=0;
  while(arr[i][0]!=0)
  {
    arr[i][0] =1;
    i++;
  }
  while(i<m)
  {
    arr[i][0] =0;
    i++;
  }

  i=0;
  while(arr[0][i]!=0)
  {
    arr[0][i] =1;
    i++;
  }
  while(i<m)
  {
    arr[0][i] =0;
    i++;
  }

  for(i=1;i<n;i++)
  {
    for(j=1;j<m;j++)
    {
      if(arr[i][j]!=0)
      {
        arr[i][j] = arr[i-1][j] + arr[i][j-1];
      }
    }
  }

  for(i=0;i<n;i++)
  {
    for(j=0;j<m;j++)
    {
      cout<<arr[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
