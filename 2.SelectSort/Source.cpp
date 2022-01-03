#include<iostream>
#include<vector>

/*
	选择排序
	即找到最小元素/最大元素，并记录其位置，
	然后和第i个元素进行交换，每次进行一个循环便找到一个最小值/最大值。
*/

template<class ValType>
void SelectSort(std::vector<ValType>& vector) {
	size_t index;
	for (size_t i = 0; i < vector.size(); ++i) {
		index = i;
		for (size_t j = i + 1; j< vector.size()-1; ++j) {
			if (vector[index] > vector[j])
				index = j;
		}
		std::swap(vector[i], vector[index]);
	}
}


int main() {
	std::vector<int> v;
	for (size_t i = 0; i < 10; ++i) {
		v.push_back(rand() % 10 + 1);
	}
	SelectSort(v);
	for (const auto& elem : v) {
		std::cout << elem << " ";
	}
	return 0;
}