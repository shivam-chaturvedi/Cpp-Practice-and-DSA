#include<iostream>
#include<vector>
#include<algorithm> // For std::max

using namespace std;

class AVLTree {
private:
    struct Node {
        int key, height;
        Node *left, *right;
        Node(int k) : key(k), height(1), left(nullptr), right(nullptr) {}
    };

    Node *root = nullptr;

    int height(Node *node) {
        return node ? node->height : 0;
    }

    int getBalanceFactor(Node *node) {
        return node ? height(node->left) - height(node->right) : 0;
    }

    Node* rightRotate(Node *y) {
        Node *x = y->left;
        Node *T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    Node* leftRotate(Node *x) {
        Node *y = x->right;
        Node *T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    Node* insert(Node *node, int key) {
        if (!node) {
            return new Node(key);
        }
        if (key < node->key) {
            node->left = insert(node->left, key);
        } else if (key > node->key) {
            node->right = insert(node->right, key);
        } else {
            return node;
        }

        // Update height of this ancestor node
        node->height = max(height(node->left), height(node->right)) + 1;

        // Get the balance factor of this ancestor node to check whether this node became unbalanced
        int balance = getBalanceFactor(node);

        // If this node becomes unbalanced, then there are 4 cases

        // Left Left Case
        if (balance > 1 && key < node->left->key) {
            return rightRotate(node);
        }

        // Right Right Case
        if (balance < -1 && key > node->right->key) {
            return leftRotate(node);
        }

        // Left Right Case
        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void preorder(Node *node, vector<int> &v) {
        if (!node) return;
        v.push_back(node->key);
        preorder(node->left, v);
        preorder(node->right, v);
    }

    void postorder(Node *node, vector<int> &v) {
        if (!node) return;
        postorder(node->left, v);
        postorder(node->right, v);
        v.push_back(node->key);
    }

    void inorder(Node *node, vector<int> &v) {
        if (!node) return;
        inorder(node->left, v);
        v.push_back(node->key);
        inorder(node->right, v);
    }

public:
    AVLTree() : root(nullptr) {}

    enum TRAVERSAL {
        INORDER, PREORDER, POSTORDER
    };

    void insert(int key) {
        root = insert(root, key);
    }

    vector<int>& traverse(TRAVERSAL type) {
        vector<int>* v = new vector<int>;
        switch (type) {
            case INORDER:
                inorder(root, *v);
                break;
            case PREORDER:
                preorder(root, *v);
                break;
            case POSTORDER:
                postorder(root, *v);
                break;
            default:
                throw runtime_error("Traversal Type Missing");
        }
        return *v;
    }

    int height() {
        return height(root);
    }
};

int main() {
    AVLTree tree;

    for (int i = 0; i < 50000; i++) {
        tree.insert(i);
    }

    cout << tree.height() << endl;

    // for (auto &i : tree.traverse(tree.INORDER)) {
    //     cout << i << " ";
    // }

    return 0;
}
