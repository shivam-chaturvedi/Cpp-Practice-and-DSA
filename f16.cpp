#include<iostream>
#include<string>
#include<vector>

int main(){
   std::vector<int> nums1={3,4,6,8,10,19},nums2={1,7,20};
    double ans;
    int size1=nums1.size(),size2=nums2.size();
    std::vector<int>::iterator it=nums1.begin();
    int l=nums1.at(size1-1);
    int u=nums2.at(0),i=0;
    i=size1-1;
    while(nums1.at(i)>nums2.at(0) && i>0){
        i--;
    }
   std::cout<<i;
    return 0;
}