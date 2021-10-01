#include <stdio.h>
#include <stdlib.h>

char jogo[3][3];
int vez = 1, cont = 0, cont1 = 0, cont2 = 0;

typedef struct{
    float porcJogador1, porcJogador2;
} Porcentagem;

void iniciarMatriz() {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            jogo[i][j] = ' ';
    cont ++;
}

void mostrarTabuleiroJogo() {
    system(" color F2 ");
    printf("\t\t\tTrabalho Final - IPE II\n\t\t\t     JOGO DA VELHA\n\n\t\t\t        1   2   3\n\t\t\t      -------------\n");
    for(int i = 0; i < 3; i++) {
        printf("\t\t\t    %d |", i+1);
        for(int j = 0; j < 3; j++)
            if(j < 3)
                printf(" %c |", jogo[i][j]);
            else
                printf(" %c ", jogo[i][j]);
        printf("\n\t\t\t      -------------\n");
    }
}

int simbolosJogo(char s) {
    if(s == 'X' || s == '0')
        return 1;
    else
        return 0;
}

int verificarLocal(int l, int c) {
    if(l < 0 || l > 2 || c < 0 || c > 2 || jogo[l][c] != 0)
        return 1;
    else
        return 0;
}

int verificarPosicaoVazia(int l, int c) {
    if(jogo[l][c] != 'X' && jogo[l][c] != '0')
        return 1;
    return 0;
}

int verificarLinhas() {
    int s = 1;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 2; j++)
            if(simbolosJogo(jogo[i][j]) && jogo[i][j] == jogo[i][j+1])
                s++;
        if(s == 3)
            return 1;
        s = 1;
    }
    return 0;
}

int verificarColunas() {
    int s = 1;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 2; j++)
            if(simbolosJogo(jogo[j][i]) && jogo[j][i] == jogo[j+1][i])
                s++;
        if(s == 3)
            return 1;
        s = 1;
    }
    return 0;
}

int verificarDiagonalPrincipal() {
    int s = 1;
    for(int i = 0; i < 2; i++) {
        if(simbolosJogo(jogo[i][i]) && jogo[i][i] == jogo[i+1][i+1])
            s++;
    }
    if(s == 3)
        return 1;
    return 0;
}

int verificarDiagonalSecundaria() {
    int s = 1;
    for(int i = 0; i < 2; i++) {
        if(simbolosJogo(jogo[i][3-i-1]) && jogo[i][3-i-1] == jogo[i+1][3-i-2])
            s++;
    }
    if(s == 3)
        return 1;
    return 0;
}

void jogar() {
    int x, y, verificar, contJog = 0, v = 0, o = 1;
    do {
        do {
            vez ++;
            mostrarTabuleiroJogo();
            printf("\n\nJogador %d\n\nDigite a linha e coluna: ", (vez % 2) + 1);
            scanf("%d %d", &x, &y);
            x--;
            y--;

            verificar = verificarLocal(x, y);
            if(verificar == 1)
                verificar += verificarPosicaoVazia(x, y);
                system("cls");
        } while(verificar != 2);

        if(o == 1)
            jogo[x][y] = 'X';
        else
            jogo[x][y] = '0';
        contJog++;
        o++;

        if(o == 3)
            o = 1;

        v += verificarLinhas();
        v += verificarColunas();
        v += verificarDiagonalPrincipal();
        v += verificarDiagonalSecundaria();
        system("cls");
    } while(v == 0 && contJog < 9);

    if(v != 0) {
        mostrarTabuleiroJogo();
        if(o - 1 == 1){
            printf("\n\n\t\t\t    Jogador 1 venceu!!\n");
            cont1++;
        }else{
            printf("\n\n\t\t\t    Jogador 2 venceu!!\n");
            cont2++;
        }
    }else
        printf("\nDEU VELHA!!\n");
}

void relatorioPartida(Porcentagem p){
    system(" color F2 ");
    p.porcJogador1 = (cont1*100)/cont;
    p.porcJogador2 = (cont2*100)/cont;
    printf("\t\t\t\tTrabalho Final - IPE II\n\t\t\t\t     JOGO DA VELHA");
    printf("\n----------------------------------------------------------------------------------------\n");
    printf("\n\t\t\t\tRELATORIO DA PARTIDA\n\n\t\t\t\t Partidas jogadas: %d\n", cont);
    printf("\nPartidas vencidas Jogador 1: %d\t\t\tPartidas vencidas Jogador 2: %d", cont1, cont2);
    printf("\nPorcentagem de vitoria Jogador 1: %.1f\t\tPorcentagem de vitoria Jogador 2: %.1f\n", p.porcJogador1, p.porcJogador2);
    printf("\n----------------------------------------------------------------------------------------\n");
}

int main() {
    system(" color F2 ");
    Porcentagem p;
    int op;
    printf("\t\t\tTrabalho Final - IPE II\n\t\t\t      JOGO DA VELHA\n");
    do {
        printf("\n1. Iniciar jogo\n0. Sair\n\nOp: ");
        scanf("%d", &op);
        system("cls");
        switch(op){
            case 1: iniciarMatriz();
                    jogar();
                    break;
            case 0: system("cls");
                    relatorioPartida(p);
                    break;
            default: printf("\n\nOpcao invalida!!\n");
        }
    } while(op == 1);
    return 0;
}
