#include <bits/stdc++.h>
#include "Word.h"
#include "Thesaurus.h"

using namespace std;

int main() {

	string instruction;

	Thesaurus* t = NULL;

	cout << "Tezaurus." << endl;
	cout << "Aby utworzyc thezaurus napisz stworz [nazwa]" << endl;
	cout << "Aby usunac tezaurus napisz usun" << endl;
	cout << "Aby dodac nowe slowo do tezaurusa napisz dodaj-slowo [slowo nadrzedne] [nowe slowo]" << endl;
	cout << "Aby wyszukac slowo napisz znajdz-slowo [szukane slowo]" << endl;
	cout << "Aby znalezc hipernym dla podanych slow napisz znajdz-hypernym [slowo 1] [slowo 2]" << endl;
	cout << "Aby zakonczyc napisz zakoncz" << endl;

	while (true) {
		cin >> instruction;
		if (instruction == "stworz") {
			string name;
			cin >> name;
			t = new Thesaurus(name);
			cout << "Stworzono nowy tezaurus o nazwie " << name << "." << endl;
		}
		else if (instruction == "usun") {
			delete t;
			t = NULL;
			cout << "Usunieto tezaurus." << endl;
		}
		else if (instruction == "dodaj") {
			string parent, child;
			cin >> parent >> child;
			if (t != NULL && t->addWord(parent, child))
				cout << "Dodano " << child << " do " << parent << "." << endl;
			else
				cout << "Nie udalo sie dodac slowa." << endl;
		}
		else if (instruction == "znajdz-slowo") {
			if (t == NULL) {
				cout << "Nie stworzono tezaurusa!" << endl;
				cin.ignore(10000, '\n');
			}
			else {
				string word;
				cin >> word;
				Word* res = t->findWord(word);
				if (res != NULL)
					cout << "Znaleziono slowo: " << res->getValue() << "." << endl;
				else
					cout << "Podane slowo nie wystepuje!" << endl;
			}
		}
		else if (instruction == "znajdz-hypernym") {
			if (t == NULL) {
				cout << "Nie stworzono tezaurusa!" << endl;
				cin.ignore(10000, '\n');
			}
			else {
				string word1, word2;
				cin >> word1 >> word2;
				Word* res = t->findHypernym(word1, word2);
				if (res != NULL)
					cout << "Hypernym dla slow " << word1 << " i " << word2 << " to " << res->getValue() << endl;
				else
					cout << "Nie udalo sie znalezc hypernymu!" << endl;
			}
		}
		else if (instruction == "zakoncz") {
			break;
		}
		else {
			cin.ignore(10000, '\n');
			cout << "Niewlasciwa instrukcja! Sprobuj ponownie." << endl;
		}
	}

	delete t;

	return 0;
}
