#include<iostream>
#include<vector>

/*
	两两元素进行比较，一趟排序下来最大/最小的元素排在最后
*/

template<class valType>
void BubbleSort(std::vector<valType>& vector) {
	for (size_t i = 0; i < vector.size(); ++i) {
		for (size_t j = 0; j < vector.size()-1-i; ++j) {
			if (vector[j] > vector[j+1]) {
				std::swap(vector[j], vector[j + 1]);
			}
		}
	}
}



int main() {
	std::vector<int> v;
	for (size_t i = 0; i < 10; ++i) {
		v.push_back(rand() % 10 + 1);
	}
	BubbleSort(v);
	for (const auto& elem : v) {
		std::cout << elem << " ";
	}
	return 0;
}