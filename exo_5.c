//#include <ctype.h>
//#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>

void Rectangle(int largeur, int hauteur){
    MLV_draw_filled_rectangle(largeur/8, hauteur/4, largeur/2, hauteur/2, MLV_COLOR_GREEN);
}

void Ellipse(int largeur, int hauteur){
    MLV_draw_ellipse(largeur/2, hauteur/2, largeur/2, hauteur/2, MLV_COLOR_GREEN);
}

void Cercle(int largeur, int hauteur){
    MLV_draw_circle(largeur/2, hauteur/2, largeur/2, MLV_COLOR_GREEN);
}

void Cercle_epais(int largeur, int hauteur){
    int radius;
    int epaisseur;
    char *couleur = (char *) malloc(10 * sizeof(char));

    printf("Radius, epaisseur et color(Maj): \n");
    scanf("%d %d %s", &radius, &epaisseur, couleur);

    int i = 0;
    char res[20] = "MLV_COLOR_";
    while (*(couleur + i)) {
        res[10 + i] = couleur[i];
        ++i;
    }
    MLV_Color Color = MLV_convert_string_to_color(res);

    MLV_draw_filled_circle(largeur/2, hauteur/2, radius, Color);
    MLV_draw_filled_circle(largeur/2, hauteur/2, radius - epaisseur, MLV_COLOR_PINK);
    free(couleur);
}

void Cercle_anim(int largeur, int hauteur){
    int pas;
    printf("Give me pas: \n");
    scanf("%d", &pas);
    for (int i = 0; i <= largeur/2 && i <= hauteur/2; i += pas){
        MLV_draw_filled_circle(largeur/2, hauteur/2, hauteur, MLV_COLOR_BLACK);
        MLV_update_window();
        MLV_draw_filled_circle(largeur/2, hauteur/2, i, MLV_COLOR_PINK);
        MLV_update_window();
        MLV_wait_seconds( 1 );
    }
}

void Polygone(){
    int n;
    printf("Donne moi un nombre: \n");
    scanf("%d", &n);
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
    int count = 0;
    char **menu_draw = (char **) malloc (6 * sizeof(char *));
    for (int i = 0; i < 6; ++i){
        *(menu_draw + i) = (char *)malloc(15 * sizeof(char));
    }
    // "Ellipse", "Cercle", "Cercle_epais", "Cercle_anim", "Polygone"};
    *(menu_draw) = "Rectangle";
    *(menu_draw + 1) = "Ellipse";
    *(menu_draw + 2) = "Cercle";
    *(menu_draw + 3) = "Cercle_epais";
    *(menu_draw + 4) = "Cercle_anim";
    *(menu_draw + 5) = "Polygone";

    for (int i = 0; i < 2; ++i){
        for (int j = 0; j < 3; ++j){
            MLV_draw_filled_rectangle(largeur/8 + (j * 150), hauteur/4 + (i*150), largeur/6, hauteur/6, MLV_COLOR_WHITE);
            MLV_draw_text(largeur/8 + (j * 150), hauteur/4 + (i*150) + 30, *(menu_draw + count), MLV_COLOR_BLUE);
            count++;
        }
    }
    MLV_update_window();
    int x_mouse = 0, y_mouse = 0;
    MLV_wait_mouse(&x_mouse, &y_mouse);
    // Dessiner les figures d'après leur coordonnées
    
    if ((x_mouse > largeur/8 && x_mouse < largeur/8 + largeur/6) &&
     (y_mouse > hauteur/4 && y_mouse < hauteur/4 + hauteur/6)){
        MLV_draw_filled_circle(largeur/2, hauteur/2, hauteur, MLV_COLOR_BLACK);
        MLV_update_window();
        Rectangle(largeur, hauteur);
        MLV_update_window();
    }

    else if ((x_mouse > largeur/8 + 150 && x_mouse < largeur/8 + 150 + largeur/6) &&
     (y_mouse > hauteur/4 && y_mouse < hauteur/4 + hauteur/6)){
        MLV_draw_filled_circle(largeur/2, hauteur/2, hauteur, MLV_COLOR_BLACK);
        MLV_update_window();
        Ellipse(largeur, hauteur);
        MLV_update_window();
    }

    else if ((x_mouse > largeur/8 + 300 && x_mouse < largeur/8 + 300 + largeur/6) &&
     (y_mouse > hauteur/4 && y_mouse < hauteur/4 + hauteur/6)){
        MLV_draw_filled_circle(largeur/2, hauteur/2, hauteur, MLV_COLOR_BLACK);
        MLV_update_window();
        Cercle(largeur, hauteur);
        MLV_update_window();
    }

    else if ((x_mouse > largeur/8 && x_mouse < largeur/8 + largeur/6) &&
     (y_mouse > hauteur/4+150 && y_mouse < hauteur/4+150 + hauteur/6)){
        MLV_draw_filled_circle(largeur/2, hauteur/2, hauteur, MLV_COLOR_BLACK);
        MLV_update_window();
        Cercle_epais(largeur, hauteur);
        MLV_update_window();
    }

    else if ((x_mouse > largeur/8+150 && x_mouse < largeur/8+150 + largeur/6) &&
     (y_mouse > hauteur/4+150 && y_mouse < hauteur/4+150 + hauteur/6)){
        MLV_draw_filled_circle(largeur/2, hauteur/2, hauteur, MLV_COLOR_BLACK);
        MLV_update_window();
        Cercle_anim(largeur, hauteur);
        MLV_update_window();
    }

    else if ((x_mouse > largeur/8+300 && x_mouse < largeur/8+300 + largeur/6) &&
     (y_mouse > hauteur/4+150 && y_mouse < hauteur/4+150 + hauteur/6)){
        MLV_draw_filled_circle(largeur/2, hauteur/2, hauteur, MLV_COLOR_BLACK);
        MLV_update_window();
        Polygone();
        MLV_update_window();
    }

    MLV_update_window();
	MLV_wait_seconds( 6 );
    MLV_draw_filled_circle(largeur/2, hauteur/2, hauteur, MLV_COLOR_BLACK);
   
	MLV_free_window();
    for (int i = 0; i < 6; ++i){
        free(*(menu_draw + i));
    }
    free(menu_draw);
}


int main( int argc, char *argv[] ){
    int largeur = 500;
    int hauteur = 500;

    MLV_create_window( "Exo - 6 - Menu", "Menu", largeur, hauteur );

    // fprintf(stderr, "Avant cercle epais : color = %s\n", color);
    menu(largeur, hauteur);

    return 0;
}