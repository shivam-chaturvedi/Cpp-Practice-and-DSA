#include<iostream>
#include<string>
using namespace std;

template <typename T,int N>
class Stack{
    private:
    int capacity;
    int top;
    T *stack;
    
    public:

    Stack(){
    capacity=N;
    top=-1;
    stack=new T[capacity];
    }
    ~Stack(){
        delete []stack;
    }

    bool push(T data){
        top++;
        
        if(top>=capacity){
            cout<< "Stack Overflow !";
            return false;
        }
        stack[top]=data;
        return true;
    }
    
    T pop(){
        if(top<0){
            cout<<"Stack UnderFlow : Stack is empty !";
            throw ;
        }
        top--;
        return stack[top+1];
    }

    T peek(){
        if(top<0){
            cout<< "Stack Is Empty !";
            throw;
        }
        return stack[top];
    }

    bool isEmpty(){
        if(top<0){
            return true;
        }
        return false;
    }

    bool isFull(){
        if(top>=capacity-1){
            return true;
        }
        return false;
    }

    void display(){
        for(int i=capacity-1;i>=0;i--){
            cout<<endl<<"| "<<stack[i]<<" |"<<endl;
            cout<<"-------";
        }
    }
};

int main(){
    Stack <char,20>s1;
    string s="hello there";
    string j;
    for(int i=0;i<s.length();i++){
        s1.push(s.at(i));
    }
    
    for(int i=0;i<s.length();i++){
        j+=s1.pop();
    }
    cout<<j;
    return 0;
}