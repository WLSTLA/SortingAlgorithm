#include<iostream>
#include<vector>

/*
	插入排序
	1.从第一个元素开始，该元素可以认为已经被排序
	2.取出下一个元素，在已经排序的元素序列中从后向前扫描
	3.如果该元素（已排序）大于新元素，将该元素移到下一位置
	4.重复步骤3，直到找到已排序的元素小于或者等于新元素的位置
	5.将新元素插入到该位置后
	重复步骤2~5
*/

template<class ValType>
void InsertSort(std::vector<ValType>& vector) {
	// i=0 已经排好序
	int index;
	for (size_t i = 1; i < vector.size(); ++i) {
		index = i;
		while (index > 0) {
			if (vector[index] < vector[index - 1])
				std::swap(vector[index], vector[index - 1]);
			index--;
		}
	}
}

int main() {
	std::vector<int> v;
	for (size_t i = 0; i < 10; ++i) {
		v.push_back(rand() % 10 + 1);
	}
	InsertSort(v);
	for (const auto& elem : v) {
		std::cout << elem << " ";
	}
	return 0;
}