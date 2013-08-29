/*
 * is_binary_tree.cpp
 * ��������һ�ֱ�ʾ���������ַ������ʽ�������ķ��ǣ�
 * N �� a ( N, N )
 * N �� ��
 * �����ս��a��ʾ����һ��Ӣ����ĸ���ű�ʾ�ա�
 * ����ķ��ĺ����ǣ��������Ľڵ�Ҫô�ǿգ�Ҫô��һ����ĸ��ͷ��������һ�����ţ�
 * �����ж������������ڵ������ӣ������ұ�������ڵ���Ҷ��ӡ�
 * Ҫ�����ڴ��н�������һ����
 *  Created on: 2013��8��29��
 *      Author: luo
 */
#include <string>
#include <iostream>

using namespace std;

class Node{
public:
	Node* left;
	Node* right;
	char content;
	Node(Node* l, Node* r, char c) : left(l), right(r), content(c){}
	~Node(){
		delete left;
		delete right;
	}
	void print(){
		cout << content << "(";
		if(left != NULL)
			left->print();
		cout << ",";
		if(right != NULL)
			right->print();
		cout << ")";
	}
};

class BinaryTreeParser{
private:
	string& tree;
	int idx; //current position
public:
	BinaryTreeParser(string& t): tree(t),idx(-1){}
	Node* parse();
};

Node* BinaryTreeParser::parse(){
	if(idx >= (signed)tree.length()){
		throw "illegal form";
	}
	++idx;
	char nextChar = tree[idx];
	if( (nextChar >= 'a' && nextChar <= 'z') || (nextChar >= 'A' && nextChar <= 'Z')){
		++idx; // get the '(' character
		if(tree[idx] != '(')
			throw "illegal form";
		Node* left = parse();
		++idx;
		if(tree[idx] != ',')
			throw "illegal form";
		Node* right = parse();
		++idx;
		if(tree[idx] != ')')
			throw "illegal form";
		return new Node(left, right, nextChar);
	}else if(nextChar == ',' || nextChar == ')'){
		--idx;
		return NULL;
	}else{
		throw "illegal form";
	}
	return NULL;
}

int main() {
	string s = "A(B(,),C(D(,),))";
	BinaryTreeParser parser(s);
	Node* node = NULL;
	try{
		node = parser.parse();
		node->print();
	}catch(char const* e){
		cout << e << endl;
	}
}
