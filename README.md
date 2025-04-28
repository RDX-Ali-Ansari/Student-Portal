# University Management System 📚

## Overview 🏫

This is a simple University Management System written in C++ that allows for handling the information and operations related to the students, faculty, and administrator. It is designed to provide functionalities such as:

- **Admin**: Manage administrator data.
- **Faculty**: Manage attendance and marks of students.
- **Student**: View attendance, marks, and fee structure.

## Features 🌟

- **Admin** can:
  - Add faculty and student data.
  - Manage faculty and student assignments.
  
- **Faculty** can:
  - Enter attendance for enrolled students.
  - Enter marks for students.

- **Students** can:
  - View their attendance and marks.
  - View their fee structure and print fee challan.

## Prerequisites ⚙️

- C++ Compiler (e.g., GCC, MinGW)
- Basic knowledge of C++ programming
- Text editor or IDE for development (e.g., Visual Studio Code, Code::Blocks, etc.)

## Setup 🛠️

1. **Clone or Download the repository**:
    ```bash
    git clone https://github.com/your-username/University-Management-System.git
    ```

2. **Compile the program**:
    ```bash
    g++ -o university_system university_system.cpp
    ```

3. **Run the program**:
    ```bash
    ./university_system
    ```

## File Structure 📂

- **Admin.txt**: Stores the administrator data.
- **Faculty.txt**: Stores faculty data.
- **Student.txt**: Stores student data.

## Classes & Functions 📘

### Admin Class 👩‍🏫

- `addNode(Node* newNode)`: Adds a new admin node to the list.
- `Admin_Data()`: Collects admin details.
- `saveToFile()`: Saves admin data to a file.

### Faculty Class 👨‍🏫

- `addNode(Node* newNode)`: Adds a new faculty node to the list.
- `Attendance(string id, string p)`: Manages attendance data.
- `Test_Type(string id, string p)`: Manages test/marks data.
- `Faculty_Data()`: Collects faculty details.

### Student Class 👨‍🎓

- `addNode(Node* newNode)`: Adds a new student node to the list.
- `view_a(string id, string p)`: Views student's attendance.
- `view_m(string id, string p)`: Views student's marks.
- `view_fee(string id, string p)`: Views student's fee structure.
- `Student_Data()`: Collects student details.

### Other Functions 🛠️

- `Entry()`: Initializes the system with existing data.
- `Exit()`: Saves data when the program ends.
  
## How it Works 💡

1. **Login**:
   - The system prompts for a login ID and password.
   - The system identifies whether the login belongs to an admin, faculty, or student.

2. **Admin Menu**:
   - Admins can add faculty or student data.
   - Admin can assign a semester to a student.

3. **Faculty Menu**:
   - Faculty can enter attendance or marks for students enrolled in their courses.

4. **Student Menu**:
   - Students can view their attendance, marks, and fee structure.

## Usage 👨‍💻

1. **Administrator**:
    - Add faculty and student details.
    - Manage faculty and student assignments.

2. **Faculty**:
    - Record attendance and marks for students in courses.

3. **Student**:
    - Check your attendance, marks, and fee details.

## Contributions 🤝

- Contributions are welcome! Feel free to fork this project, make improvements, or open issues for suggestions.

## Contact 📬

For any queries or contributions, contact the repository owner at "aliansarimuhammadamjad@example.com".
