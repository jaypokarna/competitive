#include <iostream>
#include<string>
#include<math.h>
using namespace std;

void rkm(string p ,string k, int d , int pr);

int modularexp(int base,int power,int divi);


int main()
{
  string inp,patt;
  inp = "JAYJAYJAY";
  patt = "JAY";
  //cin>>inp;
  //cin>>patt;
  rkm(inp , patt,26,pow(10,9)+7);
  return 0;
}

// prime is for taking the modulo
// d is the radix of the system used gen mein 26
void rkm(string inp ,string patt, int d , int prime)
{
  int n = inp.length(), m,h,p,t,i,s;
  m = patt.length();
  h = modularexp(d,m-1,prime);
  p= t =  i = 0;
  for(i=0;i<m;i++)
  {
    p = (d*p + patt[i]) % prime;
    t = (d*t + inp[i]) % prime;
  }
  for(s=0;s<=n-m;s++)
  {
    if(p==t)
    {
      int flag=1;
      for(i=0;i<m;i++)
      {
        if(inp[i +s ]!=patt[i])
        {
          flag=0;
        }
      }
      if(flag)
      {
        cout<<"With shift"<<" "<<s<<endl;
      }
    }
    t = ( d*(t-inp[s]*h) + inp[s+m]+ prime) % prime;
  }
}

int modularexp(int base,int power,int divi)
{
  int n = log2(power);
  int arr[n+1],i;
  arr[0] = base%divi;
  for(i=1;i<=n;i++)
  {
    arr[i] = (arr[i-1]*arr[i-1])%divi;
  }
  int bin[n+1];
  int temp = power;
  for(i=n;i>=0;i--)
  {
    bin[i] = temp%2;
    temp /=2;
  }
  temp=1;
  for(i=0;i<=n;i++)
  {
    if(bin[n-i]==1)
    {
      temp = (temp*arr[i])%divi;
    }
  }
  return temp;
}
