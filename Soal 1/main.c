#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAKSIMALBOLA 30
#define MAKSIMALKAPASITAS 10

int main() {
    int tabungGanjil[MAKSIMALKAPASITAS]; // Tabung pertama berfungsi untuk bola bernomor ganjil
    int tabungGenap[MAKSIMALKAPASITAS]; // Tabung kedua berfungsi untuk bola bernomor genap
    int oddCount = 0; // Adalah jumlah bola di tabung ganjil
    int evenCount = 0; // Adalah jumlah bola di tabung genap
    int bola[MAKSIMALBOLA]; // Array untuk menyimpan nomor bola
    char input[100]; // Untuk menyimpan input dari pengguna

    // Menginputkan nomor-nomor bola
    printf("Inputkan nomor bola (1-100) sebanyak 30, dipisahkan oleh spasi:\n");
    fgets(input, sizeof(input), stdin);

    // Memisahkan input yang dipisahkan menggunakan spasi menjadi angka-angka yang sendiri
    char *token = strtok(input, " ");
    int index = 0;
    while (token != NULL) {
        bola[index++] = atoi(token);
        token = strtok(NULL, " ");
    }

    // Perulangan untuk memproses dan menyimpan bola ke dalam tabung
    for (int i = 0; i < index; i++) {
        if (bola[i] == 0) {
            // Jika terdapat bola dengan nomor 0, maka tidak boleh disimpan
            continue;
        }
        if (bola[i] % 2 == 1 && oddCount < MAKSIMALKAPASITAS) {
            // Bola bernomor ganjil disimpan di tabung pertama
            tabungGanjil[oddCount] = bola[i];
            oddCount++;
        } else if (bola[i] % 2 == 0 && evenCount < MAKSIMALKAPASITAS) {
            // Bola bernomor genap disimpan di tabung kedua
            tabungGenap[evenCount] = bola[i];
            evenCount++;
        }
        // Jika salah satu tabung sudah penuh, bola-bola tersisa tidak boleh disimpan
        if (oddCount == MAKSIMALKAPASITAS && evenCount == MAKSIMALKAPASITAS) {
            break;
        }
    }

    // Menampilkan isi tabung pertama (bola ganjil)
    printf("\nOutput : \n");
    printf("Isi tabung pertama:\n");
    for (int i = 0; i < oddCount; i++) {
        printf("%d ", tabungGanjil[i]);
    }
    // Menjumlahkan angka-angka bola yang tersimpan di tabung pertama
    int oddSum = 0;
    for (int i = 0; i < oddCount; i++) {
        oddSum += tabungGanjil[i];
    }
    // Menampilkan jumlah angka yang ada di tabung pertama
    printf("Jumlah nomor bola di tabung pertama: %d\n", oddSum);

    // Menampilkan isi tabung kedua (bola genap)
    printf("Isi tabung kedua:\n");
    for (int i = 0; i < evenCount; i++) {
        printf("%d ", tabungGenap[i]);
    }
    // Menjumlahkan nomor bola yang tersimpan di tabung kedua
    int evenSum = 0;
    for (int i = 0; i < evenCount; i++) {
        evenSum += tabungGenap[i];
    }
    // Menampilkan jumlah angka yang ada di tabung kedua
    printf("Jumlah nomor bola di tabung kedua: %d\n", evenSum);

    return 0;
}
