//#include <ctype.h>
//#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>

void Cercle_epais(int largeur, int hauteur, int radius, int epaisseur, char *couleur ){
    int i = 0;
    char res[20] = "MLV_COLOR_";
    while (*(couleur + i)) {
        res[10 + i] = couleur[i];
        ++i;
    }
    MLV_Color Color = MLV_convert_string_to_color(res);

    MLV_draw_filled_circle(largeur/2, hauteur/2, radius, Color);
    MLV_draw_filled_circle(largeur/2, hauteur/2, radius - epaisseur, MLV_COLOR_PINK);
}


int main( int argc, char *argv[] ){
    int largeur;
    int hauteur;
    int radius;
    int epaisseur;
    char color[20];
    printf("largeur, hauteur, radius, epaisseur et couleur: \n");
    scanf("%d %d %d %d %s", &largeur, &hauteur, &radius, epaisseur, color);

    MLV_create_window( "Exo - 4 - Animation", "Animation", largeur, hauteur );

    //Ellipse(largeur, hauteur);
    // fprintf(stderr, "Avant cercle epais : color = %s\n", color);
    Cercle_epais(largeur, hauteur, radius, color, epaisseur);

	MLV_update_window();

	MLV_wait_seconds( 6 );

	MLV_free_window();
    return 0;
}