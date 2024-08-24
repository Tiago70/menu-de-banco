
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

void saldo_cliente( FILE *arquivo_cliente);

void deposito_cliente(FILE *arquivo_cliente);

void saque_cliente(FILE *arquivo_cliente);

void extrato_cliente(FILE *arquivo_cliente);

void consultarlimite_cliente(FILE *arquivo_cliente);

