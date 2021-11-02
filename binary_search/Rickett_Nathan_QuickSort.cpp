#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <algorithm>
#include <unistd.h>
#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

int arraySize;
time_t start, end;
typedef struct numbers Struct;


//reads the numbers in a file and puts them into a float pointer array
//returns the float pointed array
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
 
// A utility function to swap two elements
void swap(float* a, float* b)
{
    float t = *a;
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


//finds the pivot using median of three method
//pivot is then placed into the center
//lowest values is placed at the beginning
//highest value is placed at the end
//returns the new array
 float* median_of_three(float* array, int low, int middle, int high) {
  float numbers[3] = {array[low], array[middle], array[high]};
  sort(numbers, numbers+3);
  array[low] = numbers[0];
  array[middle] = numbers[1];
  array[high] = numbers[2];
  return array;
}

//partitions and sorts the array passed in
//returns a new pivot index for quicksort function to process recursively
int partition (float* arr, int low, int high) 
{ 
    float pivot = arr[high]; // pivot 
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
  
    for (int j = low; j <= high - 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (arr[j] < pivot) 
        { 
            i++; // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
}

//quicksorts a given array using the middle element as the pivot
//the array passed in should already have the median of three value in the center
void quickSort(float* array, int low, int high)
{
  if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
        at right place */
        int pi = partition(array, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(array, low, pi - 1); 
        quickSort(array, pi + 1, high); 
    } 
}


//Output the time taken for the quick sort algorithm to a text file
void makeAverageExecution() {
  
}

void makeExecution(int inputSize, double timeTaken) {
  string file_name = "Rickett_Nathan_executionTime.txt";
  std::ofstream file;
  file.open(file_name, std::ios::out | std::ios::app);
  file << endl << inputSize << "         " << timeTaken;
}

//THIS FUNCTION IS FOR RECORDING EXECUTION TIMES AND IS NOT NORMALLY USED IN THE PROGRAM EXCEPT FOR TESTING!!!!
void recordTimes() {
  for (int i = 0 ; i < 100; ++i) {
      string file_name = "numbers/ten" + std::to_string(i+1) + ".txt";
      float* array = getNumbers(file_name);
      auto start = high_resolution_clock::now(); //starting the timer
      quickSort(array, 0, arraySize-1);
      auto stop = high_resolution_clock::now(); //stopping the timer
      auto duration = duration_cast<microseconds>(stop - start); // setting the execution time variable
      makeExecution(10, duration.count()); // writing to file
  }
  for (int i = 0 ; i < 100; ++i) {
      string file_name = "numbers/one_hundred" + std::to_string(i+1) + ".txt";
      float* array = getNumbers(file_name);
      auto start = high_resolution_clock::now(); //starting the timer
      quickSort(array, 0, arraySize-1);
      auto stop = high_resolution_clock::now(); //stopping the timer
      auto duration = duration_cast<microseconds>(stop - start); // setting the execution time variable
      makeExecution(100, duration.count()); // writing to file
  }
  for (int i = 0 ; i < 100; ++i) {
      string file_name = "numbers/one_thousand" + std::to_string(i+1) + ".txt";
      float* array = getNumbers(file_name);
      auto start = high_resolution_clock::now(); //starting the timer
      quickSort(array, 0, arraySize-1);
      auto stop = high_resolution_clock::now(); //stopping the timer
      auto duration = duration_cast<microseconds>(stop - start); // setting the execution time variable
      makeExecution(1000, duration.count()); // writing to file
  }
  for (int i = 0 ; i < 100; ++i) {
      string file_name = "numbers/ten_thousand" + std::to_string(i+1) + ".txt";
      float* array = getNumbers(file_name);
      auto start = high_resolution_clock::now(); //starting the timer
      quickSort(array, 0, arraySize-1);
      auto stop = high_resolution_clock::now(); //stopping the timer
      auto duration = duration_cast<microseconds>(stop - start); // setting the execution time variable
      makeExecution(10000, duration.count()); // writing to file
  }
  for (int i = 0 ; i < 100; ++i) {
      string file_name = "numbers/one_hundred_thousand" + std::to_string(i+1) + ".txt";
      float* array = getNumbers(file_name);
      auto start = high_resolution_clock::now(); //starting the timer
      quickSort(array, 0, arraySize-1);
      auto stop = high_resolution_clock::now(); //stopping the timer
      auto duration = duration_cast<microseconds>(stop - start); // setting the execution time variable
      makeExecution(100000, duration.count()); // writing to file
  }

  makeAverageExecution();
}


int main(int argc, char *argv[]) {
    if (argc == 2) {
    
    float* array = getNumbers(argv[1]);
    array = median_of_three(array, 0, (arraySize-1)/2, (arraySize-1));

    auto start = high_resolution_clock::now(); //starting the timer
    quickSort(array, 0, arraySize-1);
    auto stop = high_resolution_clock::now(); //stopping the timer
    auto duration = duration_cast<microseconds>(stop - start); // setting the execution time variable

    
  }
  else {
    cout << "there must be exactly one file as parameter";
  }
  return 0;
}
