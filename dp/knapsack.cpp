#include<iostream>
#include<algorithm>
using namespace std;
int knapsack(int arr[][2] , int cap , int n);
int main()
{
  int i,n,cap;
  cin>>cap;
  cin>>n;
  int arr[n+1][2];
  for(i=1;i<=n;i++)
  {
      cin>>arr[i][0]; //space
      cin>>arr[i][1]; //value
  }
  i = knapsack(arr , cap ,n+1);
  cout<<i;
  return 0;
}

int knapsack(int arr[][2] , int cap , int n1)
{
  int i,j, price[cap+1][n1] , num=n1;
  for(i=0;i<num;i++)
  {
    price[0][i] = 0;
  }
  for(i=0;i<cap+1;i++)
  {
    price[i][0] = 0;
  }
  for(j=1;j<=cap;j++)
  {
    for(i=1;i<num;i++)
    {
    if(j>=arr[i][0])
    price[j][i] = max(price[j][i-1], arr[i][1] + price[j-arr[i][0]][i-1]);
    else
    price[j][i] = price[j][i-1];
    }
  }
  for(i=0;i<=cap;i++)
  {
    for(j=0;j<num;j++)
    {
      cout<<price[i][j]<<" ";
    }
    cout<<endl;
  }
  return price[cap][num-1];
}
