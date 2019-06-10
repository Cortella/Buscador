#pragma once
#include <string>
#include <set>
#include <map>

using namespace std;
class DataBase {
private:
	
	set<string> words;
	set<string> nameDocuments;
	map<string, set<string>> map;
public:
	//Cria Base de dados
	DataBase();
	//Le arquivos da base de dados
	set<string> ReadFiles(string path);

	//Salva nomes de arquivos existentes
	set<string> getNameDocuments();


};

