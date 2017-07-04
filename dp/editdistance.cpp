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
  int i,j;
  for(i=0;i<=s1.size();i++)
  {
    dp[i][0] =i;
  }
  for(i=0;i<=s2.size();i++)
  {
    dp[0][i] =i;
  }
    for(i=1;i<=s1.size();i++)
    {
      for(j=1;j<=s2.size();j++)
      {
        if(s1[i]==s2[j])
        {
          dp[i][j] = dp[i-1][j-1];
        }
        else
        {
          int t = min(dp[i-1][j],dp[i][j-1]);
          dp[i][j] = 1 + min(t,dp[i-1][j-1]);
        }
      }
    }
    cout<<dp[s1.size()][s2.size()];
  return 0;
}
