#include <stdio.h>
#define NUM_ITEMS 10

//enih bagian restocking punya hapis

typedef struct Item{
    char name [30];
    int stock;
    float price;
};

void MenuTampilan(){ //Fungsi untuk menampilkan display untuk memilih kegiatan yang ingin dilakukan
    printf("1. Tampilkan item\n");
    printf("2. Restock barang\n");
    printf("3. Tampilkan modal\n");
    printf("4. Keluar\n");
    printf("Masukkan pilihan anda: ");
}

void ItemTampil(Item items[]{  //Fungsi pertama, untuk menampilkan item yang ada  

}
