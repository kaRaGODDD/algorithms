#pragma once

#include <iostream>
#include <ctime>
#include <chrono>
#include <vector>

template<class T>
class BinaryTree
{
private:
	struct TreeNode
	{
		T value; 
		TreeNode* left;
		TreeNode* right; 
	};
	TreeNode* root;
	void insert(TreeNode*&, TreeNode*&);
	void display(TreeNode*) const;
	void destroy(TreeNode*);
public:
	BinaryTree();
	void insertNode(T);
	void display() const {
		display(root);
	}

	~BinaryTree();
};

#include "Tree.inl"
