#include <stdio.h>
#include <stdlib.h>
#include "data.h"

struct no {
   void *info;
   struct no *prox;
   struct no *ant;
};
typedef struct no No;
typedef struct lista Lista;
struct lista {
    int tam;
    No *ini;
    No *fin;
    No *corr;
};

Lista *lst_cria(void){
    Lista *lst=(Lista*) malloc (sizeof(Lista));
    if (lst==NULL){ 
	    printf("Falha ao alocar memoria"); 
	    exit(1);
    }
    lst->ini=NULL;
    lst->fin=NULL;
    lst->tam=0;
    lst->corr = NULL;
    return lst;
}

int lst_vazia(Lista *lst){
    if (lst->ini==NULL) return 1;
    return 0;
}

void lst_insIni(Lista *lst, void *v){
    No* novo= (No*)malloc (sizeof(No));
    //if (novo==NULL) printf("Falha ao alocar memoria"); exit(1);
    novo->info=v;
    novo->ant=NULL;
    
    if (lst_vazia(lst) == 1){// inicialização do No
        novo->prox=NULL;
        lst->ini=novo;
        lst->fin=novo;
    }
    else{ //atualização da Lista
        novo->prox=lst->ini;
	lst->ini->ant = novo;
        lst->ini=novo;
    }
    lst->tam++;
}

void lst_insFin(Lista *lst,void *v){
    No* novo= (No*)malloc (sizeof(No));
    //if (novo==NULL) printf("Falha ao alocar memoria"); exit(1);
    novo->info=v;
    novo->prox=NULL;
    
    
    novo->prox=NULL;
    if (lst_vazia(lst)){// inicialização do No
        novo->ant=NULL;
        lst->ini=novo;
        lst->fin=novo;
    }
    else{ //atualização da Lista
        novo->ant=lst->fin;
	lst->fin->prox = novo;
        lst->fin=novo;
    }
    lst->tam++;
}

void *lst_retIni(Lista *lst){
	No* no; void* v;
        if (!lst_vazia(lst)) {
		no = lst->ini;
		v = no->info;
		if (lst->ini == lst->fin) {
			lst->ini = NULL;
			lst->fin = NULL;
		} else {
			lst->ini = no->prox;
			no->prox->ant = NULL;
		}
		free(no);
		lst->tam--;	
		return v;
	}
	return NULL;
}
void *lst_retFin(Lista *lst){
    	No* no; void* v;
        if (!lst_vazia(lst)) {
		no = lst->fin;
		v = no->info;
		if (lst->ini == lst->fin) {
			lst->ini = NULL;
			lst->fin = NULL;
		} else {
			lst->fin = no->ant;
			no->ant->prox = NULL;
		}
		free(no);
		lst->tam--;
		return v;
	}
	return NULL;

}
void lst_posIni(Lista *lst){
	if(lst_vazia(lst)) {
		lst->corr = NULL;
	} else {
		lst->corr = lst->ini;
	}
}
void lst_posFin(Lista *lst){
	if(lst_vazia(lst)) {
		lst->corr = NULL;
	} else {
		lst->corr = lst->fin;
	}
}
void *lst_prox(Lista *lst){
	if(lst_vazia(lst)) {
		lst->corr = NULL;
	} else {
		lst->corr = lst->corr->prox;
	}
	return lst->corr->info;
}
void *lst_ant(Lista *lst){
	if(lst_vazia(lst)) {
		lst->corr = NULL;
	} else {
		lst->corr = lst->corr->ant;
	}
	return lst->corr->info;
    
}
void lst_libera(Lista *lst){
	No* no = lst->ini;
	lst_posIni(lst);
	if(!lst_vazia(lst)) {
		while(no){
			lst->ini = no->prox;
			free(no);
			lst->tam--;
		}
		free(lst);
	}
}

