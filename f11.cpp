#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int  main(){
    vector <int> quality={10,25,5};
    vector <int> wage={70,50,30};
      int k=2;
    // ios_base::sync_with_stdio(false);

    
    vector<double> ratio,minWages;
    vector<double>::iterator it;
    int i=0,j=0,g=0;
    int n=quality.size();
    bool flag=true,secondFlag=false;
    double temp=0,minWage=INT_MAX,counter=0,sum=0;

    for(i=0;i<n;i++){
        ratio.push_back( (wage.at(i)+0.0)/quality.at(i));
        
        if(flag && i>0){
            if(ratio.at(i-1)<ratio.at(i)){
                continue;
            }
        }
        
        j=0;
        counter=0;
        while(j<n){
            temp=ratio.at(i)*quality.at(j);
            if(temp>=wage.at(j)){
                counter++;
                g=0;
                if(counter>1){
                    while(g<counter-1 && temp>minWages.at(g) ){
                        g++;
                    }
                    it=minWages.begin();
                    minWages.insert(it+g,temp);
                }
                else{
                minWages.push_back(temp); 
                }
            }
            j++;
        }
        if(counter<k){
            if(!secondFlag){
            flag=false;
            }
            minWages.clear();
        }
        else{
            secondFlag=true;
            flag=true;
            
            for(int d=0;d<k;d++){
                sum+=minWages.at(d);
            }
            minWage=minWage<sum?minWage:sum;
            sum=0;
            minWages.clear();
            
        }
        
        }

cout<< minWage;

return 0;
}
