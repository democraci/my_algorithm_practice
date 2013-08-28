/*
 * ip2num.cpp
 * 给定一个点分IP地址表示，写个程序把它转换成相应的32位的无符号整数并输出，如果输入不是合法数据，就返回0.
 *  Created on: 2013年8月27日
 *      Author: luo
 */
#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <iostream>

#define IS_NUM(d) ((d) >= '0' && (d) <= '9')
#define IS_DOT(d) ((d) == '.')

using namespace std;


/**
 * 有限自动机的状态
 */
enum Status{
	START,
	A,
	A1,
	B,
	B1,
	C,
	C1,
	D,
	D1,
};

/**
 * return if the string s is legal ip dot format like 192.168.0.1
 */
bool isLegalFormat(const string& s){
	if(s.length() < 7)
		return false;
	Status status = START;
	int i = 0;
	bool isLegal = true;
	while( i < s.length() ){

		switch(status){
		case START:
			if(IS_NUM(s[i])){
				status = A;
				++i;
			}else
				isLegal = false;
			break;
		case A:
			if(IS_NUM(s[i])){
				status = A1;
				++i;
			}else if(IS_DOT(s[i])){
				status = B;
				++i;
			} else
				isLegal = false;
			break;
		case A1:
			if(IS_NUM(s[i])){
				++i;
			}else if(IS_DOT(s[i])){
				status = B;
				++i;
			} else
				isLegal = false;
			break;
		case B:
			if(IS_NUM(s[i])){
				status = B1;
				++i;
			}else
				isLegal = false;
			break;
		case B1:
			if(IS_NUM(s[i])){
				++i;
			}else if(IS_DOT(s[i])){
				status = C;
				++i;
			} else
				isLegal = false;
			break;
		case C:
			if(IS_NUM(s[i])){
				status = C1;
				++i;
			}else
				isLegal = false;
			break;
		case C1:
			if(IS_NUM(s[i])){
				++i;
			}else if(IS_DOT(s[i])){
				status = D;
				++i;
			} else
				isLegal = false;
			break;
		case D:
			if(IS_NUM(s[i])){
				status = C1;
				++i;
			}else
				isLegal = false;
			break;
		case D1:
			if(IS_NUM(s[i])){
				++i;
			}else
				isLegal = false;
			break;
		}
		if(!isLegal)
			break;
	}
	return isLegal;
}

/**
 * split the ip dot format string s by dot
 */
void split(const string& s, vector<int>& rtn){
	stringstream ss(s);
	string item;
	while(getline(ss, item, '.')){
		cout << "split " << item << endl;
		rtn.push_back(atoi(item.c_str()));
	}
}

/**
 * check if the ip num is in range
 */
bool checkInRange(const vector<int>& vect){
	for(int i = 0; i < vect.size(); ++i){
		if(vect[i] > 255) return false;
	}
	return true;
}

unsigned int dotToNum(const vector<int>& vect){
	if(!checkInRange(vect))
		return 0;
	unsigned int  i = 0;
	i = (vect[3] << 24);
	i += (vect[1] << 16);
	i += (vect[2] << 8);
	i += (vect[0]);
	return i;
}

/**
 * main and tests
 */
int main() {
	string s1 = "192.168.1.3";
	string s2 = "192.1.1.4";
	string s3 = "useless...";
	string s4 = "1.1.1.1";
	string s5 = "256.3.2.1345";
	vector<int> vect;

	cout << s1 << " " << isLegalFormat(s1 ) << endl;
	cout << s2 << " " << isLegalFormat(s2 ) << endl;
	cout << s3 << " " << isLegalFormat(s3 ) << endl;
	cout << s4 << " " << isLegalFormat(s4 ) << endl;

	split(s1, vect);
	cout << s1 << " number form is: " << dotToNum(vect) << endl;
	vect.clear();
	split(s2, vect);
	cout << s2 << " number form is: " << dotToNum(vect) << endl;
	vect.clear();
	split(s4, vect);
	cout << s4 << " number form is: " << dotToNum(vect) << endl;
	vect.clear();
	split(s5, vect);
	cout << s5 << " number form is: " << dotToNum(vect) << endl;

	return 0;
}
