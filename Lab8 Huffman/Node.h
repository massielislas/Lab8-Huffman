#include "NodeInterface.h"
#pragma once

using namespace std;

class Node : public NodeInterface
{
	friend class Huffman;
	friend class Tree;
	private:
		char character;
		int frequency;
		Node* left;
		Node* right;
		//int weight;

	public:
		Node();
		Node(char, int);
		~Node() {};
		char getCharacter() const;
		int getFrequency() const;
		int getWeight() const;
		void setParentFrequency();
		Node* getLeftChild() const;
		Node* getRightChild() const;
};