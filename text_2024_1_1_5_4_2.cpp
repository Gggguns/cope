#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

struct TreeNode
{
	TreeNode(pair<char, int> p = make_pair('\0', 0))
		:_left(nullptr)
		,_right(nullptr)
		, _data(p)
	{}
	
	TreeNode* _left;
	TreeNode* _right;
	pair<char,int> _data;
};
struct HFTree
{
	void input()
	{
		int n = 0;
		cin >> n;
		int i = 0;
		for (i = 0;i < n;i++)
		{
			char ch;
			int FNum=0;
			cin >> ch>>FNum;
			_l.push_back(new TreeNode(make_pair(ch, FNum)));
		}
	}
	bool CreateHFTree()
	{
		reverse(_l.begin(), _l.end());
		if (_l.size() == 0)
			return false;
		
		while(_l.size()>=2)
		{
			TreeNode* NewNode = new TreeNode;
			NewNode->_left = _l.back();
			_l.pop_back();
			NewNode->_right = _l.back();
			_l.pop_back();
			NewNode->_data.second = NewNode->_left->_data.second + NewNode->_right->_data.second;
			list<TreeNode*>::iterator it = _l.begin();
			while (it != _l.end() && NewNode->_data.second < (*it)->_data.second)
			{
				it++;
			}
			_l.insert(it, NewNode);
		}
		_root = _l.front();
		return true;
	}

	void HFTreePrevOrder()
	{
		string str;
		_HFTreePrevOrder(_root,str);
	}
	void _HFTreePrevOrder(TreeNode* root,string str)
	{
		if (root == nullptr)
			return;
		if (root->_data.first != '\0')
		{
			cout << root->_data.first << ':' << str << endl;
		}
		_HFTreePrevOrder(root->_left, str + '0');
		_HFTreePrevOrder(root->_right, str + '1');
	}
	void output()
	{
		string str;
		string ResStr;
		cin >> str;
		while (str.size())
		{
			TreeNode* root = _root;
			while (root->_left != nullptr && root->_right != nullptr)
			{
				if (str.front() == '0')
					root = root->_left;
				if (str.front() == '1')
					root = root->_right;
				str.erase(str.begin());
			}
			ResStr += root->_data.first;
		}
		cout << "original:" << ResStr<<endl;
	}
	TreeNode* _root=nullptr;
	list<TreeNode*> _l;
};
int main()
{
	HFTree HF;
	HF.input();
	HF.CreateHFTree();
	HF.HFTreePrevOrder();
	HF.output();
	int x;
	return 0;
}