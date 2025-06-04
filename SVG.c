#include <stdio.h>
#include <stdlib.h>
#include "svg.h"

void iniciar_svg(FILE *arquivo, int largura, int altura) {
    fprintf(arquivo, "<svg xmlns='http://www.w3.org/2000/svg' width='%d' height='%d'>\n",
            largura, altura);
}

void finalizar_svg(FILE *arquivo) {
    fprintf(arquivo, "</svg>\n");
}

void desenhar_retangulo(FILE *arquivo, int x, int y, int w, int h, char *cor) {
    fprintf(arquivo, "<rect x='%d' y='%d' width='%d' height='%d' fill='%s' />\n", x, y, w, h, cor);
}

void desenhar_circulo(FILE *arquivo, int cx, int cy, int r, char *cor, char *contorno, int espessura) {
    fprintf(arquivo,"<circle cx='%d' cy='%d' r='%d' fill='%s' stroke='%s' stroke-width='%d' />\n", cx, cy, r, cor, contorno, espessura);
}

void desenhar_linha(FILE *arquivo, int x1, int y1, int x2, int y2, char *contorno, int espessura) {
    fprintf(arquivo, "<line x1='%d' y1='%d' x2='%d' y2='%d' stroke='%s' stroke-width='%d' />\n", x1, y1, x2, y2, contorno, espessura);
}

void desenhar_texto(FILE *arquivo, int x, int y, char *texto, char *cor) {
    fprintf(arquivo,"<text x='%d' y='%d' fill='%s' font-family='Arial' font-size='16'>%s</text>\n", x, y, cor, texto);
}
