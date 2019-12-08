//
// Created by Luzh on 2019/12/8.
//

#ifndef BINARYSEARCHTREE_BSTREE_H
#define BINARYSEARCHTREE_BSTREE_H

template <class T>
class BSTNode {
public:
    T key; // 关键字;
    BSTNode* lChild; // 左孩子节点;
    BSTNode* rChild; // 右孩子节点;
    BSTNode* parent; // 父节点;

    BSTNode(T value, BSTNode *p, BSTNode *l, BSTNode *r):
        key(value), parent(p), lChild(l), rChild(r) {}
};

template <class T>
class BSTree {
private:
    BSTNode<T> *mRoot;
    void insert(BSTNode<T>* &tree, BSTNode<T>* z);
    void preOrder(BSTNode<T>* tree) const;
    void inOrder(BSTNode<T>* tree) const;

public:
    BSTree();
    ~BSTree();
    void destroy(BSTNode<T>* &node);
    void insert(T value);
    void preOrder();
    void inOrder();
};

template <class T>
BSTree<T>::BSTree() {
    mRoot = NULL;
}

template <class T>
BSTree<T>::~BSTree() {
    destroy(mRoot);
}

template <class T>
void BSTree<T>::destroy(BSTNode<T>* &node) {
    if (node == NULL)
        return;
    if (node->lChild)
        return destroy(node->lChild);
    if (node->rChild)
        return destroy(node->rChild);
    delete node;
    node = NULL;
}

template <class T>
void BSTree<T>::insert(T value) {
    BSTNode<T> *z = NULL;
    if ((z = new BSTNode<T>(value, NULL, NULL, NULL)) == NULL)
        return;
    insert(mRoot, z);
}

template <class T>
void BSTree<T>::insert(BSTNode<T> *&tree, BSTNode<T> *z) {
    BSTNode<T> *y = NULL;
    BSTNode<T> *x = tree;

    while (x != NULL) {
        y = x;
        if (z->key < x->key)
            x = x->lChild;
        else
            x = x->rChild;
    }

    z->parent = y;
    if (y == NULL)
        tree = z;
    else if (z->key < y->key)
        y->lChild = z;
    else
        y->rChild = z;
}

template <class T>
void BSTree<T>::preOrder() {
    preOrder(mRoot);
}

template <class T>
void BSTree<T>::preOrder(BSTNode<T> *tree) const {
    if (tree != NULL) {
        std::cout << tree->key << " ";
        preOrder(tree->lChild);
        preOrder(tree->rChild);
    }
}
template <class T>
void BSTree<T>::inOrder() {
    inOrder(mRoot);
}

template <class T>
void BSTree<T>::inOrder(BSTNode<T> *tree) const {
    if (tree != NULL) {
        inOrder(tree->lChild);
        std::cout << tree->key << " ";
        inOrder(tree->rChild);
    }
}

#endif //BINARYSEARCHTREE_BSTREE_H
