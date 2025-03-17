#include <bits/stdc++.h>
#include "Chuoi.h"

using namespace std;

class Person {
protected:
    String Cccd;
    String FullName;
    String Gender;
    String BirthDate;
    String Address;
    String PhoneNumber;

public:
    // Constructor
    Person(const String& cccd, const String& fullName, const String& gender, const String& birthDate, const String& address, const String& phoneNumber)
        {
            Cccd = cccd;
            FullName = fullName;
            Gender = gender;
            BirthDate = birthDate;
            Address = address;
            PhoneNumber = phoneNumber;
        }

    // Getter and setter methods
    String getCCCD() const { return Cccd; }

    String getFullName() const { return FullName; }

    String getGender() const { return Gender; }

    String getBirthDate() const { return BirthDate; }

    String getAddress() const { return Address; }

    String getPhoneNumber() const { return PhoneNumber; }

    // Calculate bonus method (pure virtual function, to be overridden by derived classes)
    // virtual void calculateBonus() const = 0;

    void input(){
        Cccd.inPut();
        FullName.inPut();
        Gender.inPut();
        BirthDate.inPut();
        Address.inPut();
        PhoneNumber.inPut();
    }

    void displayInfo(){ // Hiển thị 
        Cccd.outPut();
        FullName.outPut();
        Gender.outPut();
        BirthDate.outPut();
        Address.outPut();
        PhoneNumber.outPut();
    }
};



class Employee : public Person {
protected:
    String employeeId;
    double salary;

public:
    Employee(const String& cccd, const String& fullName, const String& gender,
             const String& birthDate, const String& address, const String& phoneNumber,
             const String& employeeId, double salary)
        : Person(cccd, fullName, gender, birthDate, address, phoneNumber), employeeId(employeeId), salary(salary) {}

    void calculateBonus() const;
    void displayInfo() const;
};

class OfficeEmployee : public Employee {
private:
    int monthsWorked;

public:
    OfficeEmployee(const String& cccd, const String& fullName, const String& gender,
                   const String& birthDate, const String& address, const String& phoneNumber,
                   const String& employeeId, double salary, int monthsWorked)
        : Employee(cccd, fullName, gender, birthDate, address, phoneNumber, employeeId, salary), monthsWorked(monthsWorked) {}

    void calculateBonus() const {
        if (monthsWorked < 6) {
            cout << "Bonus: 100000" << endl;
        } else {
            double bonus = 200000 + salary * 0.10 * monthsWorked / 6;
            cout << "Bonus: " << bonus << endl;
        }
    }

    void displayInfo() const {
        // Display information for OfficeEmployee
        // ...
    }
};

class SalesEmployee : public Employee {
private:
    double bonusFactor;

public:
    SalesEmployee(const String& cccd, const String& fullName, const String& gender,
                  const String& birthDate, const String& address, const String& phoneNumber,
                  const String& employeeId, double salary, double bonusFactor)
        : Employee(cccd, fullName, gender, birthDate, address, phoneNumber, employeeId, salary), bonusFactor(bonusFactor) {}

    void calculateBonus() const  {
        double bonus = 150000 * bonusFactor;
        cout << "Bonus: " << bonus << endl;
    }

    void displayInfo() const {
        // Display information for SalesEmployee
        // ...
    }
};

class ProductionEmployee : public Employee {
private:
    int totalProducts;

public:
    ProductionEmployee(const String& cccd, const String& fullName, const String& gender,
                       const String& birthDate, const String& address, const String& phoneNumber,
                       const String& employeeId, double salary, int totalProducts)
        : Employee(cccd, fullName, gender, birthDate, address, phoneNumber, employeeId, salary), totalProducts(totalProducts) {}

    void calculateBonus() const{
        double bonus = 20000 * totalProducts;
        cout << "Bonus: " << bonus << endl;
    }

    void displayInfo() const{
        // Display information for ProductionEmployee
        // ...
    }
};

class EmployeeManager {
private:
    vector<Employee*> employees;

public:
    // Methods for managing employees (add, remove, display, search, etc.)
    // ...

    ~EmployeeManager() {
        // Cleanup dynamically allocated memory
        for (auto employee : employees) {
            delete employee;
        }
    }
};

int main() {
    // Creating an instance of the Person class
    Person p;
    p.input();

    // Displaying information
    p.displayInfo();

    return 0;
}