/*
* ----------------------------------------------------------------------------
* "A LICENÇA BEER-WARE ou A LICENÇA DA CERVEJA" (Revisão 43 em Portugués Brasil):
* <pedrogaya@gmail.com> escreveu este arquivo. Enquanto esta nota estiver na coisa você poderá utilizá-la
* como quiser. Caso nos encontremos algum dia e você me reconheça e ache que esta coisa tem algum
* valor, você poderá me pagar uma cerveja em retribuição (ou mais de uma), Pedro Gaya.
* ----------------------------------------------------------------------------
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define linhas 9
#define colunas 9

void limpar(){
	#ifdef WINDOWS
	    system("cls");
	#else
	    // Assume POSIX
	    system ("clear");
	#endif
}

bool checaValidade(char matriz[linhas][colunas]){
	int iniciolinha,fimlinha,iniciocoluna,fimcoluna;
	//checa de linha em linha
	for(int l1=0;l1<9;l1++){
		for(int c1=0;c1<9;c1++){
			for(int v1=0;v1<9;v1++){
				if(v1 != c1){
					if(matriz[l1][c1] != ' ' && matriz[l1][v1] != ' '){
						if(matriz[l1][c1] == matriz[l1][v1]){
							return false;
						}
					}
				}
			}
		}
	}
	//checa de coluna em coluna
	for(int c2=0;c2<9;c2++){
		for(int l2=0;l2<9;l2++){
			for(int v2=0;v2<9;v2++){
				if(v2 != l2){
					if(matriz[l2][c2] != ' ' && matriz[v2][c2] != ' '){
						if(matriz[l2][c2] == matriz[v2][c2]){
							return false;
						}
					}
				}
			}
		}
	}
	//checa cada sub-quadrado
	for(int n=0;n<9;n++){
		switch (n){
			case 0:
				iniciolinha = 0;
				fimlinha = 3;
				iniciocoluna = 0;
				fimcoluna = 3;
				break;
			case 1:
				iniciolinha = 0;
				fimlinha = 3;
				iniciocoluna = 3;
				fimcoluna = 6;
				break;
			case 2:
				iniciolinha = 0;
				fimlinha = 3;
				iniciocoluna = 6;
				fimcoluna = 9;
				break;
			case 3:
				iniciolinha = 3;
				fimlinha = 6;
				iniciocoluna = 0;
				fimcoluna = 3;
				break;
			case 4:
				iniciolinha = 3;
				fimlinha = 6;
				iniciocoluna = 3;
				fimcoluna = 6;
				break;
			case 5:
				iniciolinha = 3;
				fimlinha = 6;
				iniciocoluna = 6;
				fimcoluna = 9;
				break;
			case 6:
				iniciolinha = 6;
				fimlinha = 9;
				iniciocoluna = 0;
				fimcoluna = 3;
				break;
			case 7:
				iniciolinha = 6;
				fimlinha = 9;
				iniciocoluna = 3;
				fimcoluna = 6;
				break;
			case 8:
				iniciolinha = 6;
				fimlinha = 9;
				iniciocoluna = 6;
				fimcoluna = 9;
				break;
		}
		for(int l3=iniciolinha;l3<fimlinha;l3++){
			for(int c3=iniciocoluna;c3<fimcoluna;c3++){
				for(int vl=iniciolinha;vl<fimlinha;vl++){
					for(int vc=iniciocoluna;vc<fimcoluna;vc++){
						if(vl != l3 && vc != c3){
							if(matriz[l3][c3] != ' ' && matriz[vl][vc] != ' '){
								if(matriz[l3][c3] == matriz[vl][vc]){
									return false;
								}
							}
						}
					}
				}
			}
		}
	}
	return true;
}

void mostraSudoku(char matriz[linhas][colunas]){
	bool funciona;
	limpar();
	//imprime quadro sudoku
	cout << " _____ _____ _____ _____ _____ _____ _____ _____ _____" << endl;
	for(int i=0;i<9;i++){
		cout << "|     |     |     |     |     |     |     |     |     |" << endl;
		cout << "|";
		for(int j=0;j<9;j++){
			cout << "  " << matriz[i][j] << "  |";
		}
		cout << "\n|_____|_____|_____|_____|_____|_____|_____|_____|_____|" << endl;
	}
	funciona = checaValidade(matriz);
	if(funciona){
		cout << "Sudoku valido." << endl;
	}
	else{
		cout << "Sudoku invalido." << endl;
	}
}

void logo(){
	limpar();
	cout << " ██▒   █▓ ▄▄▄       ██▓     ██▓▓█████▄  ▄▄▄      ▓█████▄  ▒█████   ██▀███       ██████  █    ██ ▓█████▄  ▒█████   ██ ▄█▀ █    ██ " << endl;
	cout << "▓██░   █▒▒████▄    ▓██▒    ▓██▒▒██▀ ██▌▒████▄    ▒██▀ ██▌▒██▒  ██▒▓██ ▒ ██▒   ▒██    ▒  ██  ▓██▒▒██▀ ██▌▒██▒  ██▒ ██▄█▒  ██  ▓██▒" << endl;
	cout << " ▓██  █▒░▒██  ▀█▄  ▒██░    ▒██▒░██   █▌▒██  ▀█▄  ░██   █▌▒██░  ██▒▓██ ░▄█ ▒   ░ ▓██▄   ▓██  ▒██░░██   █▌▒██░  ██▒▓███▄░ ▓██  ▒██░" << endl;
	cout << "  ▒██ █░░░██▄▄▄▄██ ▒██░    ░██░░▓█▄   ▌░██▄▄▄▄██ ░▓█▄   ▌▒██   ██░▒██▀▀█▄       ▒   ██▒▓▓█  ░██░░▓█▄   ▌▒██   ██░▓██ █▄ ▓▓█  ░██░" << endl;
	cout << "   ▒▀█░   ▓█   ▓██▒░██████▒░██░░▒████▓  ▓█   ▓██▒░▒████▓ ░ ████▓▒░░██▓ ▒██▒   ▒██████▒▒▒▒█████▓ ░▒████▓ ░ ████▓▒░▒██▒ █▄▒▒█████▓ " << endl;
	cout << "   ░ ▐░   ▒▒   ▓▒█░░ ▒░▓  ░░▓   ▒▒▓  ▒  ▒▒   ▓▒█░ ▒▒▓  ▒ ░ ▒░▒░▒░ ░ ▒▓ ░▒▓░   ▒ ▒▓▒ ▒ ░░▒▓▒ ▒ ▒  ▒▒▓  ▒ ░ ▒░▒░▒░ ▒ ▒▒ ▓▒░▒▓▒ ▒ ▒ " << endl;
	cout << "   ░ ░░    ▒   ▒▒ ░░ ░ ▒  ░ ▒ ░ ░ ▒  ▒   ▒   ▒▒ ░ ░ ▒  ▒   ░ ▒ ▒░   ░▒ ░ ▒░   ░ ░▒  ░ ░░░▒░ ░ ░  ░ ▒  ▒   ░ ▒ ▒░ ░ ░▒ ▒░░░▒░ ░ ░ " << endl;
	cout << "     ░░    ░   ▒     ░ ░    ▒ ░ ░ ░  ░   ░   ▒    ░ ░  ░ ░ ░ ░ ▒    ░░   ░    ░  ░  ░   ░░░ ░ ░  ░ ░  ░ ░ ░ ░ ▒  ░ ░░ ░  ░░░ ░ ░ " << endl;
	cout << "      ░        ░  ░    ░  ░ ░     ░          ░  ░   ░        ░ ░     ░              ░     ░        ░        ░ ░  ░  ░      ░     " << endl;
}

int menu(){
	int entrada=0;
	logo();
	cout << endl << endl << "Seja vem-vindo ao validador sudoku. Escolha a opcao desejada :" << endl;
	cout << endl << "\t1-Verificar Sudoku (inserir manualmente)" << endl;
	cout << endl << "\t2-Verificar Sudoku (escolher arquivo)" << endl;
	while(entrada != 1 && entrada != 2){
		cin >> entrada;
	}
	return entrada;
}

int main(){
	char matriz[linhas][colunas],entrada[10];
	int escolhausuario,contador=0,opc;
	string arquivo,linha;
	do{
		escolhausuario = menu();
		if(escolhausuario == 1){
			for(int i=0;i<9;i++){
				do{
				limpar();
				cout << "Digite os valores de cada casa para a linha " << i+1 << " em sequência. Para branco, use '.'!" << endl;
				cin >> entrada;
				}while(strlen(entrada)!=9);
				for(int j=0;j<9;j++){
					if(entrada[j] == '.'){
						matriz[i][j] = ' ';
					}
					else{
						matriz[i][j] = entrada[j];
					}
				}
			}
		}
		else{
			limpar();
			do{
			cout << "Favor digitar o nome do arquivo de entrada." << endl;
			cin >> arquivo;
			}while(arquivo.empty());
			ifstream arquivoSudoku(arquivo);
			if(arquivoSudoku.is_open()){
				while(getline(arquivoSudoku,linha)){
					for(int i=0;i<9;i++){
						if(linha[i] == '.'){
							matriz[contador][i] = ' ';
						}
						else{
							matriz[contador][i] = linha[i];
						}
					}
					contador++;
				}
			}
			arquivoSudoku.close();
		}
		mostraSudoku(matriz);
		do{
		cout << "\nDeseja retornar ao menu principal?" << endl << "\t1-Sim" << endl << "\t2-Nao" << endl;
		cin >> opc;
	}while(opc != 1 && opc != 2);
	}while(opc==1);
	limpar();
	return 0;
}