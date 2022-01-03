#include<iostream>
#include<vector>

/*
	��������
	�㷨˼�룺�ڴ������L[1...n]����ȡһ��Ԫ��pivot��Ϊ����(ͨ��ȡ��Ԫ��)��
	ͨ��һ�����򽫴��������Ϊ������������L[1...k-1]��L[k+1...n],ʹ��L[1...k-1]������
	Ԫ��С�����ᣬL[k+1...n]�е�����Ԫ�ض����ڵ�������,���������������λ��L(k)��,�������Ϊһ��
	���֣�Ȼ��ֱ�ݹ�ض������ӱ��ظ�����������ֱ��ÿ������ֻ��һ��Ԫ�ػ��Ϊֹ��
	������Ԫ�ط�����������λ����

	�㷨������Ҫȡ���ڵݹ���ȣ���ÿ�λ��־��ȣ���ݹ����Խ�ͣ���֮Խ�
	�ռ临�Ӷȣ����O(logn)  �O(n)
	ʱ�临�Ӷ�: ���O(nlogn) �O(n^2) ƽ��O(nlogn)
*/


template<class ValType>
class QuickObject {
public:
	size_t Partition(std::vector<ValType>& vector, size_t low, size_t high) {
		ValType pivot = vector[low];	//��һ��Ԫ����Ϊ����
		while (low < high) {			//��������Ϊlow=high
			while (vector[high] >= pivot && low < high)high--;
			vector[low] = vector[high];	//������С��Ԫ���ƶ������
			while (vector[low] <= pivot && low < high)low++;
			vector[high] = vector[low];	//��������Ԫ���ƶ����Ҷ�
		}
		vector[low] = pivot;	//���������λ��
		return low;
	}

	void QuickSort(std::vector<ValType>& vector,size_t low,size_t high) {
		if (low < high) {
			size_t pivotPos = Partition(vector, low, high);
			QuickSort(vector, low, pivotPos - 1);
			QuickSort(vector, pivotPos + 1, high);
		}
	}
};

int main() {
	std::vector<int> v;
	for (size_t i = 0; i < 10; ++i) {
		v.push_back(rand() % 10 + 1);
	}
	QuickObject<int> s;
	s.QuickSort(v,0,v.size()-1);
	for (const auto& elem : v) {
		std::cout << elem << " ";
	}
}