#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "jogo.h"

struct jogo{
    int empate;
    int pto_usuario;
    int pto_computador;
};


Jogo* jogo_cria(int empate, int pto_usuario, int pto_computador){
    Jogo* aux = (Jogo*) malloc(sizeof(Jogo));
    if(aux==NULL)
    {
        printf("Memoria eh insuficiente\n");
        exit(1);
    }
    aux->empate = empate;
    aux->pto_usuario = pto_usuario;
    aux->pto_computador = pto_computador;
    return aux;  
}

void jogo_libera(Jogo** j){
    free(*j);
    *j = NULL;
    
}

void jogar(Jogo **j, int jogada){
    srand(time(NULL));
    int jogada_computador = rand() % 3;
    printf("JOGADA COMPUTADOR: %d", jogada_computador);
    if ((jogada == 0 && jogada_computador == 2) || (jogada == 1 && jogada_computador == 0) || (jogada == 2 && jogada_computador == 1)){
        (*j)->pto_usuario++;
    }
    else if(jogada == jogada_computador){
        (*j)->empate++;
    }
    else {
        (*j)->pto_computador++;
    }

}
int get_ptousuario(Jogo *j){
    return j->pto_usuario;
}
int get_ptocomputador(Jogo *j){
    return j->pto_computador;
}
int get_empate(Jogo *j){
    return j->empate;
}

void set_ptousuario(Jogo *j, int novopto_usuario){
    j->pto_usuario = novopto_usuario;
}
void set_ptocomputador(Jogo *j, int novopto_computador){
    j->pto_computador = novopto_computador;
}

void set_empate(Jogo *j, int novo_empate){
    j->empate = novo_empate;
}

void jogo_imprime(Jogo *j){
    printf("\nPLACAR!\n");
    printf("USUARIO: %d\n", j->pto_usuario);
    printf("COMPUTADOR: %d\n", j->pto_usuario);
    printf("EMPATE: %d\n", j->empate);
    
}