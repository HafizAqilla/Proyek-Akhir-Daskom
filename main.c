#include <stdio.h>
#define NUM_ITEMS 10

//Restocking Hafiz

typedef struct Item{
    char name [30];
    int stock;
    float price;
    float hargaJual;
    float hargaModal;
} Item;

void MenuTampilan(){ //Fungsi untuk menampilkan display untuk memilih kegiatan yang ingin dilakukan
    int pilihan;
    printf("1. Tampilkan item\n");
    printf("2. Restock barang\n");
    printf("3. Tampilkan modal\n");
    printf("4. Keluar\n");
    printf("Masukkan pilihan anda: ");
    scanf("%d, pilihan");
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



// NAI DATABASE
// definenya mau pake buffer size atau num item? 
//nama structnya apa? Item? Iya, pake struct item ya samain dengan yang di atas
int main () {
    Item items[NUM_ITEMS] ={ //sesuai num of items diatas
        {"Garam", 3000.0, 5000.0, 0}, // angka pertama itu harga modal, yg kedua harga jual, terus gw pakein 0 buat stop. [jadi yg diatas kayaknya price perlu dua versi : hargaJual sama hargaModal]
        {"Kopi", 6500.0, 8000.0, 0},
        {"Teh", 6000.0, 7500.0, 0},
        {"Beras", 11500.0, 13000.0, 0},
        {"Telur", 2000.0, 3000.0, 0},
        {"Tepung", 8000.0, 10000.0, 0},
        {"Mie", 2500.0, 3500.0, 0},
        {"Permen", 8000.0, 10000.0, 0},
        {"Ayam Mentah", 20000.0, 25000.0, 0},
        {"Susu", 30000.0, 35000.0, 0} ///10 doang, minimarket versi lite
    };

    float modalawal = 1000000.0; //sejuta?
    float totalpemasukkan = 0;
    float totalpengeluaran = 0;

    //nanti maunya ada pilihan dulu munculin list, dllnya ya?
    //nanti kalo misal di function perlu buat display list barang :
    printf("\nItem Database:\n");//RECORD
    for (int i = 0; i < NUM_ITEMS; i++) {
        printf("\n%d. %s - Harga Jual: %.2f", i+1, items[i].name, items[i].hargaJual);
    }

    printf("\nItem Database:\n");
    for (int i = 0; i < NUM_ITEMS; i++) {//RESTOCK
        printf("\n%d. %s - Harga Modal: %.2f", i+1, items[i].name, items[i].hargaModal);
    }
        int pilihan;
        float modalAwal;

        int MenuTampilan();
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







    
