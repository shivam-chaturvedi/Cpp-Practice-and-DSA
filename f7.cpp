#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> nums={1,1,2,2,3,3,4,4,6,7,9,9,9,9,9,10,10,10,20};
    int i=0,j=1;
    int s=nums.size();
    while(j<s){
    while(nums.at(i)==nums.at(j) && j<s-1){
        j++;
    }
    if(j==s-1 && nums.at(j)==nums.at(i)){
        break;
    }
    i++;
    nums.at(i)=nums.at(j);
    }
    return i+1;
    return 0;
}