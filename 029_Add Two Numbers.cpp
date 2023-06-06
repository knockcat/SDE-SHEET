
Node *addTwoNumbers(Node *num1, Node *num2)
{
    // Write your code here.

    Node* dummy = new Node(0);
    Node* head = dummy;

    int carry = 0, sum = 0;

    while(num1 and num2)
    {
        sum = carry + num1->data + num2->data;

        Node* temp = new Node(sum%10);

        carry = sum/10;

        num1 = num1->next;
        num2 = num2->next;

        dummy->next = temp;
        dummy = dummy->next;
    }

    while(num1)
    {
        sum = carry + num1->data;

        Node* temp = new Node(sum%10);

        carry = sum/10;

        num1 = num1->next;
        dummy->next = temp;
        dummy = dummy->next;
    }

    while(num2)
    {
        sum = carry + num2->data;

        Node* temp = new Node(sum%10);

        carry = sum/10;

        num2 = num2->next;

        dummy->next = temp;
        dummy = dummy->next;
    }

    if(carry)
    {
        Node* temp = new Node(carry);

        dummy->next = temp;
        
        dummy = dummy->next;
    }

    return head->next;
}
