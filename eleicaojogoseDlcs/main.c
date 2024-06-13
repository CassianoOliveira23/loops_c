#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* 

Faça um programa na linguagem C que reproduza um sistema de escolha dos melhores jogos e DLCs 
(DownLoadable Content – conteúdo baixável) de uma plataforma gamer.  O sistema terá um único menu 
conforme apresentado abaixo: 
MENU: 
0 - Sair 
1 – Votar no jogo 
2 – Votar no DLC 
3 – Imprimir quantos jogadores votaram 
4 – Imprimir quantos votos cada jogo recebeu 
5 – Imprimir quantos votos cada DLC recebeu 
6 – Imprimir o jogo mais votado 
7 – Imprimir o DLC escolhido (+ de 20%) 
Nessa eleição, os jogadores deverão escolher 1 jogo e os DLCs mais votados na plataforma de jogos. 
Considere que existirão 2 jogos candidatos e 5 DLCs.  

*/

int main(int argc, char *argv[]) {
	int opcao;
	int total_votos = 0;
	int votos_dlc = 0;
	int votos_jogo = 0;
	int minecraft = 0;
	int battlefield = 0;
	int bee_kingdon = 0;
	int cute_teens = 0;
	int kit_vehicle = 0;
	int kit_medic = 0;
	int ninjas_hd = 0;
	
	
	do{
		printf("===== MENU =====\n");
		printf("\n[0] Para Sair do Programa\n");
		printf("[1] Votar no jogo\n");
		printf("[2] Votar no DLC\n");
		printf("[3] Ver total de votos\n");
		printf("[4] Ver quantos votos cada jogo recebeu\n");
		printf("[5] Ver quantos votos cada DLC recebeu\n");
		printf("[6] Ver o jogo mais votado\n");
		printf("[7] Ver o DLC eleito\n");
		printf("Digite o numero da opcao: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 0:
				printf("Saindo...\n");
				sleep(1);
				printf("Programa finalizado\n");
				printf("That's all folks\n");
				break;	
			case 1:
				printf("===== VOTE NO MELHOR JOGO =====\n");
				printf("\n[100] Minecraft \n");
				printf("[101] Battlefield 1  \n");
				printf("Digite o numero da opcao: ");
				scanf("%d", &opcao);
				
				switch(opcao){
					case 100:
						printf("\n");
						printf("Voce votou no Minecraft \n");
						minecraft++;
						break;
					case 101:
						printf("\n");
						printf("Voce votou no Battlefield 1 \n");
						battlefield++;
						break;	
					default:
						printf("\n");
						printf("\nOpcao invalida.\n");	
						break;
				}
				votos_jogo++;
				total_votos++;
				break;
			case 2:
				printf("===== VOTE NO MELHOR DLC's =====\n");
				printf("\n[1001] Bee Kingdom \n");
				printf("[1002] Cute teens \n");
				printf("[1003] Ninjas HD \n");
				printf("[1010] Kit vehicle \n");
				printf("[1011] Kit medic \n");
				printf("Digite o numero da opcao: ");
				scanf("%d", &opcao);
				
				switch(opcao){
					case 1001:
						printf("\n");
						printf("\nVoce votou em Bee Kingdon\n");
						bee_kingdon++;
						break;
					case 1002:
						printf("\n");
						printf("\nVoce votou em Cute teens\n");
						cute_teens++;
						break;
					case 1003:
						printf("\n");
						printf("\nVoce votou em Ninjas HD\n");
						ninjas_hd++;
						break;
					case 1010:
						printf("\n");
						printf("\nVoce votou em Kit vehicle\n");
						kit_vehicle++;
						break;
					case 1011:
						printf("\n");
						printf("\nVoce votou em Kit medic\n");
						kit_medic++;
						break;
					default:
						printf("\nOpcao invalida.\n");	
						break;		
				}
				votos_dlc++;
				total_votos++;
				break;
			case 3:
				printf("\n");
				printf("TOTAL DE VOTOS: %d\n", total_votos);
				break;
			case 4:
				printf("\n");
				printf("===== TOTAL DE VOTOS JOGOS =====\n");
				printf("\nMINECRAFT: %d\n", minecraft);
				printf("\nBATTLEFIELD: %d\n", battlefield);
				break;
			case 5:
				printf("\n");
				printf("===== TOTAL DE VOTOS DLC =====\n");
				printf("\nBEE KINGDON: %d\n", bee_kingdon);
				printf("CUTE TEENS: %d\n", cute_teens);
				printf("KIT VEHICLE: %d\n", kit_vehicle);
				printf("KIT MEDIC: %d\n", kit_medic);
				printf("NINJAS HD: %d\n", ninjas_hd);
				break;
			case 6:
				if(minecraft > battlefield){
					printf("O jogo mais votado eh MINECRAFT\n");
				}else if(battlefield >  minecraft){
					printf("O jogo mais votado eh BATTLEFIELD/n");
				}else{
					printf("EMPATE/n");	
				}
				break;
			case 7:
				printf("\n===== DLCs ELEITAS =====\n");
				if(bee_kingdon > votos_dlc * 0.2){
					printf("BEE KINGDON\n");
				}
				if(cute_teens > votos_dlc * 0.2){
					printf("CUTE TEENS\n");
				}
				if(kit_vehicle > votos_dlc * 0.2){
					printf("KIT VEHICLE\n");
				}	
				if(kit_medic > votos_dlc * 0.2){
					printf("KIT MEDIC\n");
				}
				if(ninjas_hd > votos_dlc * 0.2){
					printf("NINJAS HD\n");
				}
				break;
		}	
	}while(opcao!=0);
	
	return 0;
}
