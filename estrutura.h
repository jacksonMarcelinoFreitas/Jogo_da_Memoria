#include<stdio.h>
#include<locale.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

int pontuacaogeral = 0, rodada = 0, perdeu = 0;

typedef struct no{
	char elem;
	struct no *prox;
}Pilha;

void push(char valor, struct no **t){
	struct no *novo;
	novo = (struct no *) malloc (sizeof(struct no));
	novo->elem = valor;
	if( (*t) == NULL ){
		(*t) = novo;
		(*t)->prox = NULL;
	} else {
		novo->prox = (*t);
		(*t)=novo;
	}
}


//para remover os elementos da pilha
int pop(struct no **t){
	int vaux=0;
	struct no *aux;
	if( (*t)==NULL ){
		printf("Pilha Vazia \n");
	} else {
		vaux = (*t)->elem;
		aux = (*t);
		(*t)=(*t)->prox;
		free(aux);
	}
	return vaux;
}


void consulta(struct no *t){
	if (t == NULL){
		printf("Pilha Vazia \n");
	} else {
		do{
			//printf("Letras inseridas: %c \n", t->elem);
			t = t->prox;
		}while(t != NULL);
	}
}

int validarPontuacao(Pilha *topo){
   	
   	char vetor[10000];
	int i;
	int aux;

	rodada++;

	for(i=0; i<=rodada; i++){ //aqui pega a sequencia de letras 
		system("cls");
        printf("\n\n");
        printf("\tLETRA : ");
    	fflush(stdin);
   		scanf("%c", &vetor[i]);
	}

    if(topo != NULL){
        for(i=0; i<=rodada; i++){
         	if(topo -> elem == vetor[i]){
            	topo = topo -> prox;
            }
            else{

            perdeu = 1;
            system("cls");
            printf("\n ================================================");
            printf("\n |      Jogo da Mem�ria\t\t\t\t|"                 );
            printf("\n |      GENIUS C\t\t\t\t|"                        );
            printf("\n ================================================");
            printf("\n |\t\t\t\t\t\t|"                                  );
            printf("\n |      **Final de Jogo**\t\t\t|"                 );
            printf("\n |\t\t\t\t\t\t|"                                  );
            printf("\n ================================================");
            printf("\n |\t\t\t\t\t\t|"                                  );
            printf("\n |  A sua pontua��o foi: %d\t\t\t|"               ,pontuacaogeral);
            printf("\n |\t\t\t\t\t\t|"                                  );
            printf("\n ================================================");
            printf("\n |\t\t\t\t\t\t|"                                  );
            printf("\n |  A sequ�ncia de letras correta ! \t\t|"        );
            printf("\n |  \t\t"                                         );

            for(aux=0; aux<=rodada; aux++){
                printf("%c ,", topo->elem);
                topo = topo -> prox;
            }

            //pop(topo);

            printf("\n\n");
            system("pause");
            sair();

        }
      }
   }
   rodada ++;
   pontuacaogeral = pontuacaogeral + 10;

   return perdeu;
}

char gerarLetra(){
    char letras[] ={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','x','w','y','z'};
    srand(time(NULL));
    letras[0]= 'a' + (char)(rand()%26);
    return letras[0];
}

void sair(){
    system("cls");
    printf("\nTchau!!!\n");
    Sleep(2);
    exit(0);
}

void menuInicial(){
    int opcao = 1;
    printf("\nSeja Bem Vindo ao Memory Game!");
    printf("\n1 - Come�ar o jogo!");
    printf("\n2 - Sair");
    printf("\n\n >> ");
    scanf("%d", &opcao);
    
    if (opcao == 1){
        Sleep(2);
        system("cls");
    }else{
        sair(); 
    }
}













