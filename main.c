#include "estrutura.h"

int main() {
    setlocale(LC_ALL, "Portuguese");

    int  opcao = 1, perdeu = 0;
    char letraInserida, letraGerada;
    struct Pilha *topo = NULL; // Cria estrutura de dados Pilha

    menuInicial();

    do{
        //Pegar letra
        printf("\n ========================================");
        printf("\n |      Jogo da Mem�ria\t\t\t|"          );
        printf("\n |      GENIUS C\t\t\t|"                  );
        printf("\n ========================================");
        printf("\n |\t\t\t\t\t|"                            );
        printf("\n |      **Usu�rio Joga**\t\t|"           );
        printf("\n |      Informe uma letra entre A e Z\t|" );
        printf("\n |\t\t\t\t\t|"                            );
        printf("\n ========================================");
        printf("\n\n");
        printf("\tLETRA : ");
        fflush(stdin);
        scanf("%c", &letraInserida);
        push(letraInserida,&topo);
        consulta(topo);
        system("cls");

        //Programa gera a letra e apresenta
        letraGerada = gerarLetra();
        printf("\n\n");
        printf("\n ================================================");
        printf("\n |      Jogo da Mem�ria\t\t\t\t|"                );
        printf("\n |      GENIUS C\t\t\t\t|"                        );
        printf("\n ================================================");
        printf("\n |\t\t\t\t\t\t|"                                  );
        printf("\n |      **Programa Joga**\t\t\t|"                 );
        printf("\n |\t\t\t\t\t\t|"                                  );
        printf("\n |      Letra gerada pelo programa \t\t|"         );
        printf("\n |\t\t ----------\t\t\t|"                         );
        printf("\n |\t\t |        |\t\t\t|"                         );
        printf("\n |\t\t |   %c    |\t\t\t|"                        ,letraGerada );
        printf("\n |\t\t |        |\t\t\t|"                         );
        printf("\n |\t\t ----------\t\t\t|"                         );
        printf("\n |\t\t\t\t\t\t|"                                  );
        printf("\n |     Voc� tem 3 segundos para memorizar!\t|"   );
        printf("\n |\t\t\t\t\t\t|"                                  );
        printf("\n ================================================");
        printf("\n\n");
        push(letraGerada,&topo);
        Sleep(3000);
        
        //Fim de jogo
        system("cls");
        printf("\n ================================================");
        printf("\n |      Jogo da Mem�ria\t\t\t\t|"                 );
        printf("\n |      GENIUS C\t\t\t\t|"                        );
        printf("\n ================================================");
        printf("\n |\t\t\t\t\t\t|"                                  );
        printf("\n |      **Usuario Repete a Sequencia**\t\t|"      );
        printf("\n |\t\t\t\t\t\t|"                                  );
        printf("\n |\t\t\t\t\t\t|"                                  );
        printf("\n |\t Informe a sequ�ncia de letras at�\t|"       );
        printf("\n |\t  o momento iniciando pela ultima\t|"         );
        printf("\n |\t   letra informada at� a primeira \t|"       );
        printf("\n |\t\t\t\t\t\t|"                                  );
        printf("\n ================================================");
        printf("\n\n");
        system("pause");

        perdeu = validarPontuacao(topo);
 
    }while(perdeu == 0);

    return 0;
}

















