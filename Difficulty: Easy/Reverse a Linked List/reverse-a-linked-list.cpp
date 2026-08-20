/* Structure of Linked List Node
class Node {
 public:
    int data ;
    Node *next ;

    Node(int x) {
        data = x ;
        next = nullptr ;
    }
};
*/

class Solution {
  public:
    Node* reverseList(Node* head) {
        // code here
        if(!head -> next) return head;
        
        Node* prev = NULL;
        Node* curr = head;
        Node* nxt;
        
        
        while(curr){
            nxt = curr -> next;
            
            curr -> next = prev;
            
            prev = curr;
            curr = nxt;
        }
        
        return prev;
    }
};