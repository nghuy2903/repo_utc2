#include <iostream>
#include <vector>
#include <string>

class Person {
public:
    Person(std::string name, int age) : name(name), age(age) {}

    virtual void displayInfo() const {
        std::cout << "Name: " << name << ", Age: " << age;
    }

protected:
    std::string name;
    int age;
};

class Student : public Person {
public:
    Student(std::string name, int age, std::string studentId) : Person(name, age), studentId(studentId) {}

    void displayInfo() const override {
        Person::displayInfo();
        std::cout << ", Student ID: " << studentId << std::endl;
    }

private:
    std::string studentId;
};

class Teacher : public Person {
public:
    Teacher(std::string name, int age, std::string employeeId) : Person(name, age), employeeId(employeeId) {}

    void displayInfo() const override {
        Person::displayInfo();
        std::cout << ", Employee ID: " << employeeId << std::endl;
    }

private:
    std::string employeeId;
};

class ManagementSystem {
public:
    void addStudent(const Student& student) {
        students.push_back(student);
    }

    void displayAllStudents() const {
        for (const auto& student : students) {
            student.displayInfo();
        }
    }


private:
    std::vector<Student> students;
};

int main() {
    ManagementSystem managementSystem;

    while (true) {
        std::cout << "--------------MENU----------\n";
        std::cout << "1. Quan ly sinh vien\n";
        std::cout << "2. Quan ly giao vien\n";
        std::cout << "3. Quan ly nhan vien\n";
        std::cout << "0. Thoat\n";
        std::cout << "-----------------------------\n";

        int choice;
        std::cout << "Nhap lua chon: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cout << "--------------MENU: QUAN LY SINH VIEN----------\n";
                std::cout << "1. Them sinh vien\n";
                std::cout << "2. Hien thi thong tin cua sinh vien\n";
                std::cout << "3. Them danh sach sinh vien\n";
                std::cout << "0. Quay lai\n";
                std::cout << "-----------------------------------------------\n";

                int studentChoice;
                std::cout << "Nhap lua chon: ";
                std::cin >> studentChoice;

                switch (studentChoice) {
                    case 1: {
                        std::string name, studentId;
                        int age;
                        std::cout << "Nhap ten sinh vien: ";
                        std::cin >> name;
                        std::cout << "Nhap tuoi: ";
                        std::cin >> age;
                        std::cout << "Nhap ma sinh vien: ";
                        std::cin >> studentId;

                        Student student(name, age, studentId);
                        managementSystem.addStudent(student);

                        std::cout << "Sinh vien da duoc them.\n";
                        break;
                    }
                    case 2: {
                        managementSystem.displayAllStudents();
                        break;
                    }
                    case 0:
                        break;
                    default:
                        std::cout << "Lua chon khong hop le.\n";
                }

                break;
            }

            case 0:
                return 0;
            default:
                std::cout << "Lua chon khong hop le.\n";
        }
    }

    return 0;
}
