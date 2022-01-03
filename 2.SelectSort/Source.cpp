#include<iostream>
#include<vector>

/*
	ѡ������
	���ҵ���СԪ��/���Ԫ�أ�����¼��λ�ã�
	Ȼ��͵�i��Ԫ�ؽ��н�����ÿ�ν���һ��ѭ�����ҵ�һ����Сֵ/���ֵ��
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