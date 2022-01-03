#include<iostream>
#include<vector>
/*
	归并排序
*/
const size_t MAX_SIZE = 10;

template<class ValType>
class MergeObejct {
public:
	MergeObejct() {
		_tmpArr = new ValType[MAX_SIZE]();
	}
	void MergeSort(std::vector<ValType>& vector, size_t low, size_t high) {	
		if(low < high) {
			size_t mid = (high+low) / 2;
			MergeSort(vector, low, mid);
			MergeSort(vector, mid + 1, high);
			Merge(vector,low,mid,high);
		}
	}

	void Merge(std::vector<ValType>& vector, size_t low, size_t mid, size_t high) {
		// 将下标low到high的元素先复制到临时数组中
		for (size_t i = low; i <= high; ++i) {
			_tmpArr[i] = vector[i];
		}
		size_t i, j, k;
		for (i = low, j = mid + 1, k = i; i <= mid && j <= high; ++k) {
			if (_tmpArr[i] <= _tmpArr[j]) {
				vector[k] = _tmpArr[i++];
			}
			else {
				vector[k] = _tmpArr[j++];
			}
		}
		// 跳出循环时，可能元素还没被复制完
		while (i <=mid) vector[k++] = _tmpArr[i++];
		while (j <=high)vector[k++] = _tmpArr[j++];
	}

	~MergeObejct()
	{
		if (!_tmpArr)return;
		delete[] _tmpArr;
		_tmpArr = nullptr;
	}
private:
	ValType* _tmpArr;
};



int main() {
	std::vector<int> v;
	MergeObejct<int>s;
	for (size_t i = 0; i < MAX_SIZE; ++i) {
		v.push_back(rand() % 10 + 1);
	}
	s.MergeSort(v,0,v.size()-1);
	for (const auto& elem : v) {
		std::cout << elem << " ";
	}
}