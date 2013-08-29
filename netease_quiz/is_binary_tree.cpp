/*
 * is_binary_tree.cpp
 * ：现在有一种表示二叉树的字符串表达式，它的文法是：
 * N → a ( N, N )
 * N → ε
 * 其中终结符a表示任意一个英文字母，ε表示空。
 * 这个文法的含义是，二叉树的节点要么是空，要么是一个字母开头，并带有一对括号，
 * 括号中逗号左边是这个节点的左儿子，逗号右边是这个节点的右儿子。
 * 要求在内存中建立这样一棵树
 *  Created on: 2013年8月29日
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
