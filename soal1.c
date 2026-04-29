/*
EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
Modul               : 3 (Structures & Dynamics Arrays)
Hari dan Tanggal    : 29 April 2026
Nama (NIM)          : Syifa Fauziah Prasetyo (13224090)
Nama File           : prak3.c
Deskripsi           : Mengurutkan artefak dengan struct nama, kategori, tahun, dan nilai. Urutannya:
                      • kategori alfabetis naik
                      • jika sama, tahun naik
                      • jika sama, nilai turun
                      • jika sama, nama alfabetis naik

*/

#include <stdio.h>
#include <string.h>

struct artefak{
    char nama[100];
    char kategori[100];
    int tahun;
    int nilai;
};


// fungsi mengurutkan data dengan multi-kriteria
int urutan(struct artefak a, struct artefak b){

    // urutan kategori
    if(strcmp(a.kategori, b.kategori) > 0){
        return 1; // return 1, jika alfabet a lebih awal di abjad
    } else if(strcmp(a.kategori, b.kategori) == 0){

        // urutan tahun
        if(a.tahun > b.tahun){
            return 1; // return 1, jika tahun a lebih kecil
        } else if(a.tahun == b.tahun){

            // urutan nilai
            if(a.nilai < b.nilai){
                return 1; // return 1, jika nilai a lebih besar
            } else if(a.nilai == b.nilai){

                // urutan nama
                if(strcmp(a.nama, b.nama) > 0){
                    return 1; // return 1, jika nama a lebih awal di abjad
                }
            }
            
        }
    }
    return 0;
}


int main(){
    int N;
    scanf("%d", &N);
    struct artefak data[100];
    for(int i = 0; i < N; i++){
        scanf("%s %s %d %d", data[i].nama, data[i].kategori, &data[i].tahun, &data[i].nilai);
    }

    // bubble sort
    for(int i = 0; i < N - 1; i++){
        for(int j = 0; j < N - 1; j++){
            if(urutan(data[j], data[j + 1]) == 1){
                struct artefak temp;
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }

    // output
    for(int i = 0; i < N; i++){
        printf("%s %s %d %d\n", data[i].nama, data[i].kategori, data[i].tahun, data[i].nilai);
    }
    return 0;
}

/*
referensi :
https://www.w3schools.com/c/c_structs.php
https://www.w3schools.com/c/ref_string_strcmp.php
https://www.mahirkoding.com/bubble-sort-dalam-bahasa-c/
https://id.wikihow.com/Membandingkan-Dua-String-dalam-Pemrograman-C
*/ 
