#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<int> nums={4,0,4,2,2,0,1,3,3,0,3};
    int i = nums.size() - 2, j = 0, prev = 0;

        if(nums.at(0)==0 && i>0){
            return false;
        }

        while (i >= 0 && nums.at(i) != 0) {
            i--;
        }
        if (i < 0) {
            return true;
        }
        for (j = 0; j < i; j++) {
            cout<<j<<" ";
            if (nums.at(j) == 0) {

                if (j > 0) {
                    prev = j - 1;
                    while (prev >= 0) {
                        if (nums.at(prev) +prev > j) {
                            break;
                        }
                        prev--;
                    }
                    if (prev < 0) {
                        return false;
                    }
                }
            }
            else if ((nums.at(j) + j) > i) {
                break;
            }
        }
        if (j == i) {
            return false;
        }
        // return true;
  
    return 0;
}