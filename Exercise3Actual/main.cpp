#include <iostream>

using namespace std;

#define SIZE 3

struct info {
    string s_name;
    float s_grade;
} student[SIZE];

int main()
{

    cout << "Enter information of students:\n";

    for(int i = 0; i < SIZE; i++) 
    {
        cout << "\nFor loop number " << i+1;
        cout << "\nEnter name: ";
        cin >> student[i].s_name;

        cout << "Enter grade: ";
        cin >> student[i].s_grade;
    }

    cout << "Displaying information of students:\n";

    for(int i = 0; i < SIZE; i++) 
    {
        cout << "\nInformation for loop number " << i+1;
        cout << "\nName: " << student[i].s_name;

        cout << "\nGrade: " << student[i].s_grade;
    }

    return 0;

}