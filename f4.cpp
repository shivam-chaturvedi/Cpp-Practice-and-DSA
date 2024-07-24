#include<iostream>
#include<conio.h>

using namespace std;

class Binary{
    private:
    int size=20;
    int *binary;
    int length=0;

    public:
    Binary()
    {
        binary=new int[size];
    }

    ~Binary(){
        delete [] binary;
    }
    friend ostream & operator<<(ostream&,Binary);
    friend istream & operator>>(istream&,Binary&);

    int decimalValue(){
        int sum=0;
        int k=0;
        for(int i=length-1;i>=0;i--){
            if(binary[i]==1){
                sum+=1<<k;
               
            }
            k++;
        }
        return sum;
    }

    static Binary binaryValue(int decimal){
        int rem=0;
        int i=0,binary[20];
        Binary tempobj;

        while(decimal){
            rem=decimal%2;

            binary[i]=rem;
            decimal/=2;
            i++;
        }
        for(int j=0;j<i;j++){
            tempobj.binary[j]=binary[i-1-j];
            tempobj.length++;

        }
        return tempobj;
    }

    Binary operator+(Binary &b){
       int sum=decimalValue()+b.decimalValue();
       return Binary::binaryValue(sum);
    }
};

ostream & operator<<(ostream & dout,Binary b){
for(int i=0;i<b.length;i++){
cout<<b.binary[i];
}
return dout;
}

istream & operator>>(istream & din,Binary &b){
    char ch;
    int i=0;
    cout<<"\nEnter Binary Number: ";
while((ch=getch())!=13){
    if(ch=='1'){
        cout<<ch;
        b.binary[i]=1;
        b.length++;
    }
    else if(ch=='0'){
        cout<<ch;
        b.binary[i]=0;
        b.length++;
    }
    else{
        continue;
    }
    i++;
}
return cin;
}

int main(int argc ,char * argv[]){
    Binary o1,o2;
    int x=10;
    cin>>o1>>o2;
    cout<<"\nSum of "<<o1<<" and "<<o2<<" is "<<o1+o2<<" and decimal equavalent is "<<(o1+o2).decimalValue();
    
    return 0;
}