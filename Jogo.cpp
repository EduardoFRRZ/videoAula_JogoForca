#include <iostream>
#include <stdio.h>
#include <stdlib.h> // Limpar tela
#include <windows.h> // Limpar tela, setConsoleTitle, Sleep, strcmp

#define pausa system("pause")
#define limpa system("cls")

using namespace std;

void menu();
void jogo();
void forca(int vida);
void regra();

int main() {
	
	int opcao;
	SetConsoleTitle("JOGO DA FORCA");
	
	while(true) {
		
		menu();
		cin >> opcao;
		
		if(opcao == 1){
			
			limpa;
			jogo();
			pausa;
			limpa;
			
		}
		
		if (opcao == 2){
			   
			limpa;
			regra();
			pausa;
			limpa;
				
		}
		
		if(opcao == 3){
			break;	
		}
		
	}
	
	return 0;
	
}

void menu(){
	
	system("color 0A");
	
	cout << "\t\t\t\tJOGO "; Sleep(500);
	cout << "DA "; Sleep(500);
	cout << "FORCA"; Sleep(500);
	
	cout << endl << endl;
	cout << "\t\t\t\t1 - INICIAR" << endl;
	cout << "\t\t\t\t2 - REGRAS" << endl;
	cout << "\t\t\t\t3 - SAIR" << endl << endl;
	cout << "OPCAO -> ";
	
}

void jogo(){ // LOGICA DO JOGO

	char nomeCarrasco[10], nomeVitima[10], carrasco[30], mesa[30], letra;
	int vidaVitima = 0, auxVida;
	string vitima;

	for(int i = 0; i < 30; i++){
		carrasco[i] = NULL;
		mesa[i] = NULL;
	}
	
	fflush(stdin);
	cout << "Nome do Carrasco -> ";
	gets(nomeCarrasco);
	cout << "Nome da Vitima -> ";
	gets(nomeVitima);
	
	limpa;
	
	cout << "(CARRASCO) " << nomeCarrasco << " escreva a Palavra / Frase -> ";
	gets (carrasco);
	
	for(int i = 0; carrasco[i] != '\0'; i++){
		if(carrasco[i] == ' '){
			mesa[i] = ' ';
		}else{
			mesa[i] = '_';
		}
	}
	
	limpa;
	
	while(true) {
		
		auxVida = 0;
		cout << "LETRAS -> " << vitima << endl;
		
		forca(vidaVitima);
		
		if(vidaVitima == 5){
			cout << "A PALAVRA ERA -> " << carrasco << endl << endl;
			break;
		}
		
		cout << "\t\t\t\t\t" << mesa << endl << endl;
		cout << "Letra -> ";
		cin >> letra;
		
		vitima = (vitima + letra);
		
		for(int i = 0; carrasco[i] != '\0'; i++){
			if(letra == carrasco[i]){
				mesa[i] = letra;
				auxVida++;
			}
		}
		
		if(auxVida == 0){
			vidaVitima++;
		}
		
		limpa;
		
		if(!strcmp(mesa, carrasco)){
			cout << "PARABENS " << nomeVitima << " VOCE GANHOU !!!" << endl << endl;
			cout << "PALAVRA -> " << carrasco << endl << endl; 
			break;
		}
			
	}	
}

void forca(int vida){
	if(vida == 0){
		
		cout << "     ----------    "  << endl;
		cout << "    |        __|__ "  << endl;
		cout << "    |              "  << endl;
		cout << "    |              "  << endl;
		cout << "    |              "  << endl;
		cout << "    |              "  << endl;
		cout << "    |              "  << endl;
		cout << " ___|___           "  << endl;
		cout << endl;
		
	}else{
		if(vida == 1){
			
			cout << "     ----------    "  << endl;
			cout << "    |        __|__ "  << endl;
			cout << "    |          0    " << endl;
			cout << "    |              "  << endl;
			cout << "    |              "  << endl;
			cout << "    |              "  << endl;
			cout << "    |              "  << endl;
			cout << " ___|___           "  << endl;
			cout << endl;
			
		}else{
			if (vida == 2){
				
				cout << "     ----------    "  << endl;
				cout << "    |        __|__ "  << endl;
				cout << "    |          0   "  << endl;
				cout << "    |         /|   "  << endl;
				cout << "    |              "  << endl;
				cout << "    |              "  << endl;
				cout << "    |              "  << endl;
				cout << " ___|___           "  << endl;
				cout << endl;	
				
			}else{
				if(vida == 3){
					
					cout << "     ----------    "  << endl;
					cout << "    |        __|__ "  << endl;
					cout << "    |          0   "  << endl;
					cout << "    |         /|\\ "  << endl;
					cout << "    |              "  << endl;
					cout << "    |              "  << endl;
					cout << "    |              "  << endl;
					cout << " ___|___           "  << endl;
					cout << endl;
					
				}else{
					if(vida == 4){
						
						cout << "     ----------    "  << endl;
						cout << "    |        __|__ "  << endl;
						cout << "    |          0   "  << endl;
						cout << "    |         /|\\ "  << endl;
						cout << "    |          |   "  << endl;
						cout << "    |         /    "  << endl;
						cout << "    |              "  << endl;
						cout << " ___|___           "  << endl;
						cout << endl;
						
					}else{
						if(vida == 5){
							   
							cout << "     ----------    "  << endl;
							cout << "    |        __|__ "  << endl;
							cout << "    |          0   "  << endl;
							cout << "    |         /|\\ "  << endl;
							cout << "    |          |   "  << endl;
							cout << "    |         / \\ "  << endl;
							cout << "    |              "  << endl;
							cout << " ___|___           "  << endl;
							cout << endl;
							cout << "QUE PENA VC PERDEU O JOGO !!!" << endl << endl;
							   	
						}
					}
				}
			}
		}
	}
}

void regra(){
	
	cout << "REGRA NUMERO 1 -> A PALAVRA DEVE CONTER SMENTE LETRAS" << endl;
	cout << "REGRA NUMERO 2 -> NUMERO DE VIDAS = 5" << endl;
	cout << "REGRA NUMERO 3 -> LETRAS ERRADAS REPETIDAS SERAO CONSIDERADAS COMO ERROS" << endl;
}