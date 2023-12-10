#include "Tree.h"


template<class T>
inline BinaryTree<T>::BinaryTree() : root(nullptr) {}

template <class T>
void BinaryTree<T>::insert(TreeNode*& nodePtr, TreeNode*& newNode)
{
	if (nodePtr == nullptr)
		nodePtr = newNode; 
	else if (newNode->value < nodePtr->value)
		insert(nodePtr->left, newNode);
	else
		insert(nodePtr->right, newNode);
}

template<class T>
inline void BinaryTree<T>::insertNode(T val)
{
	TreeNode* newNode = new TreeNode;

	newNode->value = val;
	newNode->left = nullptr;
	newNode->right = nullptr;
	
	insert(root, newNode);
}


template <class T>
void BinaryTree<T>::display(TreeNode* nodePtr) const
{
	if (nodePtr)
	{
		display(nodePtr->left);
		std::cout << nodePtr->value << " ";
		display(nodePtr->right);
	}
}



template<class T>
inline void BinaryTree<T>::destroy(TreeNode* nodePtr)
{
	if (nodePtr)
	{
		if (nodePtr->left)
			destroy(nodePtr->left);
		if (nodePtr->right)
			destroy(nodePtr->right);
		delete nodePtr;
	}

}



template<class T>
inline BinaryTree<T>::~BinaryTree()
{
	destroy(root);
}




