#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include <sstream>
#include <string>


class Student {
public:
  int id;
  std::string name;
  float grade;

  Student(int id = 0, std::string name = "", float grade = 0.0f)
      : id(id), name(name), grade(grade) {}

  // Convert student data to a comma-separated string for file storage
  std::string serialize() const {
    std::stringstream ss;
    ss << id << "," << name << "," << grade;
    return ss.str();
  }

  // Create a Student object from a comma-separated string
  static Student deserialize(const std::string &data) {
    std::stringstream ss(data);
    std::string item;
    int id;
    std::string name;
    float grade;

    std::getline(ss, item, ',');
    id = std::stoi(item);
    std::getline(ss, name, ',');
    std::getline(ss, item, ',');
    grade = std::stof(item);

    return Student(id, name, grade);
  }

  void display() const {
    std::cout << "ID: " << id << " | Name: " << name << " | Grade: " << grade
              << std::endl;
  }
};

#endif
