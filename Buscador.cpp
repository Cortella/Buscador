// Buscador.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <fstream>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <windows.h> /* Para usar as funções de busca de arquivos */
#include <vector>    /* Para usar */
#include <sstream>   /* Para usar o Stringstream */
#include <iostream>  /* Para manipular a entrada/saída de streams */
#include <fstream>   /* Para usar o ifstream */

const int NUM_ARQUIVOS = 6000;

using namespace std;

int main() {
	ifstream file;
	int arquivosLidos = 0;
	string nomeArquivo = "data/";
	vector<string> palavras;
	//while (arquivosLidos < NUM_ARQUIVOS) {

		for (int i = 10000; i < 10010; i++) {
			nomeArquivo += to_string(i);
			file.open(nomeArquivo);
			if (!file.fail()) {
				string conteudo;
				while (file >> conteudo) { // loop para eliminar simbolos e letras maiusculas das palavras do arquivo
					for (int i = 0; conteudo[i] != '\0'; i++) {
						conteudo[i] = tolower(conteudo[i]);
						conteudo.erase(remove_if(conteudo.begin(), conteudo.end(), [](char c) { return !isalpha(c) && !isdigit(c); }), conteudo.end());
					}
					palavras.push_back(conteudo);
					cout << conteudo;
				}
			}
			
		//}
		//arquivosLidos++;
	}
	system("pause");
	return 0;
}

	// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
	// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

	// Dicas para Começar: 
	//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
	//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
	//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
	//   4. Use a janela Lista de Erros para exibir erros
	//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
	//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln


vector<string> ProcurarArquivos(string diretorio) {
	vector<string> arquivos;                     /* Vetor que irá armazenar os resultados temporários */
	string busca = "";         /* Cria o filtro, no diretório será encontrado somente arquivos .txt */
	HANDLE hFind;                                 /* Identificador da pesquisa */
	WIN32_FIND_DATA data;                         /* Estrutura que conterá informações dos arquivos */
	hFind = FindFirstFile(busca.c_str(), &data);  /* Procura pelo primeiro arquivo */
	if (hFind != INVALID_HANDLE_VALUE) {          /* Se a função não falhar */
		do {
			arquivos.push_back(data.cFileName);   /* Armazena no vetor o nome do arquivo encontrado */
		} while (FindNextFile(hFind, &data));     /* Procura pelo próximo arquivo */
		FindClose(hFind);                             /* Fecha o identificador da pesquisa */
	}
	return arquivos;                              /* Retorna o vetor como resultado */
}

string DiretorioDaAplicacao() {
	char buffer[MAX_PATH];                        /* Cria um buffer com tamanho máximo para um diretório */
	GetModuleFileName(NULL, buffer, MAX_PATH);    /* Para retornar o caminho completo do executável */
	int pos = string(buffer).find_last_of("\\/"); /* Captura a posição da última barra "/" */
	return string(buffer).substr(0, pos);         /* Extraí tudo desde o início até o ponto onde foi encontrado a barra "/" */
}

string ExtrairNomeDoArquivo(string caminho) {
	int indice = caminho.rfind('/');              /* Encontra o índice da última ocorrência da barra "/" */
	return caminho.substr(indice + 1);            /* Extraí tudo a partir do índice da barra "/" */
}
