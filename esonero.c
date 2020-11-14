#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//inizializzo la funzione
int main(){
  //dichiaro le variabili
  time_t t;
  char text[128];
  char key[128];
  int i;
  int ch;
  int scelta;
  char ctext[129];
  char dtext[129];
  int lunghezza;
  int lunghezzac;

//faccio inserire il testo all'utente
  printf("Inserisci il testo da decifrare: \n");
  fgets(text,128, stdin);

  while ((ch = getchar() !='\n' && ch != EOF));
  //controllo che il testo non superi i 128 caratteri, se li supera glilo faccio riinserire
  if(strlen(text)>128){
    printf("Il testo è troppo grande, immetti un nuovo testo: \n");
    fgets(text, 128, stdin);}
    else{
    start:
    // faccio scegliere all'utente quale opzione di decifrazione vuole attuare
      printf("Immetti 1 se vuoi inserire una chiave di criptazione altrimenti immetti 2 se vuoi generare una chiave casuale: \n");
      scanf("%d", &scelta);
      int a;
      while ((a=getchar() !='\n' && a !=EOF));
      //controllo quale opzione ha scelto
      if(scelta==1){
        do{
          // faccio inserire la chiave di criptazione
        printf("Inserisci una chiave che sia più lunga o uguale al testo da cifrare: \n");
        fgets(key, 128, stdin);
        while ((a=getchar() !='\n' && a !=EOF));
        lunghezzac=strlen(key);
        lunghezza=strlen(text);}
        //controllo la lunghezza della chive
        while(lunghezzac<lunghezza);
          printf("Chiave accettata\n");
          printf("Ecco il tuo testo cifrato: ");
          // cifro il testo
          i=0;
          while(i<lunghezza){
           ctext[i]=text[i]^key[i];
           i++;
         }
         printf("%p \n", ctext );
         // decifro il testo
         i=0;
         while (i<strlen(text)) {
           dtext[i]=ctext[i]^key[i];
           i++;
         }
         printf("Testo decifrato: %s\n", dtext );
    }
      else if (scelta==2){
        // genero una chiave casuale
        srand((unsigned) time(&t));
       char keyr[128];
       printf("La chiave generata è: ");
       i=0;
       while(i<strlen(text)){
        keyr[i]=32+(rand()%128);
        printf("%s", keyr );
        i++;

      }
      printf("\n" );


      printf("Ecco il tuo testo cifrato:");
      i=0;
      while(i<strlen(text)){
       ctext[i]=text[i]^keyr[i];
       printf("%p", ctext );
       i++;

     }
     printf("\n" );
     // decifro il testo
        i=0;
        while (i<strlen(text)) {
          dtext[i]=ctext[i]^keyr[i];
          i++;
        }
        printf("Testo decifrato: %s\n", dtext );


      }
      else {
        //riporto l'utente all'inserimento di una scelta per la cifrazione
        printf("Devi scegliere un opzione.\n");
        goto start;
      }
    }
}
