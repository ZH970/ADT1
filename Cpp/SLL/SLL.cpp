#include <iostream>

using namespace std;

typedef struct node{
  node *next;
  int c;
  int e;
}node,*List;


void Init(List &L)
{
  L=new node;
  L->next=NULL;
}

void Insert(List &L,int c,int e)
{
  List s=new node;
  s->c=c;
  s->e=e;
  L->next=s;
  s->next=NULL;
  L=L->next; //Put the ptr L to the new node.
}

void input(List &L)
{
  int c,e;
  cout<<"i:"<<endl;
  cin>>c;
  List p=L;
  while(c)
  {
    cout<<"expon:"<<endl;
    cin>>e;
    Insert(p,c,e);
    cout<<"Please inter the next i or input 0 and enter...";
    cin>>c;
  }
}

List sum(List L1,List L2)
{
  List L3;
  Init(L3);
  List p1=L1->next,p2=L2->next,p3=L3;//p1,p2分别指向多项式 L1 和 L2 的首项,p3指向L3中待插入位置的前一项。
  while(p1&&p2)
  {
    if(p1->e==p2->e)
    {
      Insert(p3,p1->c+p2->c,p1->e);
      p1=p1->next;
      p2=p2->next;
    }
    else if( (p1->e) > (p2->e))
    {
      Insert(p3,p1->c,p1->e);
      p1=p1->next;
    }
    else
    {
      Insert(p3,p2->c,p2->e);
      p2=p2->next;
    }
  }
  while(p2)
  {
    Insert(p3,p2->c,p2->e);
    p2=p2->next;
  }
  while(p1)
  {
    Insert(p3,p1->c,p1->e);
    p1=p1->next;
  }
  return L3;
}

void print(List L)
{
  List p=L->next;
  int count=0;
  while(p)
  {
    if (count==0)
      cout<<p->c<<"x^"<<p->e;
    else
      cout<<" + "<<p->c<<"x^"<<p->e;
    count++;
    p=p->next;
  }
  cout<<endl;
}

/*int main()
{
  List L1;
  Init(L1);
  cout<<"L1:"<<endl;
  input(L1);
  cout<<"L1:";
  print(L1);
  List L2;
  Init(L2);
  cout<<"L2:"<<endl;
  input(L2);
  cout<<"L2:";
  print(L2);
  List L3=sum(L1,L2);
  cout<<"The sum:";
  print(L3);
  system("pause");
}*/


