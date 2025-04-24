#include <stdio.h>

struct Node {
    int value;
    Node *next;

    Node(int value) {
        this->value = value;
        next = NULL;
    }
};

struct List {
    Node *head;

    List() {
        head = NULL;
    }

    void ins(int value, bool asc) {
        Node *n = new Node(value);
        if (head == NULL || (asc && value < head->value) || (!asc && value > head->value)) {
            n->next = head;
            head = n;
        } else {
            Node *cur = head;
            while (cur->next != NULL && ((asc && cur->next->value < value) || (!asc && cur->next->value > value))) {
                cur = cur->next;
            }
            n->next = cur->next;
            cur->next = n;
        }
    }

    void print() {
        Node *aux = head;
        while (aux != NULL) {
            printf("%d\n", aux->value);
            aux = aux->next;
        }
    }
};

int main() {
    List p;
    List i;

    int n, val;
    scanf("%d", &n);

    while (n--) {
        int val;
        scanf("%d", &val);

        if (val % 2 == 0) p.ins(val, true);
        if (val % 2 != 0) i.ins(val, false);
    }

    p.print();
    i.print();

    return 0;
}
