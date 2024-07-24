#include<iostream>
#include<typeinfo>
#include<vector>

using namespace std;

class InstanceManager{
    private:
    static int reference_count;
    static InstanceManager* instances;
    

    public:
    // virtual void manageInstances()=0;

    void addInstance(InstanceManager * instance){
       
        instances[reference_count]=*instance;
        reference_count++;
    }
    static InstanceManager* getInstances(){
        return instances;
    }
    static int getInstancesCount(){
        return reference_count;
    }
};
int InstanceManager::reference_count=0;
InstanceManager* InstanceManager::instances=new InstanceManager[100];


class A:public InstanceManager{
    private:
    vector<A *> objects;

    public:
    int id=1;
    void manageInstances(){
        addInstance(this);
    }
    
    A(){
        manageInstances();
    }
    vector<A*> getObjects(){
        // cout<<typeid(A).name();
        for(int i=0;i<getInstancesCount();i++){
           if( typeid(getInstances()[i]).name()==typeid(A).name() ){
           
           }
        }
        return objects;
    }
    ~A(){
    }

};


class B :public InstanceManager{

    public:
    void manageInstances(){
        addInstance(this);
    }
    B(){
        manageInstances();
    }
};

int main(){
    A o,o2;
    B ob1,ob2,ob3;
    int i=0;
    cout<<(o.getObjects().at(i))->id;
    
 return 0;      
}