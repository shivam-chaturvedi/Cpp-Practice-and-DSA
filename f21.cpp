#include<iostream>
#include<string>

using namespace std;

void towerOfHanoi(int n,char source,char destination,char auxiliary){
    if(n<=0){
        cout<<"Disk Must Be Greater Than 0"<<endl;
        return;
    }
    if(n==1){
        cout<<"Move disk "<< n<<" from "<<source<<" and put into "<<destination<<endl;
        return;
    }
    towerOfHanoi(n-1,source,auxiliary,destination);

    cout<<"Move disk "<<n<<" from "<<source<<" and put into "<<destination<<endl;

    towerOfHanoi(n-1,auxiliary,destination,source);
}

int parseInt(string s){
    int i=0,num=0,temp=0;
    bool negative=false;

    if(s.at(0)=='-'){
        i++;
        negative=true;
    }
    for(;i<s.size();i++){
        if(s.at(i)=='0'){
            temp=0;
        }
        if(s.at(i)=='1'){
            temp=1;
        }
        if(s.at(i)=='2'){
            temp=2;
        }
        if(s.at(i)=='3'){
            temp=3;
        }
        if(s.at(i)=='4'){
            temp=4;
        }if(s.at(i)=='5'){
            temp=5;
        }if(s.at(i)=='6'){
            temp=6;
        }if(s.at(i)=='7'){
            temp=7;
        }if(s.at(i)=='8'){
            temp=8;
        }if(s.at(i)=='9'){
            temp=9;
        }
        num=num*10+temp;
    }

return negative?-1*num:num;
}

int main(int argc ,char *argv[]){
char source='A',destination='C',auxiliary='B';

// cout<<parseInt(argv[1]);
try{
towerOfHanoi(parseInt(argv[1]),source,destination,auxiliary);
}catch(...){
    cout<<"Please ,Pass a number also";
}
}