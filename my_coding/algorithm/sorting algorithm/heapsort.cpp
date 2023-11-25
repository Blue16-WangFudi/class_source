
#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i; // 初始化最大值为根节点
    int l = 2 * i + 1; // 左子节点
    int r = 2 * i + 2; // 右子节点

    // 如果左子节点比根节点大，则更新最大值
    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }

    // 如果右子节点比根节点大，则更新最大值
    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }

    // 如果最大值不是根节点，则交换根节点和最大值
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // 递归地堆化子树
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    // 构建最大堆
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // 一个一个地从堆中取出元素
    for (int i = n - 1; i >= 0; i--) {
        // 将当前根节点（最大值）移动到末尾
        swap(arr[0], arr[i]);

        // 重新堆化未排序的元素
        heapify(arr, i, 0);
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    heapSort(arr);

    cout << "排序后的数组：\n";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
