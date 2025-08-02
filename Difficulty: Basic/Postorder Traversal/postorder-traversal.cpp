/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}; */
class Solution {
  public:
    void postorder(vector<int> &ans, Node* root){
        
        if(!root) return;
        
        postorder(ans, root -> left);
        postorder(ans, root -> right);
        ans.push_back(root -> data);
        
        
    }
    // Function to return a list containing the postorder traversal of the tree.
    vector<int> postOrder(Node* root) {
        // Your code here
        vector<int> ans;
        
        postorder(ans, root);
        
        return ans;
    }
};