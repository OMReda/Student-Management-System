#ifndef STUDENT_MANAGER_H
#define STUDENT_MANAGER_H

#include "Student.h"
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>


class StudentManager {
private:
  std::vector<Student> students;
  std::string filename;

public:
  StudentManager(std::string fn = "students.txt") : filename(fn) {
    loadFromFile();
  }

  void addStudent(const Student &s) { students.push_back(s); }

  bool editStudent(int id, std::string newName, float newGrade) {
    for (auto &s : students) {
      if (s.id == id) {
        s.name = newName;
        s.grade = newGrade;
        return true;
      }
    }
    return false;
  }

  bool deleteStudent(int id) {
    auto it = std::remove_if(students.begin(), students.end(),
                             [id](const Student &s) { return s.id == id; });
    if (it != students.end()) {
      students.erase(it, students.end());
      return true;
    }
    return false;
  }

  void viewAll() const {
    if (students.empty()) {
      std::cout << "No students found." << std::endl;
      return;
    }
    std::cout << std::left << std::setw(10) << "ID" << std::setw(20) << "Name"
              << std::setw(10) << "Grade" << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    for (const auto &s : students) {
      std::cout << std::left << std::setw(10) << s.id << std::setw(20) << s.name
                << std::setw(10) << s.grade << std::endl;
    }
  }

  void saveToFile() const {
    std::ofstream outFile(filename);
    for (const auto &s : students) {
      outFile << s.serialize() << "\n";
    }
  }

  void loadFromFile() {
    students.clear();
    std::ifstream inFile(filename);
    std::string line;
    while (std::getline(inFile, line)) {
      if (!line.empty()) {
        students.push_back(Student::deserialize(line));
      }
    }
  }

  // Searching
  void searchByName(std::string name) const {
    bool found = false;
    for (const auto &s : students) {
      if (s.name.find(name) != std::string::npos) {
        s.display();
        found = true;
      }
    }
    if (!found)
      std::cout << "No student found with name: " << name << std::endl;
  }

  void searchById(int id) const {
    for (const auto &s : students) {
      if (s.id == id) {
        s.display();
        return;
      }
    }
    std::cout << "No student found with ID: " << id << std::endl;
  }

  // Sorting
  void sortByName() {
    std::sort(
        students.begin(), students.end(),
        [](const Student &a, const Student &b) { return a.name < b.name; });
  }

  void sortByGrade(bool ascending = true) {
    std::sort(students.begin(), students.end(),
              [ascending](const Student &a, const Student &b) {
                return ascending ? a.grade < b.grade : a.grade > b.grade;
              });
  }

  void sortById() {
    std::sort(students.begin(), students.end(),
              [](const Student &a, const Student &b) { return a.id < b.id; });
  }
};

#endif
