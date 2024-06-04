#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM_ITEMS 10
#define BUFFER_SIZE 50

//MAIN PROBLEM RN
//belum ada pemasukan
//belum ada looping
//belum tau gimana hubungin stock barang dummy(tambah/kurang)
//belum ada tampilan profit/defisit
//pas restock/jurnaling kurang tampilan database
//(tambahin masalah disini)

//OPTIONAL PROBLEM
//rapihin tampilan program
//database bikin tabel
//daftar akun buat pemilik toko

//STRUCT ITEMS FOR ALL//
typedef struct Item{
    char name[30];
    int stock;
    float hargaMarket;
    float hargaJual;
    float hargaModal;
} Item;
//STRUCT ITEMS SELESAI//

//FUNCTION DECLARATION MULAI DISINI//
void ItemTampil(Item *barangdummy);
void RestockBarang(Item *barangdummy, float *modalAwal);
void TampilkanModal(Item *barangdummy, float modalAwal);
//FUNCTION DECLARATION SELESAI//

//DATABASE DUMMY//
Item items[NUM_ITEMS] = {
    {"Garam", 10, 3000.0, 5000.0, 0},
    {"Kopi", 10, 6500.0, 8000.0, 0},
    {"Teh", 10, 6000.0, 7500.0, 0},
    {"Beras", 10, 11500.0, 13000.0, 0},
    {"Telur", 10, 2000.0, 3000.0, 0},
    {"Tepung", 10, 8000.0, 10000.0, 0},
    {"Mie", 10, 2500.0, 3500.0, 0},
    {"Permen", 10, 8000.0, 10000.0, 0},
    {"Ayam Mentah", 10, 20000.0, 25000.0, 0},
    {"Susu", 10, 30000.0, 35000.0, 0}

};
//DATABASE DUMMY SELESAI//

int main () {
    float modalawal = 1000000.0; //sejuta?
    // float *modal = &modalawal;
    float totalpemasukkan = 0;
    float totalpengeluaran = 0;
    int pilihan_main;
    int pilihan_pengeluaran;
    int pilihan_pemasukan;

    //MAIN LOOP//
    while (1) {
        printf("\n--JUDUL PROGRAM--\n");
        printf("1. Pemasukkan\n");
        printf("2. Pengeluaran\n");
        printf("3. Exit\n");
        printf("Masukkan pilihan anda: ");
        scanf("%d", &pilihan_main);

        switch(pilihan_main) {
            case 1:
                printf("\n--MENU PEMASUKAN--\n");
                printf("1. Tampilkan item\n");
                printf("2. Jurnal Pembelian\n");
                printf("3. Tampilkan modal\n");
                printf("Masukkan pilihan anda: ");
                scanf("%d", &pilihan_pemasukan);

                switch (pilihan_pemasukan) {
                    case 1:
                        ItemTampil(items);
                        break;
                    case 2:
                        //JurnalKeuangan(items, modalawal);
                        break;
                    case 3:
                        TampilkanModal(items, modalawal);
                        break;
                    default:
                        printf("Pilihan tidak valid.\n");
                        break;
                }
                break;
            case 2:
                printf("\n--MENU PENGELUARAN--\n");
                printf("1. Tampilkan item\n");
                printf("2. Restock barang\n");
                printf("3. Tampilkan modal\n");
                printf("4. Keluar\n");
                printf("Masukkan pilihan anda: ");
                scanf("%d", &pilihan_pengeluaran);

                switch (pilihan_pengeluaran) {
                    case 1:
                        ItemTampil(items);
                        break;
                    case 2:
                        RestockBarang(items, &modalawal);
                        break;
                    case 3:
                        TampilkanModal(items, modalawal);
                        break;
                    case 4:
                        break;
                    default:
                        printf("Pilihan tidak valid.\n");
                }
                break;
            case 3:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Pilihan tidak valid.\n");
        }
    }    
    return 0;
}

//BAGIAN PENGELUARAN//
void ItemTampil(Item *barangdummy) { // Fungsi untuk menampilkan item
    printf("\nItem Database:\n");
    for (int i = 0; i < NUM_ITEMS; i++) {
        printf("%d. %s - Harga Jual: %.2f - Stock: %d\n", i+1, barangdummy[i].name, barangdummy[i].hargaJual, barangdummy[i].stock);
    }
}

void RestockBarang(Item *barangdummy, float *modalAwal) { // Fungsi untuk merestock barang
    int itemNumber, jumlah, exitloop;
    printf("\nItem Database:\n");
    printf("0. Exit Restock\n");
    for (int i = 0; i < NUM_ITEMS; i++) {
        printf("%d. %s - Harga Beli: %.2f\n", i+1, barangdummy[i].name, barangdummy[i].hargaMarket);
    }

    
    while (exitloop != 0) { //masalah//
        printf("\nKetik 1 untuk melanjutkan: ");
        scanf("%d", &exitloop);
        printf("Masukkan nomor item yang ingin direstock: ");
        scanf("%d", &itemNumber);
        printf("Masukkan jumlah restock untuk %s: ", barangdummy[itemNumber-1].name);
        scanf("%d", &jumlah);

        float totalHarga = jumlah * barangdummy[itemNumber-1].hargaMarket;
        if (*modalAwal >= totalHarga) {
        barangdummy[itemNumber-1].stock += jumlah; //menambahkan barang yang dibeli ke stock
        printf("Stock %s sekarang: %d\n", barangdummy[itemNumber-1].name, barangdummy[itemNumber-1].stock);
        *modalAwal -= totalHarga; //mengurangi modal dengan harga
        printf("Modal tersisa: %.2f\n", *modalAwal);
        } else {
        printf("Modal tidak cukup untuk restock %s\n", barangdummy[itemNumber-1].name);
        break;
        }
    }
}

void TampilkanModal(Item *barangdummy, float modalAwal) { // Fungsi untuk menampilkan modal
    float totalPengeluaran = 0;
    for (int i = 0; i < NUM_ITEMS; i++) {
        totalPengeluaran += barangdummy[i].stock * barangdummy[i].hargaModal;
    }
    float totalModal = modalAwal - totalPengeluaran;
    printf("\nTotal modal yang tersisa: %.2f\n", totalModal);
}
//BAGIAN PENGELUARAN SELESAI//

//BAGIAN PEMASUKAN//
