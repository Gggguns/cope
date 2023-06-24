#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Data
{
	int weight;
	char ch;
}Data;
typedef char HCode;

//Ê÷½Úµã
typedef struct HufuTreeNode
{
	int weight;
	int parent;
	int left;
	int right;
}HNode;

//´´½¨¹ş·òÂüÊ÷
HNode* HuFuManTreeCreate(int*arr,int size);

//¹ş·òÂü±àÂë
HCode** HuFuManCode(HNode* ht, int size);