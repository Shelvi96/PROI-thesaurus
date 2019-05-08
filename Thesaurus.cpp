#include "Thesaurus.h"
#include <algorithm>

Thesaurus::Thesaurus(std::string val) {
	this->root = new Word(val, NULL);
}

void deleteWord(Word* node) {
	std::vector<Word*> V = node->getHyponyms();	
	for (auto it: V) {
		deleteWord(it);
	}
	delete node;
}

Thesaurus::~Thesaurus() {
	deleteWord(this->root);
}

Word* find(std::string val, Word* node) {
	std::vector<Word*> V = node->getHyponyms();

	if (node->getValue() == val) {
		return node;
	}

	for (auto it: V) {
		Word* res = find(val, it);
		if (res != NULL)
			return res;
	}

	return NULL;
}

bool Thesaurus::addWord(std::string parent, std::string child) {
	Word* pnode = find(parent, this->root);
	if (pnode == NULL)
		return false;
	else
		pnode->addHyponym(child);
	return true;
}

Word* Thesaurus::findWord(std::string val) {
	return find(val, this->root);
}

Word* findLCA(Word* w1, Word* w2) 
{
    if (w1 == w2)  return w1; 
    if (w1->getDepth() > w2->getDepth()) 
        std::swap(w1, w2); 
    w2 = w2->getParent(); 
    return findLCA(w1,w2); 
} 

Word* Thesaurus::findHypernym(std::string word1, std::string word2) {
	Word* w1 = findWord(word1);
	Word* w2 = findWord(word2);
	if (w1 == NULL || w2 == NULL)
		return NULL;
	return findLCA(w1, w2);
}
