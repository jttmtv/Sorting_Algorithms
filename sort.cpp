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

int main(int argc, const char *argv[])
{
    std::vector<int> a{15, 5, 2, 7, 12, 6, 1, 4, 3, 9, 8, 10};
    // insertion_sort(a);
    // shell_sort(a);
    bubble_sort(a);
    print_arrary(a);
    return 0;
}