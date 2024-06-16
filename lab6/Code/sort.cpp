#include <bits/stdc++.h>

using namespace std;

// 冒泡排序
void bubbleSort(vector< int > &arr) {
	int n = arr.size();
	for(int i = 0; i < n - 1; i++) {
		for(int j = 0; j < n - i - 1; j++) {
			if(arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

// 选择排序
void selectionSort(vector< int > &arr) {
	int n = arr.size();
	for(int i = 0; i < n; i++) {
		int minIndex = i;
		for(int j = i + 1; j < n; j++) {
			if(arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		swap(arr[i], arr[minIndex]);
	}
}

// 插入排序
void insertionSort(vector< int > &arr) {
	int n = arr.size();
	for(int i = 1; i < n; i++) {
		int key = arr[i];
		int j   = i - 1;
		while(j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j          = j - 1;
		}
		arr[j + 1] = key;
	}
}

// 希尔排序
void shellSort(vector< int > &arr) {
	int n = arr.size();
	for(int gap = n / 2; gap > 0; gap /= 2) {
		for(int i = gap; i < n; i++) {
			int temp = arr[i];
			int j;
			for(j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
				arr[j] = arr[j - gap];
			}
			arr[j] = temp;
		}
	}
}

// 归并排序
void merge(vector< int > &arr, int l, int m, int r) {
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	vector< int > L(n1), R(n2);
	for(i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for(j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];
	i = 0;
	j = 0;
	k = l;
	while(i < n1 && j < n2) {
		if(L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		} else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while(i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	while(j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(vector< int > &arr, int l, int r) {
	if(l < r) {
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

// 快速排序
int partition(vector< int > &arr, int low, int high) {
	int pivot = arr[high];
	int i     = (low - 1);
	for(int j = low; j <= high - 1; j++) {
		if(arr[j] < pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

void quickSort(vector< int > &arr, int low, int high) {
	if(low < high) {
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

// 堆排序
void heapify(vector< int > &arr, int n, int i) {
	int largest = i;
	int left    = 2 * i + 1;
	int right   = 2 * i + 2;
	if(left < n && arr[left] > arr[largest])
		largest = left;
	if(right < n && arr[right] > arr[largest])
		largest = right;
	if(largest != i) {
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

void heapSort(vector< int > &arr) {
	int n = arr.size();
	for(int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);
	for(int i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

// 计数排序
void countSort(vector< int > &arr) {
	int max   = *max_element(arr.begin(), arr.end());
	int min   = *min_element(arr.begin(), arr.end());
	int range = max - min + 1;
	vector< int > count(range), output(arr.size());
	for(int i = 0; i < arr.size(); i++)
		count[arr[i] - min]++;
	for(int i = 1; i < count.size(); i++)
		count[i] += count[i - 1];
	for(int i = arr.size() - 1; i >= 0; i--) {
		output[count[arr[i] - min] - 1] = arr[i];
		count[arr[i] - min]--;
	}
	for(int i = 0; i < arr.size(); i++)
		arr[i] = output[i];
}

// 桶排序
void bucketSort(vector< float > &arr) {
	int n = arr.size();
	vector< float > b[n];
	for(int i = 0; i < n; i++) {
		int bi = n * arr[i];
		b[bi].push_back(arr[i]);
	}
	for(int i = 0; i < n; i++)
		sort(b[i].begin(), b[i].end());
	int index = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < b[i].size(); j++)
			arr[index++] = b[i][j];
}

// 获取x的第d位数字
int getDigit(int x, int d) {
	return (x / (int)pow(10, d - 1)) % 10;
}

// 基数排序
void radixsort(vector< int > &arr) {
	int maxVal = *max_element(arr.begin(), arr.end());
	int digits = log10(maxVal) + 1;
	vector< int > temp(arr.size());
	for(int d = 1; d <= digits; d++) {
		vector< int > count(10, 0);
		for(int i = 0; i < arr.size(); i++) {
			count[getDigit(arr[i], d)]++;
		}
		for(int i = 1; i < 10; i++) {
			count[i] += count[i - 1];
		}
		for(int i = arr.size() - 1; i >= 0; i--) {
			temp[count[getDigit(arr[i], d)] - 1] = arr[i];
			count[getDigit(arr[i], d)]--;
		}
		arr = temp;
	}
}

void printArray(vector< int > &arr) {
	for(int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test() {
	vector< int > arr = { 64, 34, 25, 12, 22, 11, 90 };
	cout << "原始数组：";
	printArray(arr);

	vector< int > sortedArr = arr;
	bubbleSort(sortedArr);
	cout << "冒泡排序后的数组：";
	printArray(sortedArr);

	sortedArr = arr;
	selectionSort(sortedArr);
	cout << "选择排序后的数组：";
	printArray(sortedArr);

	sortedArr = arr;
	insertionSort(sortedArr);
	cout << "插入排序后的数组：";
	printArray(sortedArr);

	sortedArr = arr;
	shellSort(sortedArr);
	cout << "希尔排序后的数组：";
	printArray(sortedArr);

	sortedArr = arr;
	mergeSort(sortedArr, 0, sortedArr.size() - 1);
	cout << "归并排序后的数组：";
	printArray(sortedArr);

	sortedArr = arr;
	quickSort(sortedArr, 0, sortedArr.size() - 1);
	cout << "快速排序后的数组：";
	printArray(sortedArr);

	sortedArr = arr;
	heapSort(sortedArr);
	cout << "堆排序后的数组：";
	printArray(sortedArr);

	sortedArr = arr;
	countSort(sortedArr);
	cout << "计数排序后的数组：";
	printArray(sortedArr);

	// 注意：桶排序需要浮点数输入，这里我们跳过桶排序

	sortedArr = arr;
	radixsort(sortedArr);
	cout << "基数排序后的数组：";
	printArray(sortedArr);
}

void menu() {
	cout << "请输入元素数量：";
	int n;
	cin >> n;
	vector< int > arr(n);
	cout << "请输入元素：";
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	cout << "原始数组：";
	printArray(arr);

	cout << "请选择排序算法：\n";
	cout << "1. 冒泡排序\n";
	cout << "2. 选择排序\n";
	cout << "3. 插入排序\n";
	cout << "4. 希尔排序\n";
	cout << "5. 归并排序\n";
	cout << "6. 快速排序\n";
	cout << "7. 堆排序\n";
	cout << "8. 计数排序\n";
	cout << "9. 基数排序\n";
	cout << "请输入你的选择（1-9）：";

	int choice;
	cin >> choice;
	vector< int > sortedArr = arr;

	switch(choice) {
		case 1:
			bubbleSort(sortedArr);
			cout << "冒泡排序后的数组：";
			break;
		case 2:
			selectionSort(sortedArr);
			cout << "选择排序后的数组：";
			break;
		case 3:
			insertionSort(sortedArr);
			cout << "插入排序后的数组：";
			break;
		case 4:
			shellSort(sortedArr);
			cout << "希尔排序后的数组：";
			break;
		case 5:
			mergeSort(sortedArr, 0, sortedArr.size() - 1);
			cout << "归并排序后的数组：";
			break;
		case 6:
			quickSort(sortedArr, 0, sortedArr.size() - 1);
			cout << "快速排序后的数组：";
			break;
		case 7:
			heapSort(sortedArr);
			cout << "堆排序后的数组：";
			break;
		case 8:
			countSort(sortedArr);
			cout << "计数排序后的数组：";
			break;
		case 9:
			radixsort(sortedArr);
			cout << "基数排序后的数组：";
			break;
		default:
			cout << "无效的选择！";
			return;
	}
	printArray(sortedArr);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cout << "单步调试请按一" << endl;
	cout << "测试请按二" << endl;
	int T;
	cin >> T;
	if(T == 1)
		menu();
	else if(T == 2)
		test();
	return 0;
}
