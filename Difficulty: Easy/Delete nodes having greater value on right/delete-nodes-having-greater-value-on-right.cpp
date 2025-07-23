/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    while (curr) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

Node *compute(Node *head) {
    if (!head || !head->next) return head;

    // Step 1: Reverse the linked list
    head = reverse(head);

    // Step 2: Remove nodes with smaller values
    Node* curr = head;
    Node* maxNode = head;

    while (curr && curr->next) {
        if (curr->next->data < maxNode->data) {
            // Remove the next node
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        } else {
            curr = curr->next;
            maxNode = curr;
        }
    }

    // Step 3: Reverse the list again
    head = reverse(head);
    return head;
}
};