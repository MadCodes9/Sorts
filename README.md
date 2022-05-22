# Sorts

## General Information 
 This project, includes insertion sort, merge sort, quick sort, bubble sort, 
* randomized quick sort, and bucket sort. The first part of the project is to compare the 
* run times of the three new sorting algorithms against the previous three. Using array 
* sizes of 500, 1000, and 2000, there will be three types of arrays: an array in ascending, 
* descending, and randomly populated order. The second part of this project, uses an array 
* that is randomly populated compares the efficency of insertion sort, merge sort, and quick 
* sort. You are to adjust the size of the array that is being sorted until the time it takes
* using each algorithm is comparatively the same.   
**Depth First Search Function**
```C++
void Graph::DFS(Graph const& graph, int v, vector<bool>& discovered) {
   int cheese = getCheese();
   discovered[v] = true;   // mark the current node as discovered
   
   if (foundCheese != true) {
       cout << v << "-> ";   // print the current node
       for (int u : graph.adjList[v]) { // do for every edge v > u
           if (!discovered[u]) {   // if u is not yet discovered
               countDFS++;
               if (u == cheese) {
                   countDFS++;
                   foundCheese = true;  //function is finished
                   cout << u;
                   cout << "\n\tNumber of vertices visitied by mouse: " << countDFS << endl;
               }
               else {
                   DFS(graph, u, discovered);
               } 
           }  
       }
   }
}
```


## Technologies
Project is created with 
* IDE: Microsoft Visual Studio 2019
* Version: 16.11.10
* Language: C++20
## Setup
To run this project use Microsoft Visual Studio or an IDE that supports C++20 and download the files.
The Cheese1.txt and Cheese2.txt represent two different mazes. These files should be located in the Debug Folder and can be changed to different values representing vertices of the graph.

![Sample Output](https://github.com/MadCodes9/MazeRun/blob/main/Output.pdf)
## Status 
This is a project created by @MadCodes9 :grinning:

Source: *Data Structures and Algorithms in C++ 2nd Edition*
