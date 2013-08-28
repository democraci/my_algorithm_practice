#include <iostream>

bool isPosterOrder(int low, int high, int arr[]){
	if(low >= high) return true;
	//suppose the tree has left children and right children
	int root = arr[high];
	int left_low = low;
	int left_high = -1;
	int right_low = -1;
	int right_high = high-1;

	bool splited = false;
	for(int i = low; i <= high-1; ++i){
		if(arr[i] > root && !splited){
			left_high = i-1;
			right_low = i;
			splited = true;
		}else if(arr[i] < root && splited){
			return false;
		}else
			left_high = i;
	}
	bool has_left = false;
	bool has_right = false;
	if(left_high >= left_low){
		has_left = true;
	}
	if(right_low != -1)
		has_right = true;
	bool isLeftPosterOrder = true;
	bool isRightPosterOrder = true;
	if(has_left)
		isLeftPosterOrder = isPosterOrder(left_low, left_high, arr);
	if(has_right)
		isRightPosterOrder = isPosterOrder(right_low, right_high, arr);
	return isLeftPosterOrder && isRightPosterOrder;
}

int main(){
	int arr[] = {6, 8, 7, 10, 12, 11, 9};
	std::cout << isPosterOrder(0, sizeof(arr)/sizeof(int) - 1, arr) << std::endl;
	int arr1[] = {8,9,10,11,3,4,2};
	std::cout << isPosterOrder(0, sizeof(arr1)/sizeof(int) - 1, arr1) << std::endl;
	return 0;
}
