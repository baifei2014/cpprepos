#include <iostream>
#include <string>
using namespace std;

// 二分查找
template <typename T>
void BinarySearch(const T& key, const T data[], int N, bool& found, int& pos)
{
    // 输入：key -待查值；data - 有序数据集(从小到大排列)；start - 查找开始位置；end - 查找结束位置
    // 输出：found - 标记key是否找到；pos - 所找到的位置
    found =false;
    pos = N;
    int low = 0;
    int high = N-1;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        if(key < data[mid])
            high = mid - 1;
        else if(data[mid] < key)
            low = mid + 1;
        else
        {
            pos = mid;
            found = true;
            break;
        }
    }
}
// 二分查找 递归算法
template <typename T>
void BinarySearch(const T& key, const T data[], int start, int end, bool& found, int& pos)
{
    // 输入：key -待查值；data - 有序数据集(从小到大排列)；start - 查找开始位置；end - 查找结束位置
    // 输出：found - 标记key是否找到；pos - 所找到的位置
    found =false;
    int low = start;
    int high = end;
    if(low <= high)
    {
        int mid = low + (high - low) / 2;
        if(key < data[mid]){
            high = mid - 1;
            BinarySearch(key, data, low, high, found, pos);
        }
        else if(data[mid] < key){
            low = mid + 1;
            BinarySearch(key, data, low, high, found, pos);
        }
        else
        {
            pos = mid;
            found = true;
        }
    }else{
        pos = -1;
    }
}
// 选择排序
template <typename T>
void SelectionSort(T data[], int& n)
{
    int i, j, k, t;
    for (i = 0; i < n-1; ++i)
    {
        k = i;
        for (j = i+1; j < n-1; ++j)
        {
            if(data[k] > data[j]){
                t = data[k];
                data[k] = data[j];
                data[j] = t;
            }
        }
    }
}
template <typename T>
void BubbleSort(T data[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        for (int j = i; j > 0; --j)
        {
            if(data[j] < data[j-1]){
                T t = data[j-1];
                data[j-1] = data[j];
                data[j] = t;
            }
        }
    }
}
// 快速排序
template <typename T>
void QuickSort(T data[], int low, int high)
{
    int privotloc;
    if(low < high){
        privotloc = Partition(data, low, high);
        QuickSort(data, low, privotloc-1);
        QuickSort(data, privotloc+1, high);
    }
}
template <typename T>
int Partition(T data[], int low, int high)
{
    T key = data[low];
    while(low < high)
    {
        while(low < high && data[high] >= key) --high;
        data[low] = data[high];
        while(low < high && data[low] <= key) ++low;
        data[high] = data[low];
    }
    data[low] = key;
    return low;
}
// 插入排序
template <typename T>
void InsertionSort(T data[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if(data[j] > data[i]){
                T t = data[j];
                data[j] = data[i];
                data[i] = t;
            }
        }
    }
}
int main()
{
    int a[10] = {45, 3, 4, 2, 5, 4, 10, 7, 6, 15}, n = 10;
    BubbleSort(a, 10);
    for(int i = 0; i < 10; i++){
        cout<< a[i] <<endl;
    }
    return 0;
}
