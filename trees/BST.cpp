#include<iostream>
#include<vector>
#include<initializer_list>
using namespace std;

class BST{
    private:
    struct Node{
        int key,height;
        Node *left,*right;
        Node(int k):key(k),height(1),left(nullptr),right(nullptr){}
    };
    Node *root;

    Node *insert(Node *node,int key){
        if(!node){
            return new Node(key);
        }
        if(key<node->key){
            node->left=insert(node->left,key);
        }
        else if(key>node->key){
            node->right=insert(node->right,key);
        }
        else{
            return node;
        }
        int leftTreeHeight=0;
        int rightTreeHeight=0;
        if(node->left){
            leftTreeHeight=node->left->height;
        }
        if(node->right){
            rightTreeHeight=node->right->height;
        }
        node->height= 1 + std::max(rightTreeHeight,leftTreeHeight);
        return node;
    }

    void inorder(Node *node,vector<int> &v){
        if(!node){
            return;
        }
        inorder(node->left,v);
        v.push_back(node->key);
        inorder(node->right,v);
    }

    Node * search(Node *node,int key){
        if(!node || node->key==key){
            return node;
        }
        else if(key<node->key){
            return search(node->left,key);
        }
        else{
            return search(node->right,key);
        }
    }

    Node * min(Node *node){
        if(!node) return node;

        while(node->left){
            node=node->left;
        }
        return node;
    }

    Node *max(Node *node){
        if(!node) return node;

        while(node->right){
            node=node->right;
        }
        return node;
    }

    Node * remove(Node *node,int key){
        if(!node) return node;

        if(key<node->key){
            node->left= remove(node->left,key);
        }
        else if(key>node->key){
            node->right= remove(node->right,key);
        }
        else{
            if(!node->left && !node->right){
                delete node;
                return nullptr;
            }
            else if(!node->left){
                Node *rightChild=node->right;
                delete node;
                return rightChild;
            }
            else if(!node->right){
                Node *leftChild=node->left;
                delete node;
                return leftChild;
            }
            else{
                Node *replaceKeyNode=std::min(node->left->height,node->right->height)==node->left->height?node->left:node->right;
                int inorderPredecessor=0,inorderSuccessor=0;
                if(replaceKeyNode==node->left){
                    inorderPredecessor=max(replaceKeyNode)->key;
                    node->key=inorderPredecessor;
                    node->left=remove(replaceKeyNode,inorderPredecessor);
                }
                else{
                    inorderSuccessor=min(replaceKeyNode)->key;
                    node->key=inorderSuccessor;
                    node->right=remove(replaceKeyNode,inorderSuccessor);
                }
            }
        }
        return node;
    }

    void clear(Node *node){
        if(!node) return;

        clear(node->left);
        clear(node->right);
        delete node;
    }

    public:
    BST():root(nullptr){}

    BST(initializer_list<int> init_list):root(nullptr){
        for(auto &i:init_list){
            insert(i);
        }
    }

    ~BST(){
        clear();
    }

    void insert(int key){
        root=insert(root,key);
    }

    vector<int> & inorder(){
        vector<int> *v=new vector<int>;
        inorder(root,*v);
        return *v;
    }

    int height() const{
        return root?root->height:0;
    }

    bool search(int key){
        return search(root,key)?true:false;
    }

    void remove(int key){
        root=remove(root,key);
    }

    void clear(){
        clear(root);
        root=nullptr;
    }
};

