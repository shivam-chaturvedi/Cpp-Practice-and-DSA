#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    void inorder(TreeNode *root,unordered_map<int,pair<TreeNode*,TreeNode*> > &nodes,TreeNode*parent){
        if(!root){
            return;
        }
        inorder(root->left,nodes,root);
        nodes[root->val]=make_pair(root,parent);
        inorder(root->right,nodes,root);
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
     vector<TreeNode*> forest;
     unordered_map<int,pair<TreeNode*,TreeNode*> > nodes;
     inorder(root,nodes,nullptr);

     forest.push_back(root);
     for(auto i:to_delete){
        try{
        TreeNode *temp=nodes.at(i).first;
        // delete node
        TreeNode *parent=nodes.at(i).second;
        if(parent!=nullptr){
            // it is root node
        if( parent->left==temp){
            // node to be deleted is left child
            parent->left=nullptr;
        } 
        else{
            parent->right=nullptr;
        }

        }

        if(temp->left){
            forest.push_back(temp->left);
        }
        if(temp->right){
            forest.push_back(temp->right);
        }

        delete temp;
        }
        catch(...){
            // not delete
        }
     }

     for(auto & i:forest){
        cout<<i->val<<" ";
     }
     return forest;
    }
};