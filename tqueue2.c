#ifndef  tqueue2_c
#define  tqueue2_c
/* Program   : tqueue2.c */
/* Deskripsi : file BODY modul queue */
/* Nama      : @fmmkyh */
/* Tanggal   : 15/09/2026*/
/***********************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "boolean.h"
#include "tqueue2.h"

/*procedure createQueue2 ( output Q:tQueue2 )
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi head dan tail dengan 0, elemen kosong='#'}*/ 
void createQueue2(tqueue2 *Q) {
    /*Kamus Lokal*/
    int i;
    /*Algoritma*/
    (*Q).head = 0;
    (*Q).tail = 0;
    for (i = 1; i <= 5; i++){
        (*Q).wadah[i] = '#';
    }
}

/*Function Head2(Q:Tqueue2) -> integer
{mengembalikan posisi elemen terdepan} */
int head2(tqueue2 Q) {
    /* Algoritma */
    return Q.head;
}

/*Function Tail2(Q:Tqueue2) -> integer
{mengembalikan posisi elemen terakhir} */
int tail2(tqueue2 Q) {
    /* Algoritma */
    return Q.tail;
}

/*Function InfoHead2(Q:Tqueue2) -> character
{mengembalikan nilai elemen terdepan} */
char infoHead2(tqueue2 Q) {
    /* Algoritma */
    if (!isEmptyQueue2(Q)){
        return Q.wadah[head2(Q)];
    } else {
        return 0;
    }
}

/*Function InfoTail2(Q:Tqueue2) -> character
{mengembalikan nilai elemen terakhir} */
char infoTail2(tqueue2 Q) {
    /* Algoritma */
    if (!isEmptyQueue2(Q)){
        return Q.wadah[tail2(Q)];
    } else {
        return 0;
    }
}

/*function isEmptyQueue2(Q:tQueue2) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue2(tqueue2 Q) {
    /* Algoritma */
    return head2(Q) == 0 && tail2(Q) == 0;
}
 
/*function isFullQueue2(Q:tQueue2) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue2(tqueue2 Q) {
    /* Algoritma */
    return head2(Q) == 1 && tail2(Q) == 5;
}

/*function isOneElement2(Q:tQueue2) -> boolean
{mengembalikan true jika Q berisi 1 elemen}*/
boolean isOneElement2(tqueue2 Q) {
    /* Algoritma */
    return head2(Q) == tail2(Q) && !(isEmptyQueue2(Q));
}

/*function sizeQueue2(Q:tQueue2)-> integer 
{mengembalikan panjang antrian Q} */
int sizeQueue2(tqueue2 Q) {
    /* Algoritma */
    if (isEmptyQueue2(Q)) {
	    return 0;
    } else if (isOneElement2(Q)) {
	    return 1;
    } else {
	    return tail2(Q) - head2(Q) + 1;
    }
}

/*procedure printQueue2(input Q:tQueue2)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak semua isi wadah ke layar}*/
void printQueue2(tqueue2 Q) {
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

/*procedure viewQueue2(input Q:tQueue2)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen yang tidak kosong ke layar}*/
void viewQueue2(tqueue2 Q)  {
    /*Kamus Lokal*/
    int i;
    /*Algoritma*/
    if (!isEmptyQueue2(Q)){
        for (i = head2(Q); i <= tail2(Q); i++){
            if (Q.wadah[i] != '#'){
                printf("%c", Q.wadah[i]);
            }
            if (i < tail2(Q)){
                printf("; ");
            }
        }
    }
    printf("\n");
}

/*Function IsTailStop(Q:TQueue2) -> boolean
{mengembalikan true jika Tail tidak dapat lagi geser}
{karena sudah di posisi kapasitas} */
boolean isTailStop(tqueue2 Q) {
    /* Algoritma */
    return tail2(Q) == 5;
}

/*Procedure ResetHead(input/output Q:TQueue2)
{I.S:Tail=kapasitas, head>1; F.S:head=1 }
{Proses: mengembalikan Head ke indeks 1 }
{Elemen selain head ikut bergeser menyesuaikan} */
/*CATATAN: di praktikum ini, resetHead dilakukan ketika Enqueue */
void resetHead(tqueue2 *Q) {
    /*Kamus Lokal*/
    int i, h; /* indeks, head lama */
    /*Algoritma*/
    if (!isEmptyQueue2(*Q) && isTailStop(*Q)) {
		h = head2(*Q);
		for (i = 1; i <= sizeQueue2(*Q); i++) {
			(*Q).wadah[i] = (*Q).wadah[h];
			h++;
		}
        for (i = sizeQueue2(*Q) + 1; i <= 5; i++) {
            (*Q).wadah[i] = '#';
        }
        (*Q).head = 1;
        (*Q).tail = sizeQueue2(*Q);
	}
}

/*procedure enQueue2( input/output Q:tQueue2, input E: character )
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q bertambah 1 bila belum penuh}
{proses: menambah elemen wadah Q, jika tail(Q)=kapasitas, 
maka semua elemen digeser lebih dulu sehingga head(Q)=1 } */
void enqueue2(tqueue2 *Q, char E) {
    /* Algoritma */
    if (!isFullQueue2(*Q)) {
	    if (isEmptyQueue2(*Q)) {
		    (*Q).head = 1;
		    (*Q).tail = 1;
	    } else {
		    if (isTailStop(*Q)) {
                resetHead(Q);
            }
		    (*Q).tail++;
	    }
	    (*Q).wadah[tail2(*Q)] = E;
    }
}
  
/*procedure deQueue2( input/output Q:tQueue2, output E: character )
{I.S.: }
{F.S.: elemen wadah Q berkurang 1 (Head), E=infohead(Q) lama, bila kosong, E='@'}
{proses: mengurangi elemen wadah Q, bila 1 elemen, 
maka Head dan Tail mengacu ke 0 } */
void dequeue2(tqueue2 *Q, char *E) {
    /* Algoritma */
    if (!isEmptyQueue2(*Q)) {
		*E = (*Q).wadah[head2(*Q)];
		(*Q).wadah[(*Q).head] = '#';
		if (isOneElement2(*Q)) {
			(*Q).head = 0;
			(*Q).tail = 0;
		} else {
			(*Q).head++;
		}
	} else {
		*E = '#';
	}
}

/*procedure enQueue2N( input/output Q:tQueue2, input N:integer )
{I.S.: Q terdefinisi, mungkin kosong, N <= kapasitas - panjang antrean}
{F.S.: elemen wadah Q bertambah <= N elemen bila belum penuh}
{proses: mengisi elemen dari keyboard, jika tail(Q) mencapai kapasitas, 
maka semua elemen digeser lebih dulu sehingga head(Q)=1 } */
void enqueue2N(tqueue2 *Q, int N) {
    /*Kamus Lokal*/
    int i; /* indeks*/
    char x; /* elemen input */
    /*Algoritma*/
	if (!isFullQueue2(*Q)) {
		printf("Banyak elemen yang ingin dimasukkan: ");
		scanf("%d", &N);
		for (i = 1; i <= N; i++) {
			printf("Masukkan elemen: ");
			scanf(" %c", &x);
            enqueue2(Q, x);
			/* resetHead(Q) otomatis termasuk */
            /* dalam enqueue2(&Q, x) */
			if (isFullQueue2(*Q)) {
				printf("Queue sudah Penuh\n");
				break;
			}
		}
	} else {
		printf("Queue sudah Penuh\n");
	}
}

/*EXTRA: kerjakan bila semua fungsi/prosedur di atas sudah well tested*/
/*Function isEqualQueue2(Q1:TQueue2,Q2:TQueue2) -> boolean
{mengembalikan true jika Q1 dan Q2 berisi elemen yang sama}
{ingat, kondisi head Q1 dan Q2 mungkin tidak sama} */
boolean isEqualQueue2(tqueue2 Q1, tqueue2 Q2) {
    /*Kamus Lokal*/
    char E1, E2;
    /* Algoritma */
    if (isEmptyQueue2(Q1) && isEmptyQueue2(Q2)) {
		return true;
	} else if (sizeQueue2(Q1) == sizeQueue2(Q2)) {
		if (isOneElement2(Q1)) {
			return infoHead2(Q1) == infoHead2(Q2);
		} else {
			dequeue2(&Q1, &E1);
			dequeue2(&Q2, &E2);
			return (E1 == E2) && isEqualQueue2(Q1, Q2);
		}
	} else {
        return false;
    }
}

#endif