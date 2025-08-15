/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'
class Solution {
  public:
    int ans = -1;
    int count = 0;
    
    void reverseOrder(Node* root, int k){
        
        if(!root || count >= k){
            return;
        }    
        
        reverseOrder(root -> right, k);
        
        count++;
        if(count == k){
            ans = root -> data;
            return;
        }
        
        reverseOrder(root -> left, k);
        
    }
    
    int kthLargest(Node *root, int k) {
        // Your code here
        count = 0;
        ans = -1;
        
        reverseOrder(root, k);
        
        return ans;
        
    }
};