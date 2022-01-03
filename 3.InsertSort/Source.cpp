#include<iostream>
#include<vector>

/*
	��������
	1.�ӵ�һ��Ԫ�ؿ�ʼ����Ԫ�ؿ�����Ϊ�Ѿ�������
	2.ȡ����һ��Ԫ�أ����Ѿ������Ԫ�������дӺ���ǰɨ��
	3.�����Ԫ�أ������򣩴�����Ԫ�أ�����Ԫ���Ƶ���һλ��
	4.�ظ�����3��ֱ���ҵ��������Ԫ��С�ڻ��ߵ�����Ԫ�ص�λ��
	5.����Ԫ�ز��뵽��λ�ú�
	�ظ�����2~5
*/

template<class ValType>
void InsertSort(std::vector<ValType>& vector) {
	// i=0 �Ѿ��ź���
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