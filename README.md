# 🎓 Student Management System

> **A precision-engineered C++ console application for academic record management.**

Efficiently manage student data with this high-performance, CLI-based system. Designed with a focus on modularity and data persistence, it provides a seamless interface for handling large datasets of student records.

---

## ✨ Features

- **📂 Persistent Storage**: Automatically saves and loads student data from `students.txt` using custom serialization.
- **🔍 Advanced Search**: Locate students instantly by **Name** or **ID**.
- **📊 Dynamic Sorting**: Organize your records by:
  - Name (Alphabetical)
  - Grade (High to Low)
  - ID (Numerical)
- **🛠️ Full CRUD Operations**: 
  - **Create**: Add new students with unique IDs.
  - **Read**: View all students in a formatted, tabular dashboard.
  - **Update**: Edit existing student names and grades.
  - **Delete**: Remove records with safety checks.
- **🛡️ Robust Input Handling**: Built-in validation to prevent system crashes on invalid numeric inputs.

---

## 🚀 Getting Started

### Prerequisites

- A C++ compiler (e.g., `g++` on MinGW/Windows, Clang, or GCC).
- `Make` (optional, for manual builds).

### Build & Run

1. **Clone or Download** the project files.
2. **Compile** using your terminal:
   ```bash
   g++ main.cpp -o sms
   ```
3. **Launch** the application:
   ```bash
   ./sms
   ```

*Alternatively, use the provided batch script on Windows:*
```powershell
.\run.bat
```

---

## 📖 Usage Guide

Upon launching, use the numeric menu to navigate:
1. **Add**: Input ID, full name, and grade.
2. **Edit**: Modify a student's profile by their unique ID.
3. **Delete**: Permanently remove a record from the database.
4. **View**: Display a clean table of all enrolled students.
5. **Search**: Find specific students using keywords or IDs.
6. **Sort**: Reorder the database for better analysis.
7. **Exit**: Securely save all changes to the disk.

---

## 🛠️ Tech Stack

- **Language**: C++17
- **Standard Library**: `vector`, `algorithm`, `fstream`, `iomanip`
- **Data Format**: Custom CSV-style serialization

---

## 📂 Project Anatomy

- `main.cpp`: Entry point & UI logic.
- `Student.h`: Core data model & serialization logic.
- `StudentManager.h`: Business logic for CRUD, searching, and sorting.
- `students.txt`: The persistent database file.

