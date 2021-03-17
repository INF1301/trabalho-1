#include <stdio.h>
#include <stdlib.h>

struct no {
   void *info;
   struct no *prox;
   struct no *ant;
};
typedef struct no No;
struct lista {
    int tam;
    No *ini;
    No *fin;
    No *corr;
};


typedef struct lista Lista;

Lista *lst_cria(void){
    Lista *lst=(Lista*) malloc (sizeof(Lista));
    lst->ini=NULL;
    lst->fin=NULL;
    lst->tam=0;
    return lst;
}

int lst_vazia(Lista *lst){
    if (lst==NULL) return 1;
    return 0;
}

void lst_insIni(Lista *lst, void *v){
    No* novo= (No*)malloc (sizeof(No));
    if (novo==NULL) printf("Falha ao alocar memoria"); exit(1);
    novo->info=v;
    novo->ant=NULL;
    
    if (lst_vazia(lst)){// inicialização do No
        novo->prox=NULL;
        Lista->ini=novo;
        Lista->fin=novo;
    }
    else{ //atualização da Lista
        novo->prox=Lista->ini;
        Lista->ini=novo;
    }
    Lista->tam++;
}

void lst_insFin(Lista *lst,void *v){
    
}
void *lst_retIni(Lista *lst){
    
}
void *lst_retFin(Lista *lst){
    
}
void lst_posIni(Lista *lst){
    
}
void lst_posFin(Lista *lst){
    
}
void *lst_prox(Lista *lst){
    
}
void *lst_ant(Lista *lst){
    
}
void lst_libera(Lista *lst){
    
}

