///*
// * poj1088.cpp
// * solution to poj 1088
// *  Created on: 2013-07-14
// *      Author: luo
// */
//#include <iostream>
//
//int r, c;
//
//class Node{
//public:
//	int length;
//	bool visited;
//public:
//	Node(){
//		length = 0;
//		visited = false;
//	}
//};
//
//int find_shortest(int** path, Node** node, int x, int y){
//	if(node[x][y].visited)
//		return node[x][y].length;
//	int top=0,down=0,left=0,right=0;
//	int max=0,tmp1=0,tmp2=0;
//
//	//right
//	if((y+1) <= c && path[x][y] > path[x][y+1] )
//		right = find_shortest(path, node, x, y+1) + 1;
//
//	//left
//	if((y-1) >= 1  && path[x][y] > path[x][y-1] )
//		left = find_shortest(path, node, x, y-1) + 1;
//
//	//down
//	if((x+1) <= r && path[x][y] > path[x+1][y]  )
//		down = find_shortest(path, node, x+1, y) + 1;
//
//	//top
//	if((x-1) >= 1 && path[x][y] > path[x-1][y]  )
//		top = find_shortest(path, node, x -1, y) + 1;
//
//	tmp1 = left > right ? left : right;
//	tmp2 = down > top ? down : top;
//	if(tmp1 == 0 && tmp2 == 0)
//		max = 1;
//	else
//		max = tmp1 > tmp2 ? tmp1 : tmp2;
//
//  node[x][y].visited=true;
//  node[x][y].length = max;
//  return max;
//}
//
//int main() {
//	std::cin >> r >> c;
//
//	int** path = new int*[r+1];
//	Node** result = new Node*[r+1];
//	for(int i = 1; i <= r; ++i){
//		path[i] = new int[c+1];
//		result[i] = new Node[c+1];
//	}
//
//	for(int i = 1; i <= r; ++i){
//		for(int j = 1; j <= c; ++j){
//			std::cin >> path[i][j];
//		}
//	}
//	int max = 0;
//	int temp = 0;
//	for(int i = 1; i <= r; ++i)
//		for(int j = 1; j <= c; ++j){
//			temp = find_shortest(path, result, i, j);
//			max = (max < temp) ? temp : max;
//		}
//
//	std::cout << max << std::endl;
//	for(int i = 1; i <= c; ++i)
//		delete[] path[i];
//	delete[] path;
//}
//
