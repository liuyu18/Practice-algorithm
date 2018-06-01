    ListNode *middleNode(ListNode *head) {
        // Write your code here
        if (head == NULL)
            return NULL;
        int cnt = 0;
        ListNode *p = head;
        while (p != NULL) {
            cnt ++;
            p = p->next;
        }
        cnt = (cnt + 1) / 2;
        while (head != NULL) {
            if (cnt == 1)
                return head;
            cnt --;
            head = head->next;
        }
    }