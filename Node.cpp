#include "Node.h"

Node::Node(char character)
{
  prev = NULL;
  next = NULL;
  element = character;
};

char Node::getElement() { return element; }

Node *Node::getPrev() { return prev; }

Node *Node::getNext() { return next; }

void Node::setElement(char character) { element = character; }

void Node::setPrev(Node *node) { prev = node; }

void Node::setNext(Node *node) { next = node; }