#include <iostream.h>
#include <conio.h>
#include <stdlib.h>

struct node
 {  char name[20];
    int age;
    float height;
    node *nxt;
 };
node *start_ptr=NULL;

int main()
{

  void push ();
  void pop();
  char ch;
  clrscr();
  cout<<"Queue
";
  cout<<"-----";

  do
  {
   cout<<"
Select an operation";
   cout<<"
u->push
";
   cout<<"o->pop
";
   cout<<"e->exit
";

   cin>>ch;

   switch(ch)
   {
    case 'u':
                     push();
                     break;
    case 'o':
                     pop();
                     break;
    case 'e':
                     exit(0);
   }
   }while(ch!='e');

                return 0;

}

void pop()
{
 node *temp1,*temp2;
 if(start_ptr==NULL)
   cout<<"The list is empty
";
 else
  {
   temp1=start_ptr;
   temp2=temp1;
  while(temp1->nxt!=NULL)
   {
    temp2=temp1;
    temp1=temp1->nxt;
   }
  if(temp1==temp2)
    {
     cout<<temp1->name<<",";
     cout<<temp1->age<<", ";
     cout<<temp1->height;
     start_ptr=NULL;
    }
  else
    {
     cout<<temp1->name<<", ";
     cout<<temp1->age<<", ";
     cout<<temp1->height;
     temp2->nxt=NULL;
     delete temp1;
    }
 }
}

void push ()
 {
    node *temp;

    temp = new node;
    cout << "Please enter the name of the person: ";
    cin >> temp->name;
    cout << "Please enter the age of the person: ";
    cin >> temp->age;
    cout << "Please enter the height of the person: ";
    cin >> temp->height;
    if (start_ptr == NULL)
                {
                 temp->nxt=NULL;
                 start_ptr = temp;
                }
    else
                {
      temp->nxt=start_ptr;
      start_ptr=temp;

                }
  }