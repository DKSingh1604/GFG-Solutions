/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void traverseLeft(Node* root, vector<int> &ans){
        if(!root || (!root -> left && !root -> right)){
            return;
        }
        
        ans.push_back(root -> data);
        
        if(root -> left) traverseLeft(root -> left, ans);
        else traverseLeft(root -> right, ans);
        
        
    }
    
    void traverseLeaf(Node* root, vector<int> &ans){
        if(!root) return;
        
        if(!root -> left && !root -> right){
            ans.push_back(root -> data);
        }
        
        traverseLeaf(root -> left, ans);
        traverseLeaf(root -> right, ans);
    }
    
    void traverseRight(Node* root, vector<int> &ans){
        if(!root || (!root -> left && !root -> right)){
            return;
        }
        
        if(root -> right) traverseRight(root -> right, ans);
        else traverseRight(root -> left, ans);
        
        ans.push_back(root -> data);
    }
    
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        if(!root) return ans;
        
        ans.push_back(root -> data);
        
        //left side traversal
        traverseLeft(root -> left, ans);
        
        
        //traverse leaf nodes
        
        //left subtree
        traverseLeaf(root -> left, ans);
        
        //right subtree
        traverseLeaf(root -> right, ans);
        
        //traverse the right part
        traverseRight(root -> right, ans);
        
        return ans;
        
    }
};