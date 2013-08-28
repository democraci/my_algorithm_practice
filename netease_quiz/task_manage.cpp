/*
 * task_manage.cpp
 * 一个人在网上做项目，加入每天都有很多项目可以选，每个项目都有一个开始时间和截止时间，
 * 每个活的钱数是不同的，可以获得最大的钱数是多少？
 * 假设最大活动数不超过100
 *  Created on: 2013年8月28日
 *      Author: luo
 */
#define MAX_TASK_COUNT 100
#define TIME_GAP 1000

struct Task{
	int start_time;
	int end_time;
	int value;
};

Task tasks[MAX_TASK_COUNT];
int maxValues[TIME_GAP][TIME_GAP];
int taskCount;

bool checkInRange(int start, int end, const Task& task){
	if(task.start_time >= start && task.end_time <= end)
		return true;
	else
		return false;
}
/**
 * 假设整个项目的时间耗用为end - start，意[start, end)为项目所耗时间
 */
int evalMaxValue(int start, int end){
	if(maxValues[start][end] != -1)
		return maxValues[start][end];
	if(start == end)
		return 0;
	int maxValue = 0;
	int tempValue = 0;
	for(int i = 0; i < taskCount; ++i){
		if(checkInRange(start, end, tasks[i])){
			tempValue = evalMaxValue(tasks[i].end_time, end) +
					evalMaxValue(start, tasks[i].start_time) + tasks[i].value;
			if(tempValue > maxValue)
				maxValue = tempValue;
		}
	}
	maxValues[start][end] = maxValue;
	return maxValue;
}

