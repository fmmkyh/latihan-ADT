/* Program   : mmatriks.c */
/* Deskripsi : driver ADT matriks integer */
/* Pembuat :  fmmkyh (on Github) */
/***********************************/

#include <stdio.h>
#include "matriks.h"
#include "boolean.h"

int main() {
	/*Kamus*/
	Matriks M1, M2, M3, M4, M5, M6, M7, M8, M9;
	Matriks S, R, G, B, K;
	int baris, kolom;

	/*Algoritma*/
	printf("\nUJI COBA MAIN PROGRAM MATRIKS\n");
	printf("\n----- Membuat Matriks Kosong M1 dan M2 -----\n");
	initMatriks(&M1);
	initMatriks(&M2);
	
	printf("\n----- Tes Isi Matriks M1 -----\n");
	printf("\n----- Print Matriks M1 -----\n");
	printMatriks(M1); 
	printf("\n----- View Matriks M1 -----\n");
	viewMatriks(M1); // Tak muncul elemen apapun
	printf("\n----- Apakah Matriks M1 kosong? -----\n");
	if (isEmptyMatriks(M1)) {
		printf("Matriks M1 kosong\n");
	} else {
		printf("Matriks M1 tidak kosong\n");
	}
	
	printf("\n----- Isi Matriks M1 -----\n");
	printf("Masukkan banyak baris: ");
	scanf("%d", &baris);
	printf("Masukkan banyak kolom: ");
	scanf("%d", &kolom);
	populateMatriks(&M1, baris, kolom);
	printf("\n----- View Matriks M1 -----\n");
	viewMatriks(M1);
	
	printf("\n----- Banyak Baris dan Kolom M1? -----\n");
	printf("Banyak baris: %d\n", getNBaris(M1));
	printf("Banyak kolom: %d\n", getNKolom(M1));
	printf("\n----- Apakah Matriks M1 Penuh? -----\n");
	if (isFullMatriks(M1)) {
		printf("Matriks M1 penuh\n");
	} else {
		printf("Matriks M1 tidak penuh\n");
	}
	
	printf("\n	----- Tambah Isi Matriks M2 -----\n");
	printf("	    dengan elemen a11 = 2 \n");
	addX(&M2, 2, 1, 1);
	printf("	    dengan elemen a21 = 4 \n");
	addX(&M2, 4, 2, 1);
	printf("	    dengan elemen a12 = 2 \n");
	addX(&M2, 2, 1, 2);
	printf("	    dengan elemen a22 = 2 \n");
	addX(&M2, 2, 2, 2);
	printf("	    dengan elemen a13 = 2 \n");
	addX(&M2, 2, 1, 3);
	printf("	    dengan elemen a23 = 3 \n");
	addX(&M2, 3, 2, 3);
	printf("\n----- View Matriks M2 -----\n");
	viewMatriks(M2);

	printf("\n	----- Kurangi Isi Matriks M2 -----\n");
	printf("	    dengan integer 2 (1x) \n");
	delX(&M2, 2);
	printf("	    dengan integer 2 (2x) \n");
	delX(&M2, 2);
	printf("\n----- View Matriks M2 -----\n");
	viewMatriks(M2);

	printf("\n----- Buat M3 Matriks Identitas -----\n");
	initMatriks(&M3);
	isiMatriksIdentitas(&M3, 3);
	printf("\n----- View Matriks M3 -----\n");
	viewMatriks(M3);

	printf("\n----- Isi Matriks M4 Random -----\n");
	isiMatriksRandom(&M4, 3, 3);
	printf("\n----- View Matriks M4 -----\n");
	viewMatriks(M4);

	printf("\n----- Tambah Matriks M3 dan M4 = M5 -----\n");
	M5 = addMatriks(M3, M4);
	printf("\n----- View Matriks M5 -----\n");
	viewMatriks(M5);

	printf("\n----- Kurangi Matriks M5 dengan M3 = M6 -----\n");
	M6 = subMatriks(M5, M3);
	printf("\n----- View Matriks M6 -----\n");
	viewMatriks(M6);

	printf("\n----- Perkalian skalar Matriks M4 dengan 2 -----\n");
	M4 = kaliSkalarMatriks(M4, 2);
	printf("\n----- View Matriks M4 -----\n");
	viewMatriks(M4);

	printf("\n----- Perkalian Matriks M4 dengan M5 -----\n");
	M5 = kaliMatriks(M4, M5);
	printf("\n----- View Matriks M5 -----\n");
	viewMatriks(M5);
	
	printf("\n----- Prosedur Transpose Matriks M5 -----\n");
	transposeMatriks(&M5);
	printf("\n----- View Matriks M5 -----\n");
	viewMatriks(M5);

	printf("\n----- Fungsi Transpose Matriks M1 -----\n");
	M1 = getTransposeMatriks(M1);
	printf("\n----- View Matriks M1 -----\n");
	viewMatriks(M1);

	printf("\n----- IMAGE PROCESSING -----\n");

	printf("\n----- Thresholding M4 (T = 12) -----\n");
	M4 = thresholding(M4, 12);
	printf("\n----- View Matriks M4 -----\n");
	viewMatriks(M4);

	printf("\n----- Citra Negatif Matriks M6 -----\n");
	M6 = citraNegatif(M6);
	printf("\n----- View Matriks M6 -----\n");
	viewMatriks(M6);

	printf("\n----- Brightness Matriks M5 (B = 50)-----\n");
	M5 = brightness(M5, 50);
	printf("\n----- View Matriks M5 -----\n");
	viewMatriks(M5);

	printf("\n----- Grayscale Matriks S -----\n");
	printf("  dari Matriks R, G, B random\n");
	initMatriks(&S);
	initMatriks(&R);
	initMatriks(&G);
	initMatriks(&B);
	isiMatriksRandom(&R, 3, 3);
	isiMatriksRandom(&G, 3, 3);
	isiMatriksRandom(&B, 3, 3);
	S = grayscale(R, G, B);
	printf("\n----- View Matriks S -----\n");
	viewMatriks(S);
	
	printf("\n----- Padding Matriks M6 ukuran n = 2 -----\n");
	M6 = addPadding(M6, 2);
	printf("\n----- View Matriks M6 -----\n");
	viewMatriks(M6);
	printf("Ukuran setelah padding: %d x %d\n", getNBaris(M6), getNKolom(M6));

	printf("\n----- Translasi Matriks M6 sebesar (1, 2) -----\n");
	M6 = translasi(M6, 2, 1); // m = 2, n = 1
	printf("\n----- View Matriks M6 -----\n");
	viewMatriks(M6);

	printf("\n----- Matriks Random M7 M8 M9-----\n");
	initMatriks(&M7);
	initMatriks(&M8);
	initMatriks(&M9);
	isiMatriksRandom(&M7, 5, 5);
	isiMatriksRandom(&M8, 5, 5);
	isiMatriksRandom(&M9, 5, 5);
	printf("\n----- View Matriks M7 -----\n");
	viewMatriks(M7);
	printf("\n----- View Matriks M8 -----\n");
	viewMatriks(M8);
	printf("\n----- View Matriks M9 -----\n");
	viewMatriks(M9);
	
	printf("\n----- Flip Vertikal Matriks M7 -----\n");
	M7 = flipVertical(M7);
	printf("\n----- View Matriks M7 -----\n");
	viewMatriks(M7);
	
	printf("\n----- Flip Horizontal Matriks M8 -----\n");
	M8 =  flipHorizontal(M8);
	printf("\n----- View Matriks M8 -----\n");
	viewMatriks(M8);

	printf("\n----- Max Pooling Matriks M7 -----\n");
	printf("      dengan pool size 3\n");
	M7 = maxPooling(M7, 3);
	printf("\n----- View Matriks M7 -----\n");
	viewMatriks(M7);

	printf("\n----- Avg Pooling Matriks M8 -----\n");
	printf("      dengan pool size 3\n");
	M8 = avgPooling(M8, 3);
	printf("\n----- View Matriks M8 -----\n");
	viewMatriks(M8);

	printf("\n----- Konvolusi Matriks M9 -----\n");
	printf("     dengan kernel K random\n");
	initMatriks(&K);
	isiMatriksRandom(&K, 5, 5);
	printf("\n----- View Kernel K random -----\n");
	viewMatriks(K);
	M9 = conv(M9, K);
	printf("\n----- View Matriks M9 -----\n");
	viewMatriks(M9);

	return 0;
}
