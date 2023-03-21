#include <iostream>
#include <stdlib.h>

using namespace std;

class node
{
public:
    int data;
    node *next;
};
insert_begin(node **start)
{
    int val;
    node *new_node = new node();
    node *ptr;
    if(new_node == NULL)
        cout<<"Error in memory allocation"<<endl;
    else
    {
        cout<<"Enter data"<<endl;cin>>val;
        new_node->data = val;
        if((*start)==NULL)
           {
               (*start)=new_node;
               new_node->next = (*start);
           }
        else
        {
            ptr = (*start);
            while(ptr->next!=(*start))
              {
                   ptr = ptr->next;
              }
            new_node->next=(*start);
            ptr->next = new_node;
            (*start) = new_node;
        }


    }
}
insert_end(node **start)
{
    int val;
    node *new_node = new node();
    node *ptr;
    if(new_node == NULL)
        cout<<"Error in memory allocation"<<endl;
    else
    {
        cout<<"Enter data"<<endl;cin>>val;
        new_node->data = val;
        new_node->next = (*start);
         if((*start)==NULL)
        {
            (*start)=new_node;
            new_node->next = (*start);
        }
        else
        {
            ptr = (*start);
            while(ptr->next!=(*start))
                ptr = ptr->next;
            ptr->next = new_node;
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
        if(postptr==(*start))
            (*start)=ptr->next;
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
        node *ptr = (*start);
        while(ptr->next!=(*start))
            ptr = ptr->next;
        ptr->next = (*start)->next;
        free((*start));
        (*start)=ptr->next;
    }
}
delete_last(node **start)
{
        if((*start)==NULL)
        cout<<"Underflow"<<endl;
    else
    {
        node *ptr,*preptr;
        ptr = (*start);
        while(ptr->next!=(*start))
        {
             preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next = (*start);
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
        cout<<"Node:\t"<<i<<"\tData:\t"<<nod_ptr->data<<endl;
        nod_ptr = nod_ptr->next;
        i++;
        while(nod_ptr!=(*start))
    {
        cout<<"Node:\t"<<i<<"\tData:\t"<<nod_ptr->data<<endl;
        nod_ptr = nod_ptr->next;
        i++;
    }
    }

}
int main()
{
    int node_data;
    node *start = NULL;
    char choice, contd;
    do
    {
        cout<<"\n\n\tCIRCULAR LINKED LIST"<<endl;
        cout<<"Select Operation: "<<endl;
        cout<<"Insert a node\n\tA. At the beginning\n\tB. At the end\n\tC. After a node\n\tD. Before a node"
            <<"\nDelete a node\n\tE. At the beginning\n\tF. At the end\n\tG. After a node\n\tH. Before a node"
            <<"\n\tI. Given data\nJ. Display\nK. Traverse"<<endl;
            cin>>choice;
        switch(toupper(choice))
        {
            case'A':insert_begin(&start);break;
            case'B':insert_end(&start);break;
            case'C':
                {
                    cout<<"Enter node data after which node is to be added"<<endl;cin>>node_data;
                    insert_after(&start,node_data);break;
                }
            case'D':
                {
                    cout<<"Enter node data before which node is to be added"<<endl;cin>>node_data;
                    insert_before(&start,node_data);break;
                }
            case'E':delete_first(&start);break;
            case'F':delete_last(&start);break;
            case'G':
                {
                    cout<<"Enter node data after which node is to be deleted"<<endl;cin>>node_data;
                    delete_after(&start,node_data);break;
                }
            case'H':
                {
                    cout<<"Enter node data before which node is to be deleted"<<endl;cin>>node_data;
                    delete_before(&start,node_data);break;
                }
            case'I':
                {
                    cout<<"Enter node data which is to be deleted"<<endl;cin>>node_data;
                    delete_data(&start,node_data);break;
                }
            case'J':display(&start);break;
            case'K':
                    {
                    cout<<"Enter node data"<<endl;cin>>node_data;
                    cout<<"Data: "<<node_data<<" is stored at "<<traverse(&start,node_data)<<endl;break;
                    }
            default:
                cout<<"Invalid Option"<<endl;break;
        }

        cout<<"Continue?(Y/N)"<<endl;cin>>contd;
    }while(toupper(contd)=='Y');
    return 0;
}
