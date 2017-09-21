#include "Huffman.h"
#include "NodeInterface.h"
#include <algorithm>
#include <queue>

Huffman::Huffman()
{

}

void Huffman::createEncodings(Node* localRoot, string encoding)
{
	if (localRoot->left != NULL)
	{
		createEncodings(localRoot->left, encoding + "0");
	}

	if (localRoot->right != NULL)
	{
		createEncodings(localRoot->right, encoding + "1");
	}

	if (localRoot->right == NULL && localRoot->left == NULL)
	{
		encodings[localRoot->character] = encoding;
	}
}

bool Huffman::readInFile(string fileName)
{
	ifstream inRead;
	char next;

	inRead.open(fileName.c_str());

	if (inRead.fail())
		return false;


	while(!inRead.eof())
	{
		next = inRead.get();
		
		if (inRead.eof())
			break;

		bool alreadyIn = false;

		for (auto& item : frequencies)
		{
			if (item.first == next)
			{
				(item.second)++;
				alreadyIn = true;
			}
		}

		if (alreadyIn == false)
		{
			frequencies[next] = 1;
		}
	}			//FINISHED READING IT IN

	return true;
}

bool Huffman::createTree(string fileName)
{
	frequencies.clear();
	bool successful = readInFile(fileName);


	for (auto& item : frequencies)   //moving from the map to a vector
	{
		Node* newNode = new Node(item.first, item.second);
		frequenciesVector.push_back(newNode);
		//addToVector(newNode); //at this point, the frequencies and the weights are the same
	}

	sort(frequenciesVector.begin(), frequenciesVector.end(), sorter);

	while (frequenciesVector.size() >= 2)
	{
		Node* parent = new Node();
		Node* leftChild = frequenciesVector.at(0);
		Node* rightChild = frequenciesVector.at(1);
		parent->left = leftChild;
		parent->right = rightChild;

		frequenciesVector.erase(frequenciesVector.begin() + 0);
		frequenciesVector.erase(frequenciesVector.begin() + 0);

		parent->setParentFrequency();
		frequenciesVector.push_back(parent);
		sort(frequenciesVector.begin(), frequenciesVector.end(), sorter);
	}

	myTree.root = frequenciesVector.at(0);
	frequenciesVector.pop_back();

	encodings.clear();
	createEncodings(myTree.root, "");

	return successful;
}


string Huffman::getCodeFromMap(char character)
{
	string code = "";

	for (auto& item : encodings)
	{
		if (character == item.first)
			code = item.second;
	}

	return code;
}

char Huffman::getCharacterFromMap(string code)
{
	char c = NULL;

	for (auto& item : encodings)
	{
		if (code == item.second)
			c = item.first;
	}

	return c;
}

string Huffman::encodeMessage(string message)
{
	string encodedMessage;
	
	for (int count = 0; count < message.length(); count++)
	{
		encodedMessage += getCodeFromMap(message[count]);
	}

	return encodedMessage;
}

string Huffman::decodeMessage(string toDecode)
{
	string encodedMessage = "";
	string decodedMessage = "";
	string word = "";
	char correspondingCharacter;
	for (int count = 0; count < toDecode.length(); count++)
	{
		word += toDecode[count];
		correspondingCharacter = getCharacterFromMap(word);

		if (correspondingCharacter != NULL) //if we found a valid sequence
		{
			decodedMessage += correspondingCharacter;
			word = ""; //clear the word
		}
	}
	return decodedMessage;
}

Tree* Huffman::getTree()
{
	Tree* pointerToTree = &myTree;
	return pointerToTree;
}

map<char, string> Huffman::getEncodings()
{
	return encodings;
}

void Huffman::deleteTree(Node*& localRoot)
{
	if (localRoot->left != NULL || localRoot->right != NULL)
	{
		deleteTree(localRoot->left);
		deleteTree(localRoot->right);
	}

	else
	{
		delete localRoot;
	}
}


/*
bool Huffman::codeFound(string code)
{
for (auto& item : encodings)
{
if (code == item.second)
{
return true;
}
}

return false;
}
*/