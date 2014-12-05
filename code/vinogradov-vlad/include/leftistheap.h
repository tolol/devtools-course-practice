// Copyright 2014 Vlad Vinogradov

#ifndef CODE_VINOGRADOV_VLAD_INCLUDE_LEFTISTHEAP_H_
#define CODE_VINOGRADOV_VLAD_INCLUDE_LEFTISTHEAP_H_

struct LHeapNode {
 public:
    explicit LHeapNode(const int key);
    static LHeapNode* merge(LHeapNode *x, LHeapNode *y);

    int _key, _dist;
    LHeapNode *_leftChild, *_rightChild;
};

// LHeapNode data structure with the lowest key in the root node
class LeftistHeap {
 public:
    LeftistHeap();
    ~LeftistHeap();
    LeftistHeap(const LeftistHeap& copy);
    LeftistHeap& operator= (const LeftistHeap& copy);
    void merge(LeftistHeap *otherLHeap);
    void insert(const int key);
    int findMin();
    int deleteMin();
    bool isEmpty();
 private:
    LHeapNode *_root;

    void freeNode(LHeapNode *node);
    LHeapNode* copyFunction(LHeapNode *copyNode);
    LHeapNode* copyRecursively(LHeapNode *other);
};

#endif  // CODE_VINOGRADOV_VLAD_INCLUDE_LEFTISTHEAP_H_
