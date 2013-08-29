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
#include <stack>

#define IS_LETTER(a) ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))

using namespace std;

class BinaryTreeParser{
private:
	string& tree;
	unsigned int idx; //next position
	stack<char> stacks;
public:
	BinaryTreeParser(string& t): tree(t),idx(0),stacks(){
		stacks.push('$');
		stacks.push('#');
	}
	bool parse();
};

/**
 * use LL(1) to parse the grammer
 */
bool BinaryTreeParser::parse(){
	char c;
	/**
	 * the grammer was writed as:
	 * # = %(#,#)
	 * # = ε
	 */
	while( (c = stacks.top()) != '$' && idx < tree.length()){
		stacks.pop();
		if(c == '#'){ //non-terminal #
			if(tree[idx] == ',' || tree[idx] == ')'){ // do nothing
			}else if(IS_LETTER(tree[idx])){
				stacks.push(')');
				stacks.push('#');
				stacks.push(',');
				stacks.push('#');
				stacks.push('(');
				stacks.push('%');
			}
		}else if(c == '%'){
			if(!IS_LETTER(tree[idx]))
				return false;
			idx++;
		}else if(c == ',' || c == ')'){
			if(c != tree[idx])
				return false;
			idx++;
		}else{
			return false;
		}
	}
	return true;
}

int main() {
	string s = "A(B(,),C(D(,),))";
	BinaryTreeParser parser(s);
	cout << parser.parse();
}
