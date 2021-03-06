#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
	char data;
	Node* par;
	vector<Node*> chi;

	Node(char v)
	{
		data = v;
		par = NULL;
	}

	void insertChild(Node* n)
	{
		chi.push_back(n);
		return;
	}

	int depth(Node* n)
	{
		int cnt = 0;
		
		while(n->par !)
	}
};

class Tree
{
public:
	Node* root;
	vector<Node*> tree_list;

	Tree() { root = NULL; }

	Tree(char v)
	{
		root = new Node(v);
		tree_list.push_back(root);
	}

	Node* searchNode(char t)
	{
		for (auto &i : tree_list)
		{
			if (i->data == t)
				return i;
		}
	}

	void insertNode(char t, char v)
	{
		for (auto &i : tree_list)
		{
			if (i->data == t)
			{
				Node* n = new Node(v);
				i->insertChild(n);
				n->par = i;
				tree_list.push_back(n);
				return;
			}
		}
	}

	void preorder(Node* n)
	{
		if (n->data == '#')
			cout << "";
		else
			cout << n->data << ""; // process

		if (n->chi.size() != 0)
		{
			for (auto &i : n->chi) // 모든 chi에 대해서 (Node*)
				preorder(i);
		}
	}

	void inorder(Node* n)
	{
		// left쪽 처리
		if (n->chi.size() != 0)
		{
			Node* left = n->chi.at(0);
			inorder(left);
		}

		// 자신 처리
		if (n->data == '#')
			cout << "";
		else
			cout << n->data << "";

		// right쪽 처리
		if (n->chi.size() != 0)
		{
			Node* right = n->chi.at(1);
			inorder(right);
		}
	}

	void postorder(Node* n)
	{
		if (n->chi.size() == 0)
		{
			if (n->data == '#')
				cout << "";
			else
				cout << n->data;
			return;
		}
		else
		{
			for (auto &i : n->chi)
				postorder(i);

			if (n->data == '#')
				cout << "";
			else
				cout << n->data;
		}
	}

	void countLeft(Node* n)
	{
		// child는 오직 left(n->chi[0])와 right(n->chi[1])로 구성
		if (n->chi.size() == 0)
			return;
		else
		{

		}
	}
};

int main(void)
{
	Tree t('A');

	int N; // 노드의 개수
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		char P;
		cin >> P;

		for (int j = 0; j < 2; j++) // 자식노드는 최대 2개
		{
			char C; // 자식노드
			cin >> C;

			t.insertNode(P, C);
		}
	}

	t.preorder(t.searchNode('A'));
	cout << endl;
	t.inorder(t.searchNode('A'));
	cout << endl;
	t.postorder(t.searchNode('A'));
	cout << endl;

	system("pause");
	return 0;
}