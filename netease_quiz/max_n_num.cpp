/*
 * max_n_num.cpp
 * ������СΪM�����飬�����İ취�ҳ�ǰN���������
 *  Created on: 2013��8��28��
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

