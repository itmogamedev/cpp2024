#pragma once
#include<vector>

void Merge(std::vector<double>& Arr, int left, int mid, int right)
{
    std::vector<double> L(mid - left + 1, 0);
    std::vector<double> R(right - mid, 0);

    int i = 0;
    int j = 0;

    for (; i < L.size(); ++i)
    {
        L[i] = Arr[left + i];
    }
    i = 0;

    for (; j < R.size(); ++j)
    {
        R[j] = Arr[mid + 1 + j];
    }
    j = 0;

    R.push_back(INT_MAX);
    L.push_back(INT_MAX);

    while (i + j < right - left + 1)
    {
        if (L[i] <= R[j])
        {
            Arr[left + i + j] = L[i];
            ++i;
        }
        else
        {
            Arr[left + i + j] = R[j];
            j++;
        }
    }
}

void MergeSort(std::vector<double>& Arr, int left, int right)
{
    if (left < right)
    {
        int mid = ((right + left) - (right + left) % 2) / 2;
        MergeSort(Arr, left, mid);
        MergeSort(Arr, mid + 1, right);
        Merge(Arr, left, mid, right);
    }
}