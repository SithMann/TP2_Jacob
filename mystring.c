#include <stdlib.h>
#include <string.h>
#include <mystring.h>


/*
 * VARIABLE LOCALE
 */

unsigned long int string_cpt = 0 ; 

/* 
 * FONCTIONS
 */

extern 
booleen_t string_existe( string_t * const string )
{
  if( string == NULL ) 
    return(FAUX) ;
  else
    return(VRAI) ; 
}

static 
err_t string_detruire( string_t ** string ) 
{
  /* ce que j'ai ajouté : */
  if(string_existe((*string))){
    free((*string));
    (*string) = NULL;
  }
  /* stop */
  return(OK) ; 
}

static
void string_afficher( string_t * const string ) 
{

  printf( "{" ) ; 
  if(  string_existe(string) ) 
    {
      printf( "%s" , string->string) ;
    }
  printf( "}" ) ; 
}

extern 
string_t * string_creer( char * const chaine ) 
{
  string_t * string = NULL ; 
  /*Ce que jai fait : */
  string = malloc(sizeof(string_t));
  string->string = chaine;
  /* cast des fonctions car conflits de types entre string et objet */
  string->p_affiche = (void (*) (objet_t *))string_afficher;
  string->p_delete = (err_t (*) (objet_t **))string_detruire;
  /*stop*/
  return( string ) ;
}
