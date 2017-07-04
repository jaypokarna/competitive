#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<math.h>
using namespace std;

int main()
{
  string s1,s2;
  cin>>s1>>s2;
  int dp[s1.size() +1][s2.size() +1];
  memset(dp,0,4*(s1.size()+1)*(s2.size()+1));
  int i,j;
    for(i=1;i<=s1.size();i++)
    {
      for(j=1;j<=s2.size();j++)
      {
        if(s1[i]==s2[j])
        {
          dp[i][j] = 1+ dp[i-1][j-1];
        }
        else
        {
          dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
      }
    }
    cout<<dp[s1.size()][s2.size()];
  return 0;
}
