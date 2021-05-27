#include <stdio.h>
#include <stdlib.h>
#include "lib/queue.h"
#include "lib/hamilton.h"

void delFilm();
void dataPelanggan();

int main(){
    int ch, i = 1, film;
    queue *q;
    q = malloc(sizeof(queue));
    initialize(q);
    do{
        system("cls");
        puts("================================");
        puts("           BIOSKOP XIX          ");
        puts("================================");
        puts("        1. MASUKKAN FILM        ");
        puts("        2. PESAN TIKET          ");
        puts("        3. DATA MEMBER          ");
        puts("        0. EXIT                 ");
        puts("================================");

        printf("\nMasukkan Pilihan : ");scanf("%d", &ch);
        switch (ch){
            case 1:
                system("cls");
                char film[100];
                int chn;

                if(i == 5){
                    puts("Film sudah Full");
                    display(q->front);
                    puts("Ketik 1 untuk HAPUS SEMUA");
                    puts("Ketik 0 untuk BATALKAN");
                    scanf("%d", &chn);
                    if (chn == 1)
                    {
                        for (int j = 1; j <= i; j++)
                        {
                            dequeue(q);
                        }
                    }
                    else if (chn == 0)
                    {
                        break;
                    }
                    else
                    {
                        printf("Angka yang anda masukkan salah");
                    }
                }else{
                    puts("Insert");
                    puts("*Catatan perhari hanya bisa memasukkan maximal 5 film\n");
                    system("pause");
                    system("cls");
                    for (i; i <= 5; i++)
                    {
                        printf("Judul Film: ");
                        fflush(stdin);
                        gets(film);
                        enqueue(q, film);
                        puts("\nKetik 1 untuk LANJUT");
                        puts("Ketik 0 untuk STOP");
                        printf("PILIH: ");
                        scanf("%d", &chn);
                        if (chn == 0)
                        {
                            break;
                        }
                        system("cls");
                    }
                    system("cls");
                    puts("Film yang dimasukkan");
                    display(q->front);
                    system("pause");
                    system("cls");
                }
                break;
            case 2:
                display(q->front);
                printf("PILIH: ");
                scanf("%d", &film);
                system("cls");
                
                // scanf();
            break;
            case 3:
                dataPelanggan();
            break;
            
            default:
            break;
        }
    }while(ch != 0);
}

void delFilm(){

}


void dataPelanggan(){
    int ch;
    do{
        puts("================================");
        puts("         Data Pelanggan         ");
        puts("================================");
        puts("        1. Tampilkan Semua      ");
        puts("        2. Cari Data            ");
        puts("================================");
        
        printf("\nMasukkan Pilihan : ");
        scanf("%d", &ch);
        switch (ch){
        case 1:
            printf("Tampilkan Semua");
            break;
        case 2:
            printf("Find");
            break;

        default:
            break;
        }
    }while(ch != 0);
}