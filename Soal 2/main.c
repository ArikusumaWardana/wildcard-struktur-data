#include <stdio.h>
#include <stdlib.h>


// deklarasi struct tnode untuk menyimpan nilai integer
struct tnode {
    // menyimpan nilai integer
    int nilai;
    // pointer ke node selanjutnya
    struct tnode *selanjutnya;
};

// Fungsi untuk menyisipkan bilangan di akhir linked list
void insertLast(int bil, struct tnode **head, struct tnode **tail) {
    struct tnode *simpulBaru = (struct tnode *)malloc(sizeof(struct tnode));
    simpulBaru->nilai = bil;
    simpulBaru->selanjutnya = NULL;

    // jika linkedlist kosong
    if (*head == NULL) {
        // set head dan tail ke node baru
        *head = *tail = simpulBaru;
    } else {
        // set next node tail ke node baru
        (*tail)->selanjutnya = simpulBaru;

        // update tail ke node baru
        *tail = simpulBaru;
    }
}


// Fungsi untuk menyisipkan bilangan di awal linked list
void insertFirst(int bil, struct tnode **head, struct tnode **tail) {
    struct tnode *simpulBaru = (struct tnode *)malloc(sizeof(struct tnode));
    simpulBaru->nilai = bil;
    simpulBaru->selanjutnya = *head;

    // jika linkedlist kosong
    if (*head == NULL) {
        // set head dan tail ke node baru
        *head = *tail = simpulBaru;
    } else {
        // update head ke node baru
        *head = simpulBaru;
    }
}


// Mencetak nilai dari setiap node dalam linkedlist
void printLinkedList(struct tnode *head) {
    struct tnode *penunjuk = head;
    while (penunjuk != NULL) {
        printf("%d ", penunjuk->nilai);
        penunjuk = penunjuk->selanjutnya;
    }
    printf("\n");
}


int main() {
    struct tnode *head, *tail;
    head = NULL;
    tail = NULL;

    insertFirst(10, &head, &tail);
    insertFirst(20, &head, &tail);
    insertFirst(30, &head, &tail);

    insertLast(40, &head, &tail);
    insertLast(50, &head, &tail);
    insertLast(60, &head, &tail);

    // Menampilkan isi linked list
    printLinkedList(head);

    return 0;
}
