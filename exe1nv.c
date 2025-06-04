#include <stdio.h>

int abertura(FILE * arquivo) {
    int retorno = fprintf(arquivo, "<svg version=\"1.1\" ");

    if (retorno < 0) {
      return 0;
    }

    retorno = fprintf(arquivo, "width=\"300\" height=\"200\" ");

    if (retorno < 0) {
      return 0;
    }

    retorno = fprintf(arquivo, "xmlns=\"http://www.w3.org/2000/svg\">");

    if (retorno < 0) {
      return 0;
    }

    return 1;
  }

int fechamento(FILE * arquivo) {
  int retorno = fprintf(arquivo, "</svg>");

  if (retorno < 0) {
    return 0;
  }

  return 1;
}

int main(void) {
  FILE * pArquivo = NULL;

  pArquivo = fopen("quadrado.svg", "w");

  if (pArquivo == NULL) {
    printf("O arquivo não foi aberto!");
  } else {
    int resultado = abertura(pArquivo);
    if (resultado) {
      resultado = fprintf(pArquivo, "<rect x=\"20\" y=\"30\" width=\"100\" height=\"100\" fill=\"red\" />");

      if (resultado) {
        resultado = fechamento(pArquivo);
      }
    } else {
      printf("Erro ao gravar no arquivo.");
    }
  }

  fclose(pArquivo);
  return 0;
}