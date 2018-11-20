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
 return number ;
}


int main(int argc, char *argv[])
{
    if(argc == 3){
     int bolunen= strtoint(argv[1]);
     int bolen= strtoint(argv[2]);
     float sonuc=1;
     sonuc = (float)bolunen/bolen;
     printf("%d / %d = %.2f\n",bolunen,bolen,sonuc);
    }
    else {
        printf("Bu işlem için 2 adet parametre göndermen gerekiyor. \n");
    }

    return 0;
}

