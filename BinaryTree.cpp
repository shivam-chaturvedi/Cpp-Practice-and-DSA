#include<iostream>
#include<vector>
#include<chrono>

using namespace std;

class BinarySearchTree{
    protected:

    struct Node{
        int val;
        Node *left,*right;
        Node():val(0),left(nullptr),right(nullptr){}
        Node(int v):val(v),left(nullptr),right(nullptr){}
    };
    Node *root;

    int height(Node * root){
        if(!root){
            return 0;
        }
        return 1 + std::max(height(root->left),height(root->right));
    }

    Node * insert(Node * root,int val){
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
            // duplicate insertion is not allowed in BST
            return root;
        }
        return root;
    }

    void inorder(Node *root,vector<int> &v){
        if(!root){
            return;
        }
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }   

    void preorder(Node * root,vector<int> &v){
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

    Node *search(Node *root,int val){
        if(!root){
            return nullptr;
        }
        else if(val<root->val){
            return search(root->left,val);
        }
        else if(val>root->val){
            return search(root->right,val);
        }
        else{
            return root;
        }
    }

    Node * max(Node *root){
        if(!root){
            return nullptr;
        }
        while(root->right){
            root=root->right;
        }
        return root;
    }
    Node * min(Node *root){
        if(!root){
            return nullptr;
        }
        while(root->left){
            root=root->left;
        }
        return root;
    }

    Node * remove(Node * root,int val){
        if(!root){
            return nullptr;
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
                Node *temp=root;
                root=root->right;
                delete temp;
                return root;
            }
            else if(!root->right){
                Node *temp=root;
                root=root->left;
                delete temp;
                return root;
            }
            else{
                // inorder successor
                 Node * minNode=min(root->right);
                 root->val=minNode->val;
                 root->right=remove(root->right,minNode->val);
                 return root;

            }
        }
        return root;
    }

    public:
    BinarySearchTree():root(nullptr){}

    void insert(int val){
        root=insert(root,val);
    }

    vector<int>& inorder(){
        vector<int> *v=new vector<int>;
        inorder(root,*v);
        return *v;
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

    bool search(int val){
        return search(root,val)?true:false;
    }

    int min(){
        return min(root)->val;
    }

    
    int max(){
        return max(root)->val;
    }

    void remove(int val){
        root=remove(root,val);
    }

    
    int height(){
        return height(root);
    }
};

class AVLTree:protected BinarySearchTree{
    private:
   
    int getBalanceFactor(Node *root){
        if(!root){
            return 0;
        }
        return height(root->left)-height(root->right);
    }

    Node * leftRotate(Node * root){
        if(!root || !root->right){
            return root;
        }
        Node *y=root->right;
        Node *temp=y->left;
        y->left=root;
        root->right=temp;
        return y;
    }

    Node * rightRotate(Node *root){
        if(!root || !root->left){
            return root;
        }
        Node *y=root->left;
        Node *temp=y->right;
        y->right=root;
        root->left=temp;
        return y;
    }

    Node * balance(Node *root){
        if(!root){
            return root;
        }
        int balanceFactor=getBalanceFactor(root);

        if(balanceFactor>1){
            if(getBalanceFactor(root->left)<0){
                root->left=leftRotate(root->left);
            }
            return rightRotate(root);
        }

        if (balanceFactor<-1) {
        // Right-Left Case
        if (getBalanceFactor(root->right) > 0) {
            root->right = rightRotate(root->right);
        }
        // Right-Right Case
        return leftRotate(root);
        }

        return root;   
    }
    public:

    void push(int val){
        insert(val);
        root=balance(root);
    }
    void pop(int val){
        remove(val);
        root=balance(root);
        
    }
    int getHeight(){
        return height();
    }
 
};

void bst(){
    BinarySearchTree tree;
    for(int i=0;i<25000;i++){
        tree.insert(i);
    }
    cout<<tree.height();
    cout<<endl;    
    cout<<tree.height();
    cout<<endl;       
}

void avl(){
    AVLTree tree;
    for(int i=0;i<25000;i++){
        tree.push(i);
    }
    cout<<tree.getHeight();
    cout<<endl;    
    cout<<tree.getHeight();
    cout<<endl;    
    
}

int main(int argc,char * argv[]){
    AVLTree tree;
    auto start = std::chrono::high_resolution_clock::now();

    bst();
    // avl();

    // Get the ending time point
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate the duration in microseconds
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    // Output the duration
    std::cout << "Execution time: " << duration.count() << " microseconds" << std::endl;

    return 0;
}