#include <bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	struct Node *left, *right;
};

Node *newNode(int item) {
	Node *temp = new Node;
	temp->key  = item;
	temp->left = temp->right = NULL;
	return temp;
}

Node *insert(Node *node, int key) {
	if(node == NULL)
		return newNode(key);
	if(key < node->key)
		node->left = insert(node->left, key);
	else if(key > node->key)
		node->right = insert(node->right, key);
	return node;
}

bool search(Node *root, int key, int &count) {
	count++;
	if(root == NULL)
		return false;
	if(root->key == key)
		return true;
	if(root->key < key)
		return search(root->right, key, count);
	return search(root->left, key, count);
}

int binarySearch(int arr[], int l, int r, int x, int &count) {
	if(r >= l) {
		int mid = l + (r - l) / 2;
		count++;
		if(arr[mid] == x)
			return mid;
		if(arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x, count);
		return binarySearch(arr, mid + 1, r, x, count);
	}
	return -1;
}
void test() {
	int arr[]  = { 2, 3, 4, 10, 40 };
	int n      = sizeof(arr) / sizeof(arr[0]);
	int x      = 10;
	int count  = 0;
	int result = binarySearch(arr, 0, n - 1, x, count);
	if(result != -1) {
		cout << "元素在索引 " << result << " 处" << endl;
		cout << "二分查找进行了 " << count << " 次比较" << endl;
	} else {
		cout << "数组中不存在该元素" << endl;
		cout << "二分查找进行了 " << count << " 次比较" << endl;
	}

	Node *root = NULL;
	root       = insert(root, arr[0]);
	for(int i = 1; i < n; i++)
		insert(root, arr[i]);

	count = 0;
	if(search(root, x, count)) {
		cout << "元素在二叉搜索树中" << endl;
		cout << "二叉搜索树查找进行了 " << count << " 次比较" << endl;
	} else {
		cout << "二叉搜索树中不存在该元素" << endl;
		cout << "二叉搜索树查找进行了 " << count << " 次比较" << endl;
	}
}

void menu() {
	cout << "请输入元素数量：";
	int n;
	cin >> n;
	int arr[n];
	cout << "请输入元素：";
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	cout << "请输入要查找的元素：";
	int x;
	cin >> x;
	int count  = 0;
	int result = binarySearch(arr, 0, n - 1, x, count);
	if(result != -1) {
		cout << "元素在索引 " << result << " 处" << endl;
		cout << "二分查找进行了 " << count << " 次比较" << endl;
	} else {
		cout << "数组中不存在该元素" << endl;
		cout << "二分查找进行了 " << count << " 次比较" << endl;
	}

	Node *root = NULL;
	root       = insert(root, arr[0]);
	for(int i = 1; i < n; i++)
		insert(root, arr[i]);

	count = 0;
	if(search(root, x, count)) {
		cout << "元素在二叉搜索树中" << endl;
		cout << "二叉搜索树查找进行了 " << count << " 次比较" << endl;
	} else {
		cout << "二叉搜索树中不存在该元素" << endl;
		cout << "二叉搜索树查找进行了 " << count << " 次比较" << endl;
	}
}


int main() {
	int T;
	cout << "请选择你要操作的模式" << endl;
	cout << "1. 单步调试" << endl;
	cout << "2. 案例测试" << endl;
	cin >> T;

	if(T == 1)
		menu();
	else if(T == 2)
		test();
	return 0;
}
