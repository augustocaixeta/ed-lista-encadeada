#include <stdio.h>

struct Node {
    int classId;
    double average;
    Node *next;

    Node(int classId, double average) {
        this->classId = classId;
        this->average = average;
        next = NULL;
    }
};

struct List {
    Node *head;

    List() {
        head = NULL;
    }

    void ins(int classId, double average) {
        Node *n = new Node(classId, average);

        if (head == NULL || classId >= head->classId) {
            n->next = head;
            head = n;
        } else {
            Node *cur = head;
            while (cur->next != NULL && cur->next->classId > classId) {
                cur = cur->next;
            }
            n->next = cur->next;
            cur->next = n;
        }
    }

    void print() {
        if (head == NULL) {
            return;
        }
        Node *a = head;
        double highest = head->average;

        while (a != NULL) {
            if (a->average > highest) {
                highest = a->average;
            }
            a = a->next;
        }
        a = head;
        while (a != NULL) {
            if (a->average == highest) {
                printf("%d ", a->classId);
            }
            a = a->next;
        }
        printf("\n");
    }

    void clear() {
        Node *a = head;
        while (a != NULL) {
            Node *next = a->next;
            delete(a);
            a = next;
        }
        head = NULL;
    }
};

int main() {
    List l;

    int n, t = 0;

    while (scanf("%d", &n) && n != 0) {
        while (n--) {
            int c, a;
            scanf("%d %d", &c, &a);
            // sorted insert
            l.ins(c, a);
        }
        printf("Turma %d\n", ++t);
        l.print();
        l.clear();
    }
}
