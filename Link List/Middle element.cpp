/* Finding middle element in a linked list

Given a singly linked list of N nodes. The task is to find the middle of the linked list.
For example, if given linked list is 1->2->3->4->5 then the output should be 3.

If there are even nodes, then there would be two middle nodes, we need to print the second middle element.
 For example, if given linked list is 1->2->3->4->5->6 then the output should be 4.

Example 1:

Input:
LinkedList: 1->2->3->4->5
Output: 3
Example 2:

Input:
LinkedList: 2->4->6->7->5->1
Output: 7 */

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
void printList(Node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}
/* Function to get the middle of the linked list*/
int getMiddle(Node* head);
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int data;
        cin >> data;
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 0; i < n - 1; ++i) {
            cin >> data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        cout << getMiddle(head) << endl;
    }
    return 0;
}


struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};

/* Should return data of middle node. If linked list is empty, then  -1*/
int getMiddle(Node* head)
{
    struct Node* demo = head;
    int cnt = 0;
    while (demo != NULL) {

        cnt++;
        demo = demo->next;
    }
    int var;
    for (int i = 0; i <= cnt / 2; i++) {
        var = head->data;
        head = head->next;
    }
    return var;

}
