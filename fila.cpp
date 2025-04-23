// https://judge.beecrowd.com/pt/problems/view/1548

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int nota;
    Node *prox;

    Node(int nota) {
        this->nota = nota;
        prox = NULL;
    }
};

struct List {
    Node *head;

    List() {
        head = NULL;
    }

    void insFinal(int nota) {
        Node *n = new Node(nota);

        if (head == NULL) {
            head = n;
        } else {
            Node *aux = head;
            while (aux->prox != NULL) {
                aux = aux->prox;
            }
            aux->prox = n;
        }
    }

    void insOrdenado(int nota) {
        Node *n = new Node(nota);
        if (head == NULL || nota > head->nota) {
            n->prox = head;
            head = n;
        } else {
            Node *atual = head;
            while (atual->prox != NULL && atual->prox->nota >= nota) {
                atual = atual->prox;
            }
            n->prox = atual->prox;
            atual->prox = n;
        }
    }

    int contarIguais(Node *list) {
        int count = 0;
        Node *a = head;
        while (a && list) {
            if (a->nota == list->nota) {
                count++;
            }
            a = a->prox;
            list = list->prox;
        }
        return count;
    }
};

int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        int M;
        scanf("%d", &M);

        List *original = new List();
        List *ordenada = new List();

        for (int i = 0; i < M; i++) {
            int nota;
            scanf("%d", &nota);
            original->insFinal(nota);
            ordenada->insOrdenado(nota);
        }

        int count = original->contarIguais(ordenada->head);
        printf("-> %d\n", count);
    }

    return 0;
}
