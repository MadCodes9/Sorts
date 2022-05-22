#pragma once
using namespace std;
class Sorts {
public:
    void insertionSort(vector<int>& S);
    void mergeSort(vector<int>& S);
    void quickSort(vector<int>& V);
    void bubbleSort(vector<int>& S);
    void randomizedQuickSort(vector<int>& V);
    void bucketSort(vector<int>& S);
    void print(vector<int>& S);
private:
    void merge(vector<int>& S, vector<int>& S1, vector<int>& S2);
    void quickSortStep(vector<int>& V, int a, int b);
    void randomizedQuickSortStep(vector<int>& V, int a, int b);
};

