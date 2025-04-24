#include <stdio.h>

struct Node {
    int pages;
    Node *next;

    Node(int value) {
        this->pages = pages;
        next = NULL;
    }
};

struct List {
    Node *head;

    List() {
        head = NULL;
    }

    void ins(int pages) {
        Node *n = new Node(pages);
        if (head == NULL || pages < head->pages) {
            n->next = head;
            head = n;
        } else {
            Node *cur = head;
            while (cur->next != NULL && cur->next->pages <= pages) {
                cur = cur->next;
            }
            n->next = cur->next;
            cur->next = n;
        }
    }

    int booksRead(int pages) {
        int booksRead = 0;
        Node *aux = head;
        while (aux != NULL) {
            if (pages >= aux->pages) {
                pages -= aux->pages;
                booksRead++;
            }
            aux = aux->next;
        }
        return booksRead;
    }
};

int main() {
    List l;

    int n;
    scanf("%d", &n);

    while (n--) {
        int value;
        scanf("%d", &value);
        // sorted insert (asc)
        l.ins(value);
    }

    int p;
    scanf("%d", &p);

    int booksRead = l.booksRead(p);
    printf("%d\n", booksRead);
}
