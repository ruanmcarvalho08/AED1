#include <stdio.h>
#include <string.h>
#define MAXchar 1000

int verificaPilha(char eq[MAXchar]);

typedef struct cel{
    char conteudo;
    struct cel *seg;
} cel;

cel *push(char c, cel *p){
    cel *temp;
    temp = malloc (sizeof(cel));
    temp->conteudo = c;
    temp->seg = p;
    return temp;
}

cel *pop(cel *p){
    cel *lixo;
    lixo = p;
    p = p->seg;
    free(lixo);
    return p;
}

int main(){
    char eq[MAXchar];
    
    while(fgets(eq, sizeof(eq), stdin) != NULL){

        for (int i = 0; eq[i]; i++){
            if (eq[i] == '\n'){ 
                eq[i] = '\0';
                break;
            }
        }
        
        if(verificaPilha(eq)){
            printf("correct\n");
        } else{
            printf("incorrect\n");
        }
    }

    return 0;
}

int verificaPilha(char eq[MAXchar]){
    cel *p = NULL;
    int i = 0;

    while(eq[i] != '\0'){
        if (eq[i] == '('){ 
            p = push('(', p);
        }
        else if (eq[i] == ')'){
            if (p == NULL){
                return 0;
            }

            p = pop(p);
        }
        i++;
    }

    if (p != NULL){
        return 0;
    }

    // se ainda houver '(' na pilha
    if (p != NULL){
        while(p != NULL){
            p = pop(p);
        }
        return 0;
    }

    return 1;
}