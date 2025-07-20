/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution {
  public:
    Node* reverseLL(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    while(curr != NULL) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(Node* head) {
    if (head == NULL || head->next == NULL) return true;

    // Step 1: Find the middle using slow & fast pointers
    Node* slow = head;
    Node* fast = head;
    while(fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse the second half
    Node* secondHalfStart = reverseLL(slow->next);

    // Step 3: Compare both halves
    Node* firstHalfStart = head;
    Node* secondHalf = secondHalfStart;

    bool isPalin = true;
    while(secondHalf != NULL) {
        if(firstHalfStart->data != secondHalf->data) {
            isPalin = false;
            break;
        }
        firstHalfStart = firstHalfStart->next;
        secondHalf = secondHalf->next;
    }

    // Step 4: Restore the list (optional, if needed)
    slow->next = reverseLL(secondHalfStart);

    return isPalin;

        
        
    }
};