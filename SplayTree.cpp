#include<iostream>
#include<vector>
#include<initializer_list>
#include<random>
#include<ctime>
#include <chrono>
#include"BST.cpp"

using namespace std;

class SplayTree{
    private:
    struct Node{
        int key;
        Node * left,*right;
        Node(int k):key(k),left(nullptr),right(nullptr){}
    };

    Node *root=nullptr;
    unsigned int count=0;

    Node *insert(Node* root,int key){
        if(!root){
            return new Node(key);
        }

        else if(key<root->key){
            root->left=insert(root->left,key);
        }

        else if(key>root->key){
            root->right=insert(root->right,key);
        }

        else{
            return root;
        }
        return root;
    }

    void inorder(Node *root,vector<int> &v){
        if(!root){
            return;
        }
        inorder(root->left,v);
        v.push_back(root->key);
        inorder(root->right,v);
    }

    
    void preorder(Node *root,vector<int> &v){
        if(!root){
            return;
        }
        v.push_back(root->key);
        preorder(root->left,v);
        preorder(root->right,v);
    }

    
    void postorder(Node *root,vector<int> &v){
        if(!root){
            return;
        }
        postorder(root->left,v);
        postorder(root->right,v);
        v.push_back(root->key);
    }

    Node *leftRotate(Node *root){
        if(!root){
            return root;
        }
        Node *y=root->right;
        root->right=y->left;
        y->left=root;
        return y;
    }

    Node *rightRotate(Node *root){
        if(!root){
            return root;
        }
        Node *y=root->left;
        root->left=y->right;
        y->right=root;
        return y;
    }

    Node * splay(Node *root,int key){
        if(!root || key==root->key){
            return root;
        }
        
        else if(key<root->key){
            if(!root->left) return root;

            if(key<root->left->key){
                root->left->left=splay(root->left->left,key);
                root=rightRotate(root);
            }
            else if(key>root->left->key){
                root->left->right=splay(root->left->right,key);
                if(root->left->right){
                    root->left=leftRotate(root->left);
                }
            }
            return root->left?rightRotate(root):root;
        }

        else{
            if(!root->right) return root;

            if(key>root->right->key){
                root->right->right=splay(root->right->right,key);
                root=leftRotate(root);
            }
            else if(key<root->right->key){
                root->right->left=splay(root->right->left,key);
                if(root->right->left){
                    root->right=rightRotate(root->right);
                }
            }
            return root->right?leftRotate(root):root;
        }
        return root;
    }

    Node *remove(Node *root,int key){
        // top down approach
        if(!root) return root;

        root=splay(root,key);
        Node *leftChild=root->left;
        Node *rightChild=root->right;
        if(root->key==key){
            // we found the key needed to be deleted
            delete root;
        }
        else{
            return root;
        }

        if(leftChild){
            leftChild->right=rightChild;
            root=leftChild;
        }
        else if(rightChild){
            root=rightChild;
        }
        else{
            root=nullptr;
        }
        return root;
    }

    void clear(Node *root){
        if(!root){
            return;
        }
        clear(root->left);
        clear(root->right);
        delete root;
    }

    public:
    SplayTree():root(nullptr){}

    SplayTree(vector<int> &v):root(nullptr){
        for(auto &i:v){
            insert(i);
        }
    }

    SplayTree(initializer_list<int> init):root(nullptr){
        for(auto &i:init){
            insert(i);
        }
    }

    ~SplayTree(){
        clear();
    }

    void insert(int key){
        root=splay(root,key);
        
        if(!root){
            root=new Node(key);
            return;
        }
        if(root->key==key){
            return;
        }
        else if(key<root->key){
            Node *newnode=new Node(key);
            newnode->left=root->left;
            root->left=nullptr;
            newnode->right=root;
            root=newnode;
        }
        else{
            Node * newnode=new Node(key);
            newnode->left=root;
            newnode->right=root->right;
            root->right=nullptr;
            root=newnode;
        }
    } 

    vector<int> &inorder(){
        vector<int> *v=new vector<int>;
        inorder(root,*v);
        return *v;
    }

    vector<int> &preorder(){
        vector<int> *v=new vector<int>;
        preorder(root,*v);
        return *v;
    }

    vector<int> &postorder(){
        vector<int> *v=new vector<int>;
        postorder(root,*v);
        return *v;
    }

    void remove(int key){
        Node * prev=root;
        root=remove(root,key);
        
    }

    void clear(){
        clear(root);
        root=nullptr;
        count=0;
    }

    bool search(int key){
        root=splay(root,key);
        if(root->key==key){
            return true;
        }
        return false;
    }    

    void populate(int number_of_nodes,int start=0,int end=100){
        mt19937 g(static_cast<unsigned >(time(nullptr)) );
        uniform_int_distribution<int> dist(start,end);
        while(number_of_nodes){
            insert(dist(g));
            number_of_nodes--;
        }
    }

    unsigned int size(){
        return count;
    }
};

int main(){
    SplayTree tree={2,34,23,-2,-2,0,303,373,22,33,23,2,33,2};

    for(auto &i:tree.preorder()){
        cout<<i<<" ";
    }
    
    return 0;
}