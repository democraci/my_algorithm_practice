///*
// * lis.cpp
// *	solution to http://hawstein.com/posts/dp-novice-to-advanced.html
// *  Created on: 2013年7月12日
// *      Author: luo
// */
//
////d(i) = max{1, d(j)+1},其中j<i,A[j]<=A[i]
//#include <iostream>
//#include <algorithm>
//
//
//int lis(int sequence[], int length){
//	int* result = new int[length + 1];
//	int max = 0;
//	result[1] = 1;
//	for(int i = 2; i <= length; ++i){
//		max = 1;
//		for(int j = 1; j < i; ++j ){
//			if(sequence[j] <= sequence[i])
//				if(max < (result[j] + 1))
//					max = result[j] + 1;
//		}
//		result[i] = max;
//	}
//	max = *(std::max_element(result+1, result+length+1));
//	delete result;
//	return max;
//}
//
//int main() {
//	int length;
//	std::cin >> length;
//	if(length < 1) {
//		std::cout <<" length must greater than 1" << std::endl;
//		return 0;
//	}
//
//	int* sequence = new int[length+1];
//	for(int i = 1; i <= length; ++i){
//		std::cin >> sequence[i];
//	}
//	std::cout << "lis is " << lis(sequence, length) << std::endl;
//	delete sequence;
//}
//
//
