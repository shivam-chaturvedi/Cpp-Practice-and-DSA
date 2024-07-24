#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> nums={-1,-1,0,0,0,1,1,1,1,1,2,3,3,7,7,7,7,9,9,8,8,8,8,8,8,9,9,-1,-1,2,2};
    vector<int>::iterator it=nums.begin();
    int count=1,prev=*it,k=0,i=0;
    int s=nums.size();
    while(it!=nums.end()){
        it++;
        i++;
        if(i==s){
            break;
        }
        if(count==2){
            if(prev!=*it){
                count=1;
            }
            
            else{
                --it;
                nums.erase(it);
                k++;
            }
        }
        else if(*it==prev){
            count++;
        }
        else{
            count=1;
        }
        prev=*it;
    }
    // cout<<nums.size();
    for(int i=0;i<nums.size();i++){
        cout<<" "<<nums.at(i);
    }
    return 0;
}