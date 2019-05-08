#ifndef Thesaurus_H
#define Thesaurus_H
#include <string>
#include <vector>
#include "Word.h"

class Thesaurus {
	public:
		Thesaurus(std::string val);
		~Thesaurus();
		bool addWord(std::string parent, std::string child);
		Word* findHypernym(std::string word1, std::string word2);
		Word* findWord(std::string val);

	protected:

	private:
		Word* root;
		
};

#endif // Thesaurus_H
