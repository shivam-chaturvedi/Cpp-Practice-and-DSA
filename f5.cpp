#include<iostream>
#include<vector>
#include<algorithm>
using std::cout;

using std::endl;
using namespace std;

int main(){
    string s="1234";
    while(nullptr){
        cout<<"he";
    }
    return 0;
}


// #include<algorithm>
// class Solution {
// public:
//     void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
//     nums1.erase(std::remove(nums1.begin(),nums1.end(),0),nums1.end());

//     nums2.erase(std::remove(nums2.begin(),nums2.end(),0),nums2.end());
 
//     int j=0,i=0;
//     for(i=0;i<m;i++){
        
//         if(nums2.at(i)!=0){
//         for(j=0;j<n;j++){
//             if(nums2.at(i)<=nums1.at(j)){
//                 nums1.insert(nums1.begin()+j,nums2.at(i));
//                 break;
//             }
//         }
//         if(j==n){
//             break;
//         }
//         }
//     }
//     if(j==n){
//         nums1.insert(nums1.end(),nums2.begin()+i,nums2.end());
//     }
    
//     }
// }; 