#include <iostream>
#include <stdlib.h>
#include<algorithm>
using namespace std;

typedef struct
{
  int x;
  int y;
}pt;

struct node
{
	int x;
  int y;
	struct node* next;
};

typedef struct node NODE;

typedef struct
{
	int count;
	NODE* n;
}HEAD;

HEAD push(HEAD stack , int x , int y);

HEAD pop(HEAD stack);

int leftturn(node * ,node* , pt);
void printlist(HEAD h);
HEAD deletelast(HEAD h);

bool sortx(pt a1 , pt b1);

bool sorty(pt a1 , pt b1);

bool sortx(pt a1 , pt b1)
{
  return a1.x < b1.x;
}
bool sorty(pt a1 , pt b1)
{
  return a1.y < b1.y;
}
int main()
{
  int i,n;
  cin>>n;
  pt arr[n];
  for(i=0;i<n;i++)
  {
    cin>>arr[i].x;
    cin>>arr[i].y;
  }
  bool (*fun_ptr)(pt,pt);
  fun_ptr = sortx;
  stable_sort(arr,arr+n,fun_ptr);
  fun_ptr = sorty;
  stable_sort(arr,arr+n,fun_ptr);
  HEAD l,u,temp;
  l.count =0;
  l.n = NULL;
  u.count=0;
  u.n = NULL;
  for(i=0;i<n;i++)
  {
    while(l.count>=2&&!leftturn((l.n)->next,(l.n),arr[i]))
    {
        l = pop(l);
    }
    l = push(l,arr[i].x,arr[i].y);
  }
  for(i=n-1;i>=0;i--)
  {
    while(u.count>=2&&!leftturn((u.n)->next,(u.n),arr[i]))
    {
        u = pop(u);
    }
    u = push(u,arr[i].x,arr[i].y);
  }
  // now you have to delete the last
  // elements of both lists
  //as they are the same

  // in the pseudocode it was mentioned
  // to append,hence, I think
  // we need to change the lists
  temp = deletelast(l);
  l = deletelast(u);
  u = temp;
  printlist(l);
  printlist(u);
  return 0;
}

HEAD deletelast(HEAD h)
{
  NODE * temp = h.n;
  while(temp->next->next !=NULL)
  {
    temp = temp->next;
  }
  temp->next = NULL;
  return h;
}
void printlist(HEAD h)
{
  NODE * temp = h.n;
  while(temp!=NULL)
  {
    cout<<temp->x<<"  "<<temp->y<<endl;
    temp = temp->next;
  }
}
int leftturn(node *n2 ,node*n1 , pt p)
{
  // (n2 - p)*(n1 -p)
  // (x2 - x0)(y1 -y0) - (x1 - x0)(y2 - y0)
  if((n2->x - p.x)*(n1->y -p.y) - (n1->x - p.x)*(n2->y - p.y) < 0)
  {
    //makes a left turn
    return 1;
  }
  return 0;
}
HEAD push(HEAD stack , int x ,int y)
{
	NODE* temp = (NODE*)malloc(sizeof(NODE));
	temp->x = x;
  temp->y = y;
	NODE* s = stack.n;
	stack.n = temp;
	temp->next = s;
	stack.count++;
	return stack;
}

HEAD pop(HEAD stack)
{
	stack.n = (stack.n)->next;
	stack.count--;
	return stack;
}
