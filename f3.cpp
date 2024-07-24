#include<iostream>
#include<conio.h>

using namespace std;

class Binary{
    
    char *binary;
    int size;

    public:
    Binary(){
        binary=nullptr;
        size=0;
    }
    ~Binary(){
        delete[] binary;
    }
    friend istream & operator>>(istream&, Binary &b);
    friend ostream & operator<<(ostream &,Binary);
    
};

istream & operator>>(istream& din, Binary &b){
    char ch,*temp;

    while((ch=getch())!=13 ){
        cout<<ch;
        temp=b.binary;
        b.size++;
        b.binary=new char[b.size];
        for(int i=0;i<b.size-1;i++){
            b.binary[i]=temp[i];
            cout<<b.binary[i];
        }
    }
    return cin;
}

ostream& operator<<(ostream & dout,Binary b){
    if(b.size==0){
        cout<<"null";
    }
    else{
        cout<<endl;
        for(int i=0;i<b.size;i++){
            cout<<b.binary[i];
           
        }
    }
        return cout;
}


int main(){
Binary o;
cout<<"Enter :";
cin>>o;
cout<<"\ninput is :";
cout<<o;
    return 0;
}