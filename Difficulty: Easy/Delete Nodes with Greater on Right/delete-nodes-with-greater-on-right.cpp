/* Structure of a Linked List node
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node *compute(Node *head) {
        
        if(!head || !head -> next) return head;
        
        //lets reverse the list
        Node* curr = head;
        Node* prev = NULL;
        Node* nxt;
        
        while(curr){
            nxt = curr -> next;
            
            curr -> next = prev;
            prev = curr;
            curr = nxt;
        }
        
        //remove the node which has greate data on the left
        head = prev;
        Node* temp = head;
        
        int max = temp -> data;
        
        while(temp -> next){
            if(temp -> next -> data < max){
                Node* toDelete = temp -> next;
                temp -> next = temp -> next -> next;
                delete(toDelete);
            }
            else{
                max = temp -> next -> data;
                temp = temp -> next;
            }
        }
        
        //reverse the LL again
        curr = head;
        prev = NULL;
        while(curr){
            nxt = curr -> next;
            
            curr -> next = prev;
            prev = curr;
            curr = nxt;
        }
        head = prev;
        return head;
    }
};