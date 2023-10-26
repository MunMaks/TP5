//#include <ctype.h>
//#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
#define HAUTEUR 300
#define LARGEUR 400


void Rectangle(int largeur, int hauteur){
    MLV_draw_filled_rectangle(largeur/8, hauteur/4, largeur/2, hauteur/2, MLV_COLOR_BLUE);
}

int main( int argc, char *argv[] ){
    
    int largeur;
    int hauteur;
    
    printf("largeur et hauteur: \n");
    scanf("%d %d", &largeur, &hauteur);
    // MLV_create_window( "Exo - 1 - Rectangle", "Rectangle", HAUTEUR, LARGEUR );  // exo1
    
    MLV_create_window( "Exo - 1 - Rectangle", "Rectangle", largeur, hauteur );
    Rectangle(largeur, hauteur);

	MLV_update_window();

	//
	// Attend 10 secondes avant la fin du programme.
	//
	MLV_wait_seconds( 6 );

	//
	// Ferme la fenêtre
	//
	MLV_free_window();
    return 0;
}