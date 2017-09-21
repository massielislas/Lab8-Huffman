//YOU MAY NOT MODIFY THIS DOCUMENT

#pragma once

#include <iostream>
using namespace std;

class NodeInterface {

public:
	NodeInterface() {}
	virtual ~NodeInterface() {}

	/*
	* Returns the character that is stored in this node
	* 
	* @return the character that is stored in this node. Nodes that do not represent a character should return '\0'.
	*/
	virtual char getCharacter() const = 0;

	/*
	* Returns the frequency of the character that is stored in this node
	*
	* @return the frequency that is stored in this node. Nodes that do not represent a character should return the sum of their children's frequencies.
	*/
	virtual int getFrequency() const = 0;

	/*
	* Returns the left child of this node or null if it doesn't have one.
	*
	* @return the left child of this node or null if it doesn't have one.
	*/
	virtual NodeInterface * getLeftChild() const = 0;

	/*
	* Returns the right child of this node or null if it doesn't have one.
	*
	* @return the right child of this node or null if it doesn't have one.
	*/
	virtual NodeInterface * getRightChild() const = 0;

};
//You can pass this struct into the sort function when sorting nodes in a data structure.
//For example, if you had a vector containing nodes and you wanted to sort that vector by frequency, you could say
//  sort(nodeVec.begin(), nodeVec.end(), sorter); //sort the nodes least to greatest
static struct {
	bool operator()(NodeInterface* a, NodeInterface* b) {
		if (a->getFrequency() == b->getFrequency()) {//if the frequencies are even,
			if (b->getCharacter() == '\0') return false;
			if (a->getCharacter() != '\0') {
				return (int)a->getCharacter() < (int)b->getCharacter();
				
			}			
			return false;	
		}
		return a->getFrequency() < b->getFrequency();
	}
} sorter;
