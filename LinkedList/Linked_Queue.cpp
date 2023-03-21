#include <iostream>
#include <stdlib.h>

using namespace std;



class node
{
public:

    node *next;
    int data;
    node *front;
    node *rear;
};


void enqueue(node **front,node **rear)
{

    int val;
    node* ptr;
     node *new_node = new node();
    if(new_node==NULL)
        cout<<"Error in Memory Allocation"<<endl;
    else
    {
        cout<<"Enter data"<<endl;   cin>>val;
        new_node->data=val;
        if((*front)==NULL)
        {
            (*rear) = new_node;
            (*front)=new_node;
        }
        else
          {
           (*rear)->next=new_node;
           (*rear)=new_node;
          }
        (*rear)->next = NULL;


    }

}

int dequeue(node **front,node **rear)
{
      node *ptr;
        int val;
    if((*front)==NULL)
        cout<<"Underflow"<<endl;
    else
    {
        val = (*front)->data;
        ptr = (*front);
        if((*front)==(*rear))
        {
            (*front)=NULL;
            (*rear)=NULL;
        }
        else
        {
            (*front) = (*front)->next;
        }
        free(ptr);
        return val;
    }
}


void display(node **front,node **rear)
{
    int i = 1;
    node * nod_ptr;
    nod_ptr = (*front);
    if((*front)==NULL)
        cout<<"Underflow"<<endl;
    else
    {
        while(nod_ptr!=NULL)
    {
        cout<<"Node:\t"<<i<<"\tData:\t"<<nod_ptr->data<<endl;
        nod_ptr=nod_ptr->next;
        i++;
    }
    cout<<"Front at : "<<(*front)<<" node data: "<<(*front)->data<<endl;
    cout<<"Rear at : "<<(*rear)<<" node data: "<<(*rear)->data<<endl;
    }

}


int main()
{

       char choice , contd;
    node *front = NULL, *rear=NULL;
    cout<<"\t\tLINKED LIST IMPLEMENTATION OF LINEAR QUEUE"<<endl;
    do
    {

        cout<<"Select Operation: "<<endl;
        cout<<"A. Enqueue\nB. Dequeue\nC. Display"<<endl;
        cin>>choice;
        switch(toupper(choice))
        {
            case'A':enqueue(&front,&rear);break;
            case'B':cout<<"Dequeued value: "<<dequeue(&front,&rear)<<endl;break;
            case'C':display(&front,&rear);break;
            default:cout<<"Invalid Option"<<endl;
        }
        cout<<"\nDo you want to continue?(Y/N)"<<endl;
        cin>>contd;
    }while(toupper(contd)=='Y');

    return 0;
}












