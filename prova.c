#include <stdio.h>
#include <string.h>
#define TAM_CONTAS 50
#define TAM_OPERACOES 10000


 struct Conta{
    int id;
    char cliente[50];
    double saldo;
    double limite;
 };



 struct Operacao{
    int id;
    int idConta;
    char tipo; //("D", "S" , "T")
    double valor;
 };






int BuscaID(struct Conta v[], int tam, int id){
    int i;
    for(i = 0; i < tam; i++){
        if(v[i].id == id){
            return i;
        }
    }
    return -1;
}



 void CadastraConta(struct Conta v[], int *tam){
    if(*tam >= TAM_CONTAS){
        printf("O limite de contas foi atingido!\n");
        return;
    }

    printf("Digite o id de sua conta: ");
    scanf("%d", &v[*tam].id);

    if(v[*tam].id<=0){
        printf("Este Id é inválido!,Digite um Id maior que 0.\n");
        return;
    }

    getchar();

    printf("Digite o nome do cliente: ");
    fgets(v[*tam].cliente, sizeof(v[*tam].cliente), stdin);


    v[*tam].cliente[strcspn(v[*tam].cliente, "\n")] = '\0';


    printf("Digite o saldo da conta:  ");
    scanf("%lf", &v[*tam].saldo);


    printf("Digite o seu limite: ");
    scanf("%lf", &v[*tam].limite);



    (*tam)++;















}





int buscaBinariaNome(struct Conta v[], int tam, char x[]){
    int inicio = 0;
    int fim = tam - 1;

    while (inicio <= fim){
        int meio = inicio+(inicio+fim)/2;
          int comp = strcmp(v[meio].cliente, x );
           if (comp == 0){
        return meio;

    }
    else{
        return -1;
    }

    }


   




 }


 int filtraDevedores(struct Conta vContas[], int tamConta,struct Conta vDevedores[], int *tamDevedores){

    int i = 0;
    *tamDevedores = 0;


    for(i = 0; i < tamConta; i++){
        if(v[i].saldo < 0){
            vDevedores[*tamDevedores] = vContas[i];
            (*tamDevedores)++;
        }
    }
    return *tamDevedores;






 }
 


 int realizarSaque(struct Conta vContas[], int tamConta, struct Operacao vOp[], int *tamOp){
    int posicao, idAlvo;
    double valorSaque;

    posicao = BuscaID(vContas, tamConta, idAlvo);

    if(posicao != -1){
        printf("A conta existe,pode fazer o saque! ");
        return 0;
    }

    if(vContas[posicao].saldo + vContas[posicao].limite <valorSaque){
        printf("Saldo insuficiente!\n");
        return 0;


    }

    vOp[posicao].saldo =-valorSaque;
    vOp[*tamOp].idConta = idAlvo;
    vOp[*tamOp].tipo = 'S';
    (*tamOp)++;

    printf("O saque foi realizado com sucesso!\n");
    return 1;



 }






void extrato(struct Conta vContas[], int tamConta, struct Operacao vOp[], int *tamOp){
    int i;
    for(i = 0; i < *tamOp; i++){
        if(vOp[i].tipo == v[i].idAlvo){


            if(vOp[i].valor <0){
                printf("Saque de %.2f\n", vOp[i].valor);
            } else {
                printf("Depósito de %.2f\n", vOp[i].valor);
            }


        }
    }
}



int main(){
    int i;
    int tamConta = 0;
    int tamOp = 0;
    struct Conta vContas[100];
    struct Operacao vOp[100];






}