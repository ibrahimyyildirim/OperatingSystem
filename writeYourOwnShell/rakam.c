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
    if(argc == 2){
    int rakam = strtoint(argv[1]);

   switch(rakam) {
      case 0 :
         printf("%d -> Sıfır\n", rakam );
         break;
      case 1 :
         printf("%d -> Bir\n", rakam );
         break;
      case 2 :
         printf("%d -> iki\n", rakam );
         break;
      case 3 :
         printf("%d -> Üç\n", rakam );
         break;
      case 4 :
         printf("%d ->Dört\n", rakam );
         break;
      case 5 :
         printf("%d -> Beş\n", rakam );
         break;
      case 6 :
         printf("%d -> Altı\n", rakam );
         break;
      case 7 :
         printf("%d -> Yedi\n", rakam );
         break;
      case 8 :
         printf("%d -> Sekiz\n", rakam );
         break;
      case 9 :
         printf("%d -> Dokuz\n", rakam );
         break;
      default :
         printf("\nParametre olarak rakam giriniz.\n" );
   }
}  else {
        printf("Bu işlem için 1 adet parametre göndermen gerekiyor. \n");
       }
   return 0;
}




