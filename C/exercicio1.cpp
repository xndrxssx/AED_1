#include <iostream>

using namespace std;

int main() {
	
	struct nodo { 	/**/
		int n;
		struct nodo *prox; /*um ponteiro que cria uma estrutura auto-referenciada*/
	} typedef caixa;/*definindo um tipo caixa*/
	
	caixa *q, *r, *s; /*ponteiros do tipo caixa*/
	struct nodo t, a, b, c, d, e; /*to criando varias instancia da estrutura nodo*/
	int g; /*declaração normal de um inteiro*/
	
	/*fazendo as atrbuições para cada int n dos struct nodo*/
	a.n = 1;
	a.prox = &b;
	b.n = 2;
	b.prox = &c;
	c.n = 3;
	c.prox = &d;
	d.n = 4;
	d.prox = NULL;
	e.n = 5;
	e.prox = NULL;
	t.n = 6;
	t.prox = NULL;
	
	cout << a.n << endl;
	
	/*fazendo os ponteiros apontarem para as instancias desejadas de struct nodo*/
	
	q = &b;
	r = &d;
	s = &e;
	
	/*acessando o valor de n via q*/
	cout << "valor de n via q: "<< q->n << endl; 
	
	q = q->prox; /*teoricamente ele aponta pra o nodo c onde n = 3;*/
	cout << "valor de n em q depois de apontar pra c: " << q -> n << endl;
	/*teoricamente isso vai me retornar um endereço de memoria que estará relacionado ao
	prox de c*/
	cout << "vendo o que tem dentro de prox em q: " << q -> prox << endl;
	/*verificando o endereço de c prox*/
	cout << c.prox << endl;
	
	
	return 0;
}
