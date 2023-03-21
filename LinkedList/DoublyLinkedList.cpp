//WAP to implement doubly linked list

#include<iostream>
#include<stdlib.h>

using namespace std;

class doubly_node{
public:
    int data;
    doubly_node *next;
    doubly_node *previous;
};

void insert_first(doubly_node **start)
{
    int val;
    doubly_node *new_node = new doubly_node();
    if (new_node==NULL)
        cout<<"Error in memory allocation"<<endl;
    else
    {
        cout<<"Enter data"<<endl;cin>>val;
        new_node->data = val;
        new_node->previous=NULL;
        new_node->next= (*start);
        (*start) = new_node;
        if((*start)!= NULL)
            (*start)->previous = new_node;
    }
}
void insert_end(doubly_node **start)
{
 int val;
    doubly_node *new_node = new doubly_node();
    if (new_node==NULL)
        cout<<"Error in memory allocation"<<endl;
    else
    {
        cout<<"Enter data"<<endl;cin>>val;
        new_node->data = val;
        new_node->next = NULL;
        doubly_node *ptr;
        ptr = (*start);
        while(ptr->next!=NULL)
            ptr = ptr->next;
        ptr->next = new_node;
        new_node->previous = ptr;

    }
}
void insert_after(doubly_node **start)
{
    int val,nod_data;
    doubly_node *new_node = new doubly_node();
    doubly_node *ptr;
    ptr = (*start);
    if (new_node==NULL)
        cout<<"Error in memory allocation"<<endl;
    else
    {
        cout<<"Enter node data after which node is to be added"<<endl;
        cin>>nod_data;
        cout<<"Enter data"<<endl;cin>>val;
        new_node->data = val;
        while(ptr->data!=nod_data)
           {ptr = ptr->next;}

        new_node->next = ptr->next;
        new_node->previous = ptr;
        ptr->next->previous = new_node;
        ptr->next = new_node;
    }

}
void insert_before(doubly_node **start)
{
    int val,nod_data;
    doubly_node *new_node = new doubly_node();
    doubly_node *ptr;
    ptr = (*start);
    if (new_node==NULL)
        cout<<"Error in memory allocation"<<endl;
    else
    {
        cout<<"Enter node data before which node is to be added"<<endl;
        cin>>nod_data;
        cout<<"Enter data"<<endl; cin>>val;
        new_node->data = val;
        while(ptr->data != nod_data)
            {ptr = ptr->next;}
        new_node->next = ptr;
        new_node->previous = ptr->previous;
        ptr->previous->next = new_node;
        ptr->previous = new_node;
    }
}
void delete_first(doubly_node **start)
{
if((*start)==NULL)
    cout<<"Underflow"<<endl;
else
{
    doubly_node *ptr;
    ptr =(*start);
    (*start) = (*start)->next;
    (*start)->previous = NULL;
    free(ptr);
}
}

void delete_after(doubly_node **start)
{
     int nod_data;
    doubly_node *ptr,*temp;
    ptr = (*start);
    if ((*start)==NULL)
        cout<<"Underflow"<<endl;
    else
    {
        cout<<"Enter node data after which node is to be deleted"<<endl;
        cin>>nod_data;
        while(ptr->data!=nod_data)
            {ptr=ptr->next;}
        temp = ptr->next;
        ptr->next = temp ->next;
        temp->next->previous = ptr;
        free(temp);
    }
}

void delete_last(doubly_node **start)
{
  if((*start)==NULL)
        cout<<"Underflow"<<endl;
    else
    {
        doubly_node *ptr;
        ptr = (*start);
        while(ptr->next!=NULL)
            ptr = ptr->next;
        ptr->previous->next = NULL;
        free(ptr);
    }
}
   doubly_node* traverse(doubly_node **start,int nod_data)
{
    doubly_node *ptr;
    if((*start)==NULL)
        cout<<"Underflow"<<endl;
    else{
            ptr=(*start);
    while(ptr->data!=nod_data)
        ptr=ptr->next;
    return ptr;}
}
void display(doubly_node **start)
{
    int i = 1;
    doubly_node *nod_ptr;
    nod_ptr = (*start);
    if((*start)==NULL)
        cout<<"Underflow"<<endl;
    else
    {
        while(nod_ptr != NULL)
    {
        cout<<"Node:\t"<<i<<"\tData:\t"<<nod_ptr->data<<endl;
        nod_ptr = nod_ptr->next;
        i++;
    }
    }
}

int main()
{
       doubly_node *start = NULL;
    int node_data;
    char choice,contd;

    do{
            cout<<"\n\n\t\tDOUBLY LINKED LIST\n\nSelect Operation: "<<endl;
            cout<<"Insert\n\tA.At Start\n\tB.At End\n\tC.Before a node\n\tD.After a node"<<endl
                <<"Delete\n\tE.At Start\n\tF.At End\n\tG. After a node"<<endl
                <<"H. Traverse\nI. Display"<<endl;
            cin>>choice;

            switch(toupper(choice))
            {
            case'A':insert_first(&start);break;
            case'B':insert_end(&start);break;
            case'C':insert_before(&start);break;
            case'D':insert_after(&start);break;
            case'E':delete_first(&start);break;
            case'F':delete_last(&start);break;
            case'G':delete_after(&start);break;
            case'H':
                 {
                    cout<<"Enter node data"<<endl;cin>>node_data;
                    cout<<"Data: "<<node_data<<" is stored at "<<traverse(&start,node_data);break;
                 }
            case'I':display(&start);break;
            default:
                cout<<"Invalid Option"<<endl;
            }
            cout<<"Do you want to continue(Y/N)?"<<endl;
            cin>>contd;

    }while(toupper(contd)=='Y');


    return 0;
}
