#include <stdio.h>
#include <string.h>
#define MAX 10000
#define MAXchar 1000

int verificaPilha(char eq[MAXchar]);

int main(){
    char eq[MAXchar];
    
    while(fgets(eq, sizeof(eq), stdin) != NULL){

        for (int i = 0; eq[i]; i++){
            if (eq[i] == '\n'){ 
                eq[i] = '\0';
                break;
            }
        }
        
        if(verificaPilha(eq) == 0){
            printf("correct\n");
        } else{
            printf("incorrect\n");
        }
    }

    return 0;
}

int verificaPilha(char eq[MAXchar]){
    int top = 0;
    for(int i = 0; eq[i] != '\0'; i++){
        if (eq[i] == '('){
            top++;
        } else if (eq[i] == ')'){
            top--;
        }

        if (top < 0) return 1;

    }
    return top;
}