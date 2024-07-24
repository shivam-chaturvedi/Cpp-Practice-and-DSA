#include<iostream>

using namespace std;

class RedBlackTree{
    private:
    enum Color{
        RED,BLACK
    };

    struct Node{
        int key;
        Color color;
        Node *left,*right,*parent;
        Node(int key):key(key),color(Color::RED),left(nullptr),right(nullptr),parent(nullptr){}
    };

    Node *root=nullptr;

    Node* insert(Node *root,Node *node){
            if(!root){
                return node;
            }

            if(node->key<root->key){
                root->left=insert(root->left,node);
                root->left->parent=root;
            }
            else if(node->key>root->key){
                root->right=insert(root->right,node);
                root->right->parent=root;
            }
            else{
                return root;
            }
            return root;
        }

    Node *leftRotate(Node* node){
        if(!node) return node;

        Node *y=node->right;
        node->right=y->left;
        if(y->left){
            y->left->parent=node;
        }
        if(node->parent){
            y->parent=node->parent;
        }

        y->left=node;
        Color c=y->color;
        node->parent=y;
        y->color=node->color;
        node->color=c;
        return y;
    }

    
    Node *rightRotate(Node* node){
        if(!node) return node;

        Node *y=node->left;
        node->left=y->right;
        if(y->right){
            y->right->parent=node;
        }
        if(node->parent){
            y->parent=node->parent;
        }

        y->right=node;
        Color c=y->color;
        node->parent=y;
        y->color=node->color;
        node->color=c;
        return y;
    }

    void fixViolation(Node *node){
        Node *parent=node->parent;
        Node *grandParent=parent->parent;
        if(parent->color==Color::BLACK){
            return;
        }
        else{
            Node *uncle=(grandParent->left==parent)?grandParent->right:grandParent->left;
            if(!uncle || uncle->color==Color::BLACK){
                Node *grandGrandParent=grandGrandParent->parent;bool isGrandParentLeftChild;
                if(grandGrandParent){
                isGrandParentLeftChild=(grandGrandParent->left==grandGrandParent)?true:false;
                }
                bool isParentLeftChild=(grandParent->left==parent)?true:false;
                if(isParentLeftChild){
                    bool isNodeLeftChild=(parent->left==node)?true:false;
                    if(isNodeLeftChild){
                        if(isGrandParentLeftChild){
                            grandGrandParent->left=rightRotate(grandParent);
                        }
                        else{
                            grandGrandParent->right=rightRotate(grandParent);
                        }
                    }
                    else{
                        grandParent->left=leftRotate(parent);
                        if(isGrandParentLeftChild){
                            grandGrandParent->left=rightRotate(grandParent);
                        }
                        else{
                            grandGrandParent->right=rightRotate(grandParent);
                        }
                    }
                }
                else{
                    bool isNodeLeftChild=(parent->left==node)?true:false;
                    if(!isNodeLeftChild){
                        if(isGrandParentLeftChild){
                            grandGrandParent->left=leftRotate(grandParent);
                        }
                        else{
                            grandGrandParent->right=leftRotate(grandParent);
                        }
                    }
                    else{
                        grandParent->right=rightRotate(parent);
                        if(isGrandParentLeftChild){
                            grandGrandParent->left=leftRotate(grandParent);
                        }
                        else{
                            grandGrandParent->right=leftRotate(grandParent);
                        }
                    }
                }
            }            
            else{
                uncle->color=Color::BLACK;
                parent->color=Color::BLACK;
                if(grandParent!=root){
                    grandParent->color=Color::RED;
                    fixViolation(grandParent);
                }
            }
        }
    }

    void inorder(Node *root){
        if(!root) return;

        inorder(root->left);
        cout<<root->key<<":"<<root->color<<" ";
        inorder(root->right);
    }

    public:
    void insert(int key){
        Node *newnode=new Node(key);
        if(!root){
            newnode->color=Color::BLACK;
        }
        root=insert(root,newnode);
        if(newnode->parent && newnode->parent->parent){
            fixViolation(newnode);
        }
        
    }

    void inorder(){
        inorder(root);
    }
};

int main(){
    RedBlackTree tree;

    tree.insert(10);
    tree.insert(9);
    tree.insert(11);
    tree.insert(8);
    tree.insert(6);
    tree.insert(10);
    tree.insert(5);
    tree.insert(33);
    tree.insert(1);
    tree.insert(10);


    tree.inorder();
    return 0;
}