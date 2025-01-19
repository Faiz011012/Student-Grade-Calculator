#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void developerInfo() {
    cout << "\nDeveloper's Info\n";
    cout << "1. (B132310122) [Muhamad Faiz bin Muhamad Yusoff - Programmer Source Code]\n";
    cout << "2. (B132310590) [MuhammadAfiq Haiqal Bin Razmi - Programmer Source Code]\n";
    cout << "3. (B132310008) [Ahamad Hazeeq Itqan Bin Mushni - Flowchart]\n";
    cout << "4. (B132310582) [Muhammad Faris Adam Bin Mohd Fauzi - Implementation]\n";
    cout << "5. (B132310037) [Muhamad Danial Sahir Bin Muhamad Subarjo - Pseudocode]\n\n";
}

void calculateGPA() {
    int numSubjects;
    cout << "Enter the number of subjects: ";
    cin >> numSubjects;

    string* subjects = new string[numSubjects];
    int* credits = new int[numSubjects];
    float* scores = new float[numSubjects];
    string* grades = new string[numSubjects];
    float* points = new float[numSubjects];

    for (int i = 0; i < numSubjects; i++) {
        cin.ignore();
        cout << "\nEnter details for subject " << (i + 1) << ":" << endl;
        cout << "Name of Subject: ";
        getline(cin, subjects[i]);
        do {
            cout << "Credit Hours (1-4): ";
            cin >> credits[i];
            if (credits[i] < 1 || credits[i] > 4)
                cout << "Invalid credit hours! Enter between 1-4." << endl;
        } while (credits[i] < 1 || credits[i] > 4);
        do {
            cout << "Total Score (0-100): ";
            cin >> scores[i];
            if (scores[i] < 0 || scores[i] > 100)
                cout << "Invalid score! Please enter between 0-100." << endl;
        } while (scores[i] < 0 || scores[i] > 100);
    }

    for (int i = 0; i < numSubjects; i++) {
        if (scores[i] >= 80) {
            grades[i] = "A";
            points[i] = 4.0;
        } else if (scores[i] >= 75) {
            grades[i] = "A-";
            points[i] = 3.7;
        } else if (scores[i] >= 70) {
            grades[i] = "B+";
            points[i] = 3.3;
        } else if (scores[i] >= 65) {
            grades[i] = "B";
            points[i] = 3.0;
        } else if (scores[i] >= 60) {
            grades[i] = "B-";
            points[i] = 2.7;
        } else if (scores[i] >= 55) {
            grades[i] = "C+";
            points[i] = 2.3;
        } else if (scores[i] >= 50) {
            grades[i] = "C";
            points[i] = 2.0;
        } else if (scores[i] >= 47) {
            grades[i] = "C-";
            points[i] = 1.7;
        } else if (scores[i] >= 44) {
            grades[i] = "D+";
            points[i] = 1.3;
        } else if (scores[i] >= 40) {
            grades[i] = "D";
            points[i] = 1.0;
        } else {
            grades[i] = "E";
            points[i] = 0.0;
        }
    }

    float totalQualityPoints = 0;
    int totalCredits = 0;
    for (int i = 0; i < numSubjects; i++) {
        totalQualityPoints += points[i] * credits[i];
        totalCredits += credits[i];
    }
    float gpa = totalQualityPoints / totalCredits;

    cout << "\n+------+--------------------+----------+----------+--------+--------+" << endl;
    cout << "| INDEX| SUBJECT            |   CREDIT |    SCORE | GRADE  | POINT  |" << endl;
    cout << "+------+--------------------+----------+----------+--------+--------+" << endl;
    for (int i = 0; i < numSubjects; i++) {
        cout << "| " << setw(4) << (i + 1)
             << " | " << setw(18) << left << subjects[i]
             << " | " << setw(8) << right << credits[i]
             << " | " << setw(8) << right << scores[i]
             << " | " << setw(6) << left << grades[i]
             << " | " << setw(6) << fixed << setprecision(2) << points[i]
             << " |" << endl;
    }
    cout << "+------+--------------------+----------+----------+--------+--------+" << endl;
    cout << "Total Credit Hours: " << totalCredits << endl;
    cout << "GPA : " << fixed << setprecision(2) << gpa << endl;
    cout << "=========================================================" << endl;

}

bool askToContinue() {
    char cont;
    cout << "Do you want to continue? (Y/N): ";
    cin >> cont;
    return (cont == 'Y' || cont == 'y');
}

int main() {
    int choice;
    do {
        cout << "Student Grade Calculator\n";
        cout << "MENU \n1. Developer's Info \n2. Grade Calculation \n3. Exit\n\nEnter your choice: ";
        cin >> choice;

        if (choice <= 0 || choice > 3) {
            cout << "Invalid input. Please re-enter.\n" << endl;
            continue;
        }

        if (choice == 1) {
            developerInfo();
        } else if (choice == 2) {
            calculateGPA();
        }

        if (choice != 3 && !askToContinue()) {
            break;
        }

    } while (choice != 3);

    cout << "Goodbye!\n";
    return 0;
}

