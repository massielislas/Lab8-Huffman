#include "TreeInterface.h"
#include "Node.h"
#include <iostream>
#include <cstdlib>

class Tree : public TreeInterface
{
	friend class Huffman;
	private:
		Node* root;

	public:
		Tree();
		Tree(Node*);
		~Tree() {};
		Node* getRootNode() const;
};