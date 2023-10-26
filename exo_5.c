//#include <ctype.h>
//#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>

void Rectangle(int largeur, int hauteur){
    MLV_draw_filled_rectangle(largeur/8, hauteur/4, largeur/2, hauteur/2, MLV_COLOR_BLUE);
}

void Ellipse(int largeur, int hauteur){
    MLV_draw_ellipse(largeur/2, hauteur/2, largeur/2, hauteur/2, MLV_COLOR_BLUE);
}

void Cercle(int largeur, int hauteur){
    MLV_draw_circle(largeur/2, hauteur/2, largeur/2, MLV_COLOR_GREEN);
}

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

void Cercle_anim(int largeur, int hauteur, int pas){
    for (int i = 0; i <= largeur/2 && i <= hauteur/2; i += pas){
        MLV_draw_filled_circle(largeur/2, hauteur/2, i, MLV_COLOR_PINK);
        MLV_update_window();
        MLV_wait_seconds( 1 );
        MLV_draw_filled_circle(largeur/2, hauteur/2, hauteur, MLV_COLOR_BLACK);
        MLV_update_window();
    }
}

void Polygone(int n){
    int x_coords[n];
    int y_coords[n];
    int x, y;
    for (int i = 0; i < n; ++i){
        MLV_wait_mouse(&x, &y);
        *(x_coords + i) = x;
        *(y_coords + i) = y;
    }
    MLV_draw_polygon(x_coords, y_coords, n, MLV_COLOR_GREEN);
}

void menu(int largeur, int hauteur){
    // Rectangle
    // Ellipse
    // Cercle
    // Cercle_epais
    // Cercle_anim
    // Polygone
    
    for (int i = 0; i < 2; ++i){
        for (int j = 0; j < 3; ++j){
            MLV_draw_filled_rectangle(largeur/8 + (j * 150), hauteur/4 + (i*150), largeur/6, hauteur/6, MLV_COLOR_GREEN);
            MLV_draw_text(largeur/8 + (j * 150), hauteur/4 + (i*150), "Bonjour !", MLV_COLOR_MAGENTA);
        }
    }


}


int main( int argc, char *argv[] ){
    int largeur = 500;
    int hauteur = 500;
    //int n;
    // char color[20];
    //printf("n: ");
    //scanf("%d", &n);

    MLV_create_window( "Exo - 6 - Menu", "Menu", largeur, hauteur );

    // fprintf(stderr, "Avant cercle epais : color = %s\n", color);
    menu(largeur, hauteur);

	MLV_update_window();

	MLV_wait_seconds( 8 );

	MLV_free_window();

    return 0;
}