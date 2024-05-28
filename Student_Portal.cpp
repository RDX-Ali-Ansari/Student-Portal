#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <unistd.h>

using namespace std;

//Creating a node structure to elevate the need of creating an array of objects for faculty, student and administrator.
struct Node {
    //Data Attributes
    string Name, Phone, City, CNIC, ID, Password, Office, Course, Code, Courses[6], Codes[6], CrHr, Type, S, Day[6], Slot[6], Attendance[6], Marks[6];
    int Fee, NumCourses;
    //Node type pointer pointing to nothing.
    Node* next;
};

class Admin {
public:
    //Data Attributes
    string Name, CNIC, City, Phone, ID, Password;

    //Creating a node type pointer.
    Node* head = NULL;

    //Administrator Methods
    void addNode(Node* newNode);
    void Admin_Data();
    void saveToFile();
};

class Student {
public:
    //Student Methods
    void Student_Data();
    void addNode(Node* newNode);
    void view_a(string id, string p);
    void view_m(string id, string p);
    void view_fee(string id, string p);

    //Creating a node type pointer.
    Node* head = NULL;
};

class Faculty {
public:
    //Student Methods
    void Faculty_Data();
    void addNode(Node* newNode);
    void Attendance(string id, string p);
    void Test_Type(string id, string p);

    //Creating a node type pointer.
    Node* head = NULL;
};

//Creating objects for the below classes.
Admin A;
Student S;
Faculty F;

//Adding an administrator node. There is no need to create multiple nodes for administrator.
void Admin::addNode(Node* newNode) {
    //New node is pointing to null.
    newNode->next = head;
    //Declaring the new node as head node.
    head = newNode;
}

void Student::addNode(Node* newNode) {
    //New node is pointing to null.
    newNode->next = head;
    //Declaring the new node as head node.
    head = newNode;
}
void Faculty::addNode(Node* newNode) {
    //New node is pointing to null.
    newNode->next = head;
    //Declaring the new node as head node.
    head = newNode;
}

void Admin::Admin_Data() {

    system("cls");
    cout << setw(90) << "======================================================\n";
    cout << setw(90) << "|WELCOME TO THE GRANDEST UNIVERSITY IN PAKISTAN PIEAS|\n";
    cout << setw(90) << "======================================================\n";
    Node* newNode = new Node;
    cout << "Enter Your Name : ";
    getline(cin, newNode->Name);
    cout << "Enter Your CNIC # : ";
    getline(cin, newNode->CNIC);
    cout << "Enter Your City : ";
    getline(cin, newNode->City);
    cout << "Enter Your Phone # : ";
    getline(cin, newNode->Phone);
    cout << "Enter Your ID and Password\n";
    cin >> newNode->ID >> newNode->Password;
    cin.ignore();
    addNode(newNode);
    cout << setw(80) << right << "--------------------------------------\n\n";
    cin.ignore();
}

void Student::Student_Data() {
    system("cls");
    cout << setw(90) << "======================================================\n";
    cout << setw(90) << "|WELCOME TO THE GRANDEST UNIVERSITY IN PAKISTAN PIEAS|\n";
    cout << setw(90) << "======================================================\n";
    cin.ignore();
    Node* newNode = new Node;
    cout << "Enter Your Name : ";
    getline(cin, newNode->Name);
    cout << "Enter Your Phone # : ";
    getline(cin, newNode->Phone);
    cout << "Enter Name OF City : ";
    getline(cin, newNode->City);
    cout << "Enter Semester Type : ";
    getline(cin, newNode->Type);
    cout << "Enter Semester # : ";
    getline(cin, newNode->S);
    cout << "How Many Courses You Want To Take : ";
    cin >> newNode->NumCourses;
    cin.ignore();

    cout << "Enter The Course Titles of the Given Courses\n";
    for (int i = 0; i  < newNode->NumCourses; ++i) {
        cout << "Course " << i + 1 << " Title: ";
        getline(cin, newNode->Courses[i]);
    }
    cout << "Enter The Course Codes of the Given Courses\n";
    for (int i = 0; i < newNode->NumCourses; i++){
        cout << "Course " << i + 1 << " Code: ";
        getline(cin, newNode->Codes[i]);
    }
    cout << "Enter Your Login ID : ";
    getline(cin, newNode->ID);
    cout << "Enter Your Password : ";
    getline(cin, newNode->Password);
    cout << "Enter What You Want.\n1. Hostel\n2. Transport\n";
    int choice;
    cin >> choice;
    if (choice == 1)
        newNode->Fee = 90000;
    else if (choice == 2)
        newNode->Fee = 75000;
    else
        newNode->Fee = 60000;
    S.addNode(newNode);
    cout << setw(80) << right << "--------------------------------------\n\n";
    cin.ignore();
}

void Student::view_a(string id, string p) {
    system("cls");
    cout << setw(90) << "==============================\n";
    cout << setw(90) << "|WELCOME TO ATTENDANCE PORTAl|\n";
    cout << setw(90) << "==============================\n";
    cin.ignore();
    string c;
    Node* current = S.head;
    while (current != NULL) {
        if (current->ID == id && current->Password == p) {
            cout << "Following Is The List Of Courses You Are Currently Enrolled.\n";
            for ( int i = 0; i < current->NumCourses; i++) {
                cout << " Course Title: " << current->Courses[i] << endl;
            }
            cout << "For Which Course Do You Want To See Attendance : ";
            getline(cin, c);
            for (int i = 0; i < current->NumCourses; ++i) {
                if (c == current->Courses[i]){
                    cout << "Student Name : " << current->Name << endl;
                    cout << "Course Name : " << current->Courses[i] << endl;
                    cout << "Course Code : " << current->Codes[i] << endl;
                    cout << "Course Credit-Hours : " << current->CrHr << endl;
                    cout << "Day  : " << current->Day[i] << endl;
                    cout << "Slot : " << current->Slot[i] << endl;
                    cout << "Attendance Status : " << current->Attendance[i] << endl;
                    cout << setw(80) << "--------------------------------------\n\n";
                    cin.ignore();
                    break;
                }
            }

            break;
        }
        current = current->next;
    }
}

void Student::view_m(string id, string p) {
    system("cls");
    cout << setw(90) << "==============================\n";
    cout << setw(90) << "   |WELCOME TO MARKS PORTAl|  \n";
    cout << setw(90) << "==============================\n";
    cin.ignore();
    string c;
    Node* current = S.head;
    while (current != NULL) {
        if (current->ID == id && current->Password == p) {
            cout<<"Following Is The List Of Courses You Are Currently Enrolled.\n";
            for ( int i = 0; i < current->NumCourses; i++) {
                cout << " Course Title: " << current->Courses[i] << endl;
            }
            cout << "For Which Course Do You Want To See Attendance : ";
            getline(cin, c);
            for (int i = 0; i < current->NumCourses; ++i) {
                if (c == current->Courses[i]){
                    cout << "Student Name: " << current->Name << endl;
                    cout << "Course Code : " << current->Codes[i] << endl;
                    cout << "Course Credit-Hours : " << current->CrHr << endl;
                    cout << "Marks Obtained  : " << current->Marks[i] << endl;
                    cout << setw(80) << "--------------------------------------\n\n";
                    cin.ignore();
                }
                break;
            }
            break;
        }
    current = current->next;
    }
}

void Student::view_fee(string id, string p) {
    system("cls");
    cout << setw(90) << "=================================\n";
    cout << setw(90) << "|WELCOME TO FEE STRUCTURE PORTAl|\n";
    cout << setw(90) << "=================================\n";
    cin.ignore();
    Node* current = S.head;
    while (current != NULL) {
        if (current->ID == id && current->Password == p) {
            cout << "Name OF The Student : " << current->Name << endl;
            cout << "City OF Student : " << current->City << endl;
            cout << "Total Fee Including (Transport/Hostel) Charges : " << current->Fee << endl;
            cout << setw(80) << right << "--------------------------------------\n\n";
            cin.ignore();
            break;
        }
        current = current->next;
    }
}

void Faculty::Faculty_Data() {
    system("cls");
    cout << setw(90) << "======================================================\n";
    cout << setw(90) << "|WELCOME TO THE GRANDEST UNIVERSITY IN PAKISTAN PIEAS|\n";
    cout << setw(90) << "======================================================\n";
    cin.ignore();
    Node* newNode = new Node;
    cout << "Enter Your Name Sir : ";
    getline(cin, newNode->Name);
    cout << "Enter Your Phone # Sir : ";
    getline(cin, newNode->Phone);
    cout << "Enter Your Office # : ";
    getline(cin, newNode->Office);
    cout << "Enter Your ID # : ";
    getline(cin, newNode->ID);
    cout << "Enter Your Password Sir : ";
    getline(cin, newNode->Password);
    cout << "Enter Assigned Course Name : ";
    getline(cin, newNode->Course);
    cout << "Enter Course Code : ";
    getline(cin, newNode->Code);
    cout << "Enter No. OF Credit-Hours : ";
    getline(cin, newNode->CrHr);
    F.addNode(newNode);
    cout << setw(80) << right << "--------------------------------------\n\n";
    cin.ignore();
}

void Faculty::Attendance(string id, string p) {
    system("cls");
    cout << setw(90) << "============================================\n";
    cout << setw(90) << "|WELCOME TO ATTENDANCE PORTAL OF University|\n";
    cout << setw(90) << "============================================\n";
    cin.ignore();
    bool found = false;
    Node* current = F.head;

    while (current != NULL) {
        if (current->ID == id && current->Password == p) {
            Node* current1 =  S.head;

            while (current1 != NULL) {
                for (int i = 0; i < current1->NumCourses; i++) {
                    if( current1->Courses[i] == current->Course){
                    found = true;
                    cout << "Student Name : " << current1->Name << endl;
                    cout << "Course Name : " << current1->Courses[i] << endl;
                    current1->Codes[i] = current->Code;
                    cout << "Course Code : " << current1->Codes[i] << endl;
                    current1->CrHr = current->CrHr;
                    cout << "Course Credit-Hours : " << current1->CrHr << endl;
                    cout << "Enter Day  : ";
                    getline(cin, current1->Day[i]);
                    cout << "Enter Slot  : ";
                    getline(cin, current1->Slot[i]);
                    cout << "Enter Attendance  : ";
                    getline(cin, current1->Attendance[i]);
                    }
                }
                current1 = current1->next;
            }
            if(!found){
            cout << "No Student Has Taken Your Course\n";
            }
            break;
        }
        current = current->next;
    }
}

void Faculty::Test_Type(string id, string p) {
    system("cls");
    cout << setw(90) << "============================================\n";
    cout << setw(90) << "|WELCOME TO ATTENDANCE PORTAL OF University|\n";
    cout << setw(90) << "============================================\n";
    cin.ignore();
    bool found = false;
    Node* current = F.head;
    while (current != NULL) {
        if (current->ID == id && current->Password == p) {
            Node* current1 =  S.head;
            while (current1 != NULL) {
                for (int i = 0; i < current1->NumCourses; i++) {
                    if( current1->Courses[i] == current->Course){
                    found = true;
                    cout << "Student Name : " << current1->Name << endl;
                    cout << "Course Name : " << current1->Courses[i] << endl;
                    cout << "Course Code : " << current1->Codes[i] << endl;
                    cout << "Course Credit-Hours : " << current1->CrHr << endl;
                    cout << "Enter Marks : ";
                    getline(cin, current1->Marks[i]);
                    }
                }
                current1 = current1->next;
            }
            if(!found){
            cout << "No Student Has Taken Your Course\n";
            }
        }
        current = current->next;
    }
}

void Entry() {
    ifstream file("Admin.txt");
    if (!file.is_open() || file.peek() == ifstream::traits_type::eof()) {
        A.Admin_Data();
    }
    else {
        Node* newNode = new Node;
        while (getline(file, newNode->Name)) {
            getline(file, newNode->CNIC);
            getline(file, newNode->City);
            getline(file, newNode->Phone);
            getline(file, newNode->ID);
            getline(file, newNode->Password);
            A.addNode(newNode);
            newNode = new Node;
        }
    }
    file.close();

    ifstream data("Faculty.txt");
    Node* newNode = new Node;
    while (getline(data, newNode->Name)) {
        getline(data, newNode->Phone);
        getline(data, newNode->Office);
        getline(data, newNode->ID);
        getline(data, newNode->Password);
        getline(data, newNode->Course);
        getline(data, newNode->Code);
        getline(data, newNode->CrHr);
        F.addNode(newNode);
        newNode = new Node;
    }
    data.close();

    ifstream person("Student.txt");
    while (getline(person, newNode->Name)) {
        getline(person, newNode->Phone);
        getline(person, newNode->City);
        getline(person, newNode->Type);
        getline(person, newNode->S);
        string numCourses;
        getline(person, numCourses);
        stringstream(numCourses) >> newNode->NumCourses;
        getline(person, newNode->ID);
        getline(person, newNode->Password);
        for (int i = 0; i < newNode->NumCourses; ++i) {
            getline(person, newNode->Courses[i]);
            getline(person, newNode->Codes[i]);
            getline(person, newNode->CrHr);
            getline(person, newNode->Day[i]);
            getline(person, newNode->Slot[i]);
            getline(person, newNode->Attendance[i]);
            getline(person, newNode->Marks[i]);
        }
        S.addNode(newNode);
        newNode = new Node;
    }
    person.close();
}

void Exit() {
    ofstream file("Admin.txt", ios::out | ios::trunc);
    Node* current = A.head;
    while (current != NULL) {
        file << current->Name << endl;
        file << current->CNIC << endl;
        file << current->City << endl;
        file << current->Phone << endl;
        file << current->ID << endl;
        file << current->Password << endl;
        current = current->next;
    }
    file.close();

    ofstream data("Faculty.txt", ios::out | ios::trunc);
    current = F.head;
    while (current != NULL) {
        if (!current->Office.empty()) {
            data << current->Name << endl;
            data << current->Phone << endl;
            data << current->Office << endl;
            data << current->ID << endl;
            data << current->Password << endl;
            data << current->Course << endl;
            data << current->Code << endl;
            data << current->CrHr << endl;
        }
        current = current->next;
    }
    data.close();

    ofstream person("Student.txt", ios::out | ios::trunc);
    current = S.head;
    while (current != NULL) {
        if (!current->Type.empty()) {
            person << current->Name << endl;
            person << current->Phone << endl;
            person << current->City << endl;
            person << current->Type << endl;
            person << current->S << endl;
            person << current->NumCourses << endl;
            person << current->ID << endl;
            person << current->Password << endl;
            for (int i = 0; i < current->NumCourses; ++i) {
                person << current->Courses[i] << endl;
                person << current->Codes[i] << endl;
                person << current->CrHr << endl;
                person << current->Day << endl;
                person << current->Slot << endl;
                person << current->Attendance << endl;
                person << current->Marks << endl;
            }
        }
        current = current->next;
    }
    person.close();
    exit(0);
}

int main() {
    Entry();
    system("cls");
    int count = 1;
    while (1) {
        cout << setw(90) << "======================================================\n";
        cout << setw(90) << "|WELCOME TO THE GRANDEST UNIVERSITY IN PAKISTAN PIEAS|\n";
        cout << setw(90) << "======================================================\n";
        cin.ignore();
        string id, pa;
        int choice;
        bool found = false;
        cout << endl << endl << endl;
        cout << setw(60) << "Enter Login-ID : ";
        getline(cin, id);
        cout << setw(60) << "Enter Password : ";
        getline(cin, pa);

        Node* current1 = A.head;
        Node* current2 = F.head;
        Node* current3 = S.head;

        while (current1 != NULL || current2 != NULL || current3 != NULL) {

            //For Administrator.
            if (current1->ID == id && current1->Password == pa) {
                    found = true;
                    cout << "1. To Enter Faculty Member Data.\n2. To Offer Semester To A Student.\nPlease Enter One OF The Following Options : ";
                    cin >> choice;
                    if (choice == 1)
                        F.Faculty_Data();
                    else if (choice == 2)
                        S.Student_Data();
                    else
                        cout << "Wrong Data Entry. Please Try Again.\n";
                }

            //For Faculty.
            else if (current2->ID == id && current2->Password == pa) {
                found = true;
                cout << "1. To Enter Attendance \n2. To Enter Marks In Assesments.\n";
                cin >> choice;
                if ( choice == 1) {
                    F.Attendance(id, pa);
                    cout << "You Want To Exit.\nPress 1 For Yes 0 For No :  ";
                    int c;
                    cin >> c;
                    if (c == 1)
                        Exit();
                }
                else if ( choice == 2 ){
                    F.Test_Type(id, pa);
                    cout << "You Want To Exit.\nPress 1 For Yes 0 For No :  ";
                    int c;
                    cin >> c;
                    if (c == 1)
                        Exit();
                }
                else {
                    cout << "Invalid Entry\n";
                    continue;
                }

            }//For Faculty.

            else if (current3->ID == id && current3->Password == pa) {
                found = true;
                cout << "1. To View Attendance\n2. To View Marks In Assesments\n3. To Print Fee Challan\n";
                cin >> choice;
                if (choice == 1) {
                    S.view_a(id, pa);
                    cout << "You Want To Exit.\nPress 1 For Yes 0 For No :  ";
                    int c;
                    cin >> c;
                    if (c == 1)
                        Exit();
                    }
                else if (choice == 2) {
                    S.view_m(id, pa);
                    cout << "You Want To Exit.\nPress 1 For Yes 0 For No :  ";
                    int c;
                    cin >> c;
                    if (c == 1)
                        Exit();
                    }
                else if (choice == 3) {
                    S.view_fee(id, pa);
                    cout << "You Want To Exit.\nPress 1 For Yes 0 For No :  ";
                    int c;
                    cin >> c;
                    if (c == 1)
                        Exit();
                    }
                else {
                    cout << "Invalid Entry\n";
                    continue;
                }

                } //For Student.
            if(current1 != NULL)
            current1 = current1->next;
            if(current2 != NULL)
            current2 = current2->next;
            if(current3 != NULL)
            current3 = current3->next;
        }

        if (!found) {
            cout << "Invalid ID or Password. Try Again.\n";
            exit(0);
        }
        count++;
    }
    return 0;
}
