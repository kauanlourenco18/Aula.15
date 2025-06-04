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

int texto(FILE *arquivo) {
    int x1, y1;
    char texto[100], cor[50]; 

    printf("Digite a coordenada x do texto: ");
    scanf("%d", &x1);
    printf("Digite a coordenada y do texto: ");
    scanf("%d", &y1);
    printf("Digite a cor do texto: ");
    scanf("%s", cor);  
    printf("Digite o texto: ");

    while (getchar() != '\n');  
    fgets(texto, sizeof(texto), stdin);
    texto[strcspn(texto, "\n")] = 0; 

    int retorno = fprintf(arquivo, "  <text x=\"%d\" y=\"%d\" fill=\"%s\">%s</text>\n", x1, y1, cor, texto);
    if (retorno < 0) {
        printf("Erro ao escrever o texto no arquivo SVG.\n");
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

    resultado = texto(pArquivo);
    if (resultado == 0) {
        printf("Erro ao escrever o texto no SVG.\n");
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
