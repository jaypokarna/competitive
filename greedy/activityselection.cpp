#include<iostream>
#include<algorithm>
using namespace std;

typedef struct
{
  int sta;
  int fin;
}task;

bool sortsta(task a1 , task b1);

bool sortfin(task a1 , task b1);

bool sortsta(task a1 , task b1)
{
  return a1.sta < b1.sta;
}
bool sortfin(task a1 , task b1)
{
  return a1.fin < b1.fin;
}
int main()
{
  int n,i;
  cin>>n;
  task arr[n];
  for(i=0;i<n;i++)
  {
    cin>>arr[i].sta>>arr[i].fin;
  }
  bool (*fun_ptr)(task,task);
  fun_ptr = sortsta;
  stable_sort(arr,arr+n,fun_ptr);
  fun_ptr= sortfin;
  stable_sort(arr,arr+n,fun_ptr);
  cout<<arr[0].sta<<" "<<arr[0].fin<<endl;
  int end = arr[0].fin;
  for(i=0;i<n;i++)
  {
    if(arr[i].sta > end)
    {
      cout<<arr[i].sta<<" "<<arr[i].fin<<endl;
      end = arr[i].fin;
    }
  }
  return 0;
}
