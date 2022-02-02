# ifndef jogo_h
# define jogo_h

# include <stdio.h>

typedef struct jogo Jogo;

Jogo* jogo_cria(int empate, int pto_usuario, int pto_computador);

void jogo_libera(Jogo** j);

void jogar(Jogo **j, int jogada);
int get_ptousuario(Jogo *j);
int get_ptocomputador(Jogo *j);
int get_empate(Jogo *j);

void set_ptousuario(Jogo *j, int novopto_usuario);
void set_ptocomputador(Jogo *j, int novopto_computador);

void set_empate(Jogo *j, int novo_empate);
void jogo_imprime(Jogo *j);

# endif
