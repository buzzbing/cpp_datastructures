//7. Design, Develop and Implement a Program for the following operations on Singly Linked List with header nodes
//a. Represent and Evaluate a Polynomial P(x,y,z) = 6.x^2.y^2.z - 4.y.z^5 + 3.x^3.y.z + 2.x.y^5.z - 2.x.y.z^3

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
void insert_term(node **start, int coef,int xp,int yp, int zp)
{
    node *new_term = new node();
    node *ptr;
    if(new_term==NULL)
        cout<<"Error in Memory Allocation"<<endl;
    else
    {

//        cout<<"\nEnter coefficient for the new term in given expression: ";cin>>new_term->coeff;
 //       cout<<"Enter power of x: ";cin>>new_term->x_power;
  //      cout<<"Enter power of y: ";cin>>new_term->y_power;
   //     cout<<"Enter power of z: ";cin>>new_term->z_power;
        new_term->coeff = coef;
        new_term->x_power = xp;
        new_term->y_power = yp;
        new_term->z_power = zp;
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

float evaluate(node **start)
{
    float sum = 0;
    int x,y,z;
    node *ptr;
    ptr = (*start);
    cout<<"\n\nEnter x: ";cin>>x;
    cout<<"Enter y: ";cin>>y;
    cout<<"Enter z: ";cin>>z;
    while(ptr!=NULL)
    {
        sum = sum + ((ptr->coeff)* pow(x,ptr->x_power) * pow(y,ptr->y_power) * pow(z,ptr->z_power));
        ptr = ptr->next;
    }

    return sum;
}

int main()
{
    char choice;
    do
    {
            node *start = NULL;
    cout<<"IMPLEMENTATION OF SINGLY LINKED LIST TO EVALUATE POLYNOMIAL:"
        <<"\n\n6.x^2.y^2.z - 4.y.z^5 + 3.x^3.y.z + 2.x.y^5.z - 2.x.y.z^3"<<endl;
    insert_term(&start,6,2,2,1);
    insert_term(&start,-4,0,1,5);
    insert_term(&start,3,3,1,1);
    insert_term(&start,2,1,5,1);
    insert_term(&start,-2,1,1,3);
    cout<<"\nEvaluated result: "<<evaluate(&start);
    cout<<"\nWant to evaluate again?(Y/N)"<<endl;
    cin>>choice;
    }while(toupper(choice)=='Y');

    return 0;
}
