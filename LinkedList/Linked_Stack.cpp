#include<iostream>
#include<stdlib.h>

using namespace std;

class node
{
public:

    node *next;
    int data;
};

void push(node **start)
{
    int val;
     node *new_node = new node();
    if(new_node==NULL)
        cout<<"Error in Memory Allocation"<<endl;
    else
    {
        cout<<"Enter data"<<endl;   cin>>val;
        new_node->data=val;
        if((*start)==NULL)
            new_node->next=NULL;
        else
           new_node->next=(*start);
        (*start)=new_node;
    }

}
int pop(node **start)
{
    int value;
    if((*start)==NULL)
        cout<<"Underflow"<<endl;
    else
    {
        node *ptr;
        ptr = (*start);
        value = ptr->data;
        (*start) = (*start)->next;
        free(ptr);
        return value;
    }
}

void display(node **start)
{
    int i = 1;
    node * nod_ptr;
    nod_ptr = (*start);
    if((*start)==NULL)
        cout<<"Stack is empty."<<endl;
    else
    {
        while(nod_ptr!=NULL)
    {
        cout<<"Node:\t"<<i<<"\tData:\t"<<nod_ptr->data<<endl;
        nod_ptr=nod_ptr->next;
        i++;
    }
    }
}

void peek(node **start)
{
    node *nod_ptr;
    if((*start)==NULL)
        cout<<"Stack is empty."<<endl;
    else
    {
        nod_ptr = (*start);
        cout<<"Top of stack Node data:\t"<<nod_ptr->data<<endl;
    }
}

int main()
{

    char choice , contd;
    node *start = NULL;
    cout<<"\t\tLINKED LIST IMPLEMENTATION OF STACK"<<endl;
    do
    {

        cout<<"Select Operation: "<<endl;
        cout<<"A. Push\nB. Pop\nC. Peek\nD. Display"<<endl;
        cin>>choice;
        switch(toupper(choice))
        {
            case'A':push(&start);break;
            case'B':cout<<"Popped value: "<<pop(&start)<<endl;break;
            case'C':peek(&start);break;
            case'D':display(&start);break;
            default:cout<<"Invalid Option"<<endl;
        }
        cout<<"\nDo you want to continue?(Y/N)"<<endl;
        cin>>contd;
    }while(toupper(contd)=='Y');

    return 0;
}
