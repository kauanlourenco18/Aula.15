#include <stdio.h>
#include <string.h>
#include "svg.h"

int main() {
    FILE *arquivo;
    char nomeArquivo[104];
    char opcao;
    int largura, altura;

    printf("Digite o nome do arquivo (sem extensão): ");
    scanf("%100s", nomeArquivo);
    strcat(nomeArquivo, ".svg");

    
    printf("Digite a largura do SVG: ");
    scanf("%d", &largura);

    printf("Digite a altura do SVG: ");
    scanf("%d", &altura);

    arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return 1;
    }

    iniciar_svg(arquivo, largura, altura);

    do {
        printf("\nEscolha a figura desejada:\nR - Retângulo\nC - Círculo\nL - Linha\nT - Texto\nF - Finalizar\n");
        printf("Opcao: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case 'R':
            case 'r': {
                int x, y, w, h;
                char cor[50];

                printf("Digite o valor de x: ");
                scanf("%d", &x);

                printf("Digite o valor de y: ");
                scanf("%d", &y);

                printf("Digite a largura: ");
                scanf("%d", &w);

                printf("Digite a altura: ");
                scanf("%d", &h);

                getchar();  
                printf("Digite a cor (ex: red, #ff0000): ");
                fgets(cor, sizeof(cor), stdin);
                cor[strcspn(cor, "\n")] = 0;

                desenhar_retangulo(arquivo, x, y, w, h, cor);
                break;
            }
            case 'C':
            case 'c': {
                int cx, cy, r, espessura;
                char cor[50], contorno[50];

                printf("Digite o valor de cx: ");
                scanf("%d", &cx);

                printf("Digite o valor de cy: ");
                scanf("%d", &cy);

                printf("Digite o raio: ");
                scanf("%d", &r);

                getchar();
                printf("Digite a cor de preenchimento: ");
                fgets(cor, sizeof(cor), stdin);
                cor[strcspn(cor, "\n")] = 0;

                printf("Digite a cor do contorno: ");
                fgets(contorno, sizeof(contorno), stdin);
                contorno[strcspn(contorno, "\n")] = 0;

                printf("Digite a espessura do contorno: ");
                scanf("%d", &espessura);

                desenhar_circulo(arquivo, cx, cy, r, cor, contorno, espessura);
                break;
            }
            case 'L':
            case 'l': {
                int x1, y1, x2, y2, espessura;
                char contorno[50];

                printf("Digite o valor de x1: ");
                scanf("%d", &x1);

                printf("Digite o valor de y1: ");
                scanf("%d", &y1);

                printf("Digite o valor de x2: ");
                scanf("%d", &x2);

                printf("Digite o valor de y2: ");
                scanf("%d", &y2);

                getchar();
                printf("Digite a cor da linha: ");
                fgets(contorno, sizeof(contorno), stdin);
                contorno[strcspn(contorno, "\n")] = 0;

                printf("Digite a espessura da linha: ");
                scanf("%d", &espessura);

                desenhar_linha(arquivo, x1, y1, x2, y2, contorno, espessura);
                break;
            }
            case 'T':
            case 't': {
                int x, y;
                char cor[50], texto[260];

                printf("Digite o valor de x: ");
                scanf("%d", &x);

                printf("Digite o valor de y: ");
                scanf("%d", &y);

                getchar();
                printf("Digite o texto: ");
                fgets(texto, sizeof(texto), stdin);
                texto[strcspn(texto, "\n")] = 0;

                printf("Digite a cor do texto: ");
                fgets(cor, sizeof(cor), stdin);
                cor[strcspn(cor, "\n")] = 0;

                desenhar_texto(arquivo, x, y, texto, cor);
                break;
            }
            case 'F':
            case 'f':
                printf("Finalizando e salvando o arquivo '%s'\n", nomeArquivo);
                finalizar_svg(arquivo);
                fclose(arquivo);
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }
    } while (opcao != 'F' && opcao != 'f');

    return 0;
}