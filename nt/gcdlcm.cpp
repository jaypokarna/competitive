#include <iostream>
#include<stdlib.h>
using namespace std;

int gcd(int a,int b);
int lcm(int a,int b);
int main()
{
  int n=10,i;
  int arr[] = { 1,2,3,4,5,67,8,9,10,16};
  int max = arr[0];
  int min = arr[0];
  for(i=1;i<n;i++)
  {
    min = gcd(min ,arr[i]);
    max = lcm(max,arr[i]);
  }
  cout<<min<<" "<<max;
  return 0;
}

int gcd(int a , int b)
{
  while(b!=0)
  {
    int c= b;
    b = a%b;
    a=c;
  }
  return a;
}

int lcm(int a,int b)
{
  int min = gcd(a,b);
  return a*b/min;
}
