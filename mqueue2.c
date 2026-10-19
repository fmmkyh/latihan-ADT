/* Program   : mqueue.c */
/* Deskripsi : file DRIVER modul queue karakter */
/* Nama      : @fmmkyh */
/* Tanggal   : 15/09/2026*/
/***********************************/

#include <stdio.h>
#include "tqueue2.h"
#include "boolean.h"

int main() {
	/*Kamus Lokal*/
	tqueue2 Q1;
	tqueue2 Q2;
	char E;
	int i;

	/*Algoritma*/

	printf("Membuat Queue Kosong Q1\n");
	createQueue2(&Q1);
	printf("Head: %d\n", head2(Q1));
	printf("Tail: %d\n", tail2(Q1));

	printf("Cek Queue Kosong?  ");
	if (isEmptyQueue2(Q1)){
		printf("Queue Kosong\n");
	} else {
		printf("Queue Tidak Kosong\n");
	}

	printf("Cek Queue Penuh?  ");
	if (isFullQueue2(Q1)){
		printf("Queue Penuh\n");
	} else {
		printf("Queue Belum Penuh\n");
	}

	printf("\nPrint Queue Q1: ");
	printQueue2(Q1);

	printf("\nView Queue Q1: ");
	viewQueue2(Q1);


	printf("\n   ------ Enqueue Q1 ------   ");
	printf("\ndengan elemen 'A', 'B', 'C'\n\n");

	enqueue2(&Q1, 'A');
	enqueue2(&Q1, 'B');
	enqueue2(&Q1, 'C');

	printf("Posisi Head: %d, Elemennya: %c\n",
		   head2(Q1), infoHead2(Q1));

	printf("Posisi Tail: %d, Elemennya: %c\n",
		   tail2(Q1), infoTail2(Q1));

	printf("\nPrint Queue Q1: ");
	printQueue2(Q1);

	printf("\nView Queue Q1: ");
	viewQueue2(Q1);


	printf("\n --- Ukuran Queue Q1 --- \n");
	printf("Size : %d\n", sizeQueue2(Q1));


	printf("\n ------ Dequeue Q1 ------ \n");
	dequeue2(&Q1, &E);
	printf("Elemen yang di-Dequeue: %c\n", E);

	printf("\n --- Ukuran Queue Q1 --- \n");
	printf("Size : %d\n", sizeQueue2(Q1));

	printf("\n   ------ Posisi Head dan Tail setelah Dequeue ------   \n");
	printf("Head: %d, Elemennya: %c\n",
		   head2(Q1), infoHead2(Q1));

	printf("Tail: %d, Elemennya: %c\n",
		   tail2(Q1), infoTail2(Q1));

	printf("\nPrint Queue Q1: ");
	printQueue2(Q1);

	printf("\nView Queue Q1: ");
	viewQueue2(Q1);


	printf("\nMembuat Queue Kosong Q2\n");
	createQueue2(&Q2);

	printf("\n   ------ Enqueue Q2 ------   \n");
	printf("\nEnqueue Q2: dengan elemen 'G'\n");

	enqueue2(&Q2, 'G');

	printf("\nPrint Queue Q2: ");
	printQueue2(Q2);

	printf("\nView Queue Q2: ");
	viewQueue2(Q2);


	printf("\n   ------ Enqueue2N Q2 ------   \n");
	enqueue2N(&Q2, 2);

	printf("\nPrint Queue Q2: ");
	printQueue2(Q2);

	printf("\nView Queue Q2: ");
	viewQueue2(Q2);


	printf("\n   ------ Cek One Element Q1 ------   \n");
	if (isOneElement2(Q1)){
		printf("Q1 memiliki 1 elemen\n");
	} else {
		printf("Q1 tidak memiliki 1 elemen\n");
	}


	printf("\n   ------ Cek IsTailStop Q1 ------   \n");
	if (isTailStop(Q1)){
		printf("Tail Q1 sudah berhenti di kapasitas\n");
	} else {
		printf("Tail Q1 masih dapat bergeser\n");
	}


	printf("\n   ------ Uji Reset Head Q1 ------   \n");
    printf("\nEnqueue elemen 'D' dan 'E' ke Q1");
	enqueue2(&Q1, 'D');
	enqueue2(&Q1, 'E');

	printf("\nSebelum Reset Head:\n");
	printf("Head: %d\n", head2(Q1));
	printf("Tail: %d\n", tail2(Q1));
	printf("Queue Q1: ");
	viewQueue2(Q1);


	printf("\n   ------ Dequeue Q1 ------   \n");

	dequeue2(&Q1, &E);
	printf("Elemen yang di-Dequeue: %c\n", E);

	printf("Queue Q1: ");
	viewQueue2(Q1);


	printf("\n   ------ IsEqualQueue2 ------   \n");

	printf("Queue Q1: ");
	viewQueue2(Q1);

	printf("Queue Q2: ");
	viewQueue2(Q2);

	if (isEqualQueue2(Q1, Q2)){
		printf("Q1 dan Q2 memiliki elemen yang sama\n");
	} else {
		printf("Q1 dan Q2 tidak memiliki elemen yang sama\n");
	}


	printf("\n   ------ Print Queue Akhir ------   \n");

	printf("Queue Q1: ");
	printQueue2(Q1);

	printf("Queue Q2: ");
	printQueue2(Q2);


	return 0;
}