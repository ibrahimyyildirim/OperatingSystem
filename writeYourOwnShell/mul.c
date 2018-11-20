#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int strtoint( char* charnums)
{
 int number=0;
 int index=0;
 while(charnums[index])
 {
    if(('0'<=charnums[index]) && (charnums[index]<='9'))
    {

    if(!number)
        number= ( (int) charnums[index]) - 48;
    else
    {
        number = (number *= 10) + ((int) charnums[index] - 48);
    }
    index++;
         }
         else
         {
            number=-1;
            printf("\nGecersiz islem");
            break;
         }
 }
 return number;
}

int main(int argc, char *argv[])
{
    if(argc == 3){
     int sayi1=strtoint(argv[1]);
     int sayi2= strtoint(argv[2]);
     int sonuc=1;
     sonuc = sayi1*sayi2;
     printf("%d x %d = %d\n",sayi1,sayi2,sonuc);
    }
    else {
        printf("Bu işlem için 2 adet parametre göndermen gerekiyor. \n");
       }
   return 0;
}

