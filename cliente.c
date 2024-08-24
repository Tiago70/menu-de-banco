#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include "cliente.h"

static char funcionariosenha[10] = "11", clientesenha[10] = "12";

void saldo_cliente(FILE *arquivo_cliente) {
	
    int cpf;
	int senha;
    struct conta conta_buscar;
    
    system("cls");
	
	printf("1 - Saldo\n");
    
    printf("\nDigite o CPF do cliente: ");
    fflush(stdin);
    scanf("%d", &cpf);
    
    fseek(arquivo_cliente, 0, SEEK_SET);
    while (fread(&conta_buscar, sizeof(struct conta), 1, arquivo_cliente)) {
        if (conta_buscar.cpf == cpf) {  
		    printf("\nDigite a senha do cliente: ");
		    fflush(stdin);
		    scanf("%d", &senha);
	
		    if (conta_buscar.senha_cliente == senha) {
		    	system("cls");
		    	
		    	printf("1 - Saldo\n");
		        printf("\nCliente: %s (CPF: %d) \n\nSaldo: %.2f\n\n", conta_buscar.nome, conta_buscar.cpf, conta_buscar.saldo);
		        continue;
		    }
			else {
		    	printf("Senha incorreta!\n");
		    	continue;
		    	system("pause");
		    }
        }
    }
    printf("\nCliente não encontrado!\n\n");
    system("pause");
}

void deposito_cliente(FILE *arquivo_cliente){
	
	system("cls");
	
	printf("2 - Depósito\n");

    int cpf;
    int senha;
    float valor;
    struct conta cliente;
    long posicao;

    printf("\nDigite o CPF do cliente: ");
    fflush(stdin);
    scanf("%d", &cpf);

    fseek(arquivo_cliente, 0, SEEK_SET); // Mover para o início do arquivo
    while ((posicao = ftell(arquivo_cliente)) != -1 && fread(&cliente, sizeof(struct conta), 1, arquivo_cliente)) {
        if (cliente.cpf == cpf) {
        	
        	printf("\nDigite a senha do cliente: ");
	    	fflush(stdin);
	    	scanf("%d", &senha);
        	
	    	if (cliente.senha_cliente == senha) {
	    		
	    	printf("\nDigite o valor do depósito: ");
			scanf("%f", &valor);
        	
            cliente.saldo += valor;
            fseek(arquivo_cliente, posicao, SEEK_SET); // Voltar para a posição do cliente no arquivo
            fwrite(&cliente, sizeof(struct conta), 1, arquivo_cliente);
    
            system("cls");
            
            printf("2 - Depósito\n");
            printf("\nDepósito realizado com sucesso! \n\nNome do cliente: %s (CPF: %d) \n\nSaldo após o depósito: %.2f\n\n", cliente.nome, cliente.cpf, cliente.saldo);
            
            system("pause");
        }
        else{
        	printf("\nSenha incorreta!\n\n");
        	system("pause");
		}
    }
	}
	printf("\nCliente não encontrado!\n\n");
	system("pause");
}
	
void saque_cliente(FILE *arquivo_cliente) {
		
	system("cls");
	printf("3 - Saque\n");	
		
    int cpf;
    int senha;
    float valor;
    struct conta cliente;
    long posicao;

    printf("\nDigite o CPF do cliente: ");
    fflush(stdin);
    scanf("%d", &cpf);

    fseek(arquivo_cliente, 0, SEEK_SET); // Mover para o início do arquivo
    while ((posicao = ftell(arquivo_cliente)) != -1 && fread(&cliente, sizeof(struct conta), 1, arquivo_cliente)) {
        if (cliente.cpf == cpf) {
        	printf("\nDigite a senha do cliente: ");
    		fflush(stdin);
    		scanf("%d", &senha);
        	
        	if (cliente.senha_cliente == senha) {
	        	printf("\nDigite o valor do saque: ");
	    		scanf("%f", &valor);
	            if (cliente.saldo >= valor) {	
	                cliente.saldo -= valor;
	                fseek(arquivo_cliente, posicao, SEEK_SET); // Voltar para a posição do cliente no arquivo
	                fwrite(&cliente, sizeof(struct conta), 1, arquivo_cliente);

	                system("cls");
	                printf("3 - Saque\n");
	                printf("\nSaque realizado com sucesso! Novo saldo: %.2f\n\n", cliente.saldo);
	                system("pause");
	            }
	            else {
	                printf("\nSenha incorreta!\n\n");
	        		system("pause");
	            }
        	}
    	}
	}
	printf("\nCliente não encontrado!\n\n");
	system("pause");
}

void extrato_cliente(FILE *arquivo_cliente){
	system("cls");
	printf("4 - Extrato\n");
	system("pause");
}
	    
void consultarlimite_cliente(FILE *arquivo_cliente){
	
	int cpf;
	int senha;
	struct conta cliente;
	
	system("cls");
	printf("5 - Consultar limite\n");
	
 	printf("\nDigite o CPF do cliente: ");
    fflush(stdin);
    scanf("%d", &cpf);
    
    fseek(arquivo_cliente, 0, SEEK_SET);
    while (fread(&cliente, sizeof(struct conta), 1, arquivo_cliente)) {
        if (cliente.cpf == cpf) {
        	  
	    printf("\nDigite a senha do cliente: ");
	    fflush(stdin);
	    scanf("%d", &senha);
	
	    if (cliente.senha_cliente == senha) {
	    	system("cls");
	    	
	    	printf("5 - Consultar limite\n");
	        printf("\nNome do cliente: %s (CPF: %d) \n\nLimite disponível: %.2f\n\n", cliente.nome, cliente.cpf, cliente.limite);
	    }
		else {
	    	printf("Senha incorreta!\n");
	    }
            system("pause");
        }
    }
    printf("\nCliente não encontrado!\n\n");
    system("pause");
}







