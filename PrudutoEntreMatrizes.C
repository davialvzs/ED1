#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#ifdef _WIN32   //Basicamente, muda a posição do cursor. If pra win e else pra linux.
    #include <windows.h>
        void posicao_cursor(int x, int y){ // Usa a Api do win com esse fim
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            COORD pos = {x, y}; //move pra posição x, y no console do win
            SetConsoleCursorPosition(hConsole, pos);
        }
    #define SLEEP(ms) Sleep((ms) / 3000)
#else
    #include <unistd.h>
        void posicao_cursor(int x, int y){ // Usa codigos ansi (codigos de escape do terminal) pra moover o cursor
            printf("\033[%d;%dH", y, x); //move pra posição x, y no console do linux
            fflush(stdout);
        }
    #define SLEEP(ms) usleep((ms) * 1000)
#endif
//----------------------------------------------------
void definir_tamanho_janela() { //Auto explicativo
    #ifdef _WIN32
        system("mode CON: cols=30 lines=77"); //30 colunas e 77 linhas
    #else
        printf("\e[8;30;77t");  //30 colunas e 77 linhas
    #endif
}

void limpa_tela() { //Auto explicativo
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void efeito_texto(const char *texto, int x, int y, int delay) { // Simula efeito de digitação
    posicao_cursor(x, y); //posiciona na posição desejada
    while (*texto){ // enquanto o ponteiro nao apontar pra "\0" (o final da string)
        printf("%c", *texto);
        fflush(stdout);
        SLEEP(delay);
        texto++;
    }
}

//-----------------------------------------------------------------

void desenho_inicial() {
    limpa_tela();
    printf("             _________________________________________________\n");
    printf("            /                                                 \\\n");
    printf("           |    _________________________________________     |\n");
    printf("           |   |                                         |    |\n");
    printf("           |   |                                         |    |\n");
    printf("           |   |                                         |    |\n");
    printf("           |   |                                         |    |\n");
    printf("           |   |                                         |    |\n");
    printf("           |   |                                         |    |\n");
    printf("           |   |                                         |    |\n");
    printf("           |   |                                         |    |\n");
    printf("           |   |                                         |    |\n");
    printf("           |   |                                         |    |\n");
    printf("           |   |                                         |    |\n");
    printf("           |   |                                         |    |\n");
    printf("           |   |_________________________________________|    |\n");
    printf("           |                                                  |\n");
    printf("            \\_________________________________________________/\n");
    printf("                   \\___________________________________/\n");
    printf("                ___________________________________________\n");
    printf("             _-'    .-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.  --- `-_\n");
    printf("          _-'.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.  .-.-.`-_\n");
    printf("       _-'.-.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-`__`. .-.-.-.`-_\n");
    printf("    _-'.-.-.-.-. .-----.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-----. .-.-.-.-.`-_\n");
    printf(" _-'.-.-.-.-.-. .---.-. .-------------------------. .-.---. .---.-.-.-.`-_\n");
    printf(":-------------------------------------------------------------------------:\n");
    printf("`---._.-------------------------------------------------------------._.---'\n");

     /*Chama a função efeito_texto pra dar efeito de digitação

                                               x , y, delay                */
    efeito_texto("Wine Matriz_trabalho.exe\n", 18, 5, 500000);
    efeito_texto("1) Jogar\n", 19, 7, 500000);
    efeito_texto("2) Sair\n", 19, 8, 500000);
    efeito_texto("_", 19, 10, 500000);

}

void creditos(){
    printf("                    _  _     __  __       _        _     \n");
    printf("                  _| || |_  |  \\/  |     | |      (_)    \n");
    printf("                 |_  __  _| | \\  / | __ _| |_ _ __ _ ____\n");
    printf("                  _| || |_  | |\\/| |/ _` | __| '__| |_  /\n");
    printf("                 |_  __  _| | |  | | (_| | |_| |  | |/ / \n");
    printf("                   |_||_|   |_|  |_|\\__,_|\\__|_|  |_/___|\n");

    printf("\n\n       #+===========================================================+#  \n");
    printf("      |        Jogo desenvolvido por Rafaela, Davi, Julia e Isabele   |  \n");
    printf("     |                                                                 |  \n");
    printf("      |                         - Versao 1.0 -                        |\n");
    printf("       #+===========================================================+#\n");

    printf("\n\n\n     +------+.      +------+       +------+       +------+      .+------+\n");
    printf("     |`.    | `.    |\\     |\\      |      |      /|     /|    .' |    .'|\n");
    printf("     |  `+--+---+   | +----+-+     +------+     +-+----+ |   +---+--+'  |\n");
    printf("     |   |  |   |   | |    | |     |      |     | |    | |   |   |  |   |\n");
    printf("     +---+--+.  |   +-+----+ |     +------+     | +----+-+   |  .+--+---+\n");
    printf("      `. |    `.|    \\|     \\|     |      |     |/     |/    |.'    | .'\n");
    printf("        `+------+     +------+     +------+     +------+     +------+'\n");
    getchar();
}

void saida() {

       printf("        _                                                           _   \n");
   printf("      _| |_ _____ _____ _____ _____ _____ _____ _____ _____ _____ _| |_ \n");
   printf("     |_   _|_____|_____|_____|_____|_____|_____|_____|_____|_____|_   _|   \n");
   printf("       |_|        ___  _          _                 _              |_|  \n");
   printf("       | |       / _ \\| |__  _ __(_) __ _  __ _  __| | __ _        | | \n");
   printf("       | |      | | | | '_ \\| '__| |/ _` |/ _` |/ _` |/ _` |       | | \n");
   printf("       | |      | |_| | |_) | |  | | (_| | (_| | (_| | (_| |       | |  \n");
   printf("       | |       \\___/|_.__/|_|  |_|\\__, |\\__,_|\\__,_|\\__,_|       | | \n");
   printf("       |_|                          |___/                    _     |_| \n");
   printf("       | |     _ __   ___  _ __    (_) ___   __ _  __ _ _ __| |    | |  \n ");
   printf("      | |    | '_ \\ / _ \\| '__|   | |/ _ \\ / _` |/ _` | '__| |    | | \n");
   printf("       | |    | |_) | (_) | |      | | (_) | (_| | (_| | |  |_|    | |  \n");
   printf("       | |    | .__/ \\___/|_|     _/ |\\___/ \\__, |\\__,_|_|  (_)    | |  \n");
   printf("       |_|    |_|                |__/       |___/                  |_|   \n");
   printf("      _| |_ _____ _____ _____ _____ _____ _____ _____ _____ _____ _| |_   \n");
   printf("     |_   _|_____|_____|_____|_____|_____|_____|_____|_____|_____|_   _|    \n");
   printf("       |_|                                                         |_|   \n");
   printf("\n\t\t       >--------- *\\(^_~)/* ---------<\n");
}

int calcularElemento(int **A, int **B, int linha, int coluna, int k, int n, int soma) {
    if (k == n) return soma;
    return calcularElemento(A, B, linha, coluna, k + 1, n, soma + A[linha][k] * B[k][coluna]);
}

void multiplicarRecursivo(int **A, int **B, int **C, int m, int n, int r, int i, int j) {
    if (i == m) return;
    if (j == r) {
        multiplicarRecursivo(A, B, C, m, n, r, i + 1, 0);
        return;
    }
    C[i][j] = calcularElemento(A, B, i, j, 0, n, 0);
    multiplicarRecursivo(A, B, C, m, n, r, i, j + 1);
}

int **alocarMatriz(int linhas, int colunas) {
    int **matriz = (int **)malloc(linhas * sizeof(int *));
    for (int i = 0; i < linhas; i++)
        matriz[i] = (int *)malloc(colunas * sizeof(int));
    return matriz;
}

void liberarMatriz(int **matriz, int linhas) {
    for (int i = 0; i < linhas; i++)
        free(matriz[i]);
    free(matriz);
}


void preencherMatriz(int **matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++)
        for (int j = 0; j < colunas; j++)
            scanf("%d", &matriz[i][j]);
}


void imprimirMatriz(int **matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }
}

void menu() {
    int opcao;
    do {
        desenho_inicial();
        if (scanf("%d", &opcao) != 1 || opcao < 1 || opcao > 2) {
            getchar();
            efeito_texto("\n           |   |  > Opção inválida! Tente novamente.\n", 19, 12, 50);
            SLEEP(1100);
            continue;
        }
        switch (opcao) {
            case 1:
                limpa_tela();
                return;
            case 2:
                limpa_tela();
                saida();
                exit(0);
        }
    } while (1);
}


int main() {
    definir_tamanho_janela();

    char jogar_novamente = 's';

    menu();
            //tolower onverte letra maiúscula em minúscula, basicamente pra reconhecer ambas como resposta
    while(tolower(jogar_novamente) == 's') { // Loop pra perguntar se quer jogar novamente
        limpa_tela();

        int m, n, r;

        printf("Digite as dimensões da matriz A (m n): ");
        scanf("%d %d", &m, &n);
        printf("Digite as dimensões da matriz B (r): ");
        scanf("%d", &r);

        int **A = alocarMatriz(m, n);
        int **B = alocarMatriz(n, r);
        int **C = alocarMatriz(m, r);

        printf("Digite os elementos da matriz A:\n");
        preencherMatriz(A, m, n);

        printf("Digite os elementos da matriz B:\n");
        preencherMatriz(B, n, r);

        multiplicarRecursivo(A, B, C, m, n, r, 0, 0);

        printf("Matriz Resultante C:\n");
        imprimirMatriz(C, m, r);

        liberarMatriz(A, m);
        liberarMatriz(B, n);
        liberarMatriz(C, m);

        printf("\n");
        printf("\n                      +-------------------------------+\n");
        printf("===================== | Deseja jogar novamente? (s/n) | ====================\n");
        printf("                      +-------------------------------+\n");
        printf("> ");
        getchar();


        do { //Condição de erro
            if (scanf("%c", &jogar_novamente) != 1 || strchr("sSnN", jogar_novamente) == NULL) {
                limpa_tela();
                printf("\n\t\t     ~* Hey, nao pode! Tente novamente. *~\n");
                printf("\n");
                printf("\n                      +-------------------------------+\n");
                printf("===================== | Deseja jogar novamente? (s/n) | ====================\n");
                printf("                      +-------------------------------+\n");
                printf("> ");
            }
        } while (strchr("sSnN", jogar_novamente) == NULL); //Strchr = se tiver esses caracteres tá certo, se nao tiver ele o loop vai continuar
    }
    getchar();
    limpa_tela();
    creditos();
    limpa_tela();
    saida();
    return 0;
}
