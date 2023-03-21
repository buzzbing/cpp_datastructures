#include <iostream>
#include <stdlib.h>

using namespace std;



class node
{
public:

    node *next;
    int data;
};


void insert_first(node **start)
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
void insert_end(node **start)
{
    int val;
     node *new_node = new node();
     node *ptr;
    if (new_node==NULL)
        cout<<"Error in Memory Allocation"<<endl;
    else
    {
        cout<<"Enter data"<<endl;   cin>>val;
        new_node->data=val;
        new_node->next=NULL;
        if((*start)==NULL)
            (*start)=new_node;
        else
           {
             ptr = (*start);
             while(ptr->next!=NULL)
                {
                    ptr=ptr->next;
                }
             ptr->next=new_node;
           }
    }
}
void insert_after(node **start, int nod_data)
{
    int val;
    node *new_node = new node();
    node *ptr;
    if(new_node==NULL)
        cout<<"Error in Memory Allocation"<<endl;
    else
    {
        cout<<"Enter data"<<endl;   cin>>val;
        new_node->data=val;
        ptr = (*start);
        while(ptr->data!=nod_data)
        {
            ptr=ptr->next;
        }
        new_node->next = ptr->next;
        ptr->next = new_node;

    }
}
void insert_before(node **start, int nod_data)
{
    int val;
     node *new_node = new node();
     node *preptr,*ptr;
    if(new_node==NULL)
        cout<<"Error in Memory Allocation"<<endl;
    else
    {
        cout<<"Enter data"<<endl;   cin>>val;
        new_node->data=val;
        ptr = (*start);
        preptr = (*start);
        while(ptr->data!=nod_data)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=new_node;
        new_node->next=ptr;
    }
}
void delete_after(node **start, int nod_data)
{
    if((*start) == NULL)
        cout<<"Underflow"<<endl;
    else
    {
        node *ptr,*postptr;
        ptr = (*start);
        postptr = ptr->next;
        while(ptr->data != nod_data)
        {
            ptr = postptr;
            postptr = postptr->next;
        }
        ptr->next = postptr->next;
        free(postptr);
    }
}
void delete_before(node **start, int nod_data)
{
    if((*start)==NULL)
        cout<<"Underflow"<<endl;
    else
    {
        node *ptr,*preptr,*temp;
        ptr = (*start);
        preptr = (*start);
        temp = (*start);
        while(ptr->data!=nod_data)
        {
            temp = preptr;
            preptr = ptr;
            ptr = ptr->next;
        }
        temp->next = ptr;
        if(preptr==(*start))
            (*start)=(*start)->next;
        free(preptr);

    }
}
void delete_first(node **start)
{
    if((*start)==NULL)
        cout<<"Underflow"<<endl;
    else
    {
        node *ptr;
        ptr = (*start);
        (*start) = (*start)->next;
        free(ptr);
    }
}
void delete_last(node **start)
{
    if((*start)==NULL)
        cout<<"Underflow"<<endl;
    else
    {
         node *ptr,*preptr;
        ptr=(*start);
        while(ptr->next!=NULL)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=NULL;
        free(ptr);
    }
}
void delete_data(node **start,int nod_data)
{
    if((*start)==NULL)
        cout<<"Underflow"<<endl;
    else
    {
         node *ptr,*preptr;
        ptr=(*start);
        preptr=(*start);
        while(ptr->data!=nod_data)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next = ptr->next;
        free(ptr);
    }
}
node* traverse(node **start,int nod_data)
{
    node *ptr;
    if((*start)==NULL)
        cout<<"Underflow"<<endl;
    else{
            ptr=(*start);
    while(ptr->data!=nod_data)
        ptr=ptr->next;
    return ptr;}
}
void display(node **start)
{
    int i = 1;
    node * nod_ptr;
    nod_ptr = (*start);
    if((*start)==NULL)
        cout<<"Underflow"<<endl;
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
int main()
{
    node *start = NULL;
    int node_data;
    char choice,contd;

    do{
            cout<<"\n\n\t\tSINGLY LINKED LIST\n\nSelect Operation: "<<endl;
            cout<<"Insert\n\tA.At Start\n\tB.At End\n\tC.Before a node\n\tD.After a node"<<endl
                <<"Delete\n\tE.At Start\n\tF.At End\n\tG.Before a node\n\tH.After a node\n\tI.Given Data"<<endl
                <<"J. Traverse\nK. Display"<<endl;
            cin>>choice;

            switch(toupper(choice))
            {
            case'A':insert_first(&start);break;
            case'B':insert_end(&start);break;
            case'C':
                {
                    cout<<"Enter node data"<<endl;cin>>node_data;
                    insert_before(&start,node_data);break;
                }
            case'D':
                {
                    cout<<"Enter node data"<<endl;cin>>node_data;
                    insert_after(&start,node_data);break;
                }
            case'E':delete_first(&start);break;
            case'F':delete_last(&start);break;
            case'G':
                {
                    cout<<"Enter node data"<<endl;cin>>node_data;
                    delete_before(&start,node_data);break;
                }
            case'H':
                {
                    cout<<"Enter node data"<<endl;cin>>node_data;
                    delete_after(&start,node_data);break;
                }
            case'I':
                {
                    cout<<"Enter node data"<<endl;cin>>node_data;
                    delete_data(&start,node_data);break;
                }
            case'J':
                 {
                    cout<<"Enter node data"<<endl;cin>>node_data;
                    cout<<"Data: "<<node_data<<" is stored at "<<traverse(&start,node_data);break;
                 }
            case'K':display(&start);break;
            default:
                cout<<"Invalid Option"<<endl;
            }
            cout<<"Do you want to continue(Y/N)?"<<endl;
            cin>>contd;

    }while(toupper(contd)=='Y');


    return 0;
}
