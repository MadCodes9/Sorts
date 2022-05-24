# Sorts
Implements six sorting algorithms; insertion sort, merge sort, quick sort, bubble sort, 
randomized quick sort, and bucket sort and compares the running times in ascending, 
descending, and randomly populated order

## General Information 
This project, includes insertion sort, merge sort, quick sort, bubble sort, 
randomized quick sort, and bucket sort. The first part of the project is to compare the 
run times of the three new sorting algorithms against the previous three. Using array 
sizes of 500, 1000, and 2000, there will be three types of arrays: an array in ascending, 
descending, and randomly populated order. The second part of this project, uses an array 
that is randomly populated compares the efficency of insertion sort, merge sort, and quick 
sort. You are to adjust the size of the array that is being sorted until the time it takes
using each algorithm is comparatively the same.   

**Random Pivot Quick Sort Function**
```C++
void Sorts::randomizedQuickSort(vector<int>& V) {
    if (V.size() <= 1)
        return;
    randomizedQuickSortStep(V, 0, V.size() - 1);

}
void Sorts::randomizedQuickSortStep(vector<int>& V, int a, int b) {
    if (a >= b)
        return;
    srand(time(NULL));
    int n = a + (rand() % (b - a)); //random number between a and b
    int pivot = V.at(n);    //to randomnize pivot 
    int tmp = V.at(b);  //pivot stays at same random position, but points to last element 
    V.at(b) = V.at(n);
    V.at(n) = tmp;

    int l;
    int r;
    l = a;
    r = b - 1;
    while (l <= r)
    {
        while (l <= r && (V.at(l) <= pivot))
            l++;
        while (r >= l && (V.at(r) >= pivot))
            r--;
        if (l < r)
        {
            int temp = V.at(r);
            V.at(r) = V.at(l);
            V.at(l) = temp;
        }
    }
    int temp = V.at(l);
    V.at(l) = V.at(b);
    V.at(b) = temp; // switch pivot to E
    randomizedQuickSortStep(V, a, l - 1);
    randomizedQuickSortStep(V, l + 1, b);

}
```


## Technologies
Project is created with 
* IDE: Microsoft Visual Studio 2019
* Version: 16.11.10
* Language: C++20
* 
## Setup
To run this project use Microsoft Visual Studio or an IDE that supports C++20 and download the .cpp and .h files into your IDE.
Asks user input to enter the size of the vector to be sorted with six different algorithms.

**Sample Output**

![Image](https://github.com/MadCodes9/Sorts/blob/main/500p1.png)
![Image](https://github.com/MadCodes9/Sorts/blob/main/500p2.png)

## Status 
This is a project created by @MadCodes9 :grinning:

Source: *Data Structures and Algorithms in C++ 2nd Edition*
