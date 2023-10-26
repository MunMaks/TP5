//#include <ctype.h>
//#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>

void Ellipse(int largeur, int hauteur){
    MLV_draw_ellipse(largeur/2, hauteur/2, largeur/2, hauteur/2, MLV_COLOR_BLUE);
}

void Cercle(int largeur, int hauteur){
    MLV_draw_circle(largeur/2, hauteur/2, largeur/2, MLV_COLOR_GREEN);
}


int main( int argc, char *argv[] ){
    int largeur;
    int hauteur;
    
    printf("largeur et hauteur: \n");
    scanf("%d %d", &largeur, &hauteur);

    MLV_create_window( "Exo - 2 - Ellipse", "Ellipse", largeur, hauteur );
    
    //Ellipse(largeur, hauteur);
    Cercle(largeur, hauteur);

	MLV_update_window();

	MLV_wait_seconds( 6 );

	MLV_free_window();
    return 0;
}