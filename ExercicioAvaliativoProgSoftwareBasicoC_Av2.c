#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void){
    int i;
    pid_t pid;
    
    if((pid = fork()) < 0){
        perror("fork");         //1
        exit(1);                //1
    }
    if (pid == 0) {
        printf("pid do filho:%d\n", getpid());  //2
    }
    else{
        printf("pid do pai: %d\n", getpid());  //3
    }
    printf("Este print sera executada por ambos os processos\n"); 
    exit(0)
}

1- Seja o código acima, observe os itens demarcados com 1, 2 e 3. Refaça o programa acima,
substituindo as linhas demarcadas por funções, que irão “printar” os valores de getpid do pai e do
filho da função fork.

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void pidFilho() {
    printf("Impressão do Pid Filho: %d\n", getpid());
}

void pidPai(pid_t pid) {
    printf("Impressão do Pid Pai: %d\n", pid);
}


int main(void) {
    pid_t pid;

    if (pid == 0) {
        pidFilho();
    } else {
        pidPai(pid); 
    }
    
    if ((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    }
    
    printf("Este print será executado por ambos os processos\n");
    exit(0);
}
//----------------------------------------------------------------------------------
//2- Implemente um programa em Linguagem C que faça testes de porta serial e que
//implemente a OpenComm, SetCommState, GetCommState, GetCommError, CloseComm
//(slides 17 – Aula 6). Use funções para testar.

#include <stdio.h>
#include <windows.h>

int main(void){
    int idporta;
    DCB confporta;
    idporta = OpenComm("COM1", 1024, 128);
    if(idporta < 0){
        printf("Erro ao tentar abrir a porta COM1\n");
        return 1;
    }
    
    if(GetCommState(idporta, &confporta) < 0){
        printf("Erro ao obter os valores dos parâmetros de configuração\n");
        return 2;
    }
    CloseComm(idporta);
    return 0
}














