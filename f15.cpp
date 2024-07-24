#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<vector<int>> Customers={{2,3},{6,3},{7,5},{11,3},{15,2},{18,1}};
    int time=Customers.at(0).at(0),size=Customers.size(),temp=0,sum=0;
    double avgTime=0;
    for(int i=0;i<size;i++){
        time+=Customers.at(i).at(1);
        temp=(max(time,Customers.at(i).at(0)+Customers.at(i).at(1)));
        if(temp>time){
            sum+=Customers.at(i).at(1);
            time=Customers.at(i).at(1)+Customers.at(i).at(0);
        }
        else{
        sum+=temp-Customers.at(i).at(0);
        }
    }
    avgTime=1.0*sum/size;
    return avgTime;

    return 0;
}