#include <iostream>

using namespace std;

int main() {

  // //Data Structure & Algorithm - Pointer and Addresses Reviewer

  // //Pointers - Special feature and special type of variable in C++ 
  // //used to point at valid data address/memory address 

  // //ANCHOR: how to declare a pointer variable?
  // int *pointer; //NOTE: works fine
  // int * pointer; //NOTE: works fine
  // int* pointer; //NOTE: works fine

  // //NOTE: a pointer variable is only used to point at 1 valid memory address

  // //ANCHOR: how to get the address of a normal variable?
  // //NOTE: first declare a pointer.
  // //NOTE: second assign a VALUE in your pointer with `&` sign at the beginning of the variable name (in the pointer variable)

  // //REVIEW: example
  // int whats_my_address = 15; //normal variable with value = 15

  // //REVIEW: pointer variable pointing to address of `whats_my_address`
  // int *get_address = &whats_my_address; 


  // int var = 69; //int variable named `var` with value 69

  // //best practice to declare a pointer variable is to begin the variable name with `p_` 
  // //and end it with what variable name it should be pointing at

  // //TODO: ex. int *p_var; <- an int pointer named `p_var` where `p_` means pointer-to/point-to and `var` in the end as `p_var` means a pointer variable pointing to var

  // int *p_var = nullptr; //NOTE: assigning your pointer to `nullptr` is the proper way of declaring a pointer

  // p_var = &var; //REVIEW: since we named our pointer variable with `p_` in the beginning and with `var` in the end (p_var)
  // // we should know that this pointer variable work is only to point at variable named `var`

  int var = 143;
  int *p_var = nullptr;

  cout << "\nNormal Variable named `var` with value `143`\nOutput: " << var << "\n";
  cout << "\nPointer Variable named `p_var` with value `nullptr`\nOutput: " << p_var << "\n";

  p_var = &var;

  cout << "\nPointer Variable named `p_var` pointing to address of `var`\nOutput: " << p_var << "\n";
  cout << "\nPointer Variable named `p_var` pointing to address of `var` value\nOutput: " << *p_var << "\n";

  cout << "\nChanging the value of `var` using pointer.\nNew Output:\n";

  *p_var = 153;

  cout << "\nChanging the value of `p_var` to `153`\n";

  cout << "\nPointer Variable named `p_var` pointing to address of `var` value\nNew Output: " << *p_var << "\n";
  cout << "\nPointer Variable named `p_var` pointing to address of `var`\nNew Output: " << p_var << "\n";

  cout << "\nNormal Variable named `var` with value `153`\nNew Output: " << var << "\n";

  int var2 = 69;

  p_var = &var2;

  cout << "\nPointer Variable named `p_var` pointing to address of `var2`\nNew Output: " << p_var << "\n";

  return 0;

}