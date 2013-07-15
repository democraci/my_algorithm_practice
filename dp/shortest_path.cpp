///*
// * shortest_path.cpp
// *
// *  Created on: 2013年7月12日
// *      Author: luo
// *      int * int[]
// *      int[][] *(int[])
// *      int** int*[]
// */
//#include <iostream>
//#include <limits>
//#include <memory.h>
//#include <stdlib.h>
//
//#define MAX_INT 10000
//
//void find_shortest_path(int** path, int node_num, int from, int to){
//	if(from < 0 || from > node_num || to < 0 || to > node_num){
//		std::cout << "illegal parameter" << std::endl;
//		return;
//	}
//	std::cout << "gonna find the shortest path from " << from << " to " << to << std::endl;
//	if( from == to){
//		std::cout << "the shortest path weight is 0" << std::endl;
//		return;
//	}
//	int* shortest_path_weight = new int[node_num + 1];
//	int* prev_node = new int[node_num + 1];
//	bool* evaled = new bool[node_num + 1];
//	memset(shortest_path_weight, MAX_INT, (node_num + 1)*sizeof(int));
//	memset(prev_node, 0, (node_num + 1)*sizeof(int));
//	memset(evaled, false, (node_num+1)*(sizeof(bool)));
//
//	evaled[from] = true;
//	int min = MAX_INT;
//	int selected = 0;
//	int prev = from;
//	shortest_path_weight[prev] = 0;
//	while(!evaled[to]) {
//		std::cout << "add " << prev << std::endl;
//		for(int i = 1; i <= node_num; ++i){
//			//只更新未算出最短路径的节点
//			if(!evaled[i])
//				//如果prev点和当前点有路径，则更新标号
//				if(path[prev][i] != 0){
//					if(shortest_path_weight[i] > (shortest_path_weight[prev] + path[prev][i])){
//						shortest_path_weight[i] = shortest_path_weight[prev] + path[prev][i];
//						prev_node[i] = prev;
//					}
//				}
//		}
//
//		min = MAX_INT;
//		//选出标号最小的点，认为其最短路径已经算出
//		for(int i = 1; i <= node_num; ++i){
//			if(!evaled[i])
//				if( min > shortest_path_weight[i]){
//					min = shortest_path_weight[i];
//					selected = i;
//				}
//		}
//		prev = selected;
//		std::cout << "the next gonna be add is " << selected << std::endl;
//		evaled[selected] = true;
//	}
//	std::cout << "the shortest path weight from " << from << " to" << to << " is"<<shortest_path_weight[to] << std::endl;;
//	system("pause");
//	std::cout << "the path is ";
//	prev = prev_node[to];
//	do {
//		std::cout<<prev<<" ";
//		prev = prev_node[prev];
//	}while(prev != from);
//	std::cout<< from <<std::endl;
//
//	delete[] shortest_path_weight;
//	delete[] prev_node;
//	delete[] evaled;
//}
//
//int main() {
//	int node_num;
//	std::cin >> node_num;
//	int edge_num;
//	std::cin >> edge_num;
//	int from, to;
//	std::cin >> from >> to;
//
//	int** path = new int*[node_num+1];
//	for(int i = 1; i <= node_num; ++i){
//		path[i] = new int[node_num + 1];
//		memset(path[i], 0, sizeof(int)*(node_num + 1));
//	}
//
//	int x, y, weight;
//	for(int i = 1; i <= edge_num; ++i){
//		std::cin >> x >> y >> weight;
//		path[x][y] = weight;
//		path[y][x] = weight;
//	}
//
//	find_shortest_path(path, node_num, from, to);
//
//	for(int i = 1; i <= node_num; ++i)
//			delete[] path[i];
//	delete[] path;
//}
//
