///*
// * hamilton_path.cpp
// * Find the hamilton path of a given map. hamilton path definition can be seen
// * http://en.wikipedia.org/wiki/Hamilton_path
// *
// *Input
// *The input file starts with a number q (q<=20) on the first line, which is the number of test cases.
// *Each test case starts with a line with two integers n and m, which are the number of islands
// *and the number of bridges in the map, respectively. The next line contains n positive integers,
// *the i-th number being the Vi value of island i. Each value is no more than 100. The following
// *m lines are in the form x y, which indicates there is a (two way) bridge between island x and
// *island y. Islands are numbered from 1 to n. You may assume there will be no more than 13 islands.
// *
// *  Created on: 2013年7月6日
// *      Author: luo
// */
//
//#include <iostream>
//#include <stdlib.h>
//#include <stdio.h>
//#include <memory.h>
//
//static int* islandValue;
//static int** edge;
//static int* degree;
//static bool* islandInMap;
//static int* hamiltonPath;
//static int totalIslandCount;
//
///**
// *
// */
//bool findHamiltonPath(int islandCount, int currentIsland, int index) {
//	//递归终止条件为只有一个岛
//	if(islandCount == 1){
//		for(int i = 1; i <= totalIslandCount; ++i ){
//			if( islandInMap[i]){
//				hamiltonPath[index] = i;
//				return true;
//			}
//		}
//	}
//	int oneDegreeIslandCount = 0;
//	int oneDegreeIsland = 0;
//	for(int i = 1; i <= totalIslandCount; ++i ){
//		if(degree[i] == 1 && islandInMap[i]){
//			oneDegreeIslandCount++;
//			oneDegreeIsland = i;
//		}
//	}
//
//	if(oneDegreeIslandCount > 1) {
//		//std::cout << "no hamilton path can be found" << std::endl;
//		return false;
//	}
//
//	int nextIslandIndex = 0;
//	if(oneDegreeIslandCount == 1){
//		if(oneDegreeIsland != currentIsland)
//			return false;
//		islandInMap[oneDegreeIsland] = false;
//		hamiltonPath[index] = oneDegreeIsland;
//		for(int i = 1; i <= totalIslandCount; ++i){
//			if(edge[oneDegreeIsland][i] == 1 && islandInMap[i]){
//				degree[i]--;
//				nextIslandIndex = i;
//				break;
//			}
//		}
//		bool rtn = findHamiltonPath(--islandCount, nextIslandIndex, ++index);
//		for(int i = 1; i <= totalIslandCount; ++i){
//			if(edge[oneDegreeIsland][i] == 1 && islandInMap[i]){
//				degree[i]++;
//			}
//		}
//		islandInMap[oneDegreeIsland] = true;
//		return rtn;
//	}else {
//		for(int i = 1; i <= totalIslandCount; ++i){
//			if(edge[currentIsland][i] == 1 && islandInMap[i])
//				degree[i]--;
//		}
//		bool rtn;
//		for(int i = 1; i <= totalIslandCount; ++i){
//			if(edge[currentIsland][i] == 1 && islandInMap[i]){
//				islandInMap[currentIsland] = false;
//				rtn = findHamiltonPath(--islandCount, i, ++index);
//				islandInMap[currentIsland] = true;
//				if(rtn) {
//					for(int i = 1; i <= totalIslandCount; ++i){
//						if(edge[currentIsland][i] == 1 && islandInMap[i])
//							degree[i]++;
//					}
//					return rtn;
//				}
//			}
//
//		}
//		for(int i = 1; i <= totalIslandCount; ++i){
//			if(edge[currentIsland][i] == 1 && islandInMap[i])
//				degree[i]++;
//		}
//		return rtn;
//	}
//
//	return true;
//}
//
//int main(){
//	int q;
//	std::cin >> q;
//
//	int n, m;
//	for(; q > 0; --q){
//		std::cin >> n >> m;
//		totalIslandCount = n;
//		islandValue = new int[n+1];
//		edge = new int*[n+1];
//		for(int i = 1; i <= n+1; ++i){
//			edge[i] = new int[n+1];
//			memset(edge[i], 0, (n+1)*sizeof(int));
//		}
//		degree = new int[n+1];
//		islandInMap = new bool[n+1];
//		hamiltonPath = new int[n+1];
//
//		memset(degree, 0, (n+1)*sizeof(int));
//		memset(islandInMap, true, (n+1)*sizeof(int));
//		memset(hamiltonPath, 0, (n+1)*sizeof(int));
//		for(int i = 1; i <= n; ++i) {
//			std::cin >> islandValue[i];
//		}
//		int x, y;
//		for(int i = 0; i < m; ++i){
//			std::cin >> x >> y;
//			edge[x][y] = 1;
//			edge[y][x] = 1;
//			degree[x]++;
//			degree[y]++;
//		}
//
//		for(int i = 1; i <= n; ++i){
//			if(findHamiltonPath(n, i, 1)) {
//				for(int j = 1; j <= n; ++i)
//					std::cout << hamiltonPath[i] << " ";
//			}
//		}
//		delete[] islandValue;
//		delete[] degree;
//		delete[] islandInMap;
//		delete[] hamiltonPath;
//		for(int i = 0; i < n+1; ++i)
//			delete[] edge[i];
//		delete[] edge;
//		islandValue = NULL;
//		edge = NULL;
//		degree = NULL;
//		islandInMap = NULL;
//		hamiltonPath = NULL;
//	}
//	return 0;
//}
