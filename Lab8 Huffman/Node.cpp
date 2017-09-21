#include "Node.h"

Node::Node()
{
	character = NULL;
	frequency = 0;
}

Node::Node(char character, int frequency)
{
	this->character = character;
	this->frequency = frequency;

}

char Node::getCharacter() const
{
	return character;
}

int Node::getFrequency() const
{
	return frequency;
}

Node* Node::getLeftChild() const
{
	return left;
}

Node* Node::getRightChild() const
{
	return right;
}

void Node::setParentFrequency()
{
	frequency = left->frequency + right->frequency;
}