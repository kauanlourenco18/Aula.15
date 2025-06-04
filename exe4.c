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

int circulo(FILE *arquivo) {
    int cx, cy, r, stroke_width;
    char fill[20], stroke[20];

    printf("Digite a coordenada cx da figura: ");
    scanf("%d", &cx);
    printf("Digite a coordenada cy da figura: ");
    scanf("%d", &cy);
    printf("Digite o raio da figura: ");
    scanf("%d", &r);
    printf("Digite a cor da figura: ");
    scanf("%19s", fill);
    printf("Digite a cor do contorno da figura: ");
    scanf("%19s", stroke);
    printf("Digite a espessura do contorno da figura: ");
    scanf("%d", &stroke_width);

    int retorno = fprintf(arquivo, "<circle cx='%d' cy='%d' r='%d' fill='%s' stroke='%s' stroke-width='%d' />\n", cx, cy, r, fill, stroke, stroke_width);
    if (retorno < 0){ 
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

    resultado = circulo(pArquivo);
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
