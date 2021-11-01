#include <iostream>
#include <fstream>
#include <sstream>

using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::stringstream;

//reads all floating point numbers from input.txt file
//stores floating point numbers in an array and returns it
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

  float array[counter];
  stringstream s(allLines);
  string num;
  counter = 0;
    while (s >> num) {
        array[counter] = stof(num);
        counter++;
        cout << num + " ";
    }
    return array;
}

//implements quick sort algorithm. Returns sorted array
float* quickSort(float* array) {
  int arraySize = sizeof(array)/sizeof(array[0]);
  float values[3];
  values[0] = array[0];
  values[1] = array[arraySize-1];
  values[2] = array[(arraySize-1)/2];
  std::sort(values, values+3);
  float pivot = values[1];
  return array;
}

//swaps two elements within an array and returns the new array
float* swap(float* oldArray, int positionX, int positionY) {
  float* newArray;
  delete(oldArray);
  return newArray;
}

//partititions the array into a left side and returns it
void partitionLeft(float* oldArray) {
  float* newArray;
  delete(oldArray);
  return newArray;
}

//partitions the array into a rightside and returns it
void partitionRight(float* oldArray) {
  float* newArray;
  delete(oldArray);
  return newArray;
}

//Output the contents of the quicksort to a file called "output.txt"
void WriteToFile(float* array) {

}

int main(int argc, char *argv[]) {
  float* array;
  if (argc == 2) {
    array = getNumbers(argv[1]);
    array = quickSort(array);
    WriteToFile(array);
  }
  else {
    cout << "there must be exactly one file as parameter";
  }
  return 0;
}