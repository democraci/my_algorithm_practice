/*
 * task_manage.cpp
 * һ��������������Ŀ������ÿ�춼�кܶ���Ŀ����ѡ��ÿ����Ŀ����һ����ʼʱ��ͽ�ֹʱ�䣬
 * ÿ�����Ǯ���ǲ�ͬ�ģ����Ի������Ǯ���Ƕ��٣�
 * ���������������100
 *  Created on: 2013��8��28��
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
 * ����������Ŀ��ʱ�����Ϊend - start����[start, end)Ϊ��Ŀ����ʱ��
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

