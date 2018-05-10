#include <stdio.h>
#define MAX_NOME 500
#define MASCULINO 0
#define MAX_CLIENTES 1000
#define MAXCPF 11

struct cliente
{
	int codigo;
	char nome[MAX_NOME+1];
	int dia_nascimento;
	int mes_nascimento;
	int ano_nascimento;
	int sexo;
	char cpf[MAXCPF+1];
};

float media(struct cliente c[],int tam)
{
	float med=0;
	int i=0,idade[MAX_CLIENTES],k=0;
	for(i=0;i < tam;i++)
	{
		idade[i]=(2018-c[i].ano_nascimento);
		k++;
	}
	for(i=0;i < tam;i++)
	{
		med+=idade[i];
	}
	med=med/k;
	return med;
}

void imprimir(struct cliente c)
{
	printf("Codigo.......: %d\n", c.codigo);
	printf("Nome.........: %s", c.nome);
	printf("Nascimento...: %d/%d/%d\n", c.dia_nascimento, c.mes_nascimento, c.ano_nascimento);
	printf("Sexo.........: ");
	if (c.sexo==MASCULINO)
	{
		printf("masculino\n");
	}
	else
	{
		printf("feminino\n");
	}
	printf("CPF.......: %s\n", c.cpf);
}

int main()
{
	float med=0;
	int n, i;
	struct cliente c[MAX_CLIENTES];
	scanf("%d",&n);
	for (i = 0; i < n; ++i)
	{
		c[i].codigo = i;
		getchar();
		fgets(c[i].nome , MAX_NOME, stdin);
		scanf("%d%d%d", &c[i].dia_nascimento, &c[i].mes_nascimento, &c[i].ano_nascimento);
		scanf("%d",&c[i].sexo);
		scanf("%s",c[i].cpf);
	}

	for (i=0; i < n; ++i)
	{
		imprimir(c[i]);
	}
	med=media(c,n);
	printf("%.2f\n",med);
	return 0;
}