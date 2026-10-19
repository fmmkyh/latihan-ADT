/* Program   : mtqueue3.c */
/* Deskripsi : file DRIVER modul queue */
/* Nama      : @fmmkyh */
/* Tanggal   : 29/09/2026 */
/***********************************/

#include <stdio.h>
#include "tqueue3.h"

int main(){
    /* Kamus */
	tqueue3 A;
    int a;
    char e, b;
    int N;
    int choice;

    /* Algoritma */
	printf("-------ADT QUEUE 3------\n");

    printf("----- createQueue3 -----\n");
    createQueue3(&A);
    printf("createQueue3 A: ");
    printQueue3(A);

    printf("Apakah A kosong?");
    if (isEmptyQueue3(A)) {
        printf(" Ya\n");
    } else {
        printf(" Tidak\n");
    }
    printf("Apakah A penuh?");
    if (isFullQueue3(A)) {
        printf(" Ya\n");
    } else {
        printf(" Tidak\n");
    }

    printf("\n----- PILIH OPERATOR QUEUE -----\n");
    printf("1. Enqueue3\n");
    printf("2. Dequeue3\n");
    printf("3. Evaluasi Isi Queue\n");
    printf("4. Keluar Program\n");
    printf("--------------------------\n");
    printf("Pilihan: ");
    scanf("%d", &choice);
    
    while (choice != 4) {
        switch (choice) {
            case 1:
                printf("\n----- enqueue3 -----\n");
                printf("Masukkan jumlah elemen yang ingin ditambahkan: ");
                scanf("%d", &N);
                for (a = 1; a <= N; a++){
                    printf("Masukkan elemen ke-%d: ", a);
                    scanf(" %c", &e);
                    enqueue3(&A, e);
                }

                printf("\n--- -Print enqueue3 A ---- \n");
                printQueue3(A);
                printf("\n---- View enqueue3 A ----: \n");
                viewQueue3(A);
                break;

            case 2:
                printf("\n----- dequeue3 -----\n");
                printf("Masukkan jumlah elemen yang ingin dihapus: ");
                scanf("%d", &N);
                for (a = 1; a <= N; a++){
                    dequeue3(&A, &b);
                    printf("Elemen ke-%d yang dihapus: %c\n", a, b);
                }

                printf("\n--- -Print dequeue3 A ---- \n");
                printQueue3(A);
                printf("\n---- View dequeue3 A ----: \n");
                viewQueue3(A);
                break;

            case 3:
                printf("\n--- Evaluasi Isi Queue A ---- \n");
                printf("Apakah A kosong?");
                if (isEmptyQueue3(A)) {
                    printf(" Ya\n");
                } else {
                    printf(" Tidak\n");
                }
                printf("Apakah A penuh?");
                if (isFullQueue3(A)) {
                    printf(" Ya\n");
                } else {
                    printf(" Tidak\n");
                }
                printf("Apakah A 1 elemen?");
                if (isOneElement3(A)) {
                    printf(" Ya\n");
                } else {
                    printf(" Tidak\n");
                }

                printf("\nPanjang antrian A: %d", sizeQueue3(A));
                printf("\nPosisi head A: %d", head3(A));
                printf("  Elemennya: %c", infoHead3(A));
                printf("\nPosisi tail A: %d", tail3(A));
                printf("  Elemennya: %c", infoTail3(A));

                printf("\nApa posisi tail berada di depan head? ");
                if (isTailOverHead(A)) {
                    printf(" Ya\n");
                } else {
                    printf(" Tidak\n");
                }

            default:
                printf("Pilihan tidak valid.\n");
        }

        printf("\n\n----- PILIH OPERATOR QUEUE -----\n");
        printf("1. Enqueue3\n");
        printf("2. Dequeue3\n");
        printf("3. Evaluasi Isi Queue\n");
        printf("4. Keluar Program\n");
        printf("--------------------------\n");
        printf("Pilihan: ");
        scanf("%d", &choice);
    }

    printf("\n--- Pengujian ADT Selesai ---\n");
    return 0;
}