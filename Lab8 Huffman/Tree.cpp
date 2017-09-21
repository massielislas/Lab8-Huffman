#include "Tree.h"

Node* Tree::getRootNode() const
{
	return root;
}

Tree::Tree(Node* root)
{
	this->root = root;
}

Tree::Tree()
{
	root = new Node();
}