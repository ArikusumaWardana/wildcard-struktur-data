#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Deklarasi struct tnode
struct tnode {
    char nama[50];
    char nim[15];
    char prodi[20];
    char peran[20];
    struct tnode *next;
};

// Prosedur untuk menyisipkan node baru di akhir linked list
void SisipkanDiAkhir(struct tnode **head, struct tnode **tail, char nama[], char nim[], char prodi[], char peran[]) {
    struct tnode *newNode = (struct tnode *)malloc(sizeof(struct tnode));
    strcpy(newNode->nama, nama);
    strcpy(newNode->nim, nim);
    strcpy(newNode->prodi, prodi);
    strcpy(newNode->peran, peran);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = *tail = newNode;
    } else {
        (*tail)->next = newNode;
        *tail = newNode;
    }

    printf("\nMahasiswa berhasil dimasukan kedalam data!\n");
}

// Prosedur untuk mencetak daftar mahasiswa
void CetakDaftar(struct tnode *head) {
    struct tnode *curr = head;
    int i = 1;
    while (curr != NULL) {
        printf("%d. %s | %s | %s (%s)\n", i++, curr->nama, curr->nim, curr->prodi, curr->peran);
        curr = curr->next;
    }
}

// Prosedur untuk menghapus node dari linked list berdasarkan nama
void HapusMahasiswa(struct tnode **head, struct tnode **tail, char nama[]) {
    struct tnode *prev = NULL, *curr = *head;

    while (curr != NULL && strcmp(curr->nama, nama) != 0) {
        prev = curr;
        curr = curr->next;
    }

    if (curr != NULL) {
        if (prev == NULL) {
            *head = *tail = curr->next;
        } else {
            prev->next = curr->next;
            if (curr == *tail) {
                *tail = prev;
            }
        }
        free(curr);
    }

    printf("\nMahasiswa berhasil dihapus!\n");
}

// Prosedur untuk mengubah peran mahasiswa berdasarkan nama
void UbahPeran(struct tnode *head, char nama[], char peranBaru[]) {
    struct tnode *curr = head;

    while (curr != NULL && strcmp(curr->nama, nama) != 0) {
        curr = curr->next;
    }

    if (curr != NULL) {
        strcpy(curr->peran, peranBaru);
    }

    printf("\nMahasiswa berhasil diubah perannya!\n");
}

// Main program
int main() {
    struct tnode *head = NULL, *tail = NULL;
    int pilihan, i;
    char nama[50], nim[15], prodi[20], peran[20], peranBaru[20];
    char enter;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Tampilkan Daftar Mahasiswa\n");
        printf("2. Tambah Mahasiswa\n");
        printf("3. Ubah Peran Mahasiswa\n");
        printf("4. Hapus Mahasiswa\n");
        printf("5. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                CetakDaftar(head);

                printf("Tekan Enter untuk melanjutkan...");
                scanf("%c", &enter); // Mengonsumsi karakter newline sebelum menunggu enter
                scanf("%c", &enter); // Mengambil tombol enter
                break;
            case 2:
                printf("Masukkan nama: ");
                scanf(" %[^\n]", nama);
                printf("Masukkan NIM: ");
                scanf(" %[^\n]", nim);
                printf("Masukkan prodi: ");
                scanf(" %[^\n]", prodi);
                printf("Masukkan peran: ");
                scanf(" %[^\n]", peran);
                SisipkanDiAkhir(&head, &tail, nama, nim, prodi, peran);

                printf("Tekan Enter untuk melanjutkan...");
                scanf("%c", &enter); // Mengonsumsi karakter newline sebelum menunggu enter
                scanf("%c", &enter); // Mengambil tombol enter
                break;
            case 3:
                printf("Masukkan nama: ");
                scanf(" %[^\n]", nama);
                printf("Masukkan peran baru: ");
                scanf(" %[^\n]", peranBaru);
                UbahPeran(head, nama, peranBaru);

                printf("Tekan Enter untuk melanjutkan...");
                scanf("%c", &enter); // Mengonsumsi karakter newline sebelum menunggu enter
                scanf("%c", &enter); // Mengambil tombol enter
                break;
            case 4:
                printf("Masukkan nama: ");
                scanf(" %[^\n]", nama);
                HapusMahasiswa(&head, &tail, nama);

                printf("Tekan Enter untuk melanjutkan...");
                scanf("%c", &enter); // Mengonsumsi karakter newline sebelum menunggu enter
                scanf("%c", &enter); // Mengambil tombol enter
                break;
            case 5:
                return 0;
            default:
                printf("Pilihan tidak valid!\n");
        }



    }

    return 0;
}
