/*
delete n nodes after m nodes
  The input list will have at least one element
  Node is defined as

struct Node {
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
        // code here
        
        if (head == NULL || m == 0) return NULL;

        Node* current = head;
    
        while (current != NULL) {
            // Skip m nodes
            for (int i = 1; i < m && current != NULL; i++) {
                current = current->next;
            }
    
            if (current == NULL) break;
    
            // Start deleting next n nodes
            Node* temp = current->next;
            for (int i = 0; i < n && temp != NULL; i++) {
                Node* del = temp;
                temp = temp->next;
                delete del;
            }
    
            // Connect the m-th node to the node after n deletions
            current->next = temp;
    
            // Move current to temp to continue the process
            current = temp;
        }
    
        return head;
        
        
    }
};