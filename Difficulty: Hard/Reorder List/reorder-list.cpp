/* Node Structure
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
}; */

class Solution {
  public:
    void reorderList(Node* head) {
        if(!head || !head->next || !head->next->next)
            return;

        // 1. Find middle
        Node* slow = head;
        Node* fast = head;

        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. Split
        Node* second = slow->next;
        slow->next = NULL;

        // 3. Reverse second half
        Node* prev = NULL;
        Node* curr = second;

        while(curr) {
            Node* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        second = prev;

        // 4. Merge
        Node* first = head;

        while(second) {
            Node* temp1 = first->next;
            Node* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};