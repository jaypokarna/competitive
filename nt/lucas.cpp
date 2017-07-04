#include <iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;

int lucas(int n,int r, int m);
int binomialCoeff(int n, int k);
int main()
{
  int n,r,m; //m  is prime
  cin>>n;
  cin>>r;
  cin>>m;
  n = lucas(n,r,m); // (n,r) mod(m) is the format
  cout<<n;
  return 0;
}

int lucas(int n,int r, int m)
{
  int sizen = log10(n)/log10(m);
  int sizer = log10(r)/log10(m);
  int size,i;
  sizen > sizen ? size = sizen+1 : size = sizer+1;
  int arrn[size];
  int arrr[size];
  for(i=size-1;i>=0;i--)
  {
    arrn[i] = n%m;
    arrr[i] = r%m;
    n/=m;
    r/=m;
  }
  int prod =1;
  for(i=0;i<size;i++)
  {
    prod *= ( binomialCoeff(arrn[i],arrr[i]) % m);
  }
  return prod;
}

int binomialCoeff(int n, int k)
{
  if(k>n)
  {
    return 0;
  }
    int C[n+1][k+1];
    int i, j;

    // Caculate value of Binomial Coefficient in bottom up manner
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= min(i, k); j++)
        {
            // Base Cases
            if (j == 0 || j == i)
                C[i][j] = 1;

            // Calculate value using previosly stored values
            else
                C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }

    return C[n][k];
}
