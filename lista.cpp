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
    Node *start;
    Node *end;
    int count;

    List() {
        start = NULL;
        end = NULL;
        count = 0;
    }

    bool empty() {
        return start == NULL && end == NULL;
    }

    int size() {
        return count;
    }

    void pushBack(int value) {
        Node *n = new Node(value);
        if (empty()) {
            start = n;
            end = n;
            return;
        }
        end->next = n;
        end = n;
        count++;
    }

    void pushFront(int value) {
        Node *n = new Node(value);
        if (empty()) {
            start = n;
            end = n;
            return;
        }
        n->next = start;
        start = n;
        count++;
    }

    void clearWhenOne() {
        delete(start);
        start = NULL;
        end = NULL;
        count = 0;
    }

    bool popFront() {
        if (empty()) {
            return false;
        }
        if (size() == 1) {
            clearWhenOne();
            return false;
        }
        Node *aux = start;
        start = start->next;
        delete(aux);
        count--;
        return true;
    }

    void popBack() {
        if (empty()) {
            return;
        }
        if (size() == 1) {
            clearWhenOne();
            return;
        }
        Node *aux = start;
        while (aux->next != end) {
            aux = aux->next;
        }
        delete(end);
        end = aux;
        end->next = NULL;
        count--;
    }

    void insert(int index, int value) {
        if (index <= 0){
            pushFront(value);
            return;
        }
        if (index >= count) {
            pushBack(value);
            return;
        }
        Node *n = new Node(value);
        Node *p = start;
        while (--index) {
            p = p->next;
        }
        n->next = p->next;
        p->next = n;
        count++;
    }

    void remove(int index) {
        if (index >= count - 1) {
            popBack();
            return;
        }
        if (index <= 0) {
            popFront();
            return;
        }
        Node *p = start;
        while (--index) {
            p = p->next;
        }
        Node *aux = p->next;
        p->next = aux->next;
        delete(aux);
        count--;
    }

    void print() {
        Node *aux = start;
        while (aux != NULL) {
            printf("%d -> ", aux->value);
            aux = aux->next;
        }
    }

    // Exercícios

    void popBackToNumber(int n) {
        while (n--) {
            popBack();
        }
    }

    void removeSecondElement(int n) {
        if (n >= count) {
            while (popFront()) {}

            return;
        }
        Node *aux = start;
        for (int i = 0; i < count - n - 1; i++) {
            aux = aux->next;
        }
        end = aux;
        count -= n;
        while (n--) {
            Node *toDel = aux->next;
            aux->next = toDel->next;
            delete(toDel);
        }
    }

    void insertEnd() {
        pushBack(count);
    }

    void pushBackOneToNumber(int n) {
        for (int i = 1; i <= n; i++) {
            pushBack(i);
        }
    }

    void pushPenultimate(int value) {
        if (count <= 1) {
            return;
        }
        Node *aux = start;
        while (aux->next != end) {
            aux = aux->next;
        }
        Node *n = new Node(value);
        n->next = end;
        aux->next = n;
        count++;
    }
};

int main() {
    List l;
    l.pushFront(10);
    l.pushFront(3);
    l.pushBack(3);
    l.pushFront(8);
    l.pushBack(50);
    l.pushFront(78);
    l.pushBack(1);
    l.pushBack(75);
    l.pushFront(25);
    l.pushBack(60);
    l.pushFront(34);
    l.pushBack(80);
    l.pushBack(30);
    l.pushBack(23);
    l.pushFront(5);
    l.pushFront(66);
    l.popFront();
    l.popFront();
    l.popBack();
    // l.remove(2);
    // l.insert(3, 5);
    // l.popBackToNumber(3);
    // l.removeSecondElement(2);
    // l.insertEnd();
    // l.pushBackOneToNumber(3);
    // l.pushPenultimate(100);
    l.print();
}

// popBackToNumber(3):
// 34 -> 25 -> 78 -> 5 -> 8 -> 3 -> 10 -> 3 -> 50 -> 1 -> 75 -> 60 -> 80 -> 30 ->
// 34 -> 25 -> 78 -> 5 -> 8 -> 3 -> 10 -> 3 -> 50 -> 1 -> 75 ->

// removeSecondElement(2):
// 34 -> 25 -> 78 -> 5 -> 8 -> 3 -> 10 -> 3 -> 50 -> 1 -> 75 ->
// 34 -> 25 -> 78 -> 5 -> 8 -> 3 -> 10 -> 3 -> 75 ->

// insertEnd:
// 34 -> 25 -> 78 -> 5 -> 8 -> 3 -> 10 -> 3 -> 50 -> 1 -> 75 -> 60 -> 80 -> 30 -> 13 ->

// pushBackOneToNumber(3):
// 34 -> 25 -> 78 -> 5 -> 8 -> 3 -> 10 -> 3 -> 50 -> 1 -> 75 -> 60 -> 80 -> 30 -> 1 -> 2 -> 3 ->

// pushPenultimate(100):
// 34 -> 25 -> 78 -> 5 -> 8 -> 3 -> 10 -> 3 -> 50 -> 1 -> 75 -> 60 -> 80 -> 100 -> 30 ->
