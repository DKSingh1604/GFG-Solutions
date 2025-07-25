/*
The structure of linked list is the following
struct Node {
    string data;
    Node *next;

    Node(string x) {
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    bool compute(Node* head) {
        // Your code goes here
        if(head == NULL) return false;
        
        Node* temp = head;
        string check = "";
        
        while(temp){
            check += temp-> data;
            temp = temp -> next;
        }
        
        int s = 0;
        int e = check.size()-1;
        while(s<=e){
            if(check[s] != check[e]){
                return false;
            }
            s++;
            e--;
        }
        return true;
    }
};