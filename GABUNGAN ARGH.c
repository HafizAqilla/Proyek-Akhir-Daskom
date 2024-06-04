#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM_ITEMS 10
#define BUFFER_SIZE 50

// MAIN PROBLEM RN
// belum ada tampilan profit/defisit
// 

// OPTIONAL PROBLEM
// rapihin tampilan program: 
// database bikin tabel

// STRUCT ITEMS FOR ALL //
typedef struct Item{
    char name[30];
    int stock;
    float hargaMarket;
    float hargaJual;
    float hargaModal;
} Item;
// STRUCT ITEMS SELESAI //


// FUNCTION DECLARATION MULAI DISINI //
void ItemTampil(Item *barangdummy);
void RestockBarang(Item *barangdummy, float *modalAwal);
void TampilkanModal(Item *barangdummy, float *modalAwal);
void PembelianBarang(Item *barangdummy, float *modalAwal);
void UbahHarga(Item *barangdummy);


// DATABASE DUMMY //
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

int main () {
//LOGIN FUNCTION
    char name[20];
    char password[10];
    do{
        printf("Enter username: ");
        scanf("%s", name);
        printf("Enter password: ");
        scanf("%s", password);

        if (strcmp(name, "Admin") == 0 && strcmp(password, "pass") == 0) {
            printf("Akses diberikan \n");
            break; 
        } else {
            printf("Coba lagi.\n");
        }
    } while (1); 


    float modalawal = 1000000.0; 
    float totalpemasukkan = 0;
    int pilihan_main;
    int pilihan_pengeluaran;
    int pilihan_pemasukan;
    int n;

    Item *barangdummy = (Item *)malloc(n * sizeof(Item));


// MAIN LOOP //
    while (1) {
        printf("\n--JUDUL PROGRAM--\n");
        printf("1. Pemasukkan\n");
        printf("2. Pengeluaran\n");
        printf("3. Exit\n");
        printf("Masukkan pilihan anda: ");
        scanf("%d", &pilihan_main);

        switch(pilihan_main) {
            case 1:
                while(1) {
                    printf("\n--MENU PEMASUKAN--\n");
                    printf("1. Tampilkan item\n");
                    printf("2. Jurnal Pembelian\n");
                    printf("3. Tampilkan modal\n");
                    printf("4. Ubah harga jual barang\n");
                    printf("5. Kembali ke menu utama\n");
                    printf("Masukkan pilihan anda: ");
                    scanf("%d", &pilihan_pemasukan);

                    switch (pilihan_pemasukan) {
                        case 1:
                            ItemTampil(items);
                            break;
                        case 2:
                            PembelianBarang(items, &modalawal);
                            break;
                        case 3:
                            TampilkanModal(items, &modalawal);
                            break;
                        case 4:
                            UbahHarga(items);
                            break;
                        case 5:
                            printf("Kembali ke menu utama...\n");
                            goto loop_main;
                        default:
                            printf("Pilihan tidak valid.\n");
                            break;
                    } 
                }
            case 2:
                while (1) {
                    printf("\n--MENU PENGELUARAN--\n");
                    printf("1. Tampilkan item\n");
                    printf("2. Restock barang\n");
                    printf("3. Tampilkan modal\n");
                    printf("4. Ubah harga jual barang\n");
                    printf("5. Kembali ke menu utama\n");
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
                            TampilkanModal(items, &modalawal);
                            break;
                        case 4:
                            UbahHarga(items);
                            break;
                        case 5:
                            printf("\nKembali ke menu utama...\n");
                            goto loop_main;
                        default:
                            printf("Pilihan tidak valid.\n");
                            break;
                    }
                }
            case 3:
                printf("Keluar...\n");
                return 0;
            default:
                printf("Pilihan tidak valid.\n");
        }
        loop_main:;
    }
    free(barangdummy);
    return 0;
}


void ItemTampil(Item *barangdummy) { // Fungsi untuk menampilkan item
    printf("\nItem Database:\n");
    printf("| %-3s | %-11s | %-12s | %-10s | %-9s |\n", "No. ", "Nama Barang", "Harga Market", "Harga Jual", "Stock Barang");
    for (int i = 0; i < NUM_ITEMS; i++) {
        printf("| %-3d | %-11s | %-12.0f | %-10.0f | %-9d |\n", i+1, barangdummy[i].name, barangdummy[i].hargaMarket, barangdummy[i].hargaJual, barangdummy[i].stock);
    }
}


void RestockBarang(Item *barangdummy, float *modalAwal) {
    int itemNumber, jumlah, exitloop = 1;
    printf("\nItem Database:\n");
    printf("| %-3s | %-11s | %-12s | %-10s | %-9s |\n", "No. ", "Nama Barang", "Harga Market", "Harga Jual", "Stock Barang");
    for (int i = 0; i < NUM_ITEMS; i++) {
        printf("| %-3d | %-11s | %-12.0f | %-10.0f | %-9d |\n", i+1, barangdummy[i].name, barangdummy[i].hargaMarket, barangdummy[i].hargaJual, barangdummy[i].stock);
    }

    while (exitloop != 0) {
        printf("\nKetik 0 untuk kembali ke menu pengeluaran..");
        printf("\nKetik 1 untuk melanjutkan: ");
        scanf("%d", &exitloop);
        if (exitloop == 0) {
            printf("\nKembali ke menu pengeluaran...\n");
            break;
        }
        printf("Masukkan nomor item yang ingin direstock: ");
        scanf("%d", &itemNumber);
        printf("Masukkan jumlah restock untuk %s: ", barangdummy[itemNumber - 1].name);
        scanf("%d", &jumlah);

        float totalHarga = jumlah * barangdummy[itemNumber - 1].hargaMarket;
        if (*modalAwal >= totalHarga) {
            barangdummy[itemNumber - 1].stock += jumlah;
            printf("Stock %s sekarang: %d\n", barangdummy[itemNumber - 1].name, barangdummy[itemNumber - 1].stock);
            *modalAwal -= totalHarga;
            printf("Modal tersisa: %.0f\n", *modalAwal);
        } else {
            printf("Modal tidak cukup untuk restock %s!\n", barangdummy[itemNumber - 1].name);
            continue;
        }
    }
}

void TampilkanModal(Item *barangdummy, float *modalAwal) { // Fungsi untuk menampilkan modal
    printf("\nTotal modal yang tersisa: %.0f\n", *modalAwal);
}


void PembelianBarang(Item *barangdummy, float *modalAwal) { // Fungsi untuk mencatat pemasukan
    int itemNumber, jumlah, totalmasuk, exitloop = 1;
    printf("\nItem Database:\n");
    printf("| %-3s | %-11s | %-12s | %-10s | %-9s |\n", "No. ", "Nama Barang", "Harga Market", "Harga Jual", "Stock Barang");
    for (int i = 0; i < NUM_ITEMS; i++) {
        printf("| %-3d | %-11s | %-12.0f | %-10.0f | %-9d |\n", i+1, barangdummy[i].name, barangdummy[i].hargaMarket, barangdummy[i].hargaJual, barangdummy[i].stock);
    }

    while (exitloop != 0) {
        printf("\nKetik 0 untuk kembali ke menu pemasukkan...");
        printf("\nKetik 1 untuk melanjutkan: ");
        scanf("%d", &exitloop);
        if (exitloop == 0) {
            printf("\nKembali ke menu pemasukkan...\n");
            break;
        }
        printf("Masukkan nomor item yang terbeli: ");
        scanf("%d", &itemNumber);
        printf("Masukkan jumlah %s yang terbeli: ", barangdummy[itemNumber - 1].name);
        scanf("%d", &jumlah);
        float totalHarga = jumlah * barangdummy[itemNumber-1].hargaJual;

        if (jumlah <= barangdummy[itemNumber-1].stock) {
            barangdummy[itemNumber-1].stock -= jumlah;
            *modalAwal += totalHarga;
            printf("Stock %s sekarang: %d\n", barangdummy[itemNumber-1].name, barangdummy[itemNumber-1].stock);
            printf("Modal tersisa: %.0f\n", *modalAwal);
        } else {
            printf("Stock %s sudah habis! \n", barangdummy[itemNumber-1].name);
            continue;
        }
    }
}


void UbahHarga(Item *barangdummy) { //Fungsi untuk mengubah harga jual
    int exitloop = 1, itemNumber;
    float ubahharga;
    printf("\nItem Database:\n");
    printf("| %-3s | %-11s | %-12s | %-10s | %-9s |\n", "No. ", "Nama Barang", "Harga Market", "Harga Jual", "Stock Barang");
    for (int i = 0; i < NUM_ITEMS; i++) {
        printf("| %-3d | %-11s | %-12.0f | %-10.0f | %-9d |\n", i+1, barangdummy[i].name, barangdummy[i].hargaMarket, barangdummy[i].hargaJual, barangdummy[i].stock);
    }

    while(exitloop != 0) {
        printf("\nKetik 0 untuk kembali ke menu sebelumnya...");
        printf("\nKetik 1 untuk melanjutkan: ");
        scanf("%d", &exitloop);
        if (exitloop == 0) {
            printf("\nKembali...\n");
            break;
        }
        printf("Masukkan nomor item yang ingin diubah: ");
        scanf("%d", &itemNumber);
        printf("Masukkan perubahan harga untuk %s: ", barangdummy[itemNumber -1].name);
        scanf("%f", &ubahharga);
        printf("Harga %s sebelumnya: %.0f\n", barangdummy[itemNumber-1].name, barangdummy[itemNumber - 1].hargaJual);
        barangdummy[itemNumber - 1].hargaJual = ubahharga;
        printf("Harga %s sekarang: %.0f\n", barangdummy[itemNumber - 1].name, barangdummy[itemNumber - 1].hargaJual);
    }

}