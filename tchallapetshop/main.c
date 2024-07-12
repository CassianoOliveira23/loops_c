#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  



//CLIENTES
#define MAX_CLIENTES 250
#define TAM_NOME 35
#define TAM_TELEFONE 15
#define TAM_CPF 15
int indice_clientes[MAX_CLIENTES];
char nome_clientes[MAX_CLIENTES][TAM_NOME];
char telefone_clientes[MAX_CLIENTES][TAM_TELEFONE];
char cpf_clientes[MAX_CLIENTES][TAM_CPF];
char nome_procurado[TAM_NOME];
int num_clientes = 0;
int indice;



// PETs
#define MAX_PET 500
#define TAM_NOME_PET 20
#define TAM_ESPECIE 20
int indice_pet[MAX_PET];
char nome_pet[MAX_PET][TAM_NOME_PET];
char especie[MAX_PET][TAM_ESPECIE];
char tipo_procurado[TAM_ESPECIE];
int num_pets = 0;



//Servicos
#define MAX_SERVICO 20
#define TAM_NOME_SERVICO 20
#define MAX_DATA 20
int indice_servico[MAX_SERVICO];
char nome_servico[MAX_SERVICO][TAM_NOME_SERVICO] = {{ '\0' }};
float valor_cobrado[MAX_SERVICO];
float valor_custo[MAX_SERVICO];
char data_servico[MAX_SERVICO][MAX_DATA];
int num_servicos = 0;




int opcao;
int i;
int indice;
float lucro_total = 0;
float lucro;

int main(int argc, char *argv[]) {
    do {
        printf("::::::::::::::: T'CHALLA PET SHOP  :::::::::::::::\n");
        printf("\n[0]  Sair\n");
        printf("[1]  Listar clientes\n");
        printf("[2]  Cadastrar cliente pelo codigo\n");
        printf("[3]  Pesquisar cliente pelo nome\n");
        printf("[4]  Excluir cliente pelo codigo\n");
        printf("[5]  Listar Pet\n");
        printf("[6]  Cadastrar Pet pelo codigo\n");
        printf("[7]  Pesquisar Pet pelo tipo\n");
        printf("[8]  Excluir Pet pelo codigo \n");
        printf("[9]  Listar servicos\n");
        printf("[10] Cadastrar servico pelo codigo\n");
        printf("[11] Atualizar servico \n");
        printf("[12] Excluir servico pelo codigo\n");
        printf("[13] Listar servicos do pet\n");
        printf("[14] Listar servicos do cliente\n");
        printf("[15] Prestar servico \n");
        printf("[16] Lucro dos servicoos \n");
        printf("\nDigite o numero da opcao:  ");
        scanf("%d", &opcao);
        
        if (opcao < 0 || opcao > 16) {
            printf("\nOpcao invalida, por favor digite um numero de 0 a 16\n");
        }
        
        
        
        switch(opcao) {
            case 0:
                printf("Finalizando");
                sleep(1);
                printf(". ");
                sleep(1);
                printf(". ");
                sleep(1);
                printf(". \n");
                sleep(1);
                printf("\nPrograma Finalizado. Volte Sempre a Pet Shop TT'CHALLA\n");
                break;   
            case 1:
                if (num_clientes == 0) {
                    printf("\nNenhum cliente cadastrado.\n\n");
                } else {
                    printf("\n===== CLIENTES CADASTRADOS: ===== \n");
                    for (i = 0; i < MAX_CLIENTES; i++) {
                        if (nome_clientes[i][0] != '\0') {
                            printf("Id do cliente %d:\n", indice_clientes[i]);
                            printf("Nome: %s\n", nome_clientes[i]);
                            printf("Telefone: %s\n", telefone_clientes[i]);
                            printf("CPF: %s\n", cpf_clientes[i]);
                            printf(" \n ");
                        }
                    }
                }
                break;
            case 2:
            	do {
                    printf("\n ===== CADASTRAR CLIENTE ===== \n");

                    printf("Digite o indice onde deseja cadastrar o cliente (0 a %d): ", MAX_CLIENTES - 1);
                    scanf("%d", &indice);

                    if (indice < 0 || indice >= MAX_CLIENTES) {
                        printf("Indice invalido. Tente novamente.\n");
                    } else if (nome_clientes[indice][0] != '\0') {
                        printf("Ja existe um cliente cadastrado nesse indice. Tente novamente.\n");
                    } else {
                    	// armazena o valor de indice na posição indice do array indice_clientes
                        indice_clientes[indice] = indice;

                        printf("Digite o nome do cliente: ");
                        scanf(" %[^\n]s", nome_clientes[indice]);

                        printf("Digite o telefone: ");
                        scanf(" %[^\n]s", telefone_clientes[indice]);

                        printf("Digite o CPF: ");
                        scanf(" %[^\n]s", cpf_clientes[indice]);

                        if (indice >= num_clientes) {
                            num_clientes = indice + 1;
                        }
                    }

                    char resposta[1];
                    printf("\n===== Deseja cadastrar outro cliente? =====\n");
                    printf("\n[S] SIM");
                    printf("\n[N] NAO\n");
                    scanf(" %[^\n]s", resposta);

                    if (tolower(resposta[0]) != 's') {
                        break;
                    }
                } while (num_clientes < MAX_CLIENTES);
                break;
            case 3:
            	printf("Digite o nome para procurar: ");
                fflush(stdin); 
                scanf(" %[^\n]s", nome_procurado);

                for (i = 0; i < MAX_CLIENTES; i++) {
                    if (strcmp(nome_procurado, nome_clientes[i]) == 0) {
                        printf("Nome encontrado no indice: %d\n", i);
                        printf("Nome: %s\n", nome_clientes[i]);
                        printf("Telefone: %s\n", telefone_clientes[i]);
                        printf("CPF: %s\n", cpf_clientes[i]);
                        break;
                    }
                }
                if (i == MAX_CLIENTES) {
                    printf("Nome nao encontrado na Lista.\n");
                }
                break;
            case 4:
            	printf("\n===== EXCLUIR CLIENTES  ===== \n");
                    for (i = 0; i < MAX_CLIENTES; i++) {
                        if (nome_clientes[i][0] != '\0') {
                            printf("Id do cliente %d: ", indice_clientes[i]);
                            printf("Nome: %s\n", nome_clientes[i]);
                            printf(" \n ");
                        }
                    }
                printf("Digite o indice para excluir (0 a %d): ", MAX_CLIENTES - 1);
                scanf("%d", &indice);
                if (indice >= 0 && indice < MAX_CLIENTES && nome_clientes[indice][0] != '\0') {
                    printf("O nome no indice %d: %s\n", indice, nome_clientes[indice]);
    
                    nome_clientes[indice][0] = '\0';
                    telefone_clientes[indice][0] = '\0';
                    cpf_clientes[indice][0] = '\0';

                    printf("O cliente %d foi excluido com sucesso.\n", indice);
                } else {
                    printf("Indice fora do intervalo valido ou cliente nao encontrado.\n");
                }
            	break;
			case 5:
				if (num_pets == 0) {
	                    printf("\nNenhum PET cadastrado.\n\n");
	                } else {
	                    printf("\n===== PETS CADASTRADOS: ===== \n");
	                    for ( i = 0; i < MAX_PET; i++) {
	                        if (nome_pet[i][0] != '\0') {
	                            printf("Id do dono do pet %d:\n", indice_pet[i]);
	                            printf("Nome do pet: %s\n", nome_pet[i]);
	                            printf("Especie: %s\n", especie[i]);
	                            printf(" \n ");
	                        }
	                    }
	                }
	            break;
            case 6:
            	do {
                    printf("\n ====== CADASTRAR PET ====== \n");
                    printf("Digite o indice onde deseja cadastrar o pet (0 a %d): ", MAX_PET - 1);
                    scanf("%d", &indice);

                    if (indice < 0 || indice >= MAX_PET) {
                        printf("Indice invalido. Tente novamente.\n");
                    } else if (nome_pet[indice][0] != '\0') {
                        printf("Ja existe um pet cadastrado nesse indice. Tente novamente.\n");
                    } else {
                        indice_pet[indice] = indice;

                        printf("Digite o nome do pet: ");
                        scanf(" %[^\n]s", nome_pet[indice]);

                        printf("Digite a especie do pet: ");
                        scanf(" %[^\n]s", especie[indice]);

                        if (indice >= num_pets) {
                            num_pets = indice + 1;
                        }
                    }

                    char resposta[3];
                    printf("\n===== Deseja cadastrar outro pet? =====\n");
                    printf("\n[S] SIM");
                    printf("\n[N] NAO\n");
                    scanf(" %[^\n]s", resposta);

                    if (tolower(resposta[0]) != 's') {
                        break;
                    }
                } while (num_pets < MAX_PET);
                break;
            case 7:
                printf("Digite a especie de pet para procurar: ");
                scanf(" %[^\n]s", tipo_procurado);

                for (i = 0; i < MAX_PET; i++) {
                    if (strcmp(tipo_procurado, especie[i]) == 0) {
                        printf("Especie encontrado no indice: %d\n", i);
                        printf("Id do pet: %d\n", indice_pet[i]);
                        printf("Nome: %s\n", nome_pet[i]);
                        printf("Especie: %s\n", especie[i]);
                        printf(" \n ");
                    }
                }
                	
                if (i == MAX_PET) {
                    printf("Tipo nao encontrado.\n");
                }
                break;
            case 8:
            	printf("\n===== EXLUIR PETS CADASTRADOS ======\n");
            	for(i = 0; i < MAX_PET; i++){
            		if (nome_pet[i][0] != '\0') {
            			printf("ID: %d\n", i);
            			printf("Nome: %s\n", nome_pet[i]);
            			printf(" \n ");
					}
            	
				}
                printf("Digite o indice (0 a %d): ", MAX_PET - 1);
                scanf("%d", &indice);

                if (indice >= 0 && indice < MAX_PET && nome_pet[indice][0] != '\0') {
                    printf("O nome no indice %d: %s\n", indice, nome_pet[indice]);
                    nome_pet[indice][0] = '\0';
                    especie[indice][0] = '\0';

                    printf("O pet %d foi marcado como excluido.\n", indice);
                } else {
                    printf("Indice fora do intervalo valido ou pet nao encontrado.\n");
                }
                break;
            case 9:
            	if (num_servicos == 0) {
			        printf("Nenhum servico cadastrado.\n\n");
			    } else {
			        printf("\n===== SERVICOS CADASTRADOS =====\n");
			        for ( i = 0; i < num_servicos; i++) {
			            if (nome_servico[i][0] != '\0') {
			                printf("Nome do serviço: %s\n", nome_servico[i]);
			                printf("Valor cobrado: %.2f\n", valor_cobrado[i]);
			                printf("Valor de custo: %.2f\n", valor_custo[i]);
			                printf(" \n ");
			            }
			        }
    			}
    			break;
            case 10:
            	do {
				    printf("\n ====== CADASTRAR SERVICO ====== \n");
				
				    printf("Digite o indice do servico (0 a %d): ", MAX_SERVICO - 1);
				    scanf("%d", &indice);
				
				    if (indice >= MAX_SERVICO) {
				        printf("Indice invalido.\n");
				    } else {
				        indice_servico[indice] = indice;
				
				        printf("Digite o nome do servico: ");
				        scanf(" %[^\n]s", nome_servico[indice]);
				
				        printf("Digite o valor cobrado: ");
				        scanf("%f", &valor_cobrado[indice]);
				
				        printf("Digite o valor de custo: ");
				        scanf("%f", &valor_custo[indice]);
				
				        if (indice >= num_servicos) {
				            num_servicos = indice + 1;
				        }
				
				        char resposta[2]; 
				        printf("\n===== Deseja cadastrar outro servico? =====\n");
				        printf("\n[S] SIM");
				        printf("\n[N] NAO\n");
				        scanf(" %[^\n]s", resposta);
				
				        if (tolower(resposta[0]) != 's') {
				            break;
				        }
				    }
				} while (num_servicos < MAX_SERVICO);
				break;
			case 11:
				do {
					printf("\n===== Qual servico deseja atualizar? =====\n");
					for ( i = 0; i < num_servicos; i++) {
			            if (nome_servico[i][0] != '\0') {
			            	printf("indice: %d \n", i);
			                printf("Nome do serviço: %s\n", nome_servico[i]);
			                printf("Valor cobrado: %.2f\n", valor_cobrado[i]);
			                printf("Valor de custo: %.2f\n", valor_custo[i]);
			                printf(" \n ");
			            }
			        }
				    printf("\n ====== ATUALIZAR SERVICO ====== \n");
				
				    printf("Digite o indice do servico (0 a %d): ", MAX_SERVICO - 1);
				    scanf("%d", &indice);
				
				    if (indice >= MAX_SERVICO) {
				        printf("Indice invalido.\n");
				    } else {
				        indice_servico[indice] = indice;
				
				        printf("Digite o nome do servico: ");
				        scanf(" %[^\n]s", nome_servico[indice]);
				
				        printf("Digite o valor cobrado: ");
				        scanf("%f", &valor_cobrado[indice]);
				
				        printf("Digite o valor de custo: ");
				        scanf("%f", &valor_custo[indice]);
				
				        if (indice >= num_servicos) {
				            num_servicos = indice + 1;
				        }
				
				        char resposta[2]; 
				        printf("\n===== Deseja Atualizar outro servico? =====\n");
				        printf("\n[S] SIM");
				        printf("\n[N] NAO\n");
				        scanf(" %[^\n]s", resposta);
				
				        if (tolower(resposta[0]) != 's') {
				            break;
				        }
				    }
				} while (num_servicos < MAX_SERVICO);
				break;
			case 12:
				printf("\n===== Qual servico deseja excluir? =====\n");
					for ( i = 0; i < num_servicos; i++) {
			            if (nome_servico[i][0] != '\0') {
			            	printf("indice: %d \n", i);
			                printf("Nome do serviço: %s\n", nome_servico[i]);
			                printf("Valor cobrado: %.2f\n", valor_cobrado[i]);
			                printf("Valor de custo: %.2f\n", valor_custo[i]);
			                printf(" \n ");
			            }
			        }
			        
				printf("Digite o indice (0 a %d): ", MAX_SERVICO - 1);
                scanf("%d", &indice);

                if (indice >= 0 && indice < MAX_SERVICO && nome_servico[indice][0] != '\0') {
                    printf("O nome no indice %d: %s\n", indice, nome_servico[indice]);
    
                    nome_servico[indice][0] = '\0';
                	valor_cobrado[indice] = -1;
                    valor_custo[indice] = -1;

                    printf("O servico %d foi excluido com sucesso.\n", indice);
                } else {
                    printf("Indice fora do intervalo valido ou servico nao encontrado.\n");
                }
            	break;
			case 13:
				printf("Digite o indice do PET para listar os servicos (0 a %d): ", MAX_PET - 1);
	            scanf("%d", &indice);
	            if (indice >= 0 && indice < MAX_PET && nome_pet[indice][0] != '\0') {
	                printf("\n===== SERVICOS DO PET %s =====\n", nome_pet[indice]);
	                

	                for (i = 0; i < MAX_SERVICO; i++) {
	                    if (indice == indice_servico[i]) {
	                        printf("Nome do servico: %s\n", nome_servico[i]);
	                        printf("Valor cobrado: %.2f\n", valor_cobrado[i]);
	                        printf("Valor de custo: %.2f\n", valor_custo[i]);
	                        printf("\n");
	                    }
	                }
	                if (i == MAX_SERVICO) {
	                    printf("Nenhum servico encontrado para este pet.\n");
	                }
	            } else {
	                printf("Indice fora do intervalo valido ou pet nao encontrado.\n");
	            }
				break;	
			case 14:
				printf("Digite o indice do cliente para listar os servicos (0 a %d): ", MAX_CLIENTES - 1);
	            scanf("%d", &indice);
	
	            if (indice >= 0 && indice < MAX_CLIENTES && nome_clientes[indice][0] != '\0') {
	                printf("\n===== SERVICOS DO CLIENTE %s =====\n", nome_clientes[indice]);
	            
	                for (i = 0; i < MAX_SERVICO; i++) {
	                    if (indice == indice_servico[i]) {
	                        printf("Nome do servico: %s\n", nome_servico[i]);
	                        printf("Valor cobrado: %.2f\n", valor_cobrado[i]);
	                        printf("Valor de custo: %.2f\n", valor_custo[i]);
	                        printf("\n");
	                    }
	                }
	                if (i == MAX_SERVICO) {
	                    printf("Nenhum servico encontrado para este cliente.\n");
	                }
	            } else {
	                printf("Indice fora do intervalo valido ou cliente nao encontrado.\n");
	            }
	            break;
	        case 15:
	            printf("Digite o indice do pet (0 a %d): ", MAX_PET - 1);
	            scanf("%d", &indice);
	
	            if (indice >= 0 && indice < MAX_PET && nome_pet[indice][0] != '\0') {
	                printf("Digite o indice do servico (0 a %d): ", MAX_SERVICO - 1);
	                scanf("%d", &opcao); 
	
	                if (opcao >= 0 && opcao < MAX_SERVICO && nome_servico[opcao][0] != '\0') {
	                    printf("Servico %s registrado para o pet %s.\n", nome_servico[opcao], nome_pet[indice]);
	                } else {
	                    printf("Indice de servico invalido ou servico nao encontrado.\n");
	                }
	            } else {
	                printf("Indice de pet invalido ou pet nao encontrado.\n");
	            }
	            break;
	        case 16:
	            if (num_servicos == 0) {
	                printf("Nenhum servico cadastrado.\n");
	            } else {
	                
	
	                for (i = 0; i < MAX_SERVICO; i++) {
	                    if (nome_servico[i][0] != '\0') {
	                        lucro = valor_cobrado[i] - valor_custo[i];
	                        lucro_total += lucro;
	                    }
	                }
	                printf("Lucro total dos servicos: %.2f\n", lucro_total);
	            }
	            break;

            	
            	
            default:
            	printf("\nOPCAO INVALIDA\n");
            	break; 
        }
        
    } while (opcao != 0);
    
    return 0;
}

