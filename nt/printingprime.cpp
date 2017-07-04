#include<iostream>
#include<math.h>

using namespace std;

int main()
{
  int i,num;
  cin>>num;
  while(num%2==0)
  {
    cout<<"2 ";
    num /=2;
  }
  for(i=3;i<sqrt(num);i+=2)
  {
    while(num%i==0)
    {
      cout<<i<<" ";
      num /=i;
    }
  }
  if(num!=1)
  {
    cout<<num;
  }
  return 0;
}
