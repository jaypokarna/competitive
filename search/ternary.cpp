#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
// here program will output index
int ternary_search(int left , int right , int key, int arr[]);
int main()
{
  int n,i;
  cin>>n;
  int arr[n];
  for(i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  sort(arr,arr + n );
  int key;
  cin>>key;
   key = ternary_search(0,n -1,key,arr);
   cout<<key;
  return 0;
}

int ternary_search(int left , int right , int key,int arr[])
{
  while(left < right)
  {
    int mid1 = left + (right - left)/3;
    int mid2 = right - (right - left)/3;
    if(key==arr[mid1])
    {
      return mid1;
    }
    else if(key == arr[mid2])
    {
      return mid2;
    }
    else if(key < arr[mid1])
    {
      right = mid1 -1 ;
    }
    else if(key > arr[mid2])
    {
      left = mid2 +1;
    }
    else if(key > arr[mid1] && key < arr[mid2])
    {
      left = mid1 + 1;
      right = mid2 -1;
    }
  }
    if(key == arr[left])
    {
      return left;
    }
    else
    {
      return -1;
    }
}
