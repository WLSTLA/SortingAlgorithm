#include<iostream>
#include<vector>

/*
	����Ԫ�ؽ��бȽϣ�һ�������������/��С��Ԫ���������
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