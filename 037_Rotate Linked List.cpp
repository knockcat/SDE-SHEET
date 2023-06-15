Node *rotate(Node *head, int k) {
     // Write your code here.

     if(!head or !head->next)
          return head;

     int cnt = 1;

     Node* temp = head;

     while(temp->next)
     {
          ++cnt;
          temp = temp->next;
     }

     temp->next = head;

     k = k % cnt;

     k = cnt - k;

     while(k--)
     {
          temp = head;
          head = head->next;
     }

     temp ->next = nullptr;

     return head;
}
