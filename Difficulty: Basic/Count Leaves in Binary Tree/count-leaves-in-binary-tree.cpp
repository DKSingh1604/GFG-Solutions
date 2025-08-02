/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

// Class Solution
class Solution {
  public:
      int countLeaf(Node* root){
          if(root == NULL){
              return 0;
          }
          
          if(root -> left == NULL && root -> right == NULL){
              return 1;
          }
          
          return countLeaf(root -> left) + countLeaf(root -> right);
      }
    
    int countLeaves(Node* root) {
        // write code here
        return countLeaf(root);
        
    }
};