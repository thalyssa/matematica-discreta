//Programa criado para gerar todos os primos num determinado espaço de tempo. A parada ocorre apenas por comando externo (Ctrl+C).

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

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

int main(){

	int n=2;
	bool teste;

	while(1){

		if(n%2!=0 || n%3!=0 || n%5!=0 || n%7!=0){
			teste = eh_primo(n);
			if(teste == true){
			printf("%d\n", n);
			}
		}

		if(n==2){
			n++;
		}else{
			n = n+2;
		}
	}
	

	return 0;
}
