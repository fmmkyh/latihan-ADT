#ifndef matriks_c
#define matriks_c
/* Program   : matriks.c */
/* Deskripsi : file BODY modul matriks integer */
/* Pembuat :  fmmkyh (on Github) */
/***********************************/

#include <stdio.h>
#include "matriks.h"
#include "boolean.h"
#include <stdlib.h>

/* KONSTRUKTOR */	

/* procedure initMatriks(output M: Matriks)
	{I.S.: - }
	{F.S.: Matriks M terdefinisi}
	{Proses mengisi elemen cell dengan -999, nbaris 0, nkolom 0} */
void initMatriks(Matriks *M) {
    // Kamus Lokal
    int i, j;
    // Algoritma
    for (i = 1; i <= 10; i++) {
        for (j = 1; j <= 10; j++) {
            M->cell[i][j] = -999;
        }
    }
    M->nbaris = 0;
    M->nkolom = 0;
}

/* procedure initMatriks0(output M: Matriks, input x, y: integer)
	{I.S.: - }
	{F.S.: Matriks M terdefinisi}
	{Proses mengisi elemen cell dengan 0 sebanyak sebanyak x baris & y kolom} 
    { Modifikasi initMatriks(M) untuk prosedur bantu dalam realisasi fungsi */
void initMatriks0(Matriks *M, int x, int y) {
    // Kamus Lokal
    int i, j;
    // Algoritma
    for (i = 1; i <= x; i++) {
        for (j = 1; j <= y; j++) {
            M->cell[i][j] = 0;
        }
    }
    M->nbaris = x;
    M->nkolom = y;
}

/* SELEKTOR */

/* function getNBaris(M: Matriks) -> integer
	{mengembalikan banyak baris matriks M yang terisi } */
int getNBaris(Matriks M) {
    // Algoritma
    return M.nbaris;
}

/* function getNKolom(M: Matriks) -> integer
	{mengembalikan banyak kolom matriks M yang terisi } */
int getNKolom(Matriks M) {
    // Algoritma
    return M.nkolom;
}

/* PREDIKAT */

/* function isEmptyMatriks(M: Matriks) -> boolean
	{mengembalikan True jika matriks M kosong } */
boolean isEmptyMatriks(Matriks M) {
    // ALgoritma
    return getNBaris(M) == 0 && getNKolom(M) == 0;
}

/* function isFullMatriks(M: Matriks) -> boolean
	{mengembalikan True jika matriks M penuh } */
boolean isFullMatriks(Matriks M) {
    // Algoritma
    return getNBaris(M) == 10 && getNKolom(M) == 10;
}

/* MUTATOR */

/* procedure addX(input/output M:Matriks, input X:integer, row:integer, col:integer)
	{I.S.: M terdefinisi, X terdefinisi }
	{F.S.: isi M.cell bertambah 1 elemen pada baris ke-row dan kolom ke-col jika belum penuh}
	{Proses: mengisi elemen M.cell dengan nilai X} */
void addX(Matriks *M, int X, int row, int col) {
    // Algoritma
    if (!isFullMatriks(*M)) {
        M->cell[row][col] = X;
        if (row > M->nbaris) {
            M->nbaris = row;
        }
        if (col > M->nkolom) {
            M->nkolom = col;
        }
    }
}

/* procedure delX(input/output M:Matriks, input X:integer )
	{I.S.: M terdefinisi, X terdefinisi}
	{F.S.: elemen M.cell berkurang 1}
	{Proses: menghapus 1 elemen bernilai X dari M.cell*/
void delX(Matriks *M, int X) {
    // Kamus Lokal
    int i, j;
    boolean found;
    // Algoritma
    found = false;
    for (int i = 1; i < 11 && !found; i++) {
        for (int j = 1; j < 11 && !found; j++) {
            if (M->cell[i][j] == X) {
                M->cell[i][j] = -999;
                found = true;
                break;
            }
        }
    }
}

/* procedure isiMatriksRandom(input/output M: Matriks, input x: integer, input y: integer)
	{I.S.: M terdefinisi}
	{F.S.: M terisi dengan bilangan random sejumlah x baris dan y kolom, nbaris=x, nkolom=y}
	{proses: mengisi matriks dengan bilangan integer random dengan jumlah baris x dan kolom y} */
void isiMatriksRandom(Matriks *M, int x, int y) {
    // Kamus Lokal
    int i, j;
    // Algoritma
    for (i = 1; i <= x; i++) {
        for (j = 1; j <= y; j++) {
            M->cell[i][j] = rand() % 10;
        }
    }
    M->nbaris = x;
    M->nkolom = y;
}

/* procedure isiMatriksIdentitas(input/output M: Matriks, input n: integer)
	{I.S.: M terdefinisi}
	{F.S.: M terisi dengan matriks identitas berukuran n x n, nbaris=nkolom=n}
	{proses: mengisi matriks dengan matriks identitas berukuran n x n} */
void isiMatriksIdentitas(Matriks *M, int n) {
    // Kamus 
    int i, j;
    // Algoritma
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i == j) {
                M->cell[i][j] = 1;
            } else {
                M->cell[i][j] = 0;
            }
        }
    }
    M->nbaris = n;
    M->nkolom = n;
}

/* OPERASI BACA/TULIS */

/* procedure populateMatriks(input/output M: Matriks, input x: integer, input y: integer)
{I.S.: M terdefinisi}
{F.S.: M terisi dengan inputan dari keybord sejumlah x baris dan y kolom, nbaris=x, nkolom=y}
{proses: mengisi matriks dengan meminta inputan dari keyboard dengan jumlah baris x dan kolom y} */
void populateMatriks(Matriks *M, int x, int y) {
    // Kamus Lokal
    int i, j;
    // Algoritma
    for (i = 1; i <= x; i++) {
        for (j = 1; j <= y; j++) {
            printf("Masukkan elemen pada baris-%d kolom-%d : ", i, j);
            scanf("%d", &M->cell[i][j]);
        }
    }
    M->nbaris = x;
    M->nkolom = y;
}

/* procedure printMatriks(input M:Matriks)
	{I.S.: M terdefinisi}
	{F.S.: -}
	{Proses: menampilkan semua elemen M.cell ke layar} */
void printMatriks(Matriks M) {
    // Kamus Lokal
    int i, j;
    // ALgoritma
    for (i = 1; i <= 10; i++) {
        for (j = 1; j <= 10; j++) {
            printf("[%d] ", M.cell[i][j]);
        }
        printf("\n");
    }
}

/* procedure viewMatriks (input M:Matriks)
	{I.S.: M terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen M.cell yang terisi ke layar} */
void viewMatriks (Matriks M) {
    // Kamus Lokal
    int i, j;
    // Algoritma
    for (i = 1; i <= getNBaris(M); i++) {
        for (j = 1; j <= getNKolom(M); j++) {
            if (M.cell[i][j] != -999) {
                printf("[%d] ", M.cell[i][j]);
            }
        }
        printf("\n");
    }
}

/* OPERASI ARITMATIKA */

/* function addMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil penjumlahan matriks M1 dengan M2} */
Matriks addMatriks(Matriks M1, Matriks M2) {
    // Kamus Lokal
    Matriks M;
    int i, j;
    // Algoritma
    initMatriks(&M);
    if (getNBaris(M1) == getNBaris(M2) && getNKolom(M1) == getNKolom(M2)) {
        M.nbaris = getNBaris(M1);
        M.nkolom = getNKolom(M2);
        for (i = 1; i <= getNBaris(M); i++) {
            for (j = 1; j <= getNKolom(M); j++) {
                M.cell[i][j] = M1.cell[i][j] + M2.cell[i][j];
            }
        }
    }
    return M;
}

/* function subMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil pengurangan antara matriks M1 dengan M2} */
Matriks subMatriks(Matriks M1, Matriks M2) {
    // Kamus Lokal
    Matriks M;
    int i, j;
    // Algoritma
    initMatriks(&M);
    if (getNBaris(M1) == getNBaris(M2) && getNKolom(M1) == getNKolom(M2)) {
        M.nbaris = getNBaris(M1);
        M.nkolom = getNKolom(M2);
        for (i = 1; i <= getNBaris(M); i++) {
            for (j = 1; j <= getNKolom(M); j++) {
                M.cell[i][j] = M1.cell[i][j] - M2.cell[i][j];
            }
        }
    }
    return M;
}

/* function kaliMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil perkalian antara matriks M1 dengan M2} */
Matriks kaliMatriks(Matriks M1, Matriks M2) {
    // Kamus Lokal
    Matriks M;
    int i, j, k, nk;
    // Algoritma
    if (getNKolom(M1) == getNBaris(M2)) {
        initMatriks0(&M, getNBaris(M1), getNKolom(M2));
        nk = getNBaris(M2);
        for (i = 1; i <= getNBaris(M); i++) {
            for (j = 1; j <= getNKolom(M); j++) {
                for (k = 1; k <= nk; k++) {
                    M.cell[i][j] += M1.cell[i][k] * M2.cell[k][j];
                } 
            }
        }
    }
    return M;
}

/* function kaliSkalarMatriks(M: Matriks, x: integer) -> Matriks
{mengembalikan perkalian antara matriks M dengan nilai skalar x} */
Matriks kaliSkalarMatriks(Matriks M1, int x) {
    // Kamus Lokal
    Matriks M;
    int i, j; 
    // algoritma
    initMatriks(&M); 
    M.nbaris = getNBaris(M1); 
    M.nkolom = getNKolom(M1); 
    for(i = 1; i <= getNBaris(M1); i++) {
        for (j = 1; j <= getNKolom(M1); j++) {
            M.cell[i][j] = M1.cell[i][j] * x;
        }
    }
    return M;
}

/* OPERASI LAINNYA */

/* procedure transposeMatriks(input/output M: Matriks)
	{I.S.: M terdefinisi}
	{F.S.: Matriks M sudah ditukar susunan baris dan kolomnya (Transpose)}
	{proses: mengubah susunan cell matriks, M.cell[i,j] menjadi M.cell[j,i]} */
void transposeMatriks(Matriks *M) {
    // Kamus Lokal
    Matriks W; //temp
    int i, j;
    // Algoritma
    initMatriks(&W);
    // copy
    W.nbaris = M->nkolom;
    W.nkolom = M->nbaris;
    for (i = 1; i <= getNBaris(W); i++) {
        for (j = 1; j <= getNKolom(W); j++) {
            W.cell[i][j] = M->cell[j][i];
        }
    }
    // paste
    M->nbaris = W.nbaris;
    M->nkolom = W.nkolom;
    for (i = 1; i <= getNBaris(W); i++) {
        for (j = 1; j <= getNKolom(W); j++) {
            M->cell[i][j] = W.cell[i][j];
        }
    }
}

/* function getTransposeMatriks(M: Matriks) -> Matriks
	{menghasilkan sebuah matriks yang merupakan hasil transpose dari matriks M} */
Matriks getTransposeMatriks(Matriks M) {
    // Kamus Lokal
    Matriks W;
    int i, j;
    // Algoritma
    initMatriks(&W);
    W.nbaris = M.nkolom;
    W.nkolom = M.nbaris;
    for (i = 1; i <= getNBaris(W); i++) {
        for (j = 1; j <= getNKolom(W); j++) {
            W.cell[i][j] = M.cell[j][i];
        }
    }
    return W;
}

/* IMAGE PROCESSING */

/* function thresholding(Matriks M; integer T) -> Matriks 
   {menghasilkan matriks hasil thresholding dengan nilai threshold T} */
Matriks thresholding(Matriks M, int T) {
    // Kamus Lokal
    int i, j;
    // Algoritma
    for (i = 1; i <= getNBaris(M); i++) {
        for (j = 1; j <= getNKolom(M); j++) {
            // mengubah ke citra biner berdasarkan threshold T
            if (M.cell[i][j] < T) {
                M.cell[i][j] = 0;
            } else {
                M.cell[i][j] = 1; // sesuai PPT
            }
        }
    }
    return M;
}

/* function citraNegatif(Matriks M) -> Matriks 
   {menghasilkan citra/matriks negatif} */
Matriks citraNegatif(Matriks M) {
    // Kamus Lokal
    int i, j;
    // Algoritma
    for (i = 1; i <= getNBaris(M); i++) {
        for (j = 1; j <= getNKolom(M); j++) {
            M.cell[i][j] = 255 - M.cell[i][j];
        }
    }
    return M;
}

/* function brightness(Matriks M, integer b) -> Matriks 
   {menghasilkan citra/matriks baru yang telah diubah kecerahannya sebasar b} */
Matriks brightness(Matriks M, int b) {
    // Kamus Lokal
    int i, j;
    // Algoritma
    for (i = 1; i <= getNBaris(M); i++) {
        for (j = 1; j <= getNKolom(M); j++) {
            if (M.cell[i][j] + b > 255) {
                M.cell[i][j] = 255;
            } else if (M.cell[i][j] + b < 0) {
                M.cell[i][j] = 0;
            } else {
                M.cell[i][j] += b;
            }
        }
    }
    return M;
}

/* function grayscale(Matriks R, Matriks G, Matriks B) -> Matriks 
   {menghasilkan citra/matriks grayscale dari citra R, G, B} */
Matriks grayscale(Matriks R, Matriks G, Matriks B) {
    // Kamus Lokal
    int i, j;
    Matriks C;
    float c = 0; // simpan hasil 
    // Algoritma
    initMatriks0(&C, getNBaris(R), getNKolom(R));
    for (i = 1; i <= getNBaris(G); i++) {
        for (j = 1; j <= getNKolom(B); j++) {
            c = R.cell[i][j] * 0.299 + G.cell[i][j] * 0.587 + B.cell[i][j] * 0.114;
            C.cell[i][j] = c;
        }
    }
    return C;
}

/* function translasi(Matriks M, integer m, integer n) -> Matriks 
   {menghasilkan citra/matriks hasil translasi sebesar m secara horizontal dan n secara vertikal} */
Matriks translasi(Matriks M, int m, int n) {
    // Kamus Lokal
    int i, j;
    Matriks T;
    // Algoritma
    // asumsi area yang ditinggalkan gambar diisi pixel 0 (warna hitam)
    initMatriks0(&T, getNBaris(M), getNKolom(M));
    for (i = 1; i <= getNBaris(T); i++) { // m horizontal: geser kolom (y)
        for (j = 1; j <= getNKolom(T); j++) { // n vertikal: geser baris (x)
            if ((1 <= i + n && i + n <= getNBaris(T)) && (1 <= j + m && j + m <= getNKolom(T))) {
                T.cell[i + n][j + m] = M.cell[i][j];
            }
        }
    }
    return T;
}

/* function flipHorizontal(Matriks M) -> Matriks 
   {menghasilkan citra/matriks hasil flip horizontal, kanan -> kiri, kir -> kanan} */
Matriks flipHorizontal(Matriks M) {
    // Kamus Lokal
    int i, j, B;
    Matriks F;
    // Algoritma
    initMatriks(&F);
    F.nbaris = getNBaris(M);
    F.nkolom = getNKolom(M);
    B = getNKolom(M);
    for (i = 1; i <= getNBaris(M); i++) {
        for (j = 1; j <= getNKolom(M); j++) {
            F.cell[i][j] = M.cell[i][B - j + 1]; 
        }
    }
    return F;
}

/* function flipVertical(Matriks M) -> Matriks 
   {menghasilkan citra/matriks hasil flip vertical, atas -> bawah, bawah <- atas} */
Matriks flipVertical(Matriks M) {
    // Kamus Lokal
    int i, j, N;
    Matriks F;
    // Algoritma
    initMatriks(&F);
    F.nbaris = getNBaris(M);
    F.nkolom = getNKolom(M);
    N = getNBaris(M);
    for (i = 1; i <= getNBaris(M); i++) {
        for (j = 1; j <= getNKolom(M); j++) {
            F.cell[i][j] = M.cell[N - i + 1][j]; 
        }
    }
    return F;
}

/* function addPadding(M: Matriks, input n:integer) -> Matriks
	{menghasilkan matriks baru dari M yang ditambahkan padding 0 sesuai dengan ukuran padding n */
Matriks addPadding(Matriks M, int n) {
    // Kamus Lokal
    Matriks P;
    int i, j;
    // Algoritma
    initMatriks0(&P, n*2 + getNBaris(M), n*2 + getNKolom(M));
    for (i = 1; i <= getNBaris(M); i++) {
        for (j = 1; j <= getNKolom(M); j++) {
            P.cell[i + n][j + n] = M.cell[i][j];
        }
    }
    return P;
}

/* function maxPooling(M: Matriks, input size:integer) -> Matriks
	{menghasilkan matriks hasil max pooling matriks M dengan pool size = size  */
Matriks maxPooling(Matriks M, int size) {
    // Kamus Lokal
    int i, j, x, y;
    int max;
    Matriks P;
    // Algoritma
    initMatriks(&P);
    P.nbaris = getNBaris(M) - size + 1;
    P.nkolom = getNKolom(M) - size + 1;
    // loop luar (posisi window di matriks M)
    for (i = 1; i <= getNBaris(M) - size + 1; i++) {
        for (j = 1; j <= getNKolom(M) - size + 1; j++) {
            // loop dalam (posisi relatif dalam window)
            max = M.cell[i][j]; // inisialisasi
            for (x = 1; x <= size; x++) {
                for (y = 1; y <= size; y++) {
                    // cek maks
                    if (max < M.cell[i + x - 1][j + y - 1]) {
                        max = M.cell[i + x - 1][j + y - 1];
                    }
                }
            }
            P.cell[i][j] = max;
        }
    }
    return P;
}

/* function avgPooling(M: Matriks, input size:integer) -> Matriks
	{menghasilkan matriks hasil average pooling matriks M dengan pool size = size  */
Matriks avgPooling(Matriks M, int size) {
    // Kamus Lokal
    int i, j, x, y;
    float sum; // Asumsi keluaran average berupa float
    Matriks P;
    // Algoritma
    initMatriks(&P);
    P.nbaris = getNBaris(M) - size + 1;
    P.nkolom = getNKolom(M) - size + 1;
    // loop luar (posisi window di matriks M)
    for (i = 1; i <= getNBaris(M) - size + 1; i++) {
        for (j = 1; j <= getNKolom(M) - size + 1; j++) {
            // loop dalam (posisi relatif dalam window)
            sum = 0; // inisialisasi
            for (x = 1; x <= size; x++) {
                for (y = 1; y <= size; y++) {
                    // hitung sum {
                    sum += M.cell[i + x - 1][j + y - 1];
                }
            }
            P.cell[i][j] = sum / (size * size);
        }
    }
    return P;
}

/* function conv(M: Matriks, K:Matriks) -> Matriks
	{menghasilkan matriks hasil konvolusi matriks M dengan kernel K  */
Matriks conv(Matriks M, Matriks K) {
    // Kamus Lokal
    int i, j, x, y, sum; 
    Matriks P;
    // Algoritma
    initMatriks(&P);
    P.nbaris = getNBaris(M) - getNBaris(K) + 1;
    P.nkolom = getNKolom(M) - getNKolom(K) + 1;
    // loop luar (posisi window di matriks M)
    for (i = 1; i <= getNBaris(M) - getNBaris(K) + 1; i++) {
        for (j = 1; j <= getNKolom(M) - getNKolom(K) + 1; j++) {
            // loop dalam (posisi relatif dalam window)
            sum = 0; // inisialisasi
            for (x = 1; x <= getNBaris(K); x++) {
                for (y = 1; y <= getNKolom(K); y++) {
                    // hitung sum {
                    sum += M.cell[i + x - 1][j + y - 1] * K.cell[x][y];
                }
            }
            P.cell[i][j] = sum;
        }
    }
    return P;
}

#endif