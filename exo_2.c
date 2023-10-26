//#include <ctype.h>
//#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>

void Ellipse(int largeur, int hauteur){
/*
 *     int       x,         Coordonnée en X du centre de l'ellipse
 *     int       y,         Coordonnée en Y du centre de l'ellipse
 *     int       radius_x,  Rayon en X de l'ellipse
 *     int       radius_y,  Rayon en Y de l'ellipse
 *     MLV_Color color      Couleur du tracé
*/
    MLV_draw_ellipse(largeur/2, hauteur/2, largeur/2, hauteur/2, MLV_COLOR_BLUE);
}

void Cercle(int largeur, int hauteur){
/*
 *    int         x,          Coordonnée en X du centre du cercle
 *    int         y,          Coordonnée en Y du centre du cercle
 *    int         radius,     Rayon du cercle
 *    MLV_Color   color       Couleur du tracé
 */
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