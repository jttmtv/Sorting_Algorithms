#include <iostream>
#include <vector>
#include <algorithm>

/*
    Print the array elements in ascending order
*/
void print_arrary(std::vector<int> &arr)
{
    for (int elem : arr)
        std::cout << elem << " ";
    std::cout << '\n';
}

/*
    Stable sorting algorithm
    Time complexity: O(n^2)
    Space complexity: O(1)
*/
void insertion_sort(std::vector<int> &arr)
{
    for (int i = 1; i < arr.size(); ++i)
        for (int j = i; j >= 1 && arr[j - 1] > arr[j]; --j)
            std::swap(arr[j - 1], arr[j]);
}

/*
    Unstable sorting algorithm
    Time complexity: O(n^2)
    Space complexity: O(1)
*/
void shell_sort(std::vector<int> &arr)
{
    for (int gap = arr.size() / 2; gap > 0; gap /= 2)
        for (int i = gap; i < arr.size(); ++i)
            for (int j = i; j >= gap && arr[j - gap] > arr[j]; j -= gap)
                std::swap(arr[j - gap], arr[j]);
}

/*
    Stable sorting algorithm
    Time complexity: O(n^2)
    Space complexity: O(1)
*/
void bubble_sort(std::vector<int> &arr)
{
    for (int i = arr.size(); i > 1; --i)
        for (int j = 1; j < i; ++j)
            if (arr[j - 1] > arr[j])
                std::swap(arr[j - 1], arr[j]);
}

/*
    Unstable sorting algorithm
    Time complexity: O(nlogn)
    Space complexity: O(1)
*/
void quick_sort(std::vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int i = low, j = high, pivot = arr[low];
        while (i < j)
        {
            while (i < j && arr[j] >= pivot)
                --j;
            arr[i] = arr[j];
            while (i < j && arr[i] <= pivot)
                ++i;
            arr[j] = arr[i];
        }
        arr[i] = pivot;
        pivot = i;
        quick_sort(arr, low, pivot - 1);
        quick_sort(arr, pivot + 1, high);
    }
}

/*
    Unstable sorting algorithm
    Time complexity: O(n^2)
    Space complexity: O(1)
*/
void selection_sort(std::vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; ++i)
    {
        int j = i;
        for (int k = i + 1; k < arr.size(); ++k)
        {
            if (arr[k] < arr[j])
                j = k;
        }
        std::swap(arr[i], arr[j]);
    }
}

int main(int argc, const char *argv[])
{
    std::vector<int> a{15, 5, 2, 7, 12, 6, 1, 4, 3, 9, 8, 10};
    // insertion_sort(a);
    // shell_sort(a);
    // bubble_sort(a);
    // quick_sort(a, 0, a.size() - 1);
    selection_sort(a);
    print_arrary(a);
    return 0;
}