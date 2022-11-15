#include <iostream>
#include <iomanip>
using namespace std;

#define size 3

struct store_information
{
    char student_name[50];
    double student_grade;
    
}information[size];

int main ()

{
	
 	cout << "Enter information of student:\n\n";
 
    for (int i = 0; i < size; i++)
    {       
    	cout << "\nFor loop number "  << i + 1;
    	cout << "\nEnter name:";
    	cin >> information [i].student_name;
    	cout << "Enter grade: ";
    	cin >> information [i].student_grade;
    }
    
    cout << "\nDisplaying information of  students: \n";
    
	for (int i = 0; i < size; i++)
	{       
    	cout << "\nInformation for loop " << i + 1;
    	cout << "\nName: " << information [i].student_name;
    	cout << "\nGrade: " << information [i].student_grade;
	}
   return 0;
   
}