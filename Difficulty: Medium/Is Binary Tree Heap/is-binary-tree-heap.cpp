// Structure of node
/*class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
  
    int countNodes(struct Node* root){
        //base case
        if(!root) return 0;
        
        int ans = 1 + countNodes(root -> left) + countNodes(root -> right);
        return ans;
        
    }
    
    bool isCBT(struct Node* root, int index, int cnt){
        if(!root) return true;
        
        if(index >= cnt){
            return false;
        }
        else{
            bool left = isCBT(root -> left, 2*index+1, cnt);
            bool right = isCBT(root -> right, 2*index+2, cnt);
            return (left && right);
        }
    }

    bool isMaxOrder(struct Node* root){
        
        if(!root -> left && !root -> right){
            return true;
        }
        
        if(!root -> right){
            return (root -> data > root -> left -> data);
        }
        
        else{
            bool left = isMaxOrder(root -> left);
            bool right = isMaxOrder(root -> right);
            
            if(left && right && (root -> data > root -> left -> data && root -> data > root -> right -> data)){
                return true;
            }
            else{
                return false;
            }
        }
    }
    bool isHeap(Node* tree) {
        // code here
        int index = 0;
        int totalCount = countNodes(tree);
        if(isCBT(tree, index, totalCount) && isMaxOrder(tree)){
            return true;
        }
        else{
            return false;
        }
    }
};