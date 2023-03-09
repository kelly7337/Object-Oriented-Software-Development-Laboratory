#pragma once
#include <iostream>
using namespace std;

class Student
{
private:
    

public:
    Student();   // This is the constructor declaration
    ~Student();  // This is the destructor: declaration

    void SetName();
    virtual void set() { std::cout << "set-Student"; }

   /* Student(int year, int month, int day);

    void SetDate(int year, int month, int day);

    int getYear() { return m_year; }
    int getMonth() { return m_month; }
    int getDay() { return m_day; }*/
};

class Derived : public Student
{
public:
    Derived();

    void SetName();

    void set() { std::cout << "set-Derived"; }
};