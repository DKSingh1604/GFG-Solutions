/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
  
    Node* reverseList(struct Node* head) {
        // code here
        if(head == NULL) return NULL;
        
        Node* curr = head;
        Node* prev = NULL;
        Node* aage = NULL;
        
        while(curr != NULL){
            aage = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = aage;
        }
        
        return prev;
        
    }
    
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
        
        num1 = reverseList(num1);
        num2 = reverseList(num2);
        
        
        Node* dummy = new Node(-1);  // dummy head
        Node* curr = dummy;
        int carry = 0;
    
        while (num1 || num2 || carry) {
            int sum = carry;
    
            if (num1) {
                sum += num1->data;
                num1 = num1->next;
            }
            if (num2) {
                sum += num2->data;
                num2 = num2->next;
            }
    
            carry = sum / 10;
            Node* newNode = new Node(sum % 10);
            curr->next = newNode;
            curr = curr->next;
        }
    
        // Reverse the result list to get final answer
        Node* result = reverseList(dummy->next);
    
        // Remove leading zeros
        while (result && result->data == 0 && result->next)
            result = result->next;
    
        return result;
        
        
        
    }
};