#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//PEMASUKAN DATA BARANG PUNYA KEI N SERE

#define BUFFER_SIZE 50

typedef struct DataBarang {
    int jumlah;
    char tanggal[BUFFER_SIZE];
    char nama[BUFFER_SIZE];
    int harga;
    int total_harga;
} DataBarang;

void inputData(DataBarang *barang, int jumlah_tipebarang);

int main(void) {
    int n;
    printf("--PEMASUKAN TOKO--\n");
    printf("Banyak jenis barang yang dibeli: ");
    scanf("%d", &n);
    getchar();

    DataBarang *barang = (DataBarang *)malloc(n * sizeof(DataBarang));

    // Input data pemasukan
    inputData(barang, n);

    // Output data pemasukan
    printf("--DATA PEMASUKAN %s--\n", barang[0].tanggal);
    for (int i = 0; i < n; i++) {
        printf("%d. ", i + 1);
        printf("Nama Barang: %s\n", barang[i].nama);
        printf("Jumlah Barang: %d\n", barang[i].jumlah);
        printf("Harga Barang: %d\n", barang[i].harga);
        printf("Total Harga Barang: %d\n", barang[i].total_harga);
        printf("\n");
    }

    free(barang);

    return 0;
}

void inputData(DataBarang *barang, int jumlah_tipebarang) {
    printf("Masukkan tanggal pembelian: ");
    fgets(barang[0].tanggal, BUFFER_SIZE, stdin);
    barang[0].tanggal[strcspn(barang[0].tanggal, "\n")] = '\0';

    for (int i = 0; i < jumlah_tipebarang; i++) {
        printf("%d. Masukkan nama barang: ", i + 1);
        fgets(barang[i].nama, BUFFER_SIZE, stdin);
        barang[i].nama[strcspn(barang[i].nama, "\n")] = '\0';

        printf("Masukkan jumlah barang: ");
        scanf("%d", &(barang[i].jumlah));

        printf("Masukkan harga barang: ");
        scanf("%d", &(barang[i].harga));

        barang[i].total_harga = barang[i].jumlah * barang[i].harga;
        getchar();
        printf("\n");
    }
}
