#include <stdio.h>
#include <string.h>

int abertura(FILE *arquivo, int *altura, int *largura) {
    int retorno;

    printf("Digite a largura da pagina: ");
    scanf("%d", largura);
    printf("Digite a altura da pagina: ");
    scanf("%d", altura);

    retorno = fprintf(arquivo, "<svg viewBox='0 0 %d %d'\n", *largura, *altura);
    if (retorno < 0) {
     return 0;
}
    retorno = fprintf(arquivo, "xmlns='http://www.w3.org/2000/svg'>\n");
    if (retorno < 0) { 
    return 0;
}
    return 1;
}

int linha(FILE *arquivo) {
    int x1, y1, x2, y2, stroke_width;
    char fill[20], stroke[20];

    printf("Digite a coordenada x1 da figura: ");
    scanf("%d", &x1);
    printf("Digite a coordenada y1 da figura: ");
    scanf("%d", &y1);
    printf("Digite a coordenada x2 da figura: ");
    scanf("%d", &x2);
    printf("Digite a coordenada y2 da figura: ");
    scanf("%d", &y2);
    printf("Digite a cor da linha: ");
    scanf("%19s", stroke);
    printf("Digite a espessura linha: ");
    scanf("%d", &stroke_width);

    int retorno = fprintf(arquivo, " <line x1='%d' y1='%d' x2='%d' y2='%d' stroke='%s' stroke-width='%d' />\n", x1, y1, x2, y2, stroke, stroke_width);
    if (retorno < 0) { 
    return 0;
    }
    return 1;
}
int fechamento(FILE *arquivo) {
    int retorno = fprintf(arquivo, "</svg>\n");
    if (retorno < 0) {
    return 0;
}
    return 1;
}

int main(void) {
    FILE *pArquivo = NULL;
    char nomeArquivo[104];
    int altura, largura, resultado;

    printf("Digite o nome do arquivo (sem extensão): ");
    scanf("%100s", nomeArquivo);
    strcat(nomeArquivo, ".svg");

    pArquivo = fopen(nomeArquivo, "w");
    if (pArquivo == NULL) {
        printf("O arquivo não foi aberto!\n");
        return 1;
    }

    resultado = abertura(pArquivo, &altura, &largura);
    if (resultado == 0) {
        printf("Erro na abertura do arquivo SVG.\n");
        fclose(pArquivo);
        return 1;
    }

    resultado = linha(pArquivo);
    if (resultado == 0) {
        printf("Erro ao escrever o círculo no SVG.\n");
        fclose(pArquivo);
        return 1;
    }

    resultado = fechamento(pArquivo);
    if (resultado == 0) {
        printf("Erro ao finalizar o arquivo SVG.\n");
        fclose(pArquivo);
        return 1;
    }

    fclose(pArquivo);
    printf("O arquivo %s foi criado com sucesso.\n", nomeArquivo);
    return 0;
}
