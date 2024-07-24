#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> nums={1,2,3};
    vector<int> temp;
    int k=4;
    k=k-nums.size();
    k=k<0?-k:k;
    cout<<k;
     int Index=nums.size()-k;
     
     if(Index<0){
        Index=-Index;
     }
     if(Index!=0){     
        int last=nums.size()-1;
        int j=0;
        for(int k=Index;k<=last;k++){
            temp.push_back(nums.at(k));
            
        }
        for(int i=0;i<Index;i++){
            temp.push_back(nums.at(i));
        }
        nums=temp;
     }
     for(int i=0;i<nums.size();i++){
        cout<<" "<<nums.at(i);
     }
    return 0;
}