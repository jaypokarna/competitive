#include <iostream>
#include<math.h>

using namespace std;
long long int modularexp(long long int base,long long int power,long long int divi);
long long int main()
{
  long long int base=3,power=200,divi=50;
  base = modularexp(base,power,divi);
  cout<<base;
  return 0;
}

long long int modularexp(long long int base,long long int power,long long int divi)
{
  long long int res = 1;
  while(power>0)
  {
    if(power&1)
    {
      res = (res*base)%divi;
    }
    power = power>>1;
    base = base*base;
  }
  return res;
}
