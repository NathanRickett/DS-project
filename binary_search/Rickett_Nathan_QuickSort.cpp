#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>

using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::stringstream;

//reads all floating point numbers from input.txt file
//stores floating point numbers in an array and returns it
float * getNumbers(string aFile) {
  string line;
  string allLines;
  ifstream file (aFile);
  if (file.is_open())
  {
    while ( getline (file,line) ) {
      allLines += line;
    }
    file.close();
  }
  else cout << "Unable to open file"; 

  stringstream ss(allLines);
  string word;
  int counter = 0;
    while (ss >> word) {
        counter++;
    }

  float array[counter];
  stringstream s(allLines);
  string num;
  counter = 0;
    while (s >> num) {
        array[counter] = stof(num);
        counter++;
    }
    cout << array[4];
    return array;
}

//implements quick sort algorithm. Returns sorted array
/* C implementation QuickSort */
 
// A utility function to swap two elements
void swap(float* a, float* b)
{
   cout << "swapping";
    int t = *a;
    *a = *b;
    *b = t;
}
 
/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (float arr[], int low, int high)
{
  cout << "partition\n";
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(float arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
 


//Output the contents of the quicksort to a file called "output.txt"
void WriteToFile(float* array) {

}

/* Function to print an array */
void printArray(float* arr, int size)
{
    
}


int main(int argc, char *argv[]) {
  float* array;
  if (argc == 2) {
    array = getNumbers(argv[1]);
    //int n = sizeof(array)/sizeof(array[0]);
    //printArray(array, n);
    //printArray(array, n);
    //quickSort(array, 0, n-1);
    //printf("Sorted array: \n");
    //WriteToFile(array);
  }
  else {
    cout << "there must be exactly one file as parameter";
  }
  return 0;
}