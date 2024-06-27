struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    if (!head || k == 0) return head;

    // Find the length and the tail of the list
    ListNode* tail = head;
    int length = 1;
    while (tail->next) {
        tail = tail->next;
        length++;
    }
    
    // Connect the tail to the head to form a circular list
    tail->next = head;
    
    // Find the new head and tail
    k = k % length;
    for (int i = 0; i < length - k; i++) {
        tail = tail->next;
    }
    
    // Break the circle
    head = tail->next;
    tail->next = NULL;
    
    return head;
}
