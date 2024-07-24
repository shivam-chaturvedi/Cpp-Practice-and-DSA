#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool isPalindrome(string s){
    int length=s.size(),i=0,last=length-1;
    while(i<length/2){
        if(s.at(i)!=s.at(last-i)){
            break;
        }
        i++;
    }
    if(i==length/2){
        return true;
    }
    return false;
}

void palindromeSubsets(string s,vector<string> &v){
    if(s.empty()){
        return;
    }

    if(isPalindrome(s)){
        v.push_back(s);
    }
    s.pop_back();
    palindromeSubsets(s,v);
}

void palindromePartitions(string s,vector<string> &v){
    if(s.empty()){
        return;
    }
    palindromeSubsets(s,v);
    s.erase(0,1);
    palindromePartitions(s,v);
}

int main(){
    vector<string> v;
    string s="namanjkdhjkdgJNSmkamakajmaamajojadhjkfahsjkjsDKOKOKOPsowOospaHSAJISOI";
    palindromePartitions(s,v);
  
    for(auto & s:v){
        cout<<s<<" ";
    }
    return 0;
}