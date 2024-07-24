#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n=5,k=2;
    int winner = 0; 
    for (int i = 1; i <= n; ++i) {
        winner = (winner + k) % i;
    }
    return winner + 1; 
        
return 0;
}