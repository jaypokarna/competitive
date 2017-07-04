#include <stdlib.h>
#include <iostream>
#include <math.h>
using namespace std;

/*


S(n,k) = S(n-1,k-1) + k*S(n-1,k)

*/
long long int fact(long long int p)
{
	long long int temp=1,i;
	for(i=2;i<=p;i++)
	{
		temp *= i;
	}
	return temp;
}

long long int comb(long long int n, long long int m)
{
	return fact(n)/ (fact(n-m)*fact(m));
}

long long int stirling(long long int n, long long int m)
{
	if(m==1||m==n)
	{
		return 1;
	}
	if(m==2)
	{
		return ( (1<<(n-1)) -1);
	}
	if(m==3)
	{
		return (pow(3,n) - 3*(1<<n) + 3)/6 ;
	}
	if(m==n-1)
	{
		return n*(n-1)/2;
	}
	long long int sum=0,i;
	for(i=0;i<=m;i++)
	{
		if((i&1)==1)
		{
			sum -= comb(m,i)*pow(m-i,n);
		}
		else
		{
			sum += comb(m,i)*pow(m-i,n);
		}
	}
	return sum;
}

int main()
{	

	return 0;
}