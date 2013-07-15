/*
 * lcs.cpp
 * solution to
 *  Created on: 2013Äê7ÔÂ14ÈÕ
 *      Author: luo
 */
#include <iostream>

using namespace std;


char a[] = "abcdef";
char b[] = "abc";

class LCS{
public:
	static int find_lcs(char* a, int size_a, char* b, int size_b);
};

int LCS::find_lcs(char* a, int size_a, char* b, int size_b){
	if(size_a == 1 && size_b == 1){
		if(a[0] == b[0])
			return 1;
		else
			return 0;
	}else if( size_a == 1){
		if(a[0] == b[size_b - 1])
			return 1;
		else
			return find_lcs(a, size_a, b, size_b - 1);
	}else if(size_b == 1){
		if(b[0] == a[size_a - 1])
			return 1;
		else
			return find_lcs(a, size_a - 1, b, size_b);
	}
	if(a[size_a - 1] == b[size_b -1])
		return find_lcs(a, size_a - 1, b, size_b -1) + 1;
	int temp1 = find_lcs(a, size_a, b, size_b - 1);
	int temp2 = find_lcs(a, size_a - 1, b, size_b);
	int max = temp1 > temp2 ? temp1 : temp2;
	return max;
}


int main(){
	cout << LCS::find_lcs(a, 6, b, 6) << endl;
	return 0;
}
