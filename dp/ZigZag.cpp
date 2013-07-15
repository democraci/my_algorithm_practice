///*
// * ZigZag.cpp
// * solution to http://community.topcoder.com/stat?c=problem_statement&pm=1259&rd=4493
// *  Created on: 2013Äê7ÔÂ12ÈÕ
// *      Author: luo
// */
//#include <memory.h>
//#include <iostream>
//
//class ZigZag {
//public:
//	int longestZigZag(int sequence[], int size);
//};
//
//int ZigZag::longestZigZag(int sequence[], int size) {
////	int size = sizeof(sequence)/sizeof(int);
//	std::cout << "the size of array is " << size << std::endl;
//	if(size == 1 || size == 0)
//		return size;
//	if(size == 2){
//		if(sequence[0] == sequence[1])
//			return 1;
//		else
//			return 2;
//	}
//
//	int* zigzag_num = new int[size+1];
//	bool* zigzag_positive = new bool[size+1];
//	memset(zigzag_num, 0, sizeof(int) * (size + 1));
//	memset(zigzag_positive, false, sizeof(bool) * (size+1));
//
//	zigzag_num[1] = 1;
//	if((sequence[1] > sequence[0])) {
//		zigzag_num[2] = 2;
//		zigzag_positive[2] = true;
//	}else if(sequence[1] == sequence[0]){
//		zigzag_num[2] = 1;
//	}else {
//		zigzag_num[2] = 2;
//		zigzag_positive[2] = false;
//	}
//
//	int max = 0;
//	int positive = false;
////	1, 17, 5, 10, 13, 15, 10, 5, 16, 8
//	for(int i = 3; i <= size; ++i){
//		max = 0;
//		positive = false;
//		for(int j = 1; j <= i-1; ++j){
//			if( sequence[i-1] > sequence[j-1]) {
//				if(zigzag_num[j] == 1){
//					if(max < zigzag_num[j] + 1){
//						max = zigzag_num[j] + 1;
////						std::cout << max << std::endl;
//						positive = true;
//					}
//				}else {
//					if(!zigzag_positive[j]){
//						if(max < zigzag_num[j] + 1){
//							max = zigzag_num[j] + 1;
//							positive = true;
//						}
//					}
//				}
//			}else if(sequence[i-1] < sequence[j-1]) {
//				if(zigzag_num[j] == 1){
//					if(max < zigzag_num[j] + 1){
//						max = zigzag_num[j] + 1;
//						positive = false;
//					}
//				}else {
//					if(zigzag_positive[j]){
//						if(max < zigzag_num[j] + 1){
//							max = zigzag_num[j] + 1;
////							std::cout << max << std::endl;
//							positive = false;
//						}
//					}
//				}
//			}
//		}
//
//		if(max == 0){
//			zigzag_num[i] = 1;
//		}else {
//			zigzag_num[i] = max;
//			zigzag_positive[i] = positive;
//		}
////		std::cout << "the max zigzag sequence num with endian " << i << " is " << max << std::endl;
//	}
//
//	int rtn = zigzag_num[1];
//	for(int i = 2; i <= size; ++i){
//		if(rtn < zigzag_num[i])
//			rtn = zigzag_num[i];
//	}
//	delete[] zigzag_num;
//	delete[] zigzag_positive;
//	return rtn;
//}
//
//
//int main() {
//	int sequence[] = {
//			1, 1, 1, 1, 2, 2, 2, 2};
//	int size = sizeof(sequence)/sizeof(int);
//	ZigZag zigzag;
//	std::cout << "the sequence's longest zigzag is " << zigzag.longestZigZag(sequence, size) << std::endl;
//	return 0;
//}
//
//
