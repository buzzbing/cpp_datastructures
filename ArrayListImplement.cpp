#include <iostream>
#include <stdlib.h>
#define max 10


using namespace std;


int avail=0;


struct nodeType
{
    int data;
    int next;
}node[max];



int getnode()
{
    int p;
    if(avail==-1)
       {
           cout<<"Overflow"<<endl;
           exit(1);
       }
    p = avail;
    avail = node[avail].next;

    return p;
}



void insert()
{
    int val, new_node;
    cout<<"Press -1 when done"<<endl;
    do
    {
        cout<<"Enter data: ";
        cin>>val;
        if(val==-1) break;
        else{
                new_node = getnode();
                node[new_node].data = val;
            }
    }while(val!=-1);
    node[new_node].next = -1;
}



void freenode(int free_index)
{

    node[free_index].next = avail;
    node[free_index].data = NULL;
    avail = free_index;
}


void del_node()
{
    char contin = 'Y';
    int ptr,i=0;

    while(node[i].next != -1)
    {
        int indx_val = node[i].next;
        i++;
    }
            cout<<"Deleted value: "<<node[i].data<<endl;
            freenode(i);
            node[--i].next = -1;

}


void inAfter()
{
    int index, data, new_node;
    cout<<"Enter index after which node is to be added: ";
    cin>>index;
    cout<<"Enter data: ";
    cin>>data;
    if(index<0 || index>max-1)
        cout<<"Invalid Insertion"<<endl;
    else
    {
    new_node = getnode();
    node[new_node].data = data;
    node[new_node].next = node[index].next;
    node[index].next = new_node ;
    }
}


void freeAfter()
{
    int index, free;
    cout<<"Enter index after which node is to be deleted: ";
    cin>>index;
    if(index<0||node[index].next==-1)
        cout<<"Invalid Deletion after given pointer"<<endl;
    else
    {
    free = node[index].next;
    cout<<"Deleted value: "<<node[free].data<<endl;
    node[index].next = node[free].next;
    freenode(free);
    }
}

void peek()
{
    cout<<"Node\tData\tNext"<<endl;
    for(int i = 0;i<max;i++)
        cout<<i<<"\t"<<node[i].data<<"\t"<<node[i].next<<endl;
}


int main()
{

    char choice, contd,index;

    for(int i = 0;i<max-1; i++)
    { node[i].next = i+1; }
    node[max -1].next = -1;

    do
        {
    cout<<"Enter your choice:\n a.Insert data\n b.Delete data"
        <<"\n c.Insert data after a node"
        <<"\n d.Delete data after a node\n e.Peek"<<endl;

    cin>>choice;

    switch(toupper(choice))
    {
        case 'A':
            insert();break;
        case 'B':
                del_node();break;
        case 'C':
                inAfter();break;
        case 'D':
                freeAfter();break;
        case 'E':
            peek();break;
        default:
            cout<<"Invalid Option"<<endl;break;

    }
    cout<<"\nDo you want to continue?(Y/N)"<<endl;
    cin>>contd;
    }while(toupper(contd)=='Y');

    return 0;
}

