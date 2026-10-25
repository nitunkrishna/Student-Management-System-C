# Student Management System

A simple, console-based **Student Management System developed in C**, designed to store, retrieve, update, and delete student records using file handling.

This project demonstrates fundamental C programming concepts, including **structures, functions, loops, conditional statements, input validation, and binary file operations**.

## Features

- **Add Student:** Store student information, including personal details, academic information, and contact details.
- **View All Students:** Display all student records stored in the system.
- **Search Student:** Find a student using their unique Student ID.
- **Update Student:** Modify a student's email address, phone number, or CGPA.
- **Delete Student:** Remove a student record using their Student ID.
- **Duplicate ID Prevention:** Prevent adding multiple students with the same ID.
- **Persistent Data Storage:** Save records locally using binary file handling.
- **Basic Input Validation:** Validate menu selections, search IDs, and CGPA during student registration.

## Technologies Used

- **Programming Language:** C
- **File Handling:** Binary files (`.dat`)
- **Standard Libraries:** `stdio.h`, `stdlib.h`, `string.h`
- **Compiler:** GCC or any compatible C compiler
- **Interface:** Command-Line Interface (CLI)

## Project Structure

```text
Student-Management-System/
│
├── main.c
├── student.h
├── add_student.c
├── view_student.c
├── search_student.c
├── update_student.c
├── delete_student.c
├── README.md
└── .gitignore
```

**File Descriptions:**

| File | Description |
|---|---|
| `main.c` | Main menu and program execution |
| `student.h` | Student structure and function declarations |
| `add_student.c` | Student registration and duplicate ID checking |
| `view_student.c` | Display all stored student records |
| `search_student.c` | Search for students by ID |
| `update_student.c` | Update existing student information |
| `delete_student.c` | Delete student records |
| `.gitignore` | Excludes generated and temporary files |

## Getting Started

### Prerequisites

Make sure a C compiler, such as GCC, is installed on your computer.

Check your GCC installation:

```bash
gcc --version
```

### Installation

**1. Clone the repository**

```bash
git clone https://github.com/nitunkrishna/Student-Management-System-C.git
```

**2. Navigate to the project directory**

```bash
cd Student-Management-System
```

**3. Compile the project**

```bash
gcc main.c add_student.c view_student.c search_student.c update_student.c delete_student.c -o student_management
```

**4. Run the application**

On macOS/Linux:

```bash
./student_management
```

On Windows:

```bash
student_management.exe
```

## Example Output

```text
================================
    Student Management System
================================

1. Add Student
2. View All
3. Search
4. Update
5. Delete
6. Exit

Enter your choice (1-6): 1
```

**Example: Adding a Student**

```text
Enter Student Name: Rahim Ahmed
Enter Student's Father Name: Karim Ahmed
Enter Student's Mother Name: Fatema Begum
Enter id: 101
Enter Session: 2024-2025
Enter Department: Computer Science
Enter Student e-mail: rahim@example.com
Enter Student Phone Number: 01712345678
Enter CGPA (0.00 - 4.00): 3.75

Student added successfully!
```

## Data Storage

The application uses binary file handling to store student information in a local file named `student.dat`.

- `fwrite()` saves student records.
- `fread()` retrieves student records.
- `fseek()` locates existing records for updates.
- `remove()` and `rename()` are used during record deletion.

Student data is retained between program executions unless the data file is deleted or modified.

**Note:** The binary data format depends on the `Student` structure and compiler/platform representation. Changes to the structure may make existing records incompatible.

## Concepts Demonstrated

- Structures (`struct`)
- Functions and modular programming
- Pointers and file pointers
- Loops and conditional statements
- String handling
- Binary file operations
- Basic input validation
- CRUD operations (Create, Read, Update, Delete)

## Current Limitations

This is a beginner-level educational project. Some limitations include:

- No graphical user interface.
- Data is stored in a local binary file rather than a database.
- Input validation is basic and does not cover every possible invalid input.
- File operations do not provide transaction or crash-recovery guarantees.
- Student records are searched sequentially rather than through an index.

## Future Improvements

Potential enhancements include:

- More comprehensive input validation.
- Improved file error handling.
- Sorting and filtering student records.
- Student statistics and CGPA reports.
- Exporting student records to CSV.
- Password-protected administrator access.
- Database integration.

## License

No open-source license has been specified for this project.

All rights are reserved by the copyright holder. Permission to view this public repository does not automatically grant permission to copy, modify, redistribute, or commercially use its source code, except as otherwise permitted by applicable law or GitHub's Terms of Service.

---

**Developed as a beginner C programming project to practice structured programming and file handling.**
