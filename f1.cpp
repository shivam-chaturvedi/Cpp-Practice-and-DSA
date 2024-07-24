#include<iostream>
#include<conio.h>
#include<typeinfo>
#include<string>

using namespace std;

template <class X>
class ArrayList{
    private:
    int capacity=0;
    X *array=nullptr;

    public:
    ArrayList(int capacity=0){
        // cout<<typeid(X).name();
        getch();
        this->capacity=capacity;
        this->array=new X[capacity];
        // for(int i=0;i<capacity;i++){
        //     array[i]=-1;
        // }
    }
    ~ArrayList(){
        delete []array;
    }
    int add(unsigned int index,X data){
        if(index>=0 && index<capacity){
            array[index]=data;
            return 0;
        }
        else{
            
            return -1;
        }
    }
    int setCapacity(unsigned int capacity){
        X *temp=array;
        int tempCapacity=this->capacity;
      
        if(capacity<=this->capacity){
            cout<<"Capacity of array can increase only !";
            return -1;
        }
        
        this->capacity=capacity;
        
        array=new X[capacity];
        // for(int i=0;i<capacity;i++){
        //     array[i]=-1;
        // }
        for(int i=0;i<tempCapacity;i++){
            array[i]=temp[i];
        }
        
        delete []temp;
        return 0;
    }
    void viewList(){
        int i;
        for ( i=0;i<this->capacity;i++){
            if(array[i]==-1){
                cout<<"null ";
            }
            else{
            // cout<<array[i]<<" ";
            }
        }
        if(i==0){
            cout<<"Array List Is empty !";
        }
    }

};

int menu(char *options[],int size){
    system("cls");
    int choice=0;
    for(int i=0;i<size;i++){
        cout<<i+1<<". "<<options[i]<<endl;
    }
    cout<<"Enter Your Choice: ";
    cin>>choice;
    if(choice>0 && choice<=size){

        return choice;
    }
    else{
        cout<<"Please,Enter valid choice !!";
        return -1;
    }
}

struct Book{
int id;
};

int main(int argc,char* argv[]){

    ArrayList <Book> list;
    Book data;
    int choice;
    char * options[]={"Add Element","View List","set Capacity","Exit"};
    while(1){
        choice=menu(options,4);
        switch(choice){
            case 1:
            int index,res;
            
            cout<<"Enter index: ";
            cin>>index;
            cout<<"\nEnter data: ";
            // cin>>data;
            res=list.add(index,data);
            if(res<0){
                cout<<"Array List Capacity Reached !!\n";
            }
            getch();
            break;
            
            case 2:
            list.viewList();
            getch();
            break;

            case 3:
            int capacity;
            cout<<"Enter New Capacity : ";
            cin>>capacity;
            list.setCapacity(capacity);
            getch();
            break;

            case 4:
            exit(0);
            
            default:
            cout<<"It will never run";
        }
    }

    return 0;
}