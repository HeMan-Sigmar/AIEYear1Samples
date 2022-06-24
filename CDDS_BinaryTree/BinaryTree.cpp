/*----------------------------------------
Author: Richard Stern
Description: A simple binary search tree
Date: 17/4/2015
----------------------------------------*/
#include "BinaryTree.h"
#include "TreeNode.h"
#include "raylib.h"
#include <iostream>
#include <cstdlib>
using namespace std;


BinaryTree::BinaryTree()
{
    m_pRoot = nullptr;
}

BinaryTree::~BinaryTree()
{
	while(m_pRoot)
	{
		Remove(m_pRoot->GetData());
	}
}

// Return whether the tree is empty
bool BinaryTree::IsEmpty() const 
{ 
	return (m_pRoot == nullptr);
}

// Insert a new element into the tree.
// Smaller elements are placed to the left, larger onces are placed to the right.
void BinaryTree::Insert(int a_nValue)
{
	TreeNode* parentNode = nullptr;
	TreeNode* newNode = new TreeNode (a_nValue);

	if (m_pRoot == nullptr)
	{
		m_pRoot = newNode;
		return;
	}
	TreeNode* currentNode = m_pRoot;
	while (currentNode != nullptr)
		{
			if (a_nValue > currentNode -> GetData())
			{
				parentNode = currentNode;
				currentNode = currentNode->GetLeft();
				
			}
			else if (a_nValue < currentNode -> GetData())
			{
				parentNode = currentNode;
				currentNode = currentNode->GetRight();

			}
			else if (a_nValue == currentNode->GetData())
			{
				return;
			}
		}
		if (a_nValue < parentNode->GetData())
		{
			parentNode->SetLeft(newNode);
		}
		else
		{
			parentNode->SetRight(newNode);
		}
	
	/*If the tree is empty, the value is inserted at the root
	Set the current node to the root
	While the current node is not null
	If the value to be inserted is less than the value in the current node
	Set the current node to the left childand continue
	If the value to be inserted is greater than the current node
	Set the current node to the right childand continue
	If the value to be inserted is the same as the value in the current node
	The value is already in the tree, so exit
	end While
	Get the parent of the current node(before it was set to null)
	If value to be inserted is less than parent
	insert value as left child node
	otherwise insert value as right child node*/
}

TreeNode* BinaryTree::Find(int a_nValue, TreeNode* iter)
{
	TreeNode* pCurrent = nullptr;
	TreeNode* pParent = nullptr;

	while (pCurrent != NULL)
	{
		if (a_nValue = pCurrent->GetData())
		{
			pCurrent && pParent;
		}
		else
		{
			if (a_nValue < pCurrent->GetData())
			{
				pCurrent->GetLeft();

			}
			else
			{
				pCurrent->GetRight();

			}
		}
	}
	return FindNode(a_nValue, pCurrent, pParent) ? pCurrent: nullptr;
}

bool BinaryTree::FindNode(int a_nSearchValue, TreeNode*& ppOutNode, TreeNode*& ppOutParent)
{


	//if ()
	//{
	//	std::cout << "Match was not found";
	//	return false;
	//}
	/*Set the current node to the root
		While the current node is not null
		if the search value equals the current node value,
			return the current node and its parent
			otherwise
			If the search value is less than the current node
			set the current node to the left child
			otherwise set the current node to the right child
			end While
			If the loop exits, then a match was not found, so return false*/

	return false;
}

void BinaryTree::Remove(int a_nValue)
{

}

void BinaryTree::PrintOrdered()
{
	PrintOrderedRecurse(m_pRoot);
	cout << endl;
}

void BinaryTree::PrintOrderedRecurse(TreeNode* pNode)
{

}

void BinaryTree::PrintUnordered()
{
    PrintUnorderedRecurse(m_pRoot);
	cout << endl;
}

void BinaryTree::PrintUnorderedRecurse(TreeNode* pNode)
{

}

void BinaryTree::Draw(TreeNode* selected)
{
	Draw(m_pRoot, 400, 40, 400, selected);
}

void BinaryTree::Draw(TreeNode* pNode, int x, int y, int horizontalSpacing, TreeNode* selected)
{
	
	horizontalSpacing /= 2;

	if (pNode)
	{
		if (pNode->HasLeft())
		{
			DrawLine(x, y, x - horizontalSpacing, y + 80, RED);

			Draw(pNode->GetLeft(), x - horizontalSpacing, y + 80, horizontalSpacing, selected);
		}

		if (pNode->HasRight())
		{
			DrawLine(x, y, x + horizontalSpacing, y + 80, RED);

			Draw(pNode->GetRight(), x + horizontalSpacing, y + 80, horizontalSpacing, selected);
		}

		pNode->Draw(x, y, (selected == pNode));
	}
}