#include "HuffmanInterface.h"
#include "Node.h"
#include <string>
#include "Tree.h"
#include <fstream>
#include <vector>

class Huffman : public HuffmanInterface
{
	private:
		Tree myTree;
		map<char, int>frequencies;
		vector<Node*>frequenciesVector;
		map<char, string>encodings;
		bool readInFile(string fileName);
		void createEncodings(Node* localRoot, string encoding);
		string getCodeFromMap(char);
		char getCharacterFromMap(string);
		void deleteTree(Node*&);

	public:
		Huffman();
		~Huffman() { 
			deleteTree(myTree.root); 
		};
		bool createTree(string filename);
		string encodeMessage(string);
		string decodeMessage(string);
		Tree* getTree();
		map<char, string>getEncodings();
};