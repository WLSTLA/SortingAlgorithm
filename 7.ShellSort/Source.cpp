#include<iostream>
#include<vector>

/*
	ϣ�������ǲ�������ĸ����汾
	�㷨˼�룺�Ƚ��������ָ��������L[i,i+d,i+2d,...,i+kd]�������ӱ�
	�Ը����ӱ�ֱ����ֱ�Ӳ���������С����d���ظ��������̣�
	ֱ��d=1Ϊֹ��
*/

template<class ValType>
void ShellSort(std::vector<ValType>& vector) {
	size_t step, i, j;
	for (step = vector.size() / 2; step >= 1; step = step / 2) {	//�����仯
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