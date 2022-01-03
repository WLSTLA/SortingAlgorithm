#include<iostream>
#include<vector>

/*
	希尔排序是插入排序的改良版本
	算法思想：先将待排序表分割成若干如L[i,i+d,i+2d,...,i+kd]的特殊子表，
	对各个子表分别进行直接插入排序。缩小增量d，重复上述过程，
	直到d=1为止。
*/

template<class ValType>
void ShellSort(std::vector<ValType>& vector) {
	size_t step, i, j;
	for (step = vector.size() / 2; step >= 1; step = step / 2) {	//步长变化
		for (i = step; i < vector.size(); ++i) {
			for (j = i; j >= step && vector[j] < vector[j - step]; j -= step) {
				std::swap(vector[j], vector[j - step]);
			}
		}
	}
}

int main() {
	std::vector<int> v;
	for (size_t i = 0; i < 10; ++i) {
		v.push_back(rand() % 10 + 1);
	}
	ShellSort(v);
	for (const auto& elem : v) {
		std::cout << elem << " ";
	}
	return 0;
}