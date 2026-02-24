#include "StudentManager.hpp"
#include <iostream>
#include <limits>
#include <string>
#include <vector>

void clearInput() {
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void showMenu() {
  std::cout << "\n--- Student Management System ---" << std::endl;
  std::cout << "1. Add Student" << std::endl;
  std::cout << "2. Edit Student" << std::endl;
  std::cout << "3. Delete Student" << std::endl;
  std::cout << "4. View All Students" << std::endl;
  std::cout << "5. Search Student" << std::endl;
  std::cout << "6. Sort Students" << std::endl;
  std::cout << "7. Save & Exit" << std::endl;
  std::cout << "Enter choice: ";
}

int main() {
  StudentManager manager;
  int choice;

  while (true) {
    system("cls");
    showMenu();
    if (!(std::cin >> choice)) {
      std::cout << "Invalid input. Please enter a number." << std::endl;
      clearInput();
      continue;
    }

    if (choice == 7) {
      manager.saveToFile();
      std::cout << "Data saved. Goodbye!" << std::endl;
      break;
    }

    switch (choice) {
    case 1: {
      int id;
      std::string name;
      float grade;
      std::cout << "Enter ID: ";
      std::cin >> id;
      std::cout << "Enter Name: ";
      clearInput();
      std::getline(std::cin, name);
      std::cout << "Enter Grade: ";
      std::cin >> grade;
      manager.addStudent(Student(id, name, grade));
      std::cout << "Student added." << std::endl;
      system("pause");
      break;
    }
    case 2: {
      int id;
      std::string name;
      float grade;
      std::cout << "Enter ID of student to edit: ";
      std::cin >> id;
      std::cout << "Enter New Name: ";
      clearInput();
      std::getline(std::cin, name);
      std::cout << "Enter New Grade: ";
      std::cin >> grade;
      if (manager.editStudent(id, name, grade)) {
        std::cout << "Student updated successfully." << std::endl;
      } else {
        std::cout << "Student not found." << std::endl;
      }
      system("pause");
      break;
    }
    case 3: {
      int id;
      std::cout << "Enter ID of student to delete: ";
      std::cin >> id;
      if (manager.deleteStudent(id)) {
        std::cout << "Student deleted successfully." << std::endl;
      } else {
        std::cout << "Student not found." << std::endl;
      }
      system("pause");
      break;
    }
    case 4:
      manager.viewAll();
      system("pause");
      break;
    case 5: {
      int subChoice;
      std::cout << "1. Search by Name\n2. Search by ID\nEnter choice: ";
      std::cin >> subChoice;
      if (subChoice == 1) {
        std::string name;
        std::cout << "Enter name to search: ";
        clearInput();
        std::getline(std::cin, name);
        manager.searchByName(name);
      } else if (subChoice == 2) {
        int id;
        std::cout << "Enter ID to search: ";
        std::cin >> id;
        manager.searchById(id);
      }
      system("pause");
      break;
    }
    case 6: {
      int subChoice;
      std::cout
          << "Sort by:\n1. Name\n2. Grade (High to Low)\n3. ID\nEnter choice: ";
      std::cin >> subChoice;
      if (subChoice == 1)
        manager.sortByName();
      else if (subChoice == 2)
        manager.sortByGrade(false);
      else if (subChoice == 3)
        manager.sortById();
      std::cout << "Sorted." << std::endl;
      manager.viewAll();
      system("pause");
      break;
    }
    default:
      std::cout << "Invalid choice." << std::endl;
      system("pause");
    }
  }

  return 0;
}
