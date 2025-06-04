#include <stdio.h>
#include <string.h> 

int main() {
    FILE *pArquivo;
    char nomeArquivo[104];
    int x, y, altura1, largura1;
    char fill[100];

    printf("Digite o nome do arquivo (sem extensão): ");
    scanf("%100s", nomeArquivo);
    strcat(nomeArquivo, ".svg");

    pArquivo = fopen(nomeArquivo, "w");

    if (pArquivo == NULL) {
        printf("O arquivo não foi aberto!\n");
    } else {
        printf("Digite a largura da pagina: ");
        scanf("%d", &largura1);
        printf("Digite a altura da pagina: ");
        scanf("%d", &altura1);
        fprintf(pArquivo, "<svg version='1.1' width='%d' height='%d'\n", largura1, altura1);

        fprintf(pArquivo, "     xmlns='http://www.w3.org/2000/svg'>\n");

        printf("Digite a coordenada x do quadrado: ");
        scanf("%d", &x);
        printf("Digite a coordenada y do quadrado: ");
        scanf("%d", &y);
        printf("Digite a largura do quadrado: ");
        scanf("%d", &largura1);
        printf("Digite a altura do quadrado: ");
        scanf("%d", &altura1);
        printf("Digite a cor do quadrado: ");
        scanf("%99s", fill);

        fprintf(pArquivo, "  <rect x='%d' y='%d' width='%d' height='%d' fill='%s' />\n", x, y, largura1, altura1, fill);

        fprintf(pArquivo, "</svg>\n");
        fclose(pArquivo);
        printf("O arquivo %s foi criado com sucesso.\n", nomeArquivo);
    }

    return 0;
}