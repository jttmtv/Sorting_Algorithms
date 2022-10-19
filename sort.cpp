#include <iostream>
#include <vector>
#include <algorithm>

void print_arrary(std::vector<int> arr)
{
    for (int elem : arr)
        std::cout << elem << " ";
}

void insertion_sort(std::vector<int> &arr)
{
    for (int i = 1; i < arr.size(); ++i)
        for (int j = i; j >= 1 && arr[j] < arr[j - 1]; --j)
            std::swap(arr[j], arr[j - 1]);
}

void shell_sort(std::vector<int> &arr)
{
    for (int gap = arr.size() / 2; gap > 0; gap /= 2)
        for (int i = gap; i < arr.size(); ++i)
            for (int j = i - gap; j >= 0 && arr[j] > arr[j + gap]; j -= gap)
                std::swap(arr[j], arr[j + gap]);
}

int main()
{
    std::vector<int> a{15, 5, 2, 7, 12, 6, 1, 4, 3, 9, 8, 10};
    // insertion_sort(a);
    shell_sort(a);
    print_arrary(a);
    return 0;
}