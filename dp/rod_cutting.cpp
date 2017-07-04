#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
  int i ,n,j;
  cout<<"Enter the number";
  cin>>n;
  int max1 , arr[n+1] , price[n+1];
  arr[0] = 0;
  for(i=1;i<=n;i++)
  {
    cin>>arr[i];
  }
  price[0] = 0;
  for(i=0;i<=n;i++)
  {
    max1 = arr[i];
    for(j=1;j<i;j++)
    {
      max1= max(price[j] + price[i-j],max1);
    }
    price[i] = max1;
  }
  for(i=1;i<=n;i++)
  {
  cout<<price[i]<<endl;
  }
  return 0;
}
