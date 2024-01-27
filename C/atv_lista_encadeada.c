/*
	versão com retorno do ponteiro da lista após as mudanças
*/
#include <stdio.h>
#include <stdlib.h>

typedef int tipo;

typedef struct nodo{
	tipo info;
	struct nodo *lig;
	
}nodo;

nodo* create(){
	return NULL;
}

nodo* insere_prim(nodo *lista, tipo info){
	nodo *p;
	p=(nodo*)malloc(sizeof(nodo));
	
	p->info=info;
	p->lig=NULL;
	
	return p;
}

nodo* insere_inic(nodo *lista, tipo info){
	nodo *p;
	p=(nodo*)malloc(sizeof(nodo));
	
	p->info=info;
	p->lig=lista;
	lista=p;
	
	return lista;
	
}

void prim(nodo *lista){
	if(lista == NULL){
		printf("\nerro\n");
	}
	else{
		while(lista != NULL){
			printf("%d ", lista->info);
			lista=lista->lig;
		}
	}
}

void ultimo(nodo *lista){
	tipo a;
	if(lista == NULL){
		printf("\nLista vazia.\n");
	}else{
		while(lista->lig != NULL){
			lista=lista->lig;
			a=lista->info;
		}
		printf("\nO ultimo elemento da lista eh: %d\n", a);
	}
}

void n_elem(nodo *lista){
	tipo num=0;
	
	if(lista == NULL){
		printf("/nErro na contagem de elementos");
	}else{
		while(lista != NULL){
			num++;
			lista=lista->lig;		
		}
		printf("\nA lista tem %d elementos.\n", num);
	}
}

nodo* insere_depois(nodo **lista, tipo v, nodo *k){
    nodo *novo_bloco, *aux=k;
    novo_bloco=(nodo*)malloc(sizeof(nodo));
    
	if(*lista==NULL) printf("Não há elementos na lista.\n");
    
	if (!novo_bloco) {
        printf("Falha na alocação de memória.\n");
		return *lista;
    }
	
	novo_bloco->info=v;
    novo_bloco->lig=aux->lig;
	aux->lig=novo_bloco;

	return *lista;
}

nodo* elimina_depois(nodo **lista, nodo *k, nodo *j){
	
	k->lig=j->lig;
	free(j);

	return *lista;
}

nodo* remove_primeiro(nodo *lista){
	nodo *p;

	p=lista;
	lista=lista->lig;
	free(p);

	return lista;
}

nodo* elimina(tipo v, nodo *lista){
    nodo *p, *pa, *temp;   
    pa=NULL;
    p=lista;

    while(p!=NULL) {
        if (p->info==v) {
            if (pa!=NULL) {
                pa->lig=p->lig;
            } else {
                lista=p->lig;
            }
            temp=p;
            p=pa->lig;
            free(temp);
        } else {
            pa=p;
            p=p->lig;
        }
    }
    return lista;
}

nodo* inserir_antes(nodo **lista, tipo v, nodo *p){
	nodo *q=(nodo*)malloc(sizeof(nodo));

	q->info=p->info;
	q->lig=p->lig;
	p->info=v;
	p->lig=q;

	return *lista;	
}

nodo* cria_lista_num(nodo **lista_dois, tipo num){
	nodo *novo_bloco, *aux=NULL;
	while(num>0){
		novo_bloco=(nodo*)malloc(sizeof(nodo));
		novo_bloco->lig=aux;
		novo_bloco->info=num;
		aux=novo_bloco;

		num--;
	}
	*lista_dois=aux;
	return *lista_dois;
}

int main() {
	nodo *lista;
    tipo a;
    
    lista=create();
    
	printf("\nInsira elementos na lista:\n");
    scanf("%d", &a);
    lista=insere_prim(lista, a);
    setbuf(stdin, NULL);
    
    scanf("%d", &a);
    lista=insere_inic(lista, a);
    setbuf(stdin, NULL);
    
    printf("\n");
    prim(lista);
	ultimo(lista);
	n_elem(lista);

	printf("\nInsira mais um elemento depois na lista:\n");
	scanf("%d", &a);
	setbuf(stdin, NULL);

	nodo *k;
	k=lista; //se k=lista->prox ele adiciona depois
	lista=insere_depois(&lista, a, k);

	scanf("%d", &a);
	setbuf(stdin, NULL);
	lista=insere_depois(&lista, a, k);

	printf("\n");
    prim(lista);
	ultimo(lista);
	n_elem(lista);

	printf("\nLista completa:\n");
    prim(lista);

	printf("\nElimina o elemento depois:\n");
	nodo *j=k->lig;
	lista=elimina_depois(&lista, k, j);
    prim(lista);

	printf("\nPrimeiro elemento removido:\n");
	lista=remove_primeiro(lista);
    prim(lista);
	printf("\n");

	printf("\nInsira mais dois elementos na lista:\n");
	scanf("%d", &a);
    lista=insere_inic(lista, a);
    setbuf(stdin, NULL);

	scanf("%d", &a);
    lista=insere_inic(lista, a);
    setbuf(stdin, NULL);

	printf("\nLista completa:\n");
    prim(lista);
	printf("\n");

	printf("\nInforme o elemento que quer remover:\n");
	scanf("%d", &a);
    lista=elimina(a, lista);
    setbuf(stdin, NULL);

	printf("\nLista completa:\n");
    prim(lista);
	printf("\n");

	printf("\nInserir antes:\n");
	nodo *p=j->lig->lig;
	scanf("%d", &a);
	lista=inserir_antes(&lista, a, p);
	setbuf(stdin, NULL);

	printf("\nLista completa:\n");
    prim(lista);
	printf("\n");

	nodo *lista_dois=create();

	printf("\nCrie uma lista com N elementos:\n");
	scanf("%d", &a);
	lista_dois=cria_lista_num(&lista_dois,a);
	setbuf(stdin, NULL);
	printf("\nLista completa:\n");
	prim(lista_dois);


	return 0;
}
