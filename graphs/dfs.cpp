#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

int main()
{
  int i,n,m;
  cin>>n>>m;
   int a,b;
   bool arr[n+1][n+1];
   bool visited[n+1];
   memset(visited,bool(0),sizeof(arr));
  memset(arr,bool(0),sizeof(arr));
  for(i=0;i<m;i++)
  {
    cin>>a>>b;
    arr[a][b] = arr[b][a] = bool(1);
  }
  stack<int> s;
  int inp;
  cin>>inp;
  s.push(inp);
  visited[inp] = bool(1);
  int count=0;
  while(s.empty()==false)
  {
    int temp = s.top();
    s.pop();
    for(i=0;i<=n;i++)
    {
      if(arr[temp][i]==bool(1)&&visited[i]==bool(0))
      {
        s.push(i);
        visited[i] = bool(1);
      }
    }
  }
  for(i=0;i<=n;i++)
  {
    if(visited[i]==bool(0))
    {
      count++;
    }
  }
  cout<<count-1;//for the oth index number
  return 0;
}
