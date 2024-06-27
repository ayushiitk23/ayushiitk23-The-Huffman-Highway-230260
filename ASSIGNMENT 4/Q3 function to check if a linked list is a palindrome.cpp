struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;

    // Find the midpoint using the slow and fast pointer approach
    ListNode *slow = head, *fast = head, *prev = NULL;
    while (fast && fast->next) {
        fast = fast->next->next;
        ListNode* next = slow->next;
        slow->next = prev;
        prev = slow;
        slow = next;
    }
    
    // If the length is odd, skip the middle element
    if (fast) slow = slow->next;

    // Compare the two halves
    while (slow) {
        if (slow->val != prev->val) return false;
        slow = slow->next;
        prev = prev->next;
    }
    return true;
}
