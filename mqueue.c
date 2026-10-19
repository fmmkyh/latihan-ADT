/* Program   : mqueue.c */
/* Deskripsi : file DRIVER modul queue karakter */
/* Nama      : @fmmkyh */
/* Tanggal   : 15/09/2026*/
/***********************************/

#include <stdio.h>
#include "tqueue.h"
#include "boolean.h" 

int main() {
	/*Kamus Lokal*/
	tqueue Q1;
	tqueue Q2;
	char E;
 
	/*Algoritma*/
	printf("Membuat Queue Kosong Q1\n");
	createQueue(&Q1);
	printf("Head: %d\n", head(Q1));
	printf("Tail: %d\n", tail(Q1));
 
	printf("Cek Queue Kosong?  ");
	if (isEmptyQueue(Q1)){
		printf("Queue Kosong\n");
	} else {
		printf("Queue Tidak Kosong\n");
	}
 
	printf("Cek Queue Penuh?  ");
	if (isFullQueue(Q1)){
		printf("Queue Penuh\n");
	} else {
		printf("Queue Belum Penuh\n");
	}

	printf("\nPrint Queue Q1: ");
	printQueue(Q1);
	printf("\nView Queue Q1: ");
	viewQueue(Q1);


	printf("\n   ------ Enqueue Q1 ------   ");
	printf("\ndengan elemen 'A', 'B', 'C'\n\n");
	enqueue(&Q1, 'A');
	enqueue(&Q1, 'B');
	enqueue(&Q1, 'C');

	printf("Cek Queue Kosong?  ");
	if (isEmptyQueue(Q1)){
		printf("Queue Kosong\n");
	} else {
		printf("Queue Tidak Kosong\n");
	}
 
	printf("Cek Queue Penuh?  ");
	if (isFullQueue(Q1)){
		printf("Queue Penuh\n");
	} else {
		printf("Queue Belum Penuh\n");
	}

	printf("Posisi Head:%d, Elemennya: %c\n", 
		head(Q1), infoHead(Q1), "\n");
	printf("Posisi Tail:%d, Elemennya: %c\n", 
		tail(Q1), infoTail(Q1));

	printf("\nPrint Queue Q1: ");
	printQueue(Q1);
	printf("\nView Queue Q1: ");
	viewQueue(Q1);
 
	printf("\n --- Ukuran Queue Q1 --- \n");
	printf("Size : %d\n", sizeQueue(Q1));

	printf("\n ------ Dequeue Q1 ------ \n");
	dequeue(&Q1, &E);
	printf("Elemen yang di-Dequeue: %c\n", E);

	printf(" --- Ukuran Queue Q1 --- \n");
	printf("Size : %d\n", sizeQueue(Q1));
	
	printf("\n   ------ Posisi Head dan Tail setelah Dequeue ------   \n");
	printf("Head: %d, Elemennya: %c\n", 
		head(Q1), infoHead(Q1));
	printf("Tail: %d, Elemennya: %c\n", 
		tail(Q1), infoTail(Q1));

	printf("\nPrint Queue Q1: ");
	printQueue(Q1);
	printf("\nView Queue Q1: ");
	viewQueue(Q1);

	printf("\nMembuat Queue Kosong Q2\n");
	createQueue(&Q2);
	printf("\n   ------ Enqueue Q2 ------   \n");
	printf("\nEnqueue Q2: dengan elemen 'G'\n");
	enqueue(&Q2, 'G');
 
	printf("Cek Queue Satu Elemen?  ");
	if (isOneElement(Q1)){
		printf("Queue memiliki 1 elemen\n");
	} else {
		printf("Queue tidak memiliki 1 elemen\n");
	}

	printf("\nPrint Queue Q2: ");
	printQueue(Q2);
	printf("\nView Queue Q2: ");
	viewQueue(Q2);

	printf("\n   ------ Enqueue2 Q1 dan Q2 ------   \n");
	printf("\nEnqueue2 Q1 dan Q2: dengan elemen 'X'\n");
	enqueue2(&Q1, &Q2, 'X');

	printf("\nQueue Q1: \n");
	viewQueue(Q1);
	printf("\nQueue Q2: \n");
	viewQueue(Q2);

	printf("\nEnqueue2 Q1 dan Q2: dengan elemen 'X', 'Y'\n");
	enqueue2(&Q1, &Q2, 'Y');

	printf("\nQueue Q1: \n");
	viewQueue(Q1);
	printf("\nQueue Q2: \n");
	viewQueue(Q2);

	printf("\n   ------ Dequeue2 Q1 dan Q2 ------   \n");
	printf("\n   ---- sekali ----   \n");
 	dequeue2(&Q1, &Q2, &E);
	printf("\nQueue Q1: ");
	viewQueue(Q1);
	printf("\nQueue Q2: ");
	viewQueue(Q2);
	printf("\n   ---- dua kali ----   \n");
 	dequeue2(&Q1, &Q2, &E);
	printf("\nQueue Q1: ");
	viewQueue(Q1);
	printf("\nQueue Q2: ");
	viewQueue(Q2);

	return 0;
}