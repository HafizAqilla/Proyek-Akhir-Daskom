#include <stdio.h>
#define NUM_ITEMS 10

typedef struct {
    char name[30];
    int stock;
    float hargaModal;
    float hargaJual;
} Item;

void MenuTampilan() {
    printf("1. Tampilkan item\n");
    printf("2. Restock barang\n");
    printf("3. Tampilkan modal\n");
    printf("4. Keluar\n");
    printf("Masukkan pilihan anda: ");
}

void ItemTampil(Item items[]) {
    printf("\nItem Database:\n");
    for (int i = 0; i < NUM_ITEMS; i++) {
        printf("%d. %s - Harga Jual: %.2f - Stock: %d\n", i+1, items[i].name, items[i].hargaJual, items[i].stock);
    }
}

void RestockBarang(Item items[]) {
    int itemNumber, jumlah;
    printf("\nMasukkan nomor item yang ingin direstock: ");
    scanf("%d", &itemNumber);
    printf("Masukkan jumlah restock untuk %s: ", items[itemNumber-1].name);
    scanf("%d", &jumlah);
    items[itemNumber-1].stock += jumlah;
    printf("Stock %s sekarang: %d\n", items[itemNumber-1].name, items[itemNumber-1].stock);
}

void TampilkanModal(Item items[], float modalAwal) {
    float totalPengeluaran = 0;
    for (int i = 0; i < NUM_ITEMS; i++) {
        totalPengeluaran += items[i].stock * items[i].hargaModal;
    }
    float totalModal = modalAwal - totalPengeluaran;
    printf("\nTotal modal yang tersisa: %.2f\n", totalModal);
}
