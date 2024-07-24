#include<iostream>
#include<stdlib.h>
using namespace std;

class LinkedList{
    private:

    struct Node{
        int data;
        Node *next;
    };
    Node *Head;
    int length;
    

    public:
    LinkedList(){
        Head=nullptr;
        length=0;
    }
    ~LinkedList(){
        Node *temp;
        while(Head!=nullptr){
            temp=Head;
            Head=Head->next;
            delete temp;
        }


    }

    int getSize(){
        return length;
    }

    void addElement(int index,int data){
    Node *newnode=new Node;
    int count =0;

    newnode->next=nullptr;
    newnode->data=data;

    if(Head==nullptr){
        Head=newnode;
    }
    else{
        Node *temp=Head,*prev;
        count=0;
        while(count!=index && temp->next!=nullptr){
            prev=temp;
            temp=temp->next;
            count++;
        }
        if(temp->next==nullptr && length){
           
            temp->next=newnode;
        }
        else if(index==0){
         
            newnode->next=Head;
            Head=newnode;
        }
        else{

            newnode->next=temp;
            prev->next=newnode;
        }

    }
    length++;
    }

    void showList(){
        Node *temp=Head;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }

};



// int main(){
//     LinkedList l;
//     int size=0,t=0,index;
//     cout<<"Enter Size: ";
//     cin>>size;
//     for(int i=0;i<size;i++){
//         system("cls");
//         cout<<"Enter Number and index: ";
//         cin>>t;
//         cin>>index;
//         l.addElement(index,t);
        
//     }
//     l.showList();
//     return 0;
// }