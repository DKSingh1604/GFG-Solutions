/*
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
class Solution {
  public:
    void solve(Node *root,int &k,int &count,vector<int> &ans)
    {
        if(root == NULL)
        {
            return;
        }
        
        ans.push_back(root->data);
        solve(root->left,k,count,ans);
        solve(root->right,k,count,ans);
        
        int s=ans.size();int sum=0;
        for(int i=s-1;i>=0;i--)
        {
            sum+=ans[i];
            if(sum == k) count++;
        }
        ans.pop_back();
    }
    int sumK(Node *root,int k)
    {
        // code here 
        vector<int> ans;int count=0;
        solve(root,k,count,ans);
        return count;
    }
};