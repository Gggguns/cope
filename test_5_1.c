#define _CRT_SECURE_NO_WARNINGS
#include"test_5_1.h"

//À≥–Ú≤È’“
int SequenceSearch(int* pa, int lenth, int key)
{
	for (int i = 0;i < lenth;i++)
	{
		ASL[SEQ_SEARCH]++;
		if (pa[i] == key)
			return i;
	}
	return -1;
}

//∂˛∑÷≤È’“
int BinarySearch(int* pa, int lenth, int key)
{
	int lower = 0, high = lenth - 1;
	int mid = (lower + high) / 2;
	while (lower <= high)
	{
		mid = (lower + high) / 2;
		ASL[BINARY_SEARCH]++;
		if (key == pa[mid])
			return mid;
		ASL[BINARY_SEARCH]++;
		if (key < pa[mid])
			high = mid - 1;
		else
			lower = mid + 1;
	}
	return -1;
}

//∂˛≤Ê ˜≈≈–Ú ˜

int SearchBST1(BTNode* pRoot, int key, BTNode** pKeyNode, BTNode** pParentNode)
{
	*pKeyNode = pRoot;
	*pParentNode = NULL;
	int found = 0;
	while (*pKeyNode)
	{
		if (key > (*pKeyNode)->key)
		{
			ASL[BST_SEARCH]++;
			*pParentNode = *pKeyNode;
			*pKeyNode = (*pKeyNode)->right;
		}
		else if (key < (*pKeyNode)->key)
		{
			ASL[BST_SEARCH]++;
			*pParentNode = *pKeyNode;
			*pKeyNode = (*pKeyNode)->left;
		}
		else
		{
			return 1;
		}
		return 0;
	}
}
int SearchBST2(BTNode* pRoot, int key)
{
	bool found = false;
	BTNode* pKeyNode = pRoot;
	while (pKeyNode)
	{
		if (key > pKeyNode->key)
		{
			ASL[BST_SEARCH]++;
			pKeyNode = pKeyNode->right;
		}
		else if (key < pKeyNode->key)
		{
			ASL[BST_SEARCH]++;
			pKeyNode = pKeyNode->left;
		}
		else
		{
			return true;
		}
	}
	return false;
}

//∆Ω∫‚∂˛≤Ê ˜
int SearchBalanceBST(BTNode* pRoot, int key)
{
	int found = 0;
	BTNode* pKeyNode = pRoot;
	while (pKeyNode)
	{
		if (key > pKeyNode->key)
		{
			ASL[BALANCE_SEARCH]++;
			pKeyNode = pKeyNode->right;
		}
		else if (key < pKeyNode->key)
		{
			ASL[BALANCE_SEARCH]++;
			pKeyNode = pKeyNode->left;
		}
		else
		{
			return true;
		}
		return false;
	}
}

//∂˛≤Ê ˜≈≈–Ú ˜≤Â»ÎÀ„∑®
int InsertBST(BTNode** pRoot, int key)
{
	BTNode* pKeyNode;
	BTNode* pParentNode = NULL;
	if (SearchBST1(*pRoot, key, &pKeyNode, &pParentNode))
		return 0;
	BTNode* pNewNode = (BTNode*)malloc(sizeof(BTNode));
	pNewNode->key = key;
	pNewNode->left = pNewNode->right = NULL;
	if (*pRoot == NULL)
		(*pRoot) = pNewNode;
	else if (key < pParentNode->key)
		pParentNode->left = pNewNode;
	else
		pParentNode->right = pNewNode;
	return 1;
}