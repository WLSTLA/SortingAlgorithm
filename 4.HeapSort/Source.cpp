#include<iostream>
#include<vector>
/*
	通过构建大顶堆或小顶堆进行排序
	大顶堆，堆顶一定是最大的元素
	小顶堆，堆顶一定是最小的元素
	同时堆是一个完全二叉树，采用数组进行存储
	则满足 父节点 indexP = (i-1)/2
	左孩子节点 indexl = 2i+1
	右孩子节点 indexr = 2i+2
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

//默认构建大顶堆
template<class ValType,class SortMethod= MaxHeap<ValType>>	
class Heap{
public:
	void CreateHeap(std::vector<ValType>& vector,size_t length) {
		// 从最后一个元素开始构造
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
			CreateHeap(vector,size);	//每次把最大/最小推到第一个位置
			--size;
			std::swap(vector[0], vector[size]);	//把当前排好序的最大或最小的元素排到最后一个元素，作为已经排好序的元素
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