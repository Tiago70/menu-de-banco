#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Funcionarios.h"

struct conta_f{
	int codigo_f;
	char cargo_f[25];
	char nome_f[25];
	int cpf_f;
	int data_nascimento_f;
	int telefone_f;
	char endereco_f[25];
	int cep_f;
	char local_f[25];
	int numero_da_casa_f;
	char bairro_f[25];
	char cidade_f[25];
	char estado_f[25];
	int senha_funcionario;
};

struct conta{
	int tipo;
	int agencia;
	int numero_da_conta;
	float limite;
	int data_vencimento;
	char nome[50];
	int cpf;
	int data_nascimento;
	int telefone;
	char endereco[50];
	int cep;
	char local[25];
	int numero_da_casa;
	char bairro[25];
	char cidade[25];
	char estado[25];
	int senha_cliente;
	float saldo;
};

int verificar_senhas( char senha_do_sistema[] ){
	char senha [10];
	fflush(stdin);
	fgets(senha, sizeof(senha) - 1, stdin);
	if ( strcmp ( senha, senha_do_sistema) == 0) return 1;
	else return 0;
}

void recebe_dados( FILE *arquivo_cliente, int tipo_conta ){
	system("cls");
	struct conta conta_temp;
	size_t tamanho;
//	pede as informações da conta poupança
	if ( tipo_conta == 1 ){
		printf("1 – AGÊNCIA: ");
		scanf("%d", &conta_temp.agencia);

		printf("\n2 – NUMERO DA CONTA: ");
		scanf("%d", &conta_temp.numero_da_conta);

		printf("\n3 – NOME DO CLIENTE: "); 
		fflush(stdin);
		fgets(conta_temp.nome, sizeof(conta_temp.nome) - 1, stdin);
		tamanho = strlen(conta_temp.nome);
	if( tamanho > 0 && conta_temp.nome[tamanho - 1] == '\n') conta_temp.nome[tamanho - 1] = '\0';

		printf("\n4 – CPF DO CLIENTE: ");
		fflush(stdin);
		scanf("%d", &conta_temp.cpf);
		
		printf("\n5 – DATA DE NASCIMENTO: ");
		fflush(stdin);
		scanf("%d", &conta_temp.data_nascimento);
		
		printf("\n6 – TELEFONE DE CONTATO: ");
		fflush(stdin);
		scanf("%d", &conta_temp.telefone);
		
		printf("\n7 – ENDEREÇO DO CLIENTE: ");
		fflush(stdin);
		fgets(conta_temp.endereco, sizeof(conta_temp.endereco), stdin);
		tamanho = strlen(conta_temp.endereco);
	if( tamanho > 0 && conta_temp.endereco[tamanho - 1] == '\n') conta_temp.endereco[tamanho - 1] = '\0';
		
		printf("\n8 – CEP: ");
		fflush(stdin);
		scanf("%d", &conta_temp.cep);
		
		printf("\n9 – LOCAL: ");
		fflush(stdin);
		fgets(conta_temp.local, sizeof(conta_temp.local), stdin);
		tamanho = strlen(conta_temp.local);
	if( tamanho > 0 && conta_temp.local[tamanho - 1] == '\n') conta_temp.local[tamanho - 1] = '\0';
		
		printf(" \n10 – NUMERO DA CASA: ");
		fflush(stdin);
		scanf("%d", &conta_temp.numero_da_casa);
		
		printf("\n11 – BAIRRO: ");
		fflush(stdin);
		fgets(conta_temp.bairro, sizeof(conta_temp.bairro), stdin);
		tamanho = strlen(conta_temp.bairro);
	if( tamanho > 0 && conta_temp.bairro[tamanho - 1] == '\n') conta_temp.bairro[tamanho - 1] = '\0';
		
		printf("\n12 – CIDADE: ");
		fflush(stdin);
		fgets(conta_temp.cidade, sizeof(conta_temp.cidade), stdin);
		tamanho = strlen(conta_temp.cidade);
	if( tamanho > 0 && conta_temp.cidade[tamanho - 1] == '\n') conta_temp.cidade[tamanho - 1] = '\0';
		
		printf("\n13 – ESTADO: ");
		fflush(stdin);
		fgets(conta_temp.estado, sizeof(conta_temp.estado), stdin);
		tamanho = strlen(conta_temp.estado);
	if( tamanho > 0 && conta_temp.estado[tamanho - 1] == '\n') conta_temp.estado[tamanho - 1] = '\0';
		
		printf("\n14 – SENHA DO CLIENTE: ");
		fflush(stdin);
		scanf("%d", &conta_temp.senha_cliente);
		fflush(stdin);
		
		conta_temp.tipo = 1;
		conta_temp.saldo = 0.0;
		conta_temp.limite = 0;
		conta_temp.data_vencimento = 0;
		
		fseek(arquivo_cliente, 0, SEEK_END);
		if (fwrite(&conta_temp, sizeof(conta_temp), 1, arquivo_cliente)) printf("Conta cadastrada com sucesso!\n");
		else {
			printf("Erro ao cadastrar o usuário!");
			fclose(arquivo_cliente);
			exit(1);
		}
		rewind(arquivo_cliente);
		system("pause");
	}
	else{
//		pede as informações da conta correte
		printf("1 – AGÊNCIA: ");
		fflush(stdin);
		scanf("%d", &conta_temp.agencia);
		
		printf("\n2 – NUMERO DA CONTA: ");
		fflush(stdin);
		scanf("%d", &conta_temp.numero_da_conta);
		
		printf("\n3 – LIMITE DA CONTA: ");
		fflush(stdin);
		scanf("%f", &conta_temp.limite);

		printf("\n4 DATA DE VENCIMENTO: ");
		fflush(stdin);
		scanf("%d", &conta_temp.data_vencimento);

		printf("\n5– NOME DO CLIENTE: "); 
		fflush(stdin);
		fgets(conta_temp.nome, sizeof(conta_temp.nome), stdin);
		tamanho = strlen(conta_temp.nome);
	if( tamanho > 0 && conta_temp.nome[tamanho - 1] == '\n') conta_temp.nome[tamanho - 1] = '\0';
		
		printf("\n6 – CPF DO CLIENTE: ");
		fflush(stdin);
		scanf("%d", &conta_temp.cpf);
		
		printf("\n7 – DATA DE NASCIMENTO: ");
		fflush(stdin);
		scanf("%d", &conta_temp.data_nascimento);
		
		printf("\n8 – TELEFONE DE CONTATO: ");
		fflush(stdin);
		scanf("%d", &conta_temp.telefone);
		
		printf("\n9 – ENDEREÇO DO CLIENTE: ");
		fflush(stdin);
		fgets(conta_temp.endereco, sizeof(conta_temp.endereco), stdin);
		tamanho = strlen(conta_temp.endereco);
	if( tamanho > 0 && conta_temp.endereco[tamanho - 1] == '\n') conta_temp.endereco[tamanho - 1] = '\0';
		
		printf("\n10 – CEP: ");
		fflush(stdin);
		scanf("%d", &conta_temp.cep);
		
		printf("\n11 – LOCAL: ");
		fflush(stdin);
		fgets(conta_temp.local, sizeof(conta_temp.local), stdin);
		tamanho = strlen(conta_temp.local);
	if( tamanho > 0 && conta_temp.local[tamanho - 1] == '\n') conta_temp.local[tamanho - 1] = '\0';
		
		printf(" \n12 – NUMERO DA CASA: ");
		fflush(stdin);
		scanf("%d", &conta_temp.numero_da_casa);
		
		printf("\n13 – BAIRRO: ");
		fflush(stdin);
		fgets(conta_temp.bairro, sizeof(conta_temp.bairro), stdin);
		tamanho = strlen(conta_temp.bairro);
	if( tamanho > 0 && conta_temp.bairro[tamanho - 1] == '\n') conta_temp.bairro[tamanho - 1] = '\0';
		
		printf("\n14 – CIDADE: ");
		fflush(stdin);
		fgets(conta_temp.cidade, sizeof(conta_temp.cidade), stdin);
		tamanho = strlen(conta_temp.cidade);
	if( tamanho > 0 && conta_temp.cidade[tamanho - 1] == '\n') conta_temp.cidade[tamanho - 1] = '\0';
		
		printf("\n15 – ESTADO: ");
		fflush(stdin);
		fgets(conta_temp.estado, sizeof(conta_temp.estado), stdin);
		tamanho = strlen(conta_temp.estado);
	if( tamanho > 0 && conta_temp.estado[tamanho - 1] == '\n') conta_temp.estado[tamanho - 1] = '\0';
	
		printf("\n16  - SALDO: ");
		fflush(stdin);
		scanf("%f", &conta_temp.saldo);
		
		printf("\n17 – SENHA DO CLIENTE: ");
		fflush(stdin);
		scanf("%d", &conta_temp.senha_cliente);
		fflush(stdin);
		
		conta_temp.tipo = 2;

		fseek(arquivo_cliente, 0, SEEK_END);
		if (fwrite(&conta_temp, sizeof(conta_temp), 1, arquivo_cliente)) printf("Conta cadastrada com sucesso!\n");
		else {
			printf("Erro ao cadastrar o usuário!");
			fclose(arquivo_cliente);
			exit(1);
		}
		rewind(arquivo_cliente);		

		system("pause");
	}
	
}

void abrir_conta( FILE *arquivo_cliente ){
	char menu_f;
	do{
		system("cls");
		printf("Abetura de conta");
		printf("\n\n1 - Conta poupanca - CP \n2 - Conta corrente - CC \n3 - voltar");
		printf("\n\nEscolha uma opção: ");
		
		menu_f = getch();
		
		switch(menu_f){
		case '1':
			recebe_dados( arquivo_cliente, 1);
			break;
		case '2':
			recebe_dados( arquivo_cliente, 2);
			break;
		case '3':
			break;
		}
	}while( menu_f != '3');	
}

void excluir_conta( FILE *arquivo_cliente ){
	system("cls");
	const char *nome_antigo = "dados cliente.txt";
	const char *nome_novo = "dados cliente temporario.txt";
	
	FILE *arquivo_cliente_temp = fopen( nome_novo , "w+");
	if (arquivo_cliente_temp == NULL){
		printf("Ocorrreu um erro ao abrir os arquivos");
		exit(5);
	}
	struct conta conta_analisada;
	int codigo_cliente, encontrado = 0;
	
	printf("Digite o número da conta para encerramento: ");
	fflush(stdin);
	scanf("%d", &codigo_cliente);
	
	fseek(arquivo_cliente, 0, SEEK_SET);
	while(fread(&conta_analisada, sizeof(conta_analisada), 1, arquivo_cliente)){
		if ( codigo_cliente != conta_analisada.agencia ){
			fseek( arquivo_cliente_temp, 0, SEEK_END);
			fwrite(&conta_analisada, sizeof(conta_analisada), 1, arquivo_cliente_temp);
		}
		else encontrado = 1;
	}
	if (encontrado){
		fclose( arquivo_cliente_temp );
		fclose( arquivo_cliente );
		remove( nome_antigo );
		rename( nome_novo, nome_antigo);
		
		
		arquivo_cliente = fopen( "dados cliente.txt", "r+");

		printf("Cliente removido com sucesso!\n");
	}
	else {
		fclose(arquivo_cliente_temp);
		remove( nome_novo );
		printf("\nNão foram encontrados clientes com esse numero\n");
	}
	system("pause");
}

void excluir_conta_senha( char ADM[], FILE *arquivo_cliente){
	system("cls");
	printf("Digite a senha de administrador: ");
	
	if (verificar_senhas(ADM)){
		printf("\n\nBem vindo administrador!");
		sleep(1);
		excluir_conta( arquivo_cliente );
	}
	else {
		printf("\n\nSenha incorreta!");
		sleep(1);
	}
}

void consultar_dados( FILE *arquivo_cliente, FILE *arquivo_funcionario){
	char menu_f;
	struct conta conta_cliente;
	struct conta_f conta_funcionario;

	do{
		system("cls");
		printf("1 - Consultar conta \n2 - Consultar funcionário \n3 - Consultar cliente \n4 - Sair");
		printf("\n\nEscolha uma das opções: ");
		menu_f = getch();
		
		switch(menu_f){
		case '1':
			system("cls");
			
			fseek(arquivo_cliente, 0, SEEK_SET);
			if(fread(&conta_cliente, sizeof(conta_cliente), 1, arquivo_cliente) != 1) printf("Ocorreu um erro na leitura \n");
			else{
				fseek(arquivo_cliente, 0, SEEK_SET);
				while (fread(&conta_cliente, sizeof(conta_cliente), 1, arquivo_cliente)){
				if ( conta_cliente.tipo == 1 ){
					printf("Tipo da conta: Conta poupança \nNome do cliente: %s \nCPF do cliente: %d \nSaldo da conta: %.2f \nData de vencimento: %d \n\n", conta_cliente.nome, conta_cliente.cpf, conta_cliente.saldo, conta_cliente.data_vencimento);
				}
				else{
					printf("Tipo da conta: Conta corrente  \nNome do cliente: %s \nCPF do cliente: %d \nSaldo da conta: %.2f \nData de vencimento: %d \n\n", conta_cliente.nome, conta_cliente.cpf, conta_cliente.saldo, conta_cliente.data_vencimento);
				}
			}
			}
			
			
			system("pause");
			break;

		case '2':
			system("cls");
			fseek(arquivo_funcionario, 0, SEEK_SET);
				while (fread(&conta_funcionario, sizeof(conta_funcionario), 1, arquivo_funcionario)){
					printf("CODIGO: %d \nCARGO: %s \nNOME DO FUNCIONÁRIO: %s \nCPF DO FUNCIONÁRIO: %d \nDATA DE NASCIMENTO: %d \nTELEFONE:  %d \n", conta_funcionario.codigo_f, conta_funcionario.cargo_f, conta_funcionario.nome_f, conta_funcionario.cpf_f, conta_funcionario.data_nascimento_f, conta_funcionario.telefone_f);
					printf("LOCAL (endereço): %s \nNÚMERO DA CASA: %d \nCEP: %d \nBAIRRO: %s \nCIDADE: %s \nESTADO: %s\n\n", conta_funcionario.endereco_f, conta_funcionario.numero_da_casa_f, conta_funcionario.cep_f, conta_funcionario.bairro_f, conta_funcionario.cidade_f, conta_funcionario.estado_f );
				}
			system("pause");
			break;

		case '3':
			system("cls");
			fseek(arquivo_cliente, 0, SEEK_SET);
			if(fread(&conta_cliente, sizeof(conta_cliente), 1, arquivo_cliente) != 1) printf("Ocorreu um erro na leitura \n");
			else {
				fseek(arquivo_cliente, 0, SEEK_SET);
				while(fread(&conta_cliente, sizeof(conta_cliente), 1, arquivo_cliente)){
					printf("NOME DO CLIENTE: %s \nCPF DO CLIENTE: %d \nDATA DE NASCIMENTO: %d \nTELEFONE: %d \nLOCAL (ENDEREÇO): %s \n", conta_cliente.nome, conta_cliente.cpf, conta_cliente.data_nascimento, conta_cliente.telefone, conta_cliente.local);
					printf("NÚMERO DA CASA: %d \nCEP: %d \nBAIRRO: %s \nCIDADE: %s \nESTADO: %s \n\n", conta_cliente.numero_da_casa, conta_cliente.cep, conta_cliente.bairro, conta_cliente.cidade, conta_cliente.estado );
				}
			}
			system("pause");
			break;

		case '4':
			
			break;
		}
	}while ( menu_f != '4');
	
}

void alterar_dados( char ADM[], FILE *arquivo_cliente, FILE *arquivo_funcionario ){
	system("cls");
	struct conta conta_cliente;
	struct conta_f conta_funcionario;
	char menu_f;
	size_t tamanho;
	int contador, escolha;
	printf("Coloque a senha de administrador: ");
	
	if (verificar_senhas(ADM)){
		do{
			system("cls");
			printf("1 – ALTERAR CONTA \n2 – ALTERAR FUNCIONÁRIO \n3 – ALTERAR CLIENTE \n4 – VOLTAR");
			printf("\n\nEscolha a opção desejada: ");
			
			menu_f = getch();
			
			switch(menu_f){
			case '1':
				system("cls");
				contador = -1;
				fseek(arquivo_cliente, 0, SEEK_SET);
				
				printf("Contas disponiveis\n\n");
				while(fread(&conta_cliente, sizeof(conta_cliente), 1, arquivo_cliente)){
					contador++;
					printf("Nome do cliente %d: %s\n\n", contador + 1, conta_cliente.nome);
				}
				printf("Escolha o numero do cliente que deseja modificar: ");
				scanf("%d", &escolha);
				
				if ( escolha > contador + 1 || escolha < 1 ) {
					printf("Opção inválida");
					sleep(1);
				}
				else {
					system("cls");
					size_t tamanho;
					escolha--;
					fseek(arquivo_cliente, 0, SEEK_SET);
					fseek(arquivo_cliente, sizeof(conta_cliente) * escolha, SEEK_SET);
					fread(&conta_cliente, sizeof(conta_cliente), 1, arquivo_cliente);
					fseek(arquivo_cliente, -sizeof(conta_cliente), SEEK_CUR);
					
					printf("Escolha o que deseja alterar: \n\n1 - TIPO DE CONTA \n2 - LIMITE DISPONÍVEL \n3 - DATA DE VENCIMENTO \n");
					scanf("%d", &escolha);
								
					switch(escolha){
						case 1:
							system("cls");
							printf("Alterar tipo da conta: ");
							fflush(stdin);
							if(conta_cliente.tipo = 1 ) conta_cliente.tipo = 2;
							else conta_cliente.tipo = 1;
							
							if (fwrite(&conta_cliente, sizeof(conta_cliente), 1, arquivo_cliente)) printf("\nAlterado com sucesso!");
							else printf("\nOcorreu um erro ao alterar a informação!");
							sleep(1);
						break;
						
						case 2:
							system("cls");
							printf("Coloque o novo limite: ");
							fflush(stdin);
							scanf("%f", conta_cliente.limite);
							
							if (fwrite(&conta_cliente, sizeof(conta_cliente), 1, arquivo_cliente)) printf("\nAlterado com sucesso!");
							else printf("\nOcorreu um erro ao alterar a informação!");
							sleep(1);
						break;
						
						case 3:
							system("cls");
							printf("Coloque a nova data de vencimento: ");
							fflush(stdin);
							scanf("%d", &conta_cliente.data_vencimento);
							
							if (fwrite(&conta_cliente, sizeof(conta_cliente), 1, arquivo_cliente)) printf("\nAlterado com sucesso!");
							else printf("\nOcorreu um erro ao alterar a informação!");
							sleep(1);
						break;						
						
						default:
							printf("\nOpção inválida\n");
						break;
					}
				}
				break;
			case '2':
				system("cls");
				contador = -1;
				fseek(arquivo_funcionario, 0, SEEK_SET);
				
				while(fread(&conta_funcionario, sizeof(conta_funcionario), 1, arquivo_funcionario)){
					contador++;
					printf("Nome do funcionario %d: %s\n\n", contador + 1, conta_funcionario.nome_f);
				}
				printf("Escolha o numero do funcionario que deseja modificar: ");
				scanf("%d", &escolha);

				if ( escolha > contador + 1 || escolha < 1 ) {
					printf("Opção inválida");
					sleep(1);
				}
				else {
					system("cls");
					size_t tamanho;
					escolha--;
					fseek(arquivo_funcionario, 0, SEEK_SET);
					fseek(arquivo_funcionario, sizeof(conta_funcionario) * escolha, SEEK_SET);
					fread(&conta_funcionario, sizeof(conta_funcionario), 1, arquivo_funcionario);
					fseek(arquivo_funcionario, sizeof(conta_funcionario) * -1, SEEK_CUR);
					
					printf("Escolha o que deseja alterar \n\n1- CODIGO DO FUNCIONÁRIO \n2 - CARGO \n3 - TELEFONE \n4 - LOCAL (ENDEREÇO) \n5 - Nº DA CASA \n6 - CEP \n7 - BAIRRO \n8 - CIDADE \n9 - ESTADO\n");
					scanf("%d", &escolha);
					switch(escolha){
						case 1:
							system("cls");
							printf("Coloque o novo código do funcionário: ");
							fflush(stdin);
							scanf("%d", &conta_funcionario.codigo_f);


							if ( fwrite(&conta_funcionario, sizeof(conta_funcionario), 1, arquivo_funcionario)) printf("\nAlterado com sucesso");
							else printf("\nOcorreu um erro ao alterar a inforção");
							sleep(1);
						break;
						
						case 2:
							system("cls");
							printf("Coloque o novo cargo do funcionário: ");
							fflush(stdin);
							fgets(conta_funcionario.cargo_f, sizeof(conta_funcionario.cargo_f), stdin);
							tamanho = strlen(conta_funcionario.cargo_f);
							if( tamanho > 0 && conta_funcionario.cargo_f[tamanho - 1] == '\n') conta_funcionario.cargo_f[tamanho - 1] = '\0';
							
							if ( fwrite(&conta_funcionario, sizeof(conta_funcionario), 1, arquivo_funcionario)) printf("\nAlterado com sucesso");
							else printf("\nOcorreu um erro ao alterar a inforção");
							sleep(1);
						break;
						
						case 3:
							system("cls");
							printf("Coloque o novo telefone do funcionário: ");
							fflush(stdin);
							scanf("%d", &conta_funcionario.telefone_f);
							
							if ( fwrite(&conta_funcionario, sizeof(conta_funcionario), 1, arquivo_funcionario)) printf("\nAlterado com sucesso");
							else printf("\nOcorreu um erro ao alterar a inforção");
							sleep(1);
						break;
						
						case 4:
							system("cls");
							printf("Coloque o novo local do funcionário: ");
							fflush(stdin);
							fgets(conta_funcionario.local_f, sizeof(conta_funcionario.local_f) - 1, stdin);
							tamanho = strlen(conta_funcionario.local_f);
							if( tamanho > 0 && conta_funcionario.local_f[tamanho - 1] == '\n') conta_funcionario.local_f[tamanho - 1] = '\0';
							
							if ( fwrite(&conta_funcionario, sizeof(conta_funcionario), 1, arquivo_funcionario)) printf("\nAlterado com sucesso");
							else printf("\nOcorreu um erro ao alterar a inforção");
							sleep(1);;
						break;
						
						case 5:
							system("cls");
							printf("Coloque o número da casa: ");
							fflush(stdin);
							scanf("%d", &conta_funcionario.numero_da_casa_f);
							
							if ( fwrite(&conta_funcionario, sizeof(conta_funcionario), 1, arquivo_funcionario)) printf("\nAlterado com sucesso");
							else printf("\nOcorreu um erro ao alterar a inforção");
							sleep(1);
						break;
						
						case 6:
							system("cls");
							printf("Coloque o novo CEP do funcionário: ");
							fflush(stdin);
							scanf("%d", &conta_funcionario.cep_f);
							
							if ( fwrite(&conta_funcionario, sizeof(conta_funcionario), 1, arquivo_funcionario)) printf("\nAlterado com sucesso");
							else printf("\nOcorreu um erro ao alterar a inforção");
							sleep(1);
						break;
						
						case 7:
							system("cls");
							printf("Coloque o novo bairro do funcionário: ");
							fflush(stdin);
							fgets(conta_funcionario.bairro_f, sizeof(conta_funcionario.bairro_f) - 1, stdin);
							tamanho = strlen(conta_funcionario.bairro_f);
							if( tamanho > 0 && conta_funcionario.bairro_f[tamanho - 1] == '\n') conta_funcionario.bairro_f[tamanho - 1] = '\0';
							
							if ( fwrite(&conta_funcionario, sizeof(conta_funcionario), 1, arquivo_funcionario)) printf("\nAlterado com sucesso");
							else printf("\nOcorreu um erro ao alterar a inforção");
							sleep(1);
						break;
						
						case 8:
							system("cls");
							printf("Coloque a nova cidade do funcionário: ");
							fflush(stdin);
							fgets(conta_funcionario.cidade_f, sizeof(conta_funcionario.cidade_f) - 1, stdin);
							tamanho = strlen(conta_funcionario.cidade_f);
							if( tamanho > 0 && conta_funcionario.cidade_f[tamanho - 1] == '\n') conta_funcionario.cidade_f[tamanho - 1] = '\0';
							
							if ( fwrite(&conta_funcionario, sizeof(conta_funcionario), 1, arquivo_funcionario)) printf("\nAlterado com sucesso");
							else printf("\nOcorreu um erro ao alterar a inforção");
							sleep(1);
						break;
						
						case 9:
							system("cls");
							printf("Coloque o novo estado do funcionário: ");
							fflush(stdin);
							fgets(conta_funcionario.estado_f, sizeof(conta_funcionario.estado_f) - 1, stdin);
							tamanho = strlen(conta_funcionario.estado_f);
							if( tamanho > 0 && conta_funcionario.estado_f[tamanho - 1] == '\n') conta_funcionario.estado_f[tamanho - 1] = '\0';
							
							if ( fwrite(&conta_funcionario, sizeof(conta_funcionario), 1, arquivo_funcionario)) printf("\nAlterado com sucesso");
							else printf("\nOcorreu um erro ao alterar a inforção");
							sleep(1);
						break;
						
						default:
							printf("\nOpção inválida\n");
						break;
					}
				}
				break;
			case '3':
				system("cls");
				contador = -1;
				fseek(arquivo_cliente, 0, SEEK_SET);
				
				while(fread(&conta_cliente, sizeof(conta_cliente), 1, arquivo_cliente)){
					contador++;
					printf("Nome do cliente %d: %s\n\n", contador + 1, conta_cliente.nome);
				}
				printf("Escolha o numero do cliente que deseja modificar: ");
				scanf("%d", &escolha);
				
				if ( escolha > contador + 1 || escolha < 1 ) {
					printf("Opção inválida");
					sleep(1);
				}
				else {
					system("cls");
					size_t tamanho;
					escolha--;
					fseek(arquivo_cliente, 0, SEEK_SET);
					fseek(arquivo_cliente, sizeof(conta_cliente) * escolha, SEEK_SET);
					fread(&conta_cliente, sizeof(conta_cliente), 1, arquivo_cliente);
					fseek(arquivo_cliente, -sizeof(conta_cliente), SEEK_CUR);
					
					printf("Escolha o que deseja alterar: \n\n1 - TELEFONE \n2 - LOCAL (ENDEREÇO) \n3 - Nº DA CASA \n4 - CEP \n5 - BAIRRO \n6 - CIDADE \n7 - ESTADO\n");
					scanf("%d", &escolha);
								
					switch(escolha){
						case 1:
							system("cls");
							printf("Coloque o novo numero de telefone: ");
							fflush(stdin);
							scanf("%d", &conta_cliente.telefone);
							
							if (fwrite(&conta_cliente, sizeof(conta_cliente), 1, arquivo_cliente)) printf("\nNúmero alterado com sucesso!");
							else printf("Ocorreu um erro ao troca o dado");
							
							sleep(1);
						break;
						
						case 2:
							system("cls");
							printf("Coloque o novo endereço: ");
							fflush(stdin);
							fgets(conta_cliente.endereco, sizeof(conta_cliente.endereco) - 1, stdin);
							tamanho = strlen(conta_cliente.endereco);
							if( tamanho > 0 && conta_cliente.endereco[tamanho - 1] == '\n') conta_cliente.endereco[tamanho - 1] = '\0';
							
							if (fwrite(&conta_cliente, sizeof(conta_cliente), 1, arquivo_cliente)) printf("Endereço alterado com sucesso!");
							else printf("\nOcorreu um erro ao alterar o dado");
							sleep(1);
						break;
						
						case 3:
							system("cls");
							printf("Coloque o novo número da casa: ");
							fflush(stdin);
							scanf("%d", &conta_cliente.numero_da_casa);
							
							if (fwrite(&conta_cliente, sizeof(conta_cliente), 1, arquivo_cliente)) printf("Numero da casa alterado com sucesso!");
							else printf("\nOcorreu um erro ao alterar o dado");
							sleep(1);
						break;
						
						case 4:
							system("cls");
							printf("Coloque o novo CEP: ");
							fflush(stdin);
							scanf("%d", &conta_cliente.cep);
							
							if (fwrite(&conta_cliente, sizeof(conta_cliente), 1, arquivo_cliente)) printf("CEP alterado com sucesso!");
							else printf("\nOcorreu um erro ao alterar o dado");
							sleep(1);
						break;
						
						case 5:
							system("cls");
							printf("Coloque o novo bairro: ");
							fflush(stdin);
							fgets(conta_cliente.bairro, sizeof(conta_cliente.bairro) - 1, stdin);
							tamanho = strlen(conta_cliente.bairro);
							if( tamanho > 0 && conta_cliente.bairro[tamanho - 1] == '\n') conta_cliente.bairro[tamanho - 1] = '\0';
							
							if (fwrite(&conta_cliente, sizeof(conta_cliente), 1, arquivo_cliente)) printf("Bairro alterado com sucesso!");
							else printf("\nOcorreu um erro ao alterar o dado");
							sleep(1);
						break;
						
						case 6:
							system("cls");
							printf("\nColoque a nova cidade: ");
							fflush(stdin);
							fgets(conta_cliente.cidade, sizeof(conta_cliente.cidade) - 1, stdin);
							tamanho = strlen(conta_cliente.cidade);
							if( tamanho > 0 && conta_cliente.cidade[tamanho - 1] == '\n') conta_cliente.cidade[tamanho - 1] = '\0';
							
							if (fwrite(&conta_cliente, sizeof(conta_cliente), 1, arquivo_cliente)) printf("Cidade alterado com sucesso!");
							else printf("\nOcorreu um erro ao alterar o dado");
							sleep(1);
						break;
						
						case 7:
							system("cls");
							printf("Coloque o novo estado: ");
							fflush(stdin);
							fgets(conta_cliente.estado, sizeof(conta_cliente.estado) - 1, stdin);
							tamanho = strlen(conta_cliente.estado);
							if( tamanho > 0 && conta_cliente.estado[tamanho - 1] == '\n') conta_cliente.estado[tamanho - 1] = '\0';
							
							if (fwrite(&conta_cliente, sizeof(conta_cliente), 1, arquivo_cliente)) printf("Estado alterado com sucesso!");
							else printf("\nOcorreu um erro ao alterar o dado");
							sleep(1);
						break;
						
						default:
							printf("\nOpção inválida\n");
						break;
					}
				}
				break;
			case '4':
	
				break;
			}
		}while ( menu_f != '4');
	}
	
	
	
}

void cadastrar_funcionario( FILE *arquivo_funcionario ){
	system("cls");
	struct conta_f conta_temp_f;
	size_t tamanho;

	printf("1 – CODIGO FUNCIONÁRIO: "); 
	fflush(stdin);
	scanf("%d", &conta_temp_f.codigo_f);

	printf("\n2 – CARGO: "); 
	fflush(stdin);
	fgets(conta_temp_f.cargo_f, sizeof(conta_temp_f.cargo_f), stdin);
	tamanho = strlen(conta_temp_f.cargo_f);
	if( tamanho > 0 && conta_temp_f.cargo_f[tamanho - 1] == '\n') conta_temp_f.cargo_f[tamanho - 1] = '\0';
	
	printf("\n5 – NOME DO FUNCIONÁRIO: "); 
	fflush(stdin);
	fgets(conta_temp_f.nome_f, sizeof(conta_temp_f.nome_f), stdin);
	tamanho = strlen(conta_temp_f.nome_f);
	if( tamanho > 0 && conta_temp_f.nome_f[tamanho - 1] == '\n') conta_temp_f.nome_f[tamanho - 1] = '\0';
	

	printf("\n6 – CPF DO FUNCIONÁRIO: ");
	fflush(stdin);
	scanf("%d", &conta_temp_f.cpf_f);

	printf("\n7 – DATA DE NASCIMENTO: ");
	fflush(stdin);
	scanf("%d", &conta_temp_f.data_nascimento_f);

	printf("\n8 – TELEFONE DE CONTATO: ");
	fflush(stdin);
	scanf("%d", &conta_temp_f.telefone_f);
	
	printf("\n9 – ENDEREÇO DO FUNCIONARIO: "); 
	fflush(stdin);
	fgets(conta_temp_f.endereco_f, sizeof(conta_temp_f.endereco_f), stdin);
	tamanho = strlen(conta_temp_f.endereco_f);
	if( tamanho > 0 && conta_temp_f.endereco_f[tamanho - 1] == '\n') conta_temp_f.endereco_f[tamanho - 1] = '\0';

	printf("\n10 – CEP: ");
	fflush(stdin);
	scanf("%d", &conta_temp_f.cep_f);
	
	printf("\n11 – LOCAL: ");
	fflush(stdin);
	fgets(conta_temp_f.local_f, sizeof(conta_temp_f.local_f), stdin);
	tamanho = strlen(conta_temp_f.local_f);
	if( tamanho > 0 && conta_temp_f.local_f[tamanho - 1] == '\n') conta_temp_f.local_f[tamanho - 1] = '\0';

	printf("\n12 – NUMERO DA CASA: "); 
	fflush(stdin);
	scanf("%d", &conta_temp_f.numero_da_casa_f);

	printf("\n13 – BAIRRO: "); 
	fflush(stdin);
	fgets(conta_temp_f.bairro_f, sizeof(conta_temp_f.bairro_f), stdin);
	tamanho = strlen(conta_temp_f.bairro_f);
	if( tamanho > 0 && conta_temp_f.bairro_f[tamanho - 1] == '\n') conta_temp_f.bairro_f[tamanho - 1] = '\0';

	printf("\n14 – CIDADE:  ");
	fflush(stdin);
	fgets(conta_temp_f.cidade_f, sizeof(conta_temp_f.cidade_f), stdin);
	tamanho = strlen(conta_temp_f.cidade_f);
	if( tamanho > 0 && conta_temp_f.cidade_f[tamanho - 1] == '\n') conta_temp_f.cidade_f[tamanho - 1] = '\0';

	printf("\n15 – ESTADO:  ");
	fflush(stdin);
	fgets(conta_temp_f.estado_f, sizeof(conta_temp_f.estado_f), stdin);
	tamanho = strlen(conta_temp_f.estado_f);
	if( tamanho > 0 && conta_temp_f.estado_f[tamanho - 1] == '\n') conta_temp_f.estado_f[tamanho - 1] = '\0';

	printf("\n16– SENHA DO FUNCIONÁRIO: ");
	fflush(stdin);
	scanf("%d", &conta_temp_f.senha_funcionario); 

	fseek(arquivo_funcionario, 0, SEEK_END);
		if (fwrite(&conta_temp_f, sizeof(conta_temp_f), 1, arquivo_funcionario)) printf("Conta cadastrada com sucesso!\n");
		else {
			printf("Erro ao cadastrar o Funcionário!");
			fclose(arquivo_funcionario);
			exit(1);
		}
		rewind(arquivo_funcionario);
	system("pause");
}

void cadastro_funcionario( FILE *arquivo_funcionario, char ADM[] ){
	system("cls");
	printf("Digite a senha de administrador: ");

	if ( verificar_senhas(ADM) == 1){
		printf("Bem-vindo administrador!");
		sleep(1);
		cadastrar_funcionario( arquivo_funcionario );
	}
	else {
		printf("Senha incorreta!"); 
		sleep(1);
	}
}

void gerar_relatorio( char funcionario_senha[]){
	system("cls");
	printf("Digite a senha do funcionário: ");

	if ( verificar_senhas(funcionario_senha)){
		printf("Senha correta, Bem-vindo!");
		sleep(2);
		system("cls");
		printf("Gerando relatorio");
		sleep(2);
	}
	else {
		printf("Senha incorreta!");
		sleep(2);
	}
}
