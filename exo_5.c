//#include <ctype.h>
//#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>

void Cercle_anim(int largeur, int hauteur, int pas){
    for (int i = 0; i <= largeur/2 && i <= hauteur/2; i += pas){
        MLV_draw_filled_circle(largeur/2, hauteur/2, i, MLV_COLOR_PINK);
        MLV_update_window();
        MLV_wait_seconds( 1 );
        MLV_draw_filled_circle(largeur/2, hauteur/2, hauteur, MLV_COLOR_BLACK);
        MLV_update_window();
    }
}


int main( int argc, char *argv[] ){
    int largeur;
    int hauteur;
    int pas;
    char color[20];
    printf("largeur, hauteur, pas: \n");
    scanf("%d %d %d", &largeur, &hauteur, &pas);

    MLV_create_window( "Exo - 4 - Animation", "Animation", largeur, hauteur );

    //Ellipse(largeur, hauteur);
    // fprintf(stderr, "Avant cercle epais : color = %s\n", color);
    Cercle_anim(largeur, hauteur, pas);

	MLV_update_window();

	MLV_wait_seconds( 6 );

	MLV_free_window();
    return 0;
}