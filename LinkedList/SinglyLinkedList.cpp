//1. WAP to implement singly linked list


#include <iostream>
#include <stdlib.h>


using namespace std;

class node{
    public:
        int info;
        node *next;
};

int insert_begin(node **start)
{
    int data;
    cout<<"Enter data: ";
    cin>>data;

    node *new_node = new node();
    if(new_node==NULL)
        cout<<"Error in memory allocation"<<endl;
    else
        new_node->info=data;
    if(start==NULL)
        new_node->next=NULL;
    else
        new_node->next=(*start);
        (*start)=new_node;
    return 0;

}
void insert_end(node **start)
{
    node *ptr;
    node *new_node = new node();
    int data;
    cout<<"Enter data: ";
    cin>>data;
    new_node ->info = data;
    new_node ->next = NULL;

    if(start==NULL)
        (*start) = new_node;
    else
    {
        ptr = (*start);
        while(ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next=new_node;
    }
}

void del_begin(node **start)
{
    if(*start==NULL)
        cout<<"Underflow"<<endl;
    else
    {
     node *ptr = (*start);
        (*start) = (*start)->next;
        free(ptr);
    }
}

void del_end(node **start)
{
    node * preptr;
        if(start==NULL)
        cout<<"Underflow"<<endl;
    else
    {
        node *ptr = (*start);
        while(ptr->next!=NULL)
        {
            preptr = ptr;
            ptr=ptr->next;
        }
        preptr->next = NULL;
        free(ptr);
    }
}

node* search_node(node **start,int data)
{
    node *ptr = *start;
    while(ptr!=NULL)
    {
        if(ptr->info==data)
            return ptr;
        else
            cout<<"node not found"<<endl;return 0;
    }
}

void display(node **start)
{
    node* ptr = *start;
    while(ptr != NULL)
       {

        cout<<"data: "<<ptr->info<<endl;
        ptr=ptr->next;
       }
}

int main()
{
int data;
node* start = NULL,*ptr;
char choice,contd;


do{
cout<<"\nChoose the function to perform:";
cout<<"\na.Insert a node at beginning\nb.Insert a node at end"
    <<"\nc.Delete a node at beginning\nd.Delete a node at end"
    <<"\ne.Search a node\nf.Display all nodes"<<endl;
    cin>>choice;


        switch(toupper(choice))
    {
    case 'A':
        insert_begin(&start);break;
    case 'B':
        insert_end(&start); break;
   case 'C':
        del_begin(&start);break;
   case 'D':
        del_end(&start);break;
    case 'E':
        {
            cout<<"Enter data"<<endl;
            cin>>data;
           ptr=search_node(&start,data);break;
        }

    case 'F':
        display(&start);break;
    default:
        cout<<"Invalid Option"<<endl;
    }
    cout<<"\nContinue?(Y/N)"<<endl;
    cin>>contd;

    }while(toupper(contd)=='Y');

    return 0;
}
