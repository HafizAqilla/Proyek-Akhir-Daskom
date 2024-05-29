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

    //Tampilan database
    void PrintDatabase();

    // Input data pemasukan
    inputData(barang, n);

    // Output data pemasukan
    printf("--DATA PEMASUKAN %s--\n", barang[0].tanggal);
    for (int i = 0; i < n; i++) {
        printf("Nomor Barang: %d", barang[i].nama);
        printf("Jumlah Barang: %d\n", barang[i].jumlah);
        printf("Harga Barang: %d\n", barang[i].harga);
        printf("Total Harga Barang: %d\n", barang[i].total_harga);
        printf("\n");
    }

    free(barang);

    return 0;
}

void inputData(DataBarang *barang, int jumlah_tipebarang) {
    InitializeDatabase(&barangdummy);
    printf("Masukkan tanggal pembelian: ");
    fgets(barang[0].tanggal, BUFFER_SIZE, stdin);
    barang[0].tanggal[strcspn(barang[0].tanggal, "\n")] = '\0';

    printf("Masukkan nomor barang: ");
    scanf("%d", &barangdummy.items[]);
    
    printf("Masukkan jumlah barang: ");
    scanf("%d", &barang.jumlah);

    printf("Masukkan harga barang: ");
    scanf("%d", &barang.harga);

    barang[i].total_harga = barang[i].jumlah * barang[i].harga;
    getchar();
    printf("\n");
}
