#ifndef SVG_H
#define SVG_H

#include <stdio.h>

void iniciar_svg(FILE *arquivo, int largura, int altura);
void finalizar_svg(FILE *arquivo);

void desenhar_retangulo(FILE *arquivo, int x, int y, int w, int h, char *cor);
void desenhar_circulo(FILE *arquivo, int cx, int cy, int r, char *cor, char *contorno, int espessura);
void desenhar_linha(FILE *arquivo, int x1, int y1, int x2, int y2,char *contorno, int espessura);
void desenhar_texto(FILE *arquivo, int x, int y, char *texto, char *cor);

#endif
