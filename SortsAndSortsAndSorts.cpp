/*
* Program: SortsAndSortsAndSorts.cpp
* Author: Ceiara Madrigal
* Course: CSCI 230
* Date: 5/11/21
* Description: This project, includes insertion sort, merge sort, quick sort, bubble sort, 
* randomized quick sort, and bucket sort. The first part of the project is to compare the 
* run times of the three new sorting algorithms against the previous three. Using array 
* sizes of 500, 1000, and 2000, there will be three types of arrays: an array in ascending, 
* descending, and randomly populated order. The second part of this project, uses an array 
* that is randomly populated compares the efficency of insertion sort, merge sort, and quick 
* sort. You are to adjust the size of the array that is being sorted until the time it takes
* using each algorithm is comparatively the same.   
*
* I certify that the following code is my own work.
*
* Exception(s): N/A
*/
#include <iostream>
#include<vector>
#include<iomanip>
#include<chrono>
#include <ctime>
#include"Sorts.h"
using namespace std;

void testSorts(int n, int index, vector<int> S) {
    Sorts sortsObj;
    chrono::time_point<chrono::system_clock> start, end;	

    switch (index)
    {
    case 0:
        start = chrono::system_clock::now();
        sortsObj.insertionSort(S);
        end = chrono::system_clock::now();
        cout << "\n\t\tInsertion Sort";
        break;
    case 1:
        start = chrono::system_clock::now();
        sortsObj.mergeSort(S);
        end = chrono::system_clock::now();
        cout << "\n\t\tMerge Sort";
        break;
    case 2:
        start = chrono::system_clock::now();
        sortsObj.quickSort(S);
        end = chrono::system_clock::now();
        cout << "\n\t\tQuick Sort";
        break;
    case 3:
        start = chrono::system_clock::now();
        sortsObj.bubbleSort(S);
        end = chrono::system_clock::now();
        cout << "\n\t\tBubble Sort";
        break;
    case 4:
        start = chrono::system_clock::now();
        sortsObj.randomizedQuickSort(S);
        end = chrono::system_clock::now();
        cout << "\n\t\tRandomized Quick Sort";
        break;
    case 5:
        start = chrono::system_clock::now();
        sortsObj.bucketSort(S);
        end = chrono::system_clock::now();
        cout << "\n\t\tBucket Sort";
        break;
    default:
        cout << "Error has occured";
        break;
    }

    chrono::duration<double> elapsed_seconds = end - start; //calculate CPU time 
    time_t end_time = chrono::system_clock::to_time_t(end);
    cout << "\n\t\tSorting...";   
    cout << "\n\t\tElapsed time: " << elapsed_seconds.count() << "s with " <<  n  << " entries\n";
    S.clear();  //clear the vector
}
int main()
{   vector<int> S1;
    vector<int> S2;
    vector<int> S3;
    int randomNum;
    int n;
    char choice;
    bool stay = true;

    cout << setw(40) << "========================" << endl;
    cout << setw(40) << "= Sorts Implementation =" << endl;
    cout << setw(40) << "========================" << endl;

    while (stay == true) {  //user can choose to continue or end program
        cout << "\n\t\tEnter the size of the vector-> ";
        cin >> n;
        cout << endl;
        for (int i = 0; i < n; i++) {   //ascending-order
            S1.push_back(i);
        }
        for (int i = n; i > 0; i--) {   //descending-order
            S2.push_back(i);
        }
        srand(0);   //randomnize-order
        for (int i = 0; i < n; i++) {
            randomNum = rand() % 20000 + 1;
            S3.push_back(randomNum);
        }
        for (int i = 0; i < 6; i++) {
            /*cout << "\t\t(ascending-order)";
            testSorts(n, i, S1);
            cout << "\t\t(descending-order)";
            testSorts(n, i, S2);*/
            cout << "\t\t(randomnize-order)";
            testSorts(n, i, S3);
            cout << endl;
        }
        cout << "\t\tWould you like to try again?(Y/N): ";
        cin >> choice;
        if (choice == 'Y' || choice == 'y') {
            stay = true;
        }
        else {
            stay = false;
        }
    }
    cout << "\n\t\tProgram has ended. Goodbye!\n";
	cin.get();
	return 0;
}

