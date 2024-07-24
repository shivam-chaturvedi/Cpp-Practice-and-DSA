#include<iostream>
#include<stdexcept>
#include<map>

using std::cout;
using std::endl;
using std::string;

template <typename T>
class Stack {
    private:
    int size;
    struct Node{
        T data;
        Node *next;
        Node():next(nullptr)
        {}
        Node(T d):data(d),next(nullptr)
        {}
    };
    Node *top;
    int limit;

    public:
    Stack(){
        size=0;
        top=nullptr; 
        limit=-1; 
    }

    ~Stack(){
        while(top!=nullptr){
            Node *temp=top;
            top=top->next;
            delete temp;
        }
    }
    
    void push(T data){
        if(limit!=-1 && size>=limit){
            throw std::runtime_error("Stack Overflow");
        }
        else{
        Node * newnode=new Node(data);
        Node *temp=top;
        newnode->next=temp;
        top=newnode;
        size++;
        }

    }

    int getSize(){
        return size;
    }

    T pop(){
        if(!top){
            throw std::runtime_error("Stack UnderFlow");
        }
        Node *temp=top;
        T data=top->data;
        top=top->next;
        delete temp;
        size--;
        return data;
    }

    T peek(){
        if(!top){
            throw std::runtime_error("Stack UnderFlow");
        }
        return top->data;
    }

    bool isEmpty(){
        if(!top){
            return true;
        }
        return false;
    }

    void setLimit(unsigned int l){
        limit=l;
    }

    void removeLimit(){
        limit=-1;
    }

    void display(){
        Node * temp=top;
        while(temp){
            cout<<"|  "<<temp->data<<"  |"<<endl;
            cout<<"-------"<<endl;
            temp=temp->next;
        }
        cout<<endl<<endl;
    }
    
};

string infixToPostfix(string infix){
    
    std::map<char,int> Precedence;
    Precedence['+']=1;
    Precedence['-']=1;
    Precedence['*']=2;
    Precedence['/']=2;
    Precedence['^']=3;
    Precedence['(']=4;
    Precedence[')']=5;
    
    
    Stack <char>s;
    int i=0;
    char nextChar;
    string postfix;
    for(int i=0;i<infix.length();i++){
        nextChar=infix.at(i);  
        
        if(Precedence[nextChar]==0){
            postfix+=nextChar;
        }
        else if(s.isEmpty()){
            s.push(nextChar);
        }
        else if(Precedence[nextChar]>Precedence[s.peek()]){
          
            if(nextChar=='('){
                s.push(nextChar);
            }
            else if(nextChar==')'){
               
                while(s.peek()!='('){
                    
                    postfix+=s.pop();
                }
                s.pop();
            }
            else{
                s.push(nextChar);
            }
            
        }
        
        else if(Precedence[nextChar]<=Precedence[s.peek()]){
            if(nextChar=='^'){
                s.push(nextChar);
            }
            else{
            while(!s.isEmpty() && !(Precedence[nextChar]>Precedence[s.peek()])){
                if(s.peek()=='('){
                    break;
                }
                postfix+=s.pop();
            
            }
            s.push(nextChar);
            }
            
        }

        
        
    }
    while(!s.isEmpty()){
        postfix+=s.pop();
    }
    return postfix;
}
    

int main(){
    string infix="a*(b+m)*o^5^9/k+i*5-9*6+8";
    cout<<"Enter Infix Expression: ";
    std::cin>>infix;
    string postfix=infixToPostfix(infix);
    cout<<postfix;


    return 0;
}
