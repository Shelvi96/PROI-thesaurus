#include "Word.h"

Word::Word(std::string val, Word* parent) {
	this->value = val;
	this->hypernym = parent;
	if (parent != NULL)
		this->depth = parent->getDepth() + 1;
	else
		this->depth = 0;
}

std::string Word::getValue() {
	return this->value;
}

int Word::getDepth() {
	return this->depth;
}

Word* Word::getParent() {
	return this->hypernym;
}

std::vector<Word*> Word::getHyponyms() {
	return this->hyponyms;
}

void Word::addHyponym(std::string word) {
	this->hyponyms.push_back(new Word(word, this));
}
