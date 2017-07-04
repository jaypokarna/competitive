#include <iostream>
#include <math.h>

using namespace std;

typedef struct
{
  int x;
  int y;
}node;
float findmindis(node arr[], int start , int end);
float dis(node n1 , node n2);
void nodesort(node arr[] , int size, int a);
int main()
{
  int arrx[] = {100,200,300,400,500,600};
  int arry[] = {5000,10000,11000,12000,13000,5000};
  int size = sizeof(arrx)/sizeof(int);
  node arr[size];
  int i;
  for(i=0;i<size;i++)
  {
    arr[i].x = arrx[i];
    arr[i].y = arry[i];
  }
  // ensure that the array is sorted in x before this step
  nodesort(arr,size,0);
  cout<<findmindis(arr,0,size -1);
  return 0;
}

float findmindis(node arr[], int start , int end)
{
  if(end - start >3)
  {
    float d = min(findmindis(arr,start, start + (end- start)/2) ,findmindis(arr, start + (end- start)/2 + 1 ,end));
    float val = arr[start + (end - start)/2 ].x + 0.1;
    int i;
    node fin[end - start];
    int j=0;
    for(i=start;i<=end;i++)
    {
      if((arr[i].x >= val - d)||(arr[i].x <= val+d))
      {
        fin[j++] = arr[i];
      }
    }
    //sort fin on the basis of y coordinate
    nodesort(fin,j,1);
    float f;
    if(j==1)
    {
      return d;
    }
    if(j==2)
    {
      f = dis(fin[0],fin[1]);
    }
    int k;
    for(i=0;i<j;i++)
    {
      if(i>=3)
      {
        k = i-3;
      }
      else
      {
        k=0;
      }
      for(;k<min(j,7);k++)
      {
        if((f > dis(fin[i] , fin[k]))&&(i!=k))
        {
          f = dis(fin[i] , fin[k]);
        }
      }
    }
    return min(f , d);
  }
  else
  {
    float temp[3];
    temp[0] = dis(arr[start] , arr[start +1]);
    temp[1] = dis(arr[start +2] , arr[start +1]);
    temp[2] = dis(arr[start] , arr[start +2]);
    float d = temp[0];
    if(d > temp[1])
    d = temp[1];
    if(d > temp[2])
    d = temp[2];
    return d;
  }
}

float dis(node n1 , node n2)
{
  return sqrt( pow(n1.x - n2.x,2) + pow(n1.y - n2.y,2) );
}

void nodesort(node arr[] ,int size,  int a)
{
  int i,j;
  if(a==0)
  {
    for(i=0;i<size;i++)
    {
      for(j=i+1;j<size;j++)
      {
        if(arr[j].x < arr[i].x)
        {
          node temp = arr[j];
          arr[j] = arr[i];
          arr[i] = temp;
        }
      }
    }
  }
  else if(a==1)
  {
    for(i=0;i<size;i++)
    {
      for(j=i+1;j<size;j++)
      {
        if(arr[j].y < arr[i].y)
        {
          node temp = arr[j];
          arr[j] = arr[i];
          arr[i] = temp;
        }
      }
    }
  }
}
