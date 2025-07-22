/*
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
} */

class Solution {
  public:
    Node* rotate(Node* head, int k) {
        // Your code here
        
        if (!head || !head->next || k == 0) return head;
        
        Node* temp = head;
        int count = 1;
        while(temp -> next){
            count++;
            temp = temp -> next;
        }
        
        
        Node* temp1 = head;
        
        
        k = k % count;
        if (k == 0) return head;
        
        for(int i = 0; i < k-1; i++){
            temp1 = temp1 -> next;
        }
        
        temp -> next = head;
        head = temp1 -> next;
        temp1 -> next = NULL;
        
        return head;
    }
};