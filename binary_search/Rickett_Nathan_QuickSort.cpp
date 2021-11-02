#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <algorithm>
#include <unistd.h>
#include <bits/stdc++.h>

using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::stringstream;

int arraySize;
time_t start, end;


float* getNumbers(string aFile) {
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

  float* array = new float[counter];
  stringstream s(allLines);
  string num;
  arraySize = counter;
  counter = 0;
    while (s >> num) {
        array[counter] = stof(num);
        counter++;
    }
    return array;
}


//implements quick sort algorithm. Returns sorted array
/* C implementation QuickSort */
 
// A utility function to swap two elements
void swap(float* a, float* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

//used for debugging
void printArray(float* array, int size)
{
    for (int i = 0; i < size; ++i) {
      cout << array[i] << " ";
    }
}

//finds and returns the pivot point using the median of three method
float* organize(float* array, int low, int middle, int high) {
  float numbers[3] = {array[low], array[middle], array[high]};
  std::sort(numbers, numbers+3); // sorting the numbers to get the true median
  array[low] = numbers[0];
  array[middle] = numbers[1];
  array[high] = numbers[2];
  return array;
}
 
int partition (float arr[], int low, int high)
{
    int middle = high/2;
    arr = organize(arr, low, middle, high); // the pivot is now in the center
    cout << endl << "\npivot: " << arr[middle] << endl;
    swap(&arr[middle], &arr[high-1]); //swapping pivot to high-1
    printArray(arr, arraySize);
    int i = (low);  // Index of smaller element
    for (int j = low+1; j < high-1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        cout << endl << arr[j] << " <= " << arr[high-1] << endl;
        if (arr[j] <= arr[high-1])  // if j <= the pivot
        {
            i++;    // increment index of smaller element
            cout << "swapping " << arr[i] << " with " <<  arr[j];
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high-1]); //swapping i with pivot
    return (i + 1);
}

 
/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(float arr[], int low, int high) {
    time(&start);
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
        cout << "new patition index: " << pi << endl;
        printArray(arr, arraySize);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
    time(&end);
}
 

//Output the time taken for the quick sort algorithm to a text file
void makeAverageExecution(int inputSize, double timeTaken) {
  string file_name = "Rickett_Nathan_averageExecutionTime.txt";
  std::ofstream file;
  file.open(file_name, std::ios::out | std::ios::app);
  file << endl << inputSize << "         " << timeTaken;
}

void makeExecution(int inputSize, double timeTaken) {
  string file_name = "Rickett_Nathan_executionTime.txt";
  std::ofstream file;
  file.open(file_name, std::ios::out | std::ios::app);
  file << endl << inputSize << "         " << timeTaken;
}


int main(int argc, char *argv[]) {
  /**
   if (argc == 2) {
    
    float* array = getNumbers(argv[1]);
    quickSort(array, 0, arraySize-1);
    double time_taken = double(end - start);
  }
  else {
    cout << "there must be exactly one file as parameter";
  }
   * **/

  for (int i = 0 ; i < 1; ++i) {
      string file_name = "numbers/one_hundred_thousand" + std::to_string(i+1) + ".txt";
      float* array = getNumbers(file_name);
      quickSort(array, 0, arraySize-1);
      double time_taken = double(end - start);
      makeExecution(100000, time_taken);
  }
  return 0;
}
