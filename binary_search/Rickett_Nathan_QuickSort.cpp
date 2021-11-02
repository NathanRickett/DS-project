//COPYRIGHT NATHAN RICKETT 2021
//CSCE 350 SECTION 002

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

//reads the numbers in a file and puts them into a float pointer array
//returns the float pointer array
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
  //getting the size of the array
  stringstream ss(allLines);
  string word;
  int counter = 0;
    while (ss >> word) {
        counter++;
    }
  //creating the float pointer array
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
 
// function for swapping to values within a pointer array
void swap(float* num1, float* num2)
{
    float temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}


/**
 * finds the pivot using median of three method
   pivot is then placed into the center
   lowest values is placed at the beginning
   highest value is placed at the end
   returns the new array
 * **/

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
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
    float pivot = arr[high]; // pivot 
    for (int k = low; k <= high - 1; k++) { 
        if (arr[k] < pivot) { // if current position in array is smaller than the pivot
            i++;
            swap(&arr[i], &arr[k]); // swap i with k
        } 
    } 
    swap(&arr[i + 1], &arr[high]); // after the loop, swap pivot with i
    return (i + 1); // return i + 1 as the new pivot index
}

//quicksorts a given array using the middle element as the pivot
//the array passed in should already have the median of three value in the center
void quickSort(float* array, int low, int high)
{
  if (low < high) {
        int pIDX = partition(array, low, high); // a pivot index used received from calling partition function
        quickSort(array, low, pIDX - 1); // sort the left side of the pivot
        quickSort(array, pIDX + 1, high); // sort the right side of the pivot
    } 
}

//writes the sorted array and time for execution to the specified file
void writeToFile(float* array, const char* fileName, double timeTaken) {
  std::ofstream file;
  file.open(fileName, std::ios::out | std::ios::app);
  for (int i = 0; i < arraySize; ++i) {
    file << array[i] << " ";
  }
  file << endl << "Time: " << timeTaken << " milliseconds" << endl;
  file.close();
}

int main(int argc, char *argv[]) {
    if (argc == 3) {
    const char* INPUT_FILE = argv[1];
    const char* OUTPUT_FILE = argv[2];
    float* array = getNumbers(INPUT_FILE); // retrieving the input numbers from the input file
    array = median_of_three(array, 0, (arraySize-1)/2, (arraySize-1)); // setting the pivot as the median of three
    auto start = high_resolution_clock::now(); //starting the timer
    quickSort(array, 0, arraySize-1); // implementing quick sort algorithm
    auto stop = high_resolution_clock::now(); //stopping the timer
    auto duration = duration_cast<microseconds>(stop - start); // setting the execution time variable
    writeToFile(array, OUTPUT_FILE, duration.count()); // writing to file
  }
  else {
    cout << "there must be exactly two files as parameter";
  }
  return 0;
}