#include<iostream>
#include<vector>
#include<chrono>

using namespace std;

class BST{
    protected:
    struct Node
    {
        int val;
        Node *left,*right;
        Node(int v):val(v),left(nullptr),right(nullptr){}
    };

    Node *root;

    Node *insert(Node *root,int val){
        if(!root){
            return new Node(val);
        }
        else if(val<root->val){
            root->left=insert(root->left,val);
        }
        else if(val>root->val){
            root->right=insert(root->right,val);
        }
        else{
            return root;
        }
        return root;
    }

    void preorder(Node *root,vector<int> &v){
        if(!root){
            return;
        }
        v.push_back(root->val);
        preorder(root->left,v);
        preorder(root->right,v);
    }

    void postorder(Node *root,vector<int> &v){
        if(!root){
            return;
        }
        postorder(root->left,v);
        postorder(root->right,v);
        v.push_back(root->val);
    }

    
    void inorder(Node *root,vector<int> &v){
        if(!root){
            return;
        }
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }

    Node * min(Node * root){
        if(!root){
            return root;
        }
        while(root->left!=nullptr){
            root=root->left;
        }
        return root;
    }

    
    Node * max(Node * root){
        if(!root){
            return root;
        }
        while(root->right!=nullptr){
            root=root->right;
        }
        return root;
    }

    Node * remove(Node *root,int val){
        if(!root){
            return root;
        }
        else if(val<root->val){
            root->left=remove(root->left,val);
        }
        else if(val>root->val){
            root->right=remove(root->right,val);
        }
        else{
            if(!root->left && !root->right){
                delete root;
                return nullptr;
            }
            else if(!root->left){
                Node *temp=root->right;
                delete root;
                return temp;
            }
            else if(!root->right){
                Node *temp=root->left;
                delete root;
                return temp;
            }
            else{
                Node * minNode=min(root->right);
                root->val=minNode->val;
                root->right=remove(root->right,minNode->val);
                return root;
            }
        }
        return root;
    }

    Node * search(Node *root,int val){
        if(!root || root->val==val){
            return root;
        }
        else if(val<root->val){
            return search(root->left,val);
        }
        else if(val>root->val){
            return search(root->right,val);
        }
        return root;
    }

    public:

    BST():root(nullptr){}

    void insert(int val){
        root=insert(root,val);
    }

    vector<int>& preorder(){
        vector<int> *v=new vector<int>;
        preorder(root,*v);
        return *v;
    }

    
    vector<int>& postorder(){
        vector<int> *v=new vector<int>;
        postorder(root,*v);
        return *v;
    }

    vector<int>& inorder(){
        vector<int> *v=new vector<int>;
        inorder(root,*v);
        return *v;
    }

    void remove(int val){
        root=remove(root,val);
    }

    int min(){
        Node *minNode= min(root);
        return minNode?minNode->val:-1;
    }

    int max(){
        Node *maxNode= max(root);
        return maxNode?maxNode->val:-1;
    }

    bool search(int val){
        return search(root,val)?true:false;
    }
    
};

class AVLTree:public BST{
    private:

    int height(Node * root){
        if(!root){
            return 0;
        }
        return 1 + std::max(height(root->left),height(root->right));
    }

    int getBalanceFactor(Node *root){
        return height(root->left)-height(root->right);
    }

    Node * rightRotate(Node * root){
        if(!root){
            return nullptr;
        }
        Node *t1,*t2;
        t1=root->left;
        t2=t1->right;
        t1->right=root;
        root->left=t2;
        return t1;
    }

    Node *leftRotate(Node *root){
        if(!root){
            return nullptr;
        }
        Node *t1,*t2;
        t1=root->right;
        t2=t1->left;
        t1->left=root;
        root->right=t2;
        return t1;
    }

    Node *balance(Node * root){
        int balanceFactor=getBalanceFactor(root);
        if(!root){
            return nullptr;
        }
        if(balanceFactor>1){
            // Left Skewed
            if(getBalanceFactor(root->left)<0){
                // LR case
                root->left=leftRotate(root->left);
            }
            return rightRotate(root);

        }
        if(balanceFactor<-1){
            // Right Skewed
            if(getBalanceFactor(root->right)>0){
                // RL case
                root->right=rightRotate(root->right);
            }
            return leftRotate(root);
        }

        return root;
    }

    public:

    void push(int val){
        insert(val);
        root=balance(root);
    }

    int getHeight(){
        return height(root);
    }

};

