#include <iostream>

using namespace std;

int main() {

  int size = 0;

  cout << "\nEnter your desired Size for our Array: ";
  cin >> size;

  int *array = new(nothrow) int[size] {};

  if(array == nullptr) {
    cerr << "\nInvalid Format! Failed to create an array.\n";
    return 1;
  }

  for(int i = 0; i != size; ++i) {
    cout << "\nEnter Value for Array[" << i << "]: ";
    cin >> array[i];
  }

  for(int i = 0; i != size; ++i) {
    cout << "\nValue in Array[" << i << "]: " << array[i];
  }

  delete[] array; 
  array = nullptr;

  return 0;

}