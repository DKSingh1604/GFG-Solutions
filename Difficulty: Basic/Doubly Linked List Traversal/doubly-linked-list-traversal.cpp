/* Structure of doubly linked list Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};*/
class Solution {
  public:
    vector<vector<int>> displayList(Node *head) {
        // code here
        if(!head) return {};
        
        vector<vector<int>> ans(2);
        
        Node* temp = head;
        
        while(temp){
            ans[0].push_back(temp -> data);
            if(temp -> next){
                temp = temp -> next;
            }
            else{
                break;
            }
            
        }
        //the temp will already be on the last node of the DLL
        
        while(temp){
            ans[1].push_back(temp -> data);
            temp = temp -> prev;
        }
        
        return ans;
    }
};