#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;

void method(int n , int arr[])
{
	bool b[n];
	memset(b,bool(0),sizeof(b));
	int i,count=0;
	while(count<n)
	{
		for(i=0;i<n;i++)
		{
			if(b[i]==bool(0))
			{
				break;
			}
		}
		int j = arr[i],k=i;
		cout<<i+1<<" ";
		b[i] = bool(1);
		count++;
		while(j!=i+1)
		{
			cout<<j<<" ";
			b[j-1] = bool(1);
			j = arr[j-1];
			count++;
		}
		cout<<k+1<<"\n";
	}
}

int main()
{
	int i,n;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	method(n,arr);
	return 0;
}