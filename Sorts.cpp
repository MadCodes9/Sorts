#include <iostream>
#include <vector>
#include "Sorts.h"
using namespace std;

void Sorts::insertionSort(vector<int>& S) {
    int size = S.size();
    int elem;
    int prev;

    for (int i = 1; i < size; i++) {
        elem = S[i];
        prev = i - 1;

        while (prev >= 0 && S[prev] > elem) {
            S[prev + 1] = S[prev];  //swap curr elem with previous elem
            prev = prev - 1;
        }
        S[prev + 1] = elem; //swap previous elem with curr elem
    }
}
void Sorts::mergeSort(vector<int>& S) {
    int size = S.size();
    int mid = size / 2; //cut vector in half
    vector<int> S1;
    vector<int> S2;

    if (size <= 1) return;  //base case

    for (int i = 0; i < mid; i++) { //first half of the vector
        S1.push_back(S[i]);
    }
    for (int j = 0; j < (size - mid); j++) {    //second half of the vector
        S2.push_back(S[mid + j]);
    }

    mergeSort(S1);  //recursively calls ms to create tree
    mergeSort(S2);
    merge(S, S1, S2);   //sort S1 and S2 and merge into S  
}
void Sorts::merge(vector<int>& S, vector<int>& S1, vector<int>& S2) {
    int i = 0;
    int j = 0;
    int k = 0;  //counter for original vector

    int n1 = S1.size(); //size of halfs of vector S
    int n2 = S2.size();

    while (i < n1 && j < n2) {  //compares each index of S1 and S2
        if (S1[i] < S2[j]) {    //S1 is less than S2 insert S1 in back of S
            S[k] = S1[i];
            i++;
        }
        else {  //S1 is greater than S2 insert S2 in back of S
            S[k] = S2[j];
            j++;
        }
        k++;    //increment index of S
    }

    while (i < n1) {    //S1 has elements left over 
        S[k] = S1[i];   //insert rest of elements in back of S
        i++;
        k++;
    }
    while (j < n2) {    //S2 has elements left over
        S[k] = S2[j];   //insert rest of elements in back of S
        j++;
        k++;
    }
}
void Sorts::quickSort(vector<int>& V) {
    if (V.size() <= 1)
        return;	// vector size 1 or less cant be sort
    quickSortStep(V, 0, V.size() - 1);
}
void Sorts::quickSortStep(vector<int>& V, int a, int b) {
    if (a >= b)
        return;	// if lower bound pass upper bound, terminate the function
    int pivot = V.at(b); // pivot is last elem
    int l = a;	// left edge = first elem
    int r = b - 1; // right edge = next to last elem
    while (l <= r) // as long as l not pass or equals r
    {
        while (l <= r && !(pivot < V.at(l))) // l to right till larger
            l++;
        while (r >= l && !(V.at(r) < pivot)) // r to left till smaller
            r--;
        if (l < r)
        {
            int temp = V.at(r);
            V.at(r) = V.at(l);
            V.at(l) = temp;
        } // swap l and r if l in front of r
    }
    int temp = V.at(l);
    V.at(l) = V.at(b);
    V.at(b) = temp; // switch pivot to E
    quickSortStep(V, a, l - 1); // repeat on elem before E
    quickSortStep(V, l + 1, b); // repeat on elem after E
}
void Sorts::bubbleSort(vector<int>& S) {
    int n = S.size();
    int temp;
    //indices i & j are used to tranverse and compare the sequence
    for (int i = 0; i < n; i++) {  //row
        for (int j = 1; j < n - i; j++) {   //column
            if (S.at(j - 1) > S.at(j)) {
                temp = S.at(j - 1);
                S.at(j - 1) = S.at(j);
                S.at(j) = temp;
            }
        }
    }
}
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
void Sorts::bucketSort(vector<int>& S) {
    vector<int> B;
    long long max = S.at(0);
    int i = 0;
    int j = 0;

    for (int i = 1; i < S.size(); i++) {
        if (S.at(i) > max) {    //find max element in S to create buckets
            max = S.at(i);
        }
    }

    for (int i = 0; i <= max; i++) {     //create empty bucket
        B.push_back(0);
    }
    //start
    for (int i = 0; i < S.size(); i++) {    //set element from S equal to bucket index of element
        B.at(S.at(i))++;    
    }
    //end
    for (int i = 0; i <= max; i++) {
        for (int j = 0; j < B.at(i); j++) {
           // cout << i;
        }
       /* while (B.at(i) == 0 && i < max) {   //skip over bucket index if element is zero
            i++;
        }
        S.at(j) = B.at(i);  //set the sequence to now ordered bucket
        j++;*/   
    }
}
void Sorts::print(vector<int>& S) {
    int size = S.size();
    for (int i = 0; i < size; i++) {
        cout << S[i] << " ";
    }
    cout << endl;
}