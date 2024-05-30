#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM_ITEMS 10
#define BUFFER_SIZE 50

//STRUCT ITEMS FOR ALL//
typedef struct Item{
        char name[30];
        int stock;
        float price;
        float hargaJual;
        float hargaModal;
    } Item;
//STRUCT ITEMS SELESAI//


//FUNCTION DECLARATION MULAI DISINI//
void ItemTampil(Item *barangdummy);
void RestockBarang(Item *barangdummy);
void TampilkanModal(Item *barangdummy, float modalAwal);




//FUNCTION DECLARATION SELESAI//


//DATABASE DUMMY//
Item items[NUM_ITEMS] = { //sesuai num of items diatas
        {"Garam", 10, 3000.0, 5000.0, 0},
        {"Kopi", 10, 6500.0, 8000.0, 0},
        {"Teh", 10, 6000.0, 7500.0, 0},
        {"Beras", 10, 11500.0, 13000.0, 0},
        {"Telur", 10, 2000.0, 3000.0, 0},
        {"Tepung", 10, 8000.0, 10000.0, 0},
        {"Mie", 10, 2500.0, 3500.0, 0},
        {"Permen", 10, 8000.0, 10000.0, 0},
        {"Ayam Mentah", 10, 20000.0, 25000.0, 0},
        {"Susu", 10, 30000.0, 35000.0, 0}}; ///10 doang, minimarket versi lite
//DATABASE DUMMY SELESAI//

int main () {
    float modalawal = 1000000.0; //sejuta?
    float totalpemasukkan = 0;
    float totalpengeluaran = 0;
    int pilihan_main;
    int pilihan_pengeluaran;
    int pilihan_pemasukan;

    //MAIN OPTION//
    printf("--JUDUL PROGRAM--\n");
    printf("1. Pemasukkan\n");
    printf("2. Pengeluaran\n");
    printf("3. Exit\n");
    printf("Masukkan pilihan anda: ");
    scanf("%d", &pilihan_main);

    switch(pilihan_main) {
        case 1:
            printf("P");
            //Pemasukan();//BELOM SELESAI//
            break;
        case 2:
            //OPSI PENGELUARAN//
            printf("\n--MENU PENGELUARAN--\n");
            printf("1. Tampilkan item\n");
            printf("2. Restock barang\n");
            printf("3. Tampilkan modal\n");
            printf("4. Keluar\n");
            printf("Masukkan pilihan anda: ");
            scanf("%d", &pilihan_pemasukan);

            switch (pilihan_pengeluaran) {
                case 1:
                    ItemTampil(items);
                    break;
                case 2:
                    RestockBarang(items);
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
            break;
        default:
            printf("Pilihan tidak valid.\n");
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

void RestockBarang(Item *barangdummy) { // Fungsi untuk merestock barang
    int itemNumber, jumlah;
    printf("\nMasukkan nomor item yang ingin direstock: ");
    scanf("%d", &itemNumber);
    printf("Masukkan jumlah restock untuk %s: ", barangdummy[itemNumber-1].name);
    scanf("%d", &jumlah);
    barangdummy[itemNumber-1].stock += jumlah;
    printf("Stock %s sekarang: %d\n", barangdummy[itemNumber-1].name, barangdummy[itemNumber-1].stock);
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