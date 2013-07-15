///*
// * coin_change.cpp
// *solution to http://hawstein.com/posts/dp-novice-to-advanced.html
// *
// *  Created on: 2013Äê7ÔÂ12ÈÕ
// *      Author: luo
// */
//#include <iostream>
//bool evaled[10000] = { true,false };
//int  coin_num[10000000] = { 0, 1, 2, 1, 2, 1 };
//
//
//int min_change_num(int num){
//	if(num < 0) {
//		std::cout << " illegal parameters" << std::endl;
//	}
//	int min;
//	for(int i = 6; i <= num; ++i) {
//		min = coin_num[i-1];
//		if(min > coin_num[i-3])
//			min = coin_num[i-3];
//		if(min > coin_num[i-5])
//			min = coin_num[i-5];
//		coin_num[i] = min + 1;
//	}
//
//	return coin_num[num];
//}
//
////int min_change_num(int num){
////	if(evaled[num])
////		return coin_num[num];
////	int rtn = min_change_num(num - 1) + 1;
////	int min_change;
////	if(num >= 5) {
////		min_change = min_change_num(num - 5);
////		if(rtn > (min_change + 1))
////			rtn = min_change + 1;
////	}
////	if(num >= 3) {
////		min_change = min_change_num(num - 3);
////		if(rtn > min_change)
////			rtn = min_change + 1;
////	}
////	evaled[num] = true;
////	coin_num[num] = rtn;
////	return rtn;
////}
//
//int main() {
//	std::cout << min_change_num(9000000);
//	return 0;
//}
