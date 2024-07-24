#include<iostream>
#include<vector>
#include<chrono>
#include"BST.cpp"

using namespace std;

class AVLTree{
    private:
    struct Node
    {
        int key,height;
        Node *left,*right;
        Node(int k):key(k),height(1),left(nullptr),right(nullptr){}
    };

    Node *root=nullptr;

    int height(Node *node){
        if(!node) return 0;
        int leftSubtreeHeight=0;
        int rightSubtreeHeight=0;
        
        if(node->left){
            leftSubtreeHeight=node->left->height;
        }
        if(node->right){
            rightSubtreeHeight=node->right->height;
        }
        return (1 + std::max(leftSubtreeHeight,rightSubtreeHeight));
    }

    Node *rightRotate(Node * node){
        if(!node) return node;

        Node * y=node->left;
        node->left=y->right;
        y->right=node;
        node->height=height(node);
        y->height=height(y);
        return y;
    }

    Node *leftRotate(Node *node){
        if(!node) return node;

        Node *y=node->right;
        node->right=y->left;
        y->left=node;
        node->height=height(node);
        y->height=height(y);
        return y;
    }

    Node *insert(Node *node,int key){
        if(!node){
            return new Node(key);
        }
        else if(key<node->key){
            node->left=insert(node->left,key);
        }else if(key>node->key){
            node->right=insert(node->right,key);
        }else{
            return node;
        }
        node->height=height(node);
        return balance(node);
    }

    int getBalanceFactor(Node *node){
        if(!node) return 0;
        int leftSubtreeHeight=0;
        int rightSubtreeHeight=0;
        if(node->left){
            leftSubtreeHeight=node->left->height;
        }
        if(node->right){
            rightSubtreeHeight=node->right->height;
        }

        return leftSubtreeHeight-rightSubtreeHeight;
    }

    Node * balance(Node *node){
        if(!node) return node;
        int balanceFactor=getBalanceFactor(node);

        if(balanceFactor>1){
            if(getBalanceFactor(node->left)>0){
                // left left case
                node=rightRotate(node);
            }
            else if(getBalanceFactor(node->left)<0){
                // left right case
                node->left=leftRotate(node->left);
                node=rightRotate(node);
            }
        }
        else if(balanceFactor<-1){
            if(getBalanceFactor(node->right)<0){
                // right right case
                node=leftRotate(node);
            }
            else if(getBalanceFactor(node->right)>0){
                node->right=rightRotate(node->right);
                node=leftRotate(node);
            }
        }
        return node;
    }

    Node * search(Node *node,int key){
        if(!node) return node;

        if(key<node->key){
            return search(node->left,key);
        }
        else if(key>node->key){
            return search(node->right,key);
        }
        else{
            return node;
        }
    }

    void inorder(Node *node,vector<int> &v){
        if(!node){
            return;
        }
        inorder(node->left,v);
        v.push_back(node->key);
        inorder(node->right,v);
    }

    public:
    void insert(int key){
        root=insert(root,key);
    }

    int height(){
        return height(root);
    }

    vector<int> & inorder(){
        vector<int> *v=new vector<int>;
        inorder(root,*v);
        return *v;
    }

    bool search(int key){
        return search(root,key)?true:false;
    }
};

// int main(){
//     AVLTree tree;
//     for(int i=250000;i>0;i--){
//         tree.insert(i);
//     }
//     auto start=chrono::high_resolution_clock::now();
//     cout<<tree.search(0)<<endl;
//     auto end=chrono::high_resolution_clock::now();

//     auto duration=chrono::duration_cast<chrono::microseconds>(end-start);

//     cout<<endl<<duration.count();

//     return 0;
// }