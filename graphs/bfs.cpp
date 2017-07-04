#include <iostream>
#include<stdlib.h>
#include<string.h>
#include<vector>
using namespace std;

int main()
{
  int t,i;
  cin>>t;
  int levelarr[t+1];
  memset(levelarr,-1,sizeof(levelarr));
  levelarr[0] = -1;
  levelarr[1]=1;
  vector <int> lev[t];
  lev[0].push_back(1);
  int arr[t-1][2];
  for(i=0;i<t-1;i++)
  {
    cin>>arr[i][0];
    cin>>arr[i][1];
  }
  for(i=0;i<t;i++)
  {
    int j;
    for(j=0;j<lev[i].size();j++)
    {
      int temp = lev[i][j];
      int k;
      for(k=0;k<t-1;k++)
      {
        if(arr[k][0]==temp&&levelarr[arr[k][1]]==-1)
        {
          levelarr[arr[k][1]] = levelarr[arr[k][0]]+1;
          lev[i+1].push_back(arr[k][1]);
        }
        else if(arr[k][1]==temp&&levelarr[arr[k][0]]==-1)
        {
          levelarr[arr[k][0]] = levelarr[arr[k][1]]+1;
          lev[i+1].push_back(arr[k][0]);
        }
      }
    }
  }
  int s,count=0;
  cin>>s;
  for(i=0;i<=t;i++)
  {
    if(levelarr[i]==s)
    {
      count++;
    }
  }
  cout<<count;
  return 0;
}
