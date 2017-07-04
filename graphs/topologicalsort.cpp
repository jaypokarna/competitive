#include<stdlib.h>
#include<iostream>
#include<queue>
#include<vector>
#include<string.h>
using namespace std;


void topologicalsort(int n, bool **arr, int fin[]);
int main()
{

  // fin will have the stored values
  return 0;
}

void topologicalsort(int n, bool **arr, int fin[])
{
  queue <int> q;
  bool visited[n+1];
  int i,j,indegree[n+1];
  memset(indegree,0,sizeof(indegree));
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=n;j++)
    {
      if(arr[i][j]==bool(1))
      {
        indegree[j]++;
      }
    }
  }
  for(i=1;i<=n;i++)
  {
    if(indegree[i]==0)
    {
      q.push(i);
      visited[i] = bool(1);
    }
  }
  int index=0;
  while(q.empty()==bool(0))
  {
    int vertex = q.front();
    q.pop();
    fin[index++] = vertex;
    for(i=1;i<=n;i++)
    {
      if(arr[vertex][i]==bool(1)&&visited[i]==bool(0))
      {
        indegree[i]--;
        if(indegree[i]==0)
        {
          q.push(i);
          visited[i]= bool(1);
        }
      }
    }
  }
}
