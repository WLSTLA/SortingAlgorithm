#include<iostream>
#include<vector>

/*
	快速排序
	算法思想：在待排序表L[1...n]中任取一个元素pivot作为枢轴(通常取首元素)，
	通过一趟排序将待排序表划分为独立的两部分L[1...k-1]和L[k+1...n],使得L[1...k-1]中所有
	元素小于枢轴，L[k+1...n]中的所有元素都大于等于枢轴,枢轴放在了其最终位置L(k)上,这个过程为一次
	划分，然后分别递归地队两个子表重复上述操作，直至每部分内只有一个元素或空为止，
	即所有元素放在了其最终位置上

	算法表现主要取决于递归深度，若每次划分均匀，则递归深度越低，反之越深。
	空间复杂度：最好O(logn)  最坏O(n)
	时间复杂度: 最好O(nlogn) 最坏O(n^2) 平均O(nlogn)
*/


template<class ValType>
class QuickObject {
public:
	size_t Partition(std::vector<ValType>& vector, size_t low, size_t high) {
		ValType pivot = vector[low];	//第一个元素作为枢轴
		while (low < high) {			//结束条件为low=high
			while (vector[high] >= pivot && low < high)high--;
			vector[low] = vector[high];	//比枢轴小的元素移动到左端
			while (vector[low] <= pivot && low < high)low++;
			vector[high] = vector[low];	//比枢轴大的元素移动到右端
		}
		vector[low] = pivot;	//更新枢轴的位置
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