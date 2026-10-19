#ifndef  tqueue3_c
#define  tqueue3_c
/* Program   : tqueue3.c */
/* Deskripsi : file BODY modul queue */
/* Nama      : @fmmkyh */
/* Tanggal   : 29/09/2026 */
/***********************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "boolean.h"
#include "tqueue3.h"

/*function isEmptyQueue3(Q:tQueue3) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue3(tqueue3 Q) {
    /* Algoritma */
    return Q.head == 0 && Q.tail == 0;
}

/*function isFullQueue3(Q:tQueue3) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue3(tqueue3 Q) {
    /* Algoritma */
    return (tail3(Q) % 5) + 1 == head3(Q) || (sizeQueue3(Q) == 5);
}

/*function isOneElement3(Q:tQueue3) -> boolean
{mengembalikan true jika Q 1 elemen}*/
boolean isOneElement3(tqueue3 Q) {
    /* Algoritma */
    if (!isEmptyQueue3(Q)) {
        return head3(Q) == tail3(Q);
    } else {
        return false;
    }
}

/*procedure createQueue3 ( output Q:tQueue3)
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi komponen dengan 0, elemen kosong='#'}*/ 
void createQueue3(tqueue3 *Q) {
    /* Kamus Lokal */
    int i;
    /* Algoritma */
    (*Q).head = 0;
    (*Q).tail = 0;
    for (i = 1; i <= 5; i++) {
        (*Q).wadah[i] = '#';
    }
}

/*Function Head3(Q:tqueue3) -> integer
{mengembalikan posisi elemen terdepan} */
int head3(tqueue3 Q) {
    /* Algoritma */
    return Q.head;
}

/*Function Tail3(Q:tqueue3) -> integer
{mengembalikan posisi elemen terakhir} */
int tail3(tqueue3 Q) {
    /* Algoritma */
    return Q.tail;
}

/*Function InfoHead3(Q:tqueue3) -> character
{mengembalikan nilai elemen terdepan} */
char infoHead3(tqueue3 Q) {
    /* Algoritma */
    if (!isEmptyQueue3(Q)) {
        return Q.wadah[head3(Q)];
    }
    else {
        return 0;
    }
}

/*Function InfoTail3(Q:tqueue3) -> character
{mengembalikan nilai elemen terakhir} */
char infoTail3(tqueue3 Q) {
    /* Algoritma */
    if (!isEmptyQueue3(Q)) {
        return Q.wadah[tail3(Q)];
    }
    else {
        return 0;
    }
}

/*function sizeQueue3(Q:tQueue3)-> integer 
{mengembalikan panjang antrian Q} */
int sizeQueue3(tqueue3 Q) {
    /* Kamus Lokal */
    int i;
    /* Algoritma */
    if (isEmptyQueue3(Q)) {
        return 0;
    } else {
        return ((tail3(Q) - head3(Q) + 5) % 5) + 1;
    }
}

/*procedure printQueue3(input Q:tQueue3)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak isi wadah ke layar, berisi atau kosong}*/
void printQueue3(tqueue3 Q) {
    /* Kamus Lokal */
    int i;
    /* Algoritma */
    if (!isEmptyQueue3(Q)) {
        for (i = 1; i <= 5; i++) {
            printf("%c", Q.wadah[(Q.head + i - 2) % 5 + 1]);
            if (i < 5) {
                printf("; ");
            }
        }
    } else {
        printf("Queue Kosong.\n");
    }
}

/*procedure viewQueue3(input Q:tQueue3)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen yang tidak kosong ke layar}*/
void viewQueue3(tqueue3 Q) {
    /* Kamus Lokal */
    int i;
    /* Algoritma */
    if (!isEmptyQueue3(Q)) {
        for (i = 1; i <= sizeQueue3(Q); i++) {
            printf("%c", Q.wadah[(Q.head + i - 2) % 5 + 1]);
            if (i < sizeQueue3(Q)) {
                printf("; ");
            }
        }
    } else {
        printf("Queue Kosong.\n");
    }
}

/*procedure enQueue3( input/output Q:tQueue3, input E: character )
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q bertambah 1 bila belum penuh}
{proses: menambah elemen wadah Q sebagai tail, mungkin memutar ke 1 } */
void enqueue3(tqueue3 *Q, char E) {
    /* Kamus Lokal */
    int i;
    /* Algoritma */
    if (!isFullQueue3(*Q)) {
        if (isEmptyQueue3(*Q)) {
            (*Q).head = 1;
            (*Q).tail = 1;
        } else {
            (*Q).tail = ((*Q).tail % 5) + 1;
        }
        (*Q).wadah[(*Q).tail] = E;
    } else {
        printf("Queue Sudah Penuh.\n");
    } 
}
  
/*procedure deQueue3( input/output Q:tQueue3,output E: character )
{I.S.: }
{F.S.: elemen wadah Q berkurang 1 (Head), E=infohead(Q), bila kosong E=' '}
{proses: mengurangi elemen wadah Q, bila 1 elemen, maka Head dan Tail mengacu ke 0 } */
void dequeue3(tqueue3 *Q, char *E) {
    /* Kamus Lokal */
    int i;
    /* Algoritma */
    if (isEmptyQueue3(*Q)) {
        printf("Queue Sudah Kosong.\n");
    } else {
        *E = (*Q).wadah[(*Q).head];
        (*Q).wadah[(*Q).head] = '#';
        if (isOneElement3(*Q)) {
            (*Q).head = 0;
            (*Q).tail = 0;
        } else {
            (*Q).head = ((*Q).head % 5) + 1;
        }
    }
}

/*EKSTRA: kerjakan bila semua fungsi/prosedur di atas sudah well tested*/
/*function isTailOverHead(Q:tQueue3) -> boolean
{mengembalikan true jika tail berada di depan head}*/
boolean isTailOverHead(tqueue3 Q) {
    /* Algoritma */
    return tail3(Q) > head3(Q);
}

#endif