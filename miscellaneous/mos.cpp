#include<iostream>
//#include<algorithm>
#include<math.h>
using namespace std;

int find(int arr[] , int size ,int ele);
int main()
{
  int i,n=19;
  //cin>>n;
  int arr[n];
  for(i=0;i<n;i++)
  {
    arr[i]=2*(i+1);
    //cin>>arr[i];
  }
  //sort(arr,arr+n);
  for(i=0;i<n;i++)
  {
    cout<<find(arr,n,i+1)<<endl;
  }
  return 0;
}

//returns the index
int find(int arr[] , int size , int ele)
{
  if(ele<arr[0]||ele>arr[size-1])
  {
    return -1;
  }
  int t = sqrt(size);

  /*
  Initial 1

  int pt[t];
  for(i=0;i<t;i++)
  {
    pt[i] = arr[i*t];
  }
  pt[i] == arr[i*t]
  */
  int start =0,end=t*t;
  if(ele<arr[end])
  {
    while(end-start>t)
    {
      int mid = (start+end)/2;
      mid -= (mid%t);
      if(arr[mid]==ele)
      {
        return mid;
      }
      else if(arr[mid]<ele)
      {
        start = mid;
      }
      else
      {
        end = mid;
      }
    }
  }
  else
  {
    start = end;
    end = size;
  }
  while(end>=start)
  {
    int mid = start + ((end-start)/2);
    if(arr[mid]==ele)
    {
      return mid;
    }
    else if(arr[mid]<ele)
    {
      start = mid+1;
    }
    else
    {
      end = mid-1;
    }
  }
  return -1;
  /*

  Initial 2
  while((i<size)&& arr[i] <=ele)
  {
    i +=t;
  }
  int j=i;
  i-=t;
  */
  /*
  Initial 2
  while(arr[i*t] <= ele&&(i<t))
  {
    i++;
  }
  i--;
  i = i*t;
  int j= (i+1)*t;
  */
  /*
  Initial 1 and 2
  for(;i<=j;i++)
  {
    if(arr[i]==ele)
    {
      return i;
    }
  }*/
  return -1;
}
