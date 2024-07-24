#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> prices={1,1,6};
    
    int stock,profit=0,i=0,j=0;
    int s=prices.size();
    
    while(i<s){
    for(j=i;(j!=s-1) && (prices[j]>=prices[j+1]) ;j++);
    if(j==s-1){
        break;
    }
    stock=prices[j];
    j++;
    while((j!=s-1) && (prices[j]<prices[j+1] ) ){
        j++;
    }
    profit+=prices[j]-stock;
    i=j;
    }
    cout<<profit; 
    return 0;
}