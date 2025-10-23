#include <stdio.h>
#include <stdlib.h>
#define MAXchar 1000

typedef struct cel {
    char conteudo;
    struct cel *seg;
} cel;

cel *push(char c, cel *p){
    cel *nova;
    nova = malloc (sizeof(cel));
    nova->conteudo = c;
    nova->seg = p->seg;
    return nova;
}

cel *pop(cel *p){
    cel *lixo;
    lixo = p->seg;
    p->seg = lixo->seg;
    free(lixo);
    return p;
}

int verificaPilha(char expressao[MAXchar]){
    int i = 0, diamantes = 0;

    cel *p = malloc (sizeof(cel));
    p->seg = NULL;

    while(expressao[i] != '\0'){
        if(expressao[i] == '<'){
            p->seg = push('<', p);
        } else if(expressao[i] == '>'){
            if(p->seg != NULL){
                pop(p);
                diamantes++;
            };
        }
        
        i++;
    }

    while(p->seg != NULL){
            pop(p);
        }

    free(p);

    return diamantes;
}

int main(){
    int n;
    char expressao[MAXchar];

    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++){
        if (fgets(expressao, sizeof(expressao), stdin) != NULL){
            for(int i = 0; expressao[i]; i++) {
            if(expressao[i] == '\n') {
                expressao[i] = '\0';
                break;
            }
        }
    }

        printf("%d\n", verificaPilha(expressao));
    }
}