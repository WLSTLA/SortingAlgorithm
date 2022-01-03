#include<iostream>
#include<vector>
/*
	ͨ�������󶥶ѻ�С���ѽ�������
	�󶥶ѣ��Ѷ�һ��������Ԫ��
	С���ѣ��Ѷ�һ������С��Ԫ��
	ͬʱ����һ����ȫ������������������д洢
	������ ���ڵ� indexP = (i-1)/2
	���ӽڵ� indexl = 2i+1
	�Һ��ӽڵ� indexr = 2i+2
*/

template<class ValType>
struct MinHeap {
	bool operator()(const ValType& val1, const ValType& val2) {
		return val1 < val2;
	}
};

template<class ValType>
struct MaxHeap {
	bool operator()(const ValType& val1, const ValType& val2) {
		return val1 > val2;
	}
};

//Ĭ�Ϲ����󶥶�
template<class ValType,class SortMethod= MaxHeap<ValType>>	
class Heap{
public:
	void CreateHeap(std::vector<ValType>& vector,size_t length) {
		// �����һ��Ԫ�ؿ�ʼ����
		for (size_t i = length - 1; i > 0; --i) {
			size_t parentIndex = (i - 1) / 2;
			if (MaxHeap<ValType>()(vector[i], vector[parentIndex])) {
				std::swap(vector[i], vector[parentIndex]);
			}
		}
	}

	void HeapSort(std::vector<ValType>& vector) {
		size_t size = vector.size();
		while (size > 0) {
			CreateHeap(vector,size);	//ÿ�ΰ����/��С�Ƶ���һ��λ��
			--size;
			std::swap(vector[0], vector[size]);	//�ѵ�ǰ�ź����������С��Ԫ���ŵ����һ��Ԫ�أ���Ϊ�Ѿ��ź����Ԫ��
		}
	}
};

int main() {
	std::vector<int> v;
	Heap<int>s;
	for (size_t i = 0; i < 10; ++i) {
		v.push_back(rand() % 10 + 1);
	}
	s.HeapSort(v);
	for (const auto& elem : v) {
		std::cout << elem << " ";
	}
	return 0;
}