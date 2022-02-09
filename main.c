//Napisz program, który policzy krotność występowania poszczególnych znaków drukowalnych z tabeli
// ASCII (więc nie bawimy się w polskie znaki), w pliku podanym jako argument programu. Napisz plik
// wejściowy lub wygeneruj np. jakąś angielską stroną z man'a. Wynik programu wyświetl na standardowe wyjście.

//zad lab7/zad2

#include<stdio.h>

int main(int argc, char **argv) {

    int i, znak;
    int characterCounter[10000] = { 0 };
    FILE *fp = fopen(argv[1], "r");

    if(argc<2){
        printf("Nie podałeś argumentu\n");
    } else if (fp==NULL){
        printf("Podany plik nie istnieje\n");
    } else if (fgetc(fp)==EOF){
        printf("Podany plik jest pusty\n");
    } else {
        while((znak=fgetc(fp))) {
            if(znak == EOF) break;
            characterCounter[znak]++;
        }
        for(i=0; i<10000; i++) {
            if(characterCounter[i] > 0) {
                printf("Znak %c występuje %d razy\n", i, characterCounter[i]);
            }
        }
        fclose(fp);
    }
    return 0;
}