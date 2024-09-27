#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
};

void reverseList(Node*& head) {
    Node* curr = head;
    Node* temp = NULL;

    while (curr != NULL) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    if (temp != NULL) {
        head = temp->prev;
    }
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    Node* head = NULL;
    Node* temp = NULL;

    for (int i = 0; i < n; i++) {
        if (head == NULL) {
            head = new Node();
            cin >> head->data;
            head->next = NULL;
            head->prev = NULL;
            temp = head;
        } else {
            Node* newItem = new Node();
            cin >> newItem->data;
            newItem->next = NULL;
            newItem->prev = temp;
            temp->next = newItem;
            temp = newItem;
        }
    }

    cout << "Forward traversal: ";
    printList(head);

    reverseList(head);

    cout << "Reversed forward traversal: ";
    printList(head);

    return 0;
}
