#include<stdlib.h>
#include<iostream>
#include<stack>
#include<string.h>
using namespace std;

void dfs(int inp , bool visited[], int n, bool **arr, bool flag[]);
int main()
{
  int i,j,a,b,n,m,inp;
  cin>>n>>m;
  bool visited[n+1];
  bool **arr;
  arr = (bool**)malloc(sizeof(bool*)*(n+1));
  for(i=0;i<=n;i++)
  {
    arr[i] = (bool*)malloc(sizeof(bool)*(n+1));
    memset(arr[i],bool(0),sizeof(arr[i]));
  }
  memset(visited,bool(0),sizeof(visited));
  for(i=0;i<m;i++)
  {
    // assuming a b means a to b
    cin>>a>>b;
    arr[a][b] = bool(1);
  }
  cin>>inp;
  bool flag[n+1];
  memset(flag,bool(1),sizeof(flag));
  dfs(inp,visited,n,arr,flag);
  for(i=0;i<=n;i++)
  {
    for(j=i+1;j<=n;j++)
    {
      arr[i][j] = arr[j][i];
    }
  }
  memcpy(flag,visited,sizeof(flag));
  memset(visited,bool(0),sizeof(visited));
  dfs(inp,visited,n,arr,flag);
  for(i=1;i<=n;i++)
  {
    cout<<visited[i]<<"\n";
  }
  return 0;
}

void dfs(int inp , bool visited[], int n, bool **arr, bool flag[])
{
  stack<int> s;
  s.push(inp);
  visited[inp] = bool(1);
  int i;
  while(s.empty()==false)
  {
    int temp = s.top();
    s.pop();
    for(i=0;i<=n;i++)
    {
      if(arr[temp][i]==bool(1)&&visited[i]==bool(0)&&flag[i]==bool(1))
      {
        s.push(i);
        visited[i] = bool(1);
      }
    }
  }
}
