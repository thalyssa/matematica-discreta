#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

#define ALPHSIZE 27
#define TXTSIZE 500

typedef struct node node;

struct node{
	char letter;
	int index;
};

node alphabet[ALPHSIZE];

void fill_alphabet(node vet[]); //Testada
bool eh_primo(int n); //Testada
void generate_key(); //Testada
void encript();

int main(){

	int choice;

	printf("Bem vindo! Digite sua opcao:\n1 - Gerar chave publica\n2 - Encriptar um texto\n3 - Desencriptar um texto\n");
	scanf("%d", &choice);

	fill_alphabet(alphabet);
	
	switch(choice){
		case 1:
			getchar();
			generate_key();
			break;
		case 2:
			getchar();
			encript();
			break;
		case 3:
			getchar();
			break;
		default:
			printf("Operacao invalida!\n");
			break;
	}

	return 0;
}

void fill_alphabet(node vet[]){
	int i;
	for(i=0;i<ALPHSIZE;i++){
		if(i!=26){
			alphabet[i].letter = (char)97+i;
		}else{
			alphabet[i].letter = (char)32;
		}
		
		alphabet[i].index = i;
	}
}

bool eh_primo(int n){
	int mod, i = 2;
	double sqroot = sqrt (n);

	for(i=2;i<=sqroot;i++){
		mod = n%i;
		if(mod == 0){
			return false;
		}
	}

	return true;
}

void generate_key(){
	long long int p, q, e, n;
	FILE *output = fopen("chave.txt", "w");

	if (output == NULL){
		printf("ERRO NA CRIAÇÃO DO ARQUIVO!!!");
	}

	printf("Digite dois numeros primos: \n");
	scanf("%lld %lld", &p, &q);

	if(eh_primo(p) == false || eh_primo(q) == false){
		printf("Um dos numeros nao eh primo!\n");
	}else{
		printf("Digite agora o expoente: \n");
		scanf("%lld", &e);

		n = p*q;

		fprintf(output, "n = %lld e = %lld", n, e);

		fclose (output);
	}
}

int search_alphabet(char c){
	int i=0;

	while(i<ALPHSIZE){
		if(c == alphabet[i].letter){
			return alphabet[i].index;
		}else{
			i++;
		}
	}

	return -1;
}

void encript(){

	int i, index;
	long long int numbtxt[TXTSIZE], encode[TXTSIZE], n, e, aux;
	char text[TXTSIZE];
	FILE *output = fopen("encriptado.txt", "w");

	if (output == NULL){
		printf("ERRO NA CRIAÇÃO DO ARQUIVO!!!");
	}

	printf("Digite o texto a ser encriptado (Max.:%d caracteres): ", TXTSIZE);
	
	scanf("%[^\n]s", text);

	for(i=0;i<strlen(text);i++){
		char aux = text[i];
		index = search_alphabet(aux);

		if(index == -1){
			printf("Caractere invalido: %c\n", aux);
		}else{
			numbtxt[i] = index;
		}
	}

	printf("Favor digite a chave publica e o expoente: \n");
	scanf("%lld %lld", &n, &e);

	//Encriptar
	for(i=0;i<strlen(text);i++){
		aux = pow(numbtxt[i], e);
		encode[i] = aux%n;
		fprintf(output, "%lld", encode[i]);
		if(i!=strlen(text)-1){
			fprintf(output, " ");
		}
	}

	fclose(output);
}
