#include <stdio.h>
#define NUM_ITEMS 10

void PrintDatabase();
void Pengeluaran();

int main () {
    //DATABASE DUMMY//
    float modalawal = 1000000.0; //sejuta?
    float totalpemasukkan = 0;
    float totalpengeluaran = 0;


    //MAIN PROGRAM//
    int option;
    printf("--JUDUL PROGRAM--\n");
    printf("1. Pemasukkan\n");
    printf("2. Pengeluaran\n");
    printf("3. Exit\n");
    scanf("%d", &option);

    switch(option) {
        case 1:
            void Pemasukan();
            break;
        case 2:
            void Pengeluaran();


    }
};


    //nanti maunya ada pilihan dulu munculin list, dllnya ya?
    //nanti kalo misal di function perlu buat display list barang :
typedef struct Item{
        char name[30];
        int stock;
        float price;
        float hargaJual;
        float hargaModal;
    } Item;

void InitializeDatabase(Item *barangdummy) {
    Item items[NUM_ITEMS] = { //sesuai num of items diatas
        {"Garam", 10, 3000.0, 5000.0, 0}, // angka pertama itu harga modal, yg kedua harga jual, terus gw pakein 0 buat stop. [jadi yg diatas kayaknya price perlu dua versi : hargaJual sama hargaModal]
        {"Kopi", 10, 6500.0, 8000.0, 0},
        {"Teh", 10, 6000.0, 7500.0, 0},
        {"Beras", 10, 11500.0, 13000.0, 0},
        {"Telur", 10, 2000.0, 3000.0, 0},
        {"Tepung", 10, 8000.0, 10000.0, 0},
        {"Mie", 10, 2500.0, 3500.0, 0},
        {"Permen", 10, 8000.0, 10000.0, 0},
        {"Ayam Mentah", 10, 20000.0, 25000.0, 0},
        {"Susu", 10, 30000.0, 35000.0, 0} ///10 doang, minimarket versi lite
    } 
};

void PrintDatabase(){
    printf("\nItem Database:\n");//RECORD
    for (int i = 0; i < NUM_ITEMS; i++) {
        printf("\n%d. %s - Harga Jual: %.2f", i+1, items[i].name, items[i].hargaJual);
    }

    printf("\nItem Database:\n");
    for (int i = 0; i < NUM_ITEMS; i++) {//RESTOCK
        printf("\n%d. %s - Harga Modal: %.2f", i+1, items[i].name, items[i].hargaModal);
    }
}


void Pengeluaran(){
//Restocking Hafiz
    int pilihan;
    float modalAwal;

    int MenuTampilan();
    printf("Choose: ");
    scanf("%d", &pilihan);

    switch (pilihan) {
        case 1:
            ItemTampil(items);
            break;
        case 2:
            RestockBarang(items);
            break;
        case 3:
            TampilkanModal(items, modalAwal);
            break;
        case 4:
            return 0;
        default:
            printf("Pilihan tidak valid.\n");
        }

    typedef struct Item{
        char name [30];
        int stock;
        float price;
        float hargaJual;
        float hargaModal;
    } Item;

    void MenuTampilan(){ //Fungsi untuk menampilkan display untuk memilih kegiatan yang ingin dilakukan
        printf("1. Tampilkan item\n");
        printf("2. Restock barang\n");
        printf("3. Tampilkan modal\n");
        printf("4. Keluar\n");
        printf("Masukkan pilihan anda: ");
    }

    void ItemTampil(Item items[]) { //Fungsi untuk menampilkan item
        printf("\nItem Database:\n");
        for (int i = 0; i < NUM_ITEMS; i++) {
            printf("%d. %s - Harga Jual: %.2f - Stock: %d\n", i+1, items[i].name, items[i].hargaJual, items[i].stock);
        }
    }

    void RestockBarang(Item items[]) { //Fungsi untuk ngerestock barang
        int itemNumber, jumlah;
        printf("\nMasukkan nomor item yang ingin direstock: ");
        scanf("%d", &itemNumber);
        printf("Masukkan jumlah restock untuk %s: ", items[itemNumber-1].name);
        scanf("%d", &jumlah);
        items[itemNumber-1].stock += jumlah;
        printf("Stock %s sekarang: %d\n", items[itemNumber-1].name, items[itemNumber-1].stock);
    }

    void TampilkanModal(Item items[], float modalAwal) { //Fungsi buat nampilin modal
        float totalPengeluaran = 0;
        for (int i = 0; i < NUM_ITEMS; i++) {
            totalPengeluaran += items[i].stock * items[i].hargaModal;
        }
        float totalModal = modalAwal - totalPengeluaran;
        printf("\nTotal modal yang tersisa: %.2f\n", totalModal);
    }
}

///INI BELUM SELESAI RAAHHHHHHHHHHH///
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
    inputData(barang, n, Database);
    InitializeDatabase(&barangdummy);

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

void inputData(DataBarang *barang, int jumlah_tipebarang, Database) {
    printf("Masukkan tanggal pembelian: ");
    fgets(barang[0].tanggal, BUFFER_SIZE, stdin);
    barang[0].tanggal[strcspn(barang[0].tanggal, "\n")] = '\0';

    printf("Masukkan nomor barang: ");
    scanf("%d", &Database.items[]);
    
    printf("Masukkan jumlah barang: ");
    scanf("%d", &(barang.jumlah));

    printf("Masukkan harga barang: ");
    scanf("%d", &(barang.harga));

    barang[i].total_harga = barang[i].jumlah * barang[i].harga;
    getchar();
    printf("\n");
}


