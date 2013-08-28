/*
 * max_n_num.cpp
 * 给出大小为M的数组，用最快的办法找出前N个大的数字
 *  Created on: 2013年8月28日
 *      Author: luo
 */
#include <stdlib.h>

#include <queue>
#include <vector>

using namespace std;



int main() {
	int m, n;
	scanf("%d%d", &m, &n);

	int num = 0;
	priority_queue<int, vector<int>, greater<int> > nums;
	for(int i = 0; i < m; ++i){
		scanf("%d", &num);
		nums.push(num);
	}

	for(int i = 0; i < n; ++i)
		printf("%d ", nums.pop());
}

