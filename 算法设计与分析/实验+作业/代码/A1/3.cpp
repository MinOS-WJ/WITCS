#include <iostream>
#include <climits>

struct Result {
    int maxVal;
    int minVal;
};

Result findMaxMin(const int arr[], int low, int high) {
    Result res;
    
    if (low == high) {
        res.maxVal = arr[low];
        res.minVal = arr[low];
        return res;
    }
    
    if (high - low == 1) {
        if (arr[low] > arr[high]) {
            res.maxVal = arr[low];
            res.minVal = arr[high];
        } else {
            res.maxVal = arr[high];
            res.minVal = arr[low];
        }
        return res;
    }
    
    int mid = low + (high - low) / 2;
    
    Result leftRes = findMaxMin(arr, low, mid);
    
    Result rightRes = findMaxMin(arr, mid + 1, high);
    
    res.maxVal = (leftRes.maxVal > rightRes.maxVal) ? leftRes.maxVal : rightRes.maxVal;
    res.minVal = (leftRes.minVal < rightRes.minVal) ? leftRes.minVal : rightRes.minVal;
    
    return res;
}

int main() {
    int n;
    if (!(std::cin >> n) || n <= 0) {
        std::cout << "无效的输入" << std::endl;
        return 0;
    }

    int* arr = new int[n];
    
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    
    Result res = findMaxMin(arr, 0, n - 1);
    
    std::cout << "最大值: " << res.maxVal << std::endl;
    std::cout << "最小值: " << res.minVal << std::endl;
    
    delete[] arr;
    
    return 0;
}