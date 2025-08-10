// Node Structure
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
  public:
    pair<int, int> solve(Node* root){
        
        //base case
        if(!root){
            pair<int, int> p = make_pair(0, 0);
            return p;
        }
        
        //recursive call
        pair<int, int> leftAns = solve(root -> left);
        pair<int, int> rightAns = solve(root -> right);
        
        pair<int, int> res;
        //processing
        res.first = root -> data + leftAns.second + rightAns.second;//including sum
        res.second = max(leftAns.first, leftAns.second) + max(rightAns.first, rightAns.second);//excluding sum
        
        return res;
        
    }
    // Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) {
        // code here
        pair<int, int> ans = solve(root);
        return max(ans.first, ans.second);
    }
};