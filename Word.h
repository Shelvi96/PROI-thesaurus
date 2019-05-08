#ifndef Word_H
#define Word_H
#include <string>
#include <vector>

class Word {
	public:
		Word(std::string val, Word* parent);
		std::string getValue();
		int getDepth();
		Word* getParent();
		std::vector<Word*> getHyponyms();
		void addHyponym(std::string word);

	protected:

	private:
		std::string value;
		std::vector<Word*> hyponyms; // children
		Word* hypernym; // parent;
		int depth; // necessary for lca algorithm
};

#endif // Word_H