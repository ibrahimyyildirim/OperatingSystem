#include<stdio.h> 
#include<string.h> 
#include<stdlib.h>  
#include<sys/wait.h>

#define clear() printf("\033[H\033[J")

void init_shell()           //açılış ekran karşılama
{ 
	clear(); 
	printf("\n\n\n\n******************"
		"************************");  
	printf("\n\n\tOPERATING SYSTEM PROJECT - 1\n"); 
	printf("\n*******************"
		"***********************"); 
	char* username = getenv("USER"); 
	printf("\n\n\nProgram birazdan başlatılacak @%s", username); 
	printf("\n"); 
	sleep(3); 
	clear(); 
} 

void shellHelp()        // yardım menüsü
{ 
	printf("\n***SHELL YARDIM EKRANI***\n"
		"\nShell'de kullanabileceğiniz konutlar:\n"
		"\n>mul\t\tçarpma işlemi"
		"\n>div\t\tbölme işlemi"
		"\n>rakam\t\trakam adını ekrana yazdırır"
		"\n>cat\t\tekrana yazı yazmanızı sağlar"
		"\n>clear\t\tekranı temizler"
        "\n>help\t\tyardım ekranını getirir"
		"\n>exit\t\t2sn içinde programı sonlandırır\n\n"); 
} 

    
int split (const char *txt, char delim, char ***tokens)    // split fonksiyonu
{
    int *tklen, *t, count = 1;
    char **arr, *p = (char *) txt;

    while (*p != '\0') if (*p++ == delim) count += 1;
    t = tklen = calloc(count, sizeof (int));
    for (p = (char *) txt; *p != '\0'; p++) *p == delim ? *t++ : (*t)++;
    *tokens = arr = malloc(count * sizeof (char *));
    t = tklen;
    p = *arr++ = calloc (*(t++) + 1, sizeof (char *));
    while (*txt != '\0')
    {
        if (*txt == delim)
        {
            p = *arr++ = calloc (*(t++) + 1, sizeof (char *));
            txt++;
        }
        else *p++ = *txt++;
    }
    free (tklen);
    return count;
}


int main(int argc, char *argv[],char ** envp){

char **tokens;                      //split edilen kelimelerin tutulduğu tokenlar
int count;                          //kelime sayacı
char *str[500];                     //klavye giriş stringi

init_shell();
shellHelp();

 while (strcmp(str,"exit")!= 0){

 printf ("\nmyshell>> ");
 gets(str);


 count = split(str, ' ', &tokens);          //girilen stringi split etme kısmı
 
 char *newargv[count];

    
 for (int i = 0; i < count; i++) {                      // dinamik argüman dizisi
    newargv[i]=(char*) malloc(5*sizeof(char));
    }
    newargv[count]=(char*) malloc(5*sizeof(char));
 for (int j = 0; j < count; j++) {
     // printf ("%s\n", tokens[j]);
    strcpy(newargv[j],tokens[j]);
    }
    newargv[count] = NULL;

    int i;
 if(strcmp(newargv[0],"div")== 0){              // ilk string kelimeler ile kıyaslanıp ona göre program çağrısı yapılıyor
          int fv = fork();
             if(fv==0){
                   i= execv("div",newargv);
        }
         else {
          wait(&i);
      }         
    }
 else if(strcmp(newargv[0],"mul")== 0){
          int fv = fork();                          // shell'in devam etmesi için yapılan fork'lar
             if(fv==0){
                   i= execv("mul",newargv);
         }
             else {
          wait(&i);
      }       
    }
 else if (strcmp(newargv[0],"rakam")== 0)  {
         int fv = fork();
           if(fv==0) {
                   i= execv("rakam",newargv);   
        }
          else {        
        //while(1);         
        //sleep(1);           
        wait(&i);
      }  
    }
 else if (strcmp(newargv[0],"cat")== 0)  {
         printf ("cat: "); 
         for (int i=1;i<count;i++){
         printf ("%s ",tokens[i]);  
        }       
        printf ("\n"); 
        }

 else if (strcmp(newargv[0],"clear")== 0)  {
    clear();   
         }
 else if (strcmp(newargv[0],"help")== 0)  {
    shellHelp();   
         }
 else if (strcmp(newargv[0],"exit")== 0)  {
    printf ("Programdan çıkılıyor...\n");
    sleep(2);
    clear(); 
    exit(0); 
    }
 else {
        printf ("Hatalı parametre girdiniz..! 'help' komutu yardımı ile geçerli komutları görebilirsin. \n");
    }
 
    }
    return 0;
}

