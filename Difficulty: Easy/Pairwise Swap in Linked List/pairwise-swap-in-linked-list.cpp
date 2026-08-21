/* Structure of linked list Node
class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};*/
class Solution {
  public:
    Node* pairwiseSwap(Node* head) {
        
        if(!head -> next) return head;
        Node* dummy = new Node(0);
        
        Node* prev = dummy;
        Node* curr = head;
        
        while(curr && curr -> next){
           //save the pointers
           Node* nxtPair = curr -> next -> next;
           Node* second = curr -> next;
           
           //reverse this pair of nodes
           second -> next = curr;
           curr -> next = nxtPair;
           prev -> next = second;
           
           //update the pointers
           prev = curr;
           curr = nxtPair;
           
        }
        head = dummy -> next;
        delete(dummy);
        return head;
    }
};