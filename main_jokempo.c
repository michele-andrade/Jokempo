#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "jogo.h"

int main(){
    Jogo* j = jogo_cria(0, 0, 0);

    int vitoria_usuario = 0;
    int vitoria_computador = 0;
    int placar_empate = 0;

    int jogada;

    printf("BEM VINDO AO JOKEMPO!\n");
    printf("0->pedra\n");
    printf("1->papel\n");
    printf("2->tesoura\n");
    

    for(int i = 0; i < 5; i++){
        printf("\nPARTIDA %d\n", i + 1);
        printf("\nDIGITE SUA JOGADA!\n");
        scanf("%d", &jogada);
        jogar(&j, jogada);
        int empate = get_empate(j);
        int pto_usuario = get_ptousuario(j);
        int pto_computador = get_ptocomputador(j);
        set_ptousuario(j, pto_usuario);
        set_ptocomputador(j, pto_computador);
        set_empate(j, empate);
    }
    int empate = get_empate(j);
    int pto_usuario = get_ptousuario(j);
    int pto_computador = get_ptocomputador(j);
    if (pto_usuario > pto_computador){
        vitoria_usuario++;
    }
    else if (pto_usuario < pto_computador){
        vitoria_computador++;
    }
    else{
        placar_empate++;
    }
    jogo_imprime(j);
    printf("\nO PLACAR DA 1 PARTIDA É:\n");
    printf("USUARIO: %d  COMPUTADOR: %d  EMPATE: %d\n", vitoria_usuario, vitoria_computador, placar_empate);

    char continuar;
    printf("DIGITE (c) PARA CONTINUAR OU (p) para parar: ");
    scanf("\n%c", &continuar);
    while (continuar == 'c'){
        for(int i = 0; i < 2; i++){ 
            printf("PARTIDA %d\n", i + 1);
            printf("\nDIGITE SUA JOGADA!\n");
            scanf("%d", &jogada);
            jogar(&j, jogada);
            int empate = get_empate(j);
            int pto_usuario = get_ptousuario(j);
            int pto_computador = get_ptocomputador(j);
            set_ptousuario(j, pto_usuario);
            set_ptocomputador(j, pto_computador);
            set_empate(j, empate);
        }
        int empate = get_empate(j);
        int pto_usuario = get_ptousuario(j);
        int pto_computador = get_ptocomputador(j);
        if (pto_usuario > pto_computador){
            vitoria_usuario++;
        }
        else if (pto_usuario < pto_computador){
            vitoria_computador++;
        }
        else{
            placar_empate++;
        }
        jogo_imprime(j);
        printf("\nO PLACAR DA PARTIDA É:\n");
        printf("USUARIO: %d  COMPUTADOR: %d  EMPATE: %d\n", vitoria_usuario, vitoria_computador, placar_empate);

        printf("DIGITE (c) PARA CONTINUAR OU (p) para parar: ");
        scanf("\n%c", &continuar);
    }
    printf("\nO PLACAR FINAL É:\n");
    printf("USUARIO: %d  COMPUTADOR: %d  EMPATE: %d\n", vitoria_usuario, vitoria_computador, placar_empate);

    jogo_libera(&j);




    return 0;
}