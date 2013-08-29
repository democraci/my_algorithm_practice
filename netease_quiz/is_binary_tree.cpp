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
	 * # = ��
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
