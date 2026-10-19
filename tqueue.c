#ifndef  tqueue_c
#define  tqueue_c
/* Program   : tqueue.c */
/* Deskripsi : file BODY modul queue */
/* Nama      : @fmmkyh */
/* Tanggal   : 15/09/2026*/
/***********************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "boolean.h"
#include "tqueue.h"

/*procedure createQueue ( output Q:tQueue)
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi elemen dengan huruf '-', head=tail=0 }*/ 
void createQueue(tqueue *Q) {
    /*Kamus Lokal*/
    int i;
    /*Algoritma*/
    (*Q).head = 0;
    (*Q).tail = 0;
    for (i = 1; i <= 5; i++){
        (*Q).wadah[i] = '-';
    }
}

/*function Head(Q:tQueue)-> integer 
{mengembalikan elemen terdepan antrian Q} */
//int Head(tqueue Q);
#define head(Q) (Q).head //implementasi fisik macro

/*function Tail(Q:tQueue)-> integer 
{mengembalikan elemen terakhir antrian Q} */
//int Tail(tqueue Q);
#define tail(Q) (Q).tail //implementasi fisik macro

/*function infoHead(Q:tQueue)-> character 
{mengembalikan nilai elemen terdepan antrian Q} */
/*pikirkan bila antrian kosong*/
int infoHead(tqueue Q) {
    /* Algoritma */
    if (!isEmptyQueue(Q)){
        return Q.wadah[head(Q)];
    } else {
        return 0;
    }
}

/*function infoTail(Q:tQueue)-> character 
{mengembalikan nilai elemen terakhir antrian Q} */
/*pikirkan bila antrian kosong*/
int infoTail(tqueue Q) {
    /* Algoritma */
    if (!isEmptyQueue(Q)){
        return Q.wadah[tail(Q)];
    } else {
        return 0;
    }
}

/*function sizeQueue(Q:tQueue)-> integer 
{mengembalikan panjang antrian Q} */
int sizeQueue(tqueue Q) {
    /* Algoritma */
    if (isEmptyQueue(Q)){
        return 0;
    } else {
        return (tail(Q));
    }
}

/*procedure printQueue(input Q:tQueue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak semua elemen wadah ke layar}*/
void printQueue(tqueue Q) {
    /*Kamus Lokal*/
    int i;
    /*Algoritma*/
    for (i = 1; i <= 5; i++){
        printf("%c", Q.wadah[i]);
        if (i < 5){
            printf(";");
        }
    }
    printf("\n");
}

/*procedure viewQueue(input Q:tQueue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen tak kosong ke layar}*/
void viewQueue(tqueue Q) {
    /*Kamus Lokal*/
    int i;
    /*Algoritma*/
    if (!isEmptyQueue(Q)){
        for (i = 1; i <= tail(Q); i++){
            printf("%c", Q.wadah[i]);
            if (i < tail(Q)){
                printf("; ");
            }
        }
    }
    printf("\n");
}

/*function isEmptyQueue(Q:tQueue) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue(tqueue Q){
    /* Algoritma */
    return (head(Q) == 0);
}
 
/*function isFullQueue(Q:tQueue) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue(tqueue Q){
    /* Algoritma */
    return (tail(Q) == 5);
}

/*function isOneElement(Q:tQueue) -> boolean
{mengembalikan true jika hanya ada 1 elemen }*/
boolean isOneElement(tqueue Q){
    /* Algoritma */
    return (sizeQueue(Q) == 1);
}

/*procedure enqueue( input/output Q:tQueue, input e: character )
{I.S.: Q dan e terdefinisi}
{F.S.: elemen wadah Q bertambah 1, bila belum penuh}
{proses: menambah elemen wadah Q } */
void enqueue(tqueue *Q, char e){
    /* Algoritma */
    if (!isFullQueue(*Q)){
        if (isEmptyQueue(*Q)){
            (*Q).head = 1;
            (*Q).tail = 1;
        } else {
            (*Q).tail++;
        }
        (*Q).wadah[(*Q).tail] = e;
    }
}
  
/*procedure deQueue( input/output Q:tQueue, output e: character )
{I.S.: }
{F.S.: e=infohead(Q) atau e='-' bila Q kosong, elemen wadah Q berkurang 1 }
{proses: mengurangi elemen wadah Q, semua elemen di belakang head digeser maju }
{bila awalnya 1 elemen, maka Head dan Tail menjadi 0 } */
void dequeue(tqueue *Q, char *e){
    /*Kamus Lokal*/
    int i;
    /*Algoritma*/
    if (!isEmptyQueue(*Q)){
        *e = infoHead(*Q);
        if (isOneElement(*Q)){
            (*Q).wadah[(*Q).head] = '-';
            (*Q).head = 0;
            (*Q).tail = 0;
        } else {
            for (i = 1; i <= tail(*Q)-1; i++){ 
                (*Q).wadah[i] = (*Q).wadah[i+1];
            }
            (*Q).wadah[(*Q).tail] = '-';
            (*Q).tail--;
        }
    } else { 
        *e = '-';
    }
}

/*tambahan, dikerjakan bila cukup waktu */

/*procedure enqueue2( input/output Q1:tQueue, input/output Q2:tQueue, input e: character )
{I.S.: e terdefinisi}
{F.S.: elemen wadah Q1 atau Q2 bertambah 1, bila belum penuh}
{proses: menambah elemen wadah pada antrian terpendek dari Q1 atau Q2} */
void enqueue2(tqueue *Q1, tqueue *Q2, char e){
    /* Algoritma */
    if (isFullQueue(*Q1) && isFullQueue(*Q2)){
    } else if (isFullQueue(*Q1)){
        enqueue(Q2, e);
    } else if (isFullQueue(*Q2)){
        enqueue(Q1, e);
    } else {
        if (sizeQueue(*Q1) <= sizeQueue(*Q2)){
            enqueue(Q1, e);
        } else {
            enqueue(Q2, e);
        }
    }
}

/*procedure dequeue2( input/output Q1:tQueue, input/output Q2:tQueue, output e: character )
{I.S.: }
{F.S.: e=infohead Q1 atau Q2 atau e='-' bila Q1 dan Q2 kosong, elemen wadah Q1 atau Q2 berkurang 1 }
{proses: mengurangi elemen wadah antrian terpanjang Q1 atau Q2, semua elemen di belakang head digeser maju }
{bila awalnya 1 elemen, maka Head dan Tail antrian menjadi 0 } */
void dequeue2(tqueue *Q1, tqueue *Q2, char *e){
    /* Algoritma */
    if (isEmptyQueue(*Q1) && isEmptyQueue(*Q2)){
        *e = '-';
    } else if (isEmptyQueue(*Q1)){
        dequeue(Q2, e);
    } else if (isEmptyQueue(*Q2)){
        dequeue(Q1, e);
    } else {
        if (sizeQueue(*Q1) >= sizeQueue(*Q2)){
            dequeue(Q1, e);
        } else {
            dequeue(Q2, e);
        }
    }
}

#endif
