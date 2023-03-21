
#include<iostream>
#include<stdlib.h>

using namespace std;

class node
{
public:
    int data;
    node *next;
    unsigned int prior;
    node *front;
    node *rear;
};

void enqueue(node **front,node **rear)
{
    int val,priority;
    node *ptr,*preptr;
    node *new_node = new node();
    if(new_node==NULL)
        cout<<"Error in memory allocation"<<endl;
    else
    {
        cout<<"Enter data: "<<endl; cin>>val;
        cout<<"Enter priority: "<<endl; cin>>priority;

        new_node->data = val;
        new_node->prior= priority;

        ptr = (*front);
        preptr= (*front);

        if((*front)==NULL)
        {
            (*rear) = new_node;
            (*front)=new_node;
        }

        else
        {
            if(new_node->prior < ptr->prior)
            {
                new_node->next = ptr;
                (*front) = new_node;
            }
            else if(new_node->prior >= (*rear)->prior)
            {
                (*rear)->next=new_node;
                (*rear)=new_node;
            }
            else
            {
                while((ptr->prior) <= (new_node->prior))
                {   preptr = ptr;
                    ptr = ptr->next;}

                new_node->next = preptr->next;
                preptr->next = new_node;

       }


        }

        }
        (*rear)->next = NULL;

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
        cout<<"Node:\t"<<i<<"\tData:\t"<<nod_ptr->data
        <<"\tPriority:\t"<<nod_ptr->prior<<endl;
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
    cout<<"\t\tLINKED LIST IMPLEMENTATION OF PRIORITY QUEUE"<<endl;
    do
    {

        cout<<"\nSelect Operation: "<<endl;
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
    }while(toupper(contd)!='N');
    return 0;
}
