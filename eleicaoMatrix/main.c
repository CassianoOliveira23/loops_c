#include <stdio.h>
#include <stdlib.h>

/* 
Fa�a um programa na linguagem C que reproduza um sistema de vota��o fict�cia para a prefeitura de 
uma cidade. O sistema ter� um �nico menu conforme apresentado abaixo: 
MENU: 
0 - Sair 
1 � Votar para prefeito e vereador 
2 � Imprimir quantos eleitores votaram 
3 � Imprimir quantos votos cada prefeito recebeu 
4 � Imprimir quantos votos cada vereador recebeu 
5 � Imprimir quem foi eleito 

Nessa elei��o, os eleitores dever�o escolher 1 prefeito e os vereadores mais votados para comandar a 
Matrix. Considere que existir�o 2 candidatos a prefeito e 7 candidatos a vereador. Os vereadores est�o 
distribu�dos em 3 partidos pol�ticos. 

Candidatos a prefeito  
N�mero  Nome 
99      Neo 
87      Agente Smith 

Candidatos a vereador 
N�mero      Nome 
99001      Trinity 
99002      Morpheus
87111       Cypher
87112     Agente Brown
87113    Agente Jones     
76301     Or�culo
76302     Garoto colher 

Na hora da vota��o para prefeito, o usu�rio poder� escolher entre duas op��es de voto: 99 ou 87. N�o 
havendo voto branco ou nulo! 

Na hora da vota��o para vereador, o usu�rio poder� escolher entre um dos candidatos: 99001, 99002, 
87111, 87112, 87113, 76301, 76302. N�o haver� voto branco, nulo ou no partido! 

O prefeito que tiver mais votos ser� eleito.  
Todo vereador que tiver mais de 10% de todos votos ser� eleito.

 */

#include <stdio.h>

int main(int argc, char *argv[]) {
    int opcao;
    int totalEleitores = 0;
    int votosNeo = 0, votosSmith = 0;
    int votosTrinity = 0, votosMorpheus = 0, votosCypher = 0, votosBrown = 0, votosJones = 0, votosOraculo = 0, votosColher = 0;

    do {
        printf("\n[0] para Sair ");
        printf("\n[1] para Votar para prefeito e vereador");
        printf("\n[2] para Imprimir quantos eleitores votaram");
        printf("\n[3] para Imprimir quantos votos cada prefeito recebeu ");
        printf("\n[4] para Imprimir quantos votos cada vereador recebeu  ");
        printf("\n[5] para Imprimir quem foi eleito ");
        printf("\nDigite sua opcao:  ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 0:
                break;
            case 1:
                printf("\n===== Vote para Prefeito =====\n");
                printf("[99] - Neo\n");
                printf("[87] - Agente Smith\n");
                printf("Escolha o n�mero do candidato a prefeito: ");
                scanf("%d", &opcao);
                if (opcao == 99) {
                    votosNeo++;
                    printf("Voc� votou no Neo para Prefeito\n");
                } else if (opcao == 87) {
                    votosSmith++;
                    printf("Voc� votou no Agente Smith para Prefeito\n");
                } else {
                    printf("Op��o inv�lida para prefeito!\n");
                }

                printf("\n===== Vote para Vereador =====\n");
                printf("[99001] - Trinity\n");
                printf("[99002] - Morpheus\n");
                printf("[87111] - Cypher\n");
                printf("[87112] - Agente Brown\n");
                printf("[87113] - Agente Jones\n");
                printf("[76301] - Or�culo\n");
                printf("[76302] - Garoto colher\n");
                printf("Escolha o n�mero do candidato a vereador: ");
                scanf("%d", &opcao);
                
                switch(opcao) {
                    case 99001:
                        votosTrinity++;
                        printf("Voc� votou em Trinity para Vereadora\n");
                        break;
                    case 99002:
                        votosMorpheus++;
                        printf("Voc� votou em Morpheus para Vereador\n");
                        break;
                    case 87111:
                        votosCypher++;
                        printf("Voc� votou em Cypher para Vereador\n");
                        break;
                    case 87112:
                        votosBrown++;
                        printf("Voc� votou em Agente Brown para Vereador\n");
                        break;
                    case 87113:
                        votosJones++;
                        printf("Voc� votou em Agente Jones para Vereador\n");
                        break;
                    case 76301:
                        votosOraculo++;
                        printf("Voc� votou em Or�culo para Vereador\n");
                        break;
                    case 76302:
                        votosColher++;
                        printf("Voc� votou em Garoto colher para Vereador\n");
                        break;
                    default:
                        printf("Op��o inv�lida para vereador!\n");
                }
                totalEleitores++;
                break;
                
            case 2:
                printf("Total de eleitores que votaram: %d\n", totalEleitores);
                break;
            case 3:
                printf("Total de votos do Neo: %d\n", votosNeo);
                printf("Total de votos do Agente Smith: %d\n", votosSmith);
                break;
            case 4:
                printf("\nTotal de votos de Trinity: %d", votosTrinity);
                printf("\nTotal de votos de Morpheus: %d", votosMorpheus);
                printf("\nTotal de votos de Cypher: %d", votosCypher);
                printf("\nTotal de votos de Agente Brown: %d", votosBrown);
                printf("\nTotal de votos de Agente Jones: %d", votosJones);
                printf("\nTotal de votos de Or�culo: %d", votosOraculo);
                printf("\nTotal de votos de Garoto colher: %d", votosColher);
                break;
            case 5:
                printf("\n===== Resultado das Elei��es =====");
                if (votosNeo > votosSmith) {
                    printf("\nNeo eleito Presidente da Matrix");
                } 
				else if (votosNeo < votosSmith) {
                    printf("\nAgente Smith eleito presidente da Matrix");
                } 
				else {
                    printf("\nEmpate!");
                }
                
                printf("\nVereadores eleitos: ");
                if (votosTrinity > totalEleitores * 0.1)
				{
					printf("Trinity\n");	
				} 
                if (votosMorpheus > totalEleitores * 0.1) 
                {
                	printf("Morpheus\n");
				}
                if (votosCypher > totalEleitores * 0.1) 
                {
                	printf("Cypher\n");
				}
                if (votosBrown > totalEleitores * 0.1) 
                {
                	printf("Agente Brown\n");
				}
                if (votosJones > totalEleitores * 0.1) 
                {
                	printf("Agente Jones\n");
				}
                if (votosOraculo > totalEleitores * 0.1) 
                {
                	printf("Or�culo\n");
				}
                if (votosColher > totalEleitores * 0.1) 
                {
                	printf("Garoto colher\n");
				}
                break;
            default:
                printf("Op��o inv�lida! Por favor, escolha uma op��o v�lida.\n");
        }
    } while (opcao != 0);

    return 0;
}

