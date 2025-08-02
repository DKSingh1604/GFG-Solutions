/* A binary tree node


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void ino(vector<int> &v, Node* r){
        
        if(r == NULL) return;
        
        ino(v, r -> left);
        v.push_back(r -> data);
        ino(v, r -> right);
        
        
    }
    // Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2) {
        // Your Code here
        vector<int> v1;
        vector<int> v2;
        
        ino(v1, r1);
        ino(v2, r2);
        
        if(v1.size() != v2.size()){
            return false;
        }
        
        for(int i = 0; i < v1.size(); i++){
            if(v1[i] != v2[i]){
                return false;
            }
        }
        return true;
    }
};