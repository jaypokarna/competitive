#include <iostream>
#include <math.h>
#include<string.h>
#include<algorithm>
#define endl \n
using namespace std;

void create(int arr[] ,int ret[], int start, int end);
int search(int k,int arr[],int size);
int main()
{
  ios::sync_with_stdio(false);
  int n,i,s;
  cin>>n;
  int arr[n];
  for(i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  cin>>s;
  int x[(int)pow(2,(int)n/2+1)] , y[(int)pow(2,(int)n-n/2-1)];
  memset(x,0,sizeof(x));
  memset(y,0,sizeof(y));
  create(arr,x,0,n/2);
  create(arr,y,n/2 +1,n-1);
  sort(y , y + sizeof(y)/4);
  /*
  Implement the
  binary search for the index here
  */
  int m = 0;
  for(i=0;i<sizeof(x)/4;i++)
  {
    int p = search(s-x[i],y,sizeof(y)/4);
    int t;
    (p<0) ? t = x[i] : t = p+x[i];
    if(t<=s)
    {
        m = max(m,t);
    }
  }
  cout<<m;
  return 0;
}

int search(int k,int arr[],int size)
{
  //size is the index
  if(k<0)
  {
    return -1;
  }
   int start=0,end=size,mid;
   while(end>=start)
   {
     mid  = (start+end)/2;
     if(arr[mid]==k)
     {
       return k;
     }
     else if(arr[mid]<k)
     {
       start=mid+1;
     }
     else
     {
       end = mid-1;
     }
   }
   return arr[mid-1];
}
void create(int arr[] ,int ret[], int start, int end)
{
  int size = end - start + 1,i;
  int temp = 0,k;
  int power = 1<<size;
  for(i=0;i<power;i++)
  {
    int j;
    for(j=start,k=0;j<=end;j++,k++)
    {
      if((temp & 1<<k)!=0)
      {
        ret[i] += arr[j] ;
      }
    }
    temp++;
  }
}
