#include <stdlib.h>
#include <string.h>
#include <individu.h>


/*
 * VARIABLE LOCALE
 */

unsigned long int individu_cpt = 0 ; 

/* 
 * FONCTIONS
 */

extern 
booleen_t individu_existe( individu_t * const individu )
{
  if( individu == NULL ) 
    return(FAUX) ;
  else
    return(VRAI) ; 
} 

static 
err_t individu_detruire( individu_t ** individu ) 
{
  /* ce que j'ai ajouté : */
  if(individu_existe((*individu))){
    free((*individu));
    (*individu) = NULL;
  }
  /* stop */
  return(OK) ; 
}

static
void individu_afficher( individu_t * const individu ) 
{

  printf( "{" ) ; 
  if(  individu_existe(individu) ) 
    {
      printf( "%s %s" , individu->prenom , individu->nom ) ;
    }
  printf( "}" ) ; 
} 

extern 
individu_t * individu_creer( char * const prenom , char * const nom ) 
{
  individu_t * individu = NULL ; 
    /* ce que j'ai ajouté : */
  individu = malloc(sizeof(individu_t));
  individu->nom = nom;
  individu->prenom = prenom;
  /* cast des fonctions car conflits de types entre individu et objet */
  individu->p_affiche = (void (*) (objet_t *))individu_afficher;
  individu->p_delete = (err_t (*) (objet_t **))individu_detruire;
  /* stop */
  return( individu ) ;
}
