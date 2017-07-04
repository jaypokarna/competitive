#include<stdlib.h>
#include<iostream>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  long long int n,i,j,k;
  cin>>n;
  long long int arr[n][n];
  //Do the initialisation steps here

  //warshall starts
  for(k=0;k<n;k++)
  {
    for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
      {
        if(arr[i][k]+arr[k][j] < arr[i][j])
        {
          arr[i][j]=arr[i][k]+arr[k][j];
        }
      }
    }
  }
  return 0;
}
