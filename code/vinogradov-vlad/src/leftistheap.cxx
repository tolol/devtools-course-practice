  // Copyright 2014 Vlad Vinogradov

#include "include/leftistheap.h"

#include <string>

LHeapNode::LHeapNode(const int key)
    : _key(key),
      _dist(0),
      _leftChild(NULL),
      _rightChild(NULL) {
}

LHeapNode* LHeapNode::merge(LHeapNode *x, LHeapNode *y) {
    if (x == NULL) {
        return y;
    }
    if (y == NULL) {
        return x;
    }

    // Since it's a min height biased leftist heap
    if (x->_key > y->_key) {
        LHeapNode *temp = x;
        x = y;
        y = temp;
    }

    x->_rightChild = merge(x->_rightChild, y);

    // We always try to move the node to the left side
    // to retain the leftist property
    if (x->_leftChild == NULL) {
        x->_leftChild = x->_rightChild;
        x->_rightChild = NULL;
    } else {
        if (x->_leftChild->_dist < x->_rightChild->_dist) {
            LHeapNode *temp = x->_leftChild;
            x->_leftChild = x->_rightChild;
            x->_rightChild = temp;
        }
        x->_dist = x->_rightChild->_dist + 1;
    }

    return x;
}

LeftistHeap::LeftistHeap()
    : _root(NULL) {
}

LeftistHeap::~LeftistHeap() {
    freeNode(_root);
}

LeftistHeap::LeftistHeap(const LeftistHeap& copy)
    : _root(copyFunction(copy._root)) {
}

LeftistHeap& LeftistHeap::operator= (const LeftistHeap& copy) {
    _root = copyFunction(copy._root);
    return *this;
}

void LeftistHeap::merge(LeftistHeap *otherLHeap) {
    _root = LHeapNode::merge(_root, otherLHeap->_root);

    // Forget the second heap
    otherLHeap->_root = NULL;
}

void LeftistHeap::insert(const int key) {
    LHeapNode *newNode = new LHeapNode(key);
    _root = LHeapNode::merge(_root, newNode);
}

int LeftistHeap::findMin() {
    if (_root) {
        return _root->_key;
    } else {
        throw std::string("Heap is empty.");
    }
}

int LeftistHeap::deleteMin() {
    // Take the key, delete the root
    // and merge left and right subtrees
    if (_root) {
        LHeapNode *leftChild = _root->_leftChild;
        LHeapNode *rightChild = _root->_rightChild;
        int keyValue = _root->_key;
        delete _root;
        _root = LHeapNode::merge(leftChild, rightChild);
        return keyValue;
    } else {
        throw std::string("Heap is empty.");
    }
}

bool LeftistHeap::isEmpty() {
    return (_root == NULL);
}

void LeftistHeap::freeNode(LHeapNode *node) {
    // Walk along the whole tree and delete all nodes
    if (node) {
        if (node->_leftChild) {
            freeNode(node->_leftChild);
        }
        if (node->_rightChild) {
            freeNode(node->_rightChild);
        }
        delete node;
        node = NULL;
    }
}

LHeapNode* LeftistHeap::copyFunction(LHeapNode *copyNode) {
    return copyRecursively(copyNode);
}

LHeapNode* LeftistHeap::copyRecursively(LHeapNode *other) {
    if (other == NULL) {
        return NULL;
    }

    LHeapNode *newNode = new LHeapNode(other->_key);
    newNode->_dist = other->_dist;

    newNode->_leftChild = copyRecursively(other->_leftChild);
    newNode->_rightChild = copyRecursively(other->_rightChild);

    return newNode;
}
