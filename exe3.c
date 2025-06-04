#include <stdio.h>
#include <string.h>

int abertura(FILE *arquivo, int *largura1, int *altura1) {
    int retorno = fprintf(arquivo, "<svg version='1.1'\n");
    if (retorno < 0) {
        return 0;
    } 

    printf("Digite a largura da página: ");
    scanf("%d", largura1);
    printf("Digite a altura da página: ");
    scanf("%d", altura1);

    retorno = fprintf(arquivo, "width='%d' height='%d'\n", *largura1, *altura1);
    if (retorno < 0) return 0;

    retorno = fprintf(arquivo, "xmlns='http://www.w3.org/2000/svg'>\n");
    if (retorno < 0) return 0;

    return 1;
}

int retangulo(FILE *arquivo) {
    int x, y, altura2, largura2;  
    char cor[20]; 

    printf("Digite a coordenada x do retangulo: ");
    scanf("%d", &x);
    printf("Digite a coordenada y do retangulo: ");
    scanf("%d", &y);
    printf("Digite a largura do retangulo:: ");
    scanf("%d", &largura2);
    printf("Digite a altura do retangulo: ");
    scanf("%d", &altura2);
    printf("Digite a cor do retangulo: ");
    scanf("%19s", cor);

    int retorno = fprintf(arquivo, "<rect x='%d' y='%d' width='%d' height='%d' fill='%s' />\n", x, y, largura2, altura2, cor);
    if (retorno < 0) return 0;
    return 1;
}

int fechamento(FILE *arquivo) {
    int retorno = fprintf(arquivo, "</svg>\n");
    if (retorno < 0) return 0;
    return 1;
}

int main(void) {
    FILE *pArquivo = NULL;
    char nomeArquivo[104];
    int largura, altura, resultado;

    printf("Digite o nome do arquivo (sem extensão): ");
    scanf("%100s", nomeArquivo);
    strcat(nomeArquivo, ".svg");

    pArquivo = fopen(nomeArquivo, "w");
    if (pArquivo == NULL) {
        printf("O arquivo não foi aberto!\n");
        return 1; 
    }

    resultado = abertura(pArquivo, &largura, &altura);
    if (resultado == 0) {
        printf("Erro na abertura do %s\n", nomeArquivo);
        fclose(pArquivo);
        return 1;
    }

    resultado = retangulo(pArquivo);
    if (resultado == 0) {
        printf("Erro ao escrever o %s.\n", nomeArquivo);
        fclose(pArquivo);
        return 1;
    }

    resultado = fechamento(pArquivo);
    if (resultado == 0) {
        printf("Erro no fechamento do arquivo SVG.\n");
        fclose(pArquivo);
        return 1;
    }

    fclose(pArquivo);
    printf("O arquivo %s foi criado com sucesso.\n", nomeArquivo);
    return 0;
}
