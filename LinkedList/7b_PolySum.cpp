//7. Design, Develop and Implement a Program for the following operations on Singly Linked List with header nodes
//b. Find the sum of two polynomials POLY1(x,y,z) and POLY2(x,y,z) and store the result in POLYSUM(x,y,z)


#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

class node
{
    public:
    int coeff;
    int x_power;
    int y_power;
    int z_power;
    node *next;

};
void insert_term(node **start)
{
    node *new_term = new node();
    node *ptr;
    if(new_term==NULL)
        cout<<"Error in Memory Allocation"<<endl;
    else
    {

        cout<<"\nEnter coefficient for the new term in given polynomial: ";cin>>new_term->coeff;
        cout<<"Enter power of x: ";cin>>new_term->x_power;
        cout<<"Enter power of y: ";cin>>new_term->y_power;
        cout<<"Enter power of z: ";cin>>new_term->z_power;

        if((*start)==NULL)
        {(*start)=new_term; }
        else
        {
            ptr = (*start);
            while(ptr->next!=NULL)
                {ptr = ptr->next;}
            ptr->next = new_term;

        }
        new_term->next=NULL;
    }
}


void display(node **p1, node **p2)
{
    node *ptr1 = (*p1);
    node *ptr2 = (*p2);
    if(((*p1)==NULL)&&((*p2)==NULL))
        cout<<"No expression given"<<endl;
    else
    {
        cout<<"The polynomial sum is:"<<endl;
        while(ptr1!=NULL)
        {
            cout<<"("<<ptr1->coeff<<".x^"<<ptr1->x_power<<".y^"<<ptr1->y_power
                <<".z^"<<ptr1->z_power<<")"<<"  +  ";
            ptr1 = ptr1->next;
        }

        while(ptr2->next!=NULL)
        {
            cout<<"("<<ptr2->coeff<<".x^"<<ptr2->x_power<<".y^"<<ptr2->y_power
                <<".z^"<<ptr2->z_power<<")"<<"  +  ";
                ptr2 = ptr2->next;
        }
        cout<<"("<<ptr2->coeff<<".x^"<<ptr2->x_power<<".y^"<<ptr2->y_power
            <<".z^"<<ptr2->z_power<<")"<<endl;
    }


}
int evaluate(node **p1,node **p2)
{
    int sum = 0;
    int x,y,z;
    node *ptr1,*ptr2;
    ptr1 = (*p1);
    ptr2 = (*p2);
    cout<<"\n\nEnter x: ";cin>>x;
    cout<<"Enter y: ";cin>>y;
    cout<<"Enter z: ";cin>>z;
    while(ptr1!=NULL)
    {
        sum = sum + ((ptr1->coeff)* pow(x,ptr1->x_power) * pow(y,ptr1->y_power) * pow(z,ptr1->z_power));
        ptr1 = ptr1->next;
    }
       while(ptr2!=NULL)
    {
        sum = sum + ((ptr2->coeff)* pow(x,ptr2->x_power) * pow(y,ptr2->y_power) * pow(z,ptr2->z_power));
        ptr2 = ptr2->next;
    }

    return sum;
}

int main()
{
        char choice;
        int p1_terms,p2_terms;
    do
    {
        node *poly1_start = NULL,*poly2_start=NULL;

        cout<<"IMPLEMENTATION OF SINGLY LINKED LIST TO EVALUATE POLY1(x,y,z) AND POLY2(x,y,z) SUM"<<endl;

        cout<<"\n\nFor polynomial POLY1(x,y,z,): \n "<<endl
            <<"Enter number of terms in POLY1(x,y,z): "; cin>>p1_terms;
        for(int i =0;i<p1_terms;i++)
            insert_term(&poly1_start);

        cout<<"\n\nFor polynomial POLY2(x,y,z,): \n "<<endl
            <<"Enter number of terms in POLY2(x,y,z): "; cin>>p2_terms;
        for(int i =0;i<p2_terms;i++)
            insert_term(&poly2_start);

        display(&poly1_start,&poly2_start);
        cout<<"\nEvaluated result: "<<evaluate(&poly1_start,&poly2_start);

        cout<<"\nWant to evaluate again?(Y/N)"<<endl;
        cin>>choice;

    }while(toupper(choice)=='Y');

    return 0;
}
