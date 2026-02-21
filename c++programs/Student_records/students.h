#ifndef STUDENTS_H
#define STUDENTS_H
// includes
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cctype>
// using std library
using namespace std;

// student class
class student
{
    // private
private:
    // variables
    struct student_Info
    {
        int id;
        string first_name, last_name;
        int age;
        string gender;
    };
    vector<student_Info> my_student;
    // public
public:
    // functions
    // default constructor
    student();
    // destructor
    virtual ~student();
    // write to file
    void write_to_file(string file);
    // read from file
    void read_from_file(string file);
    // Convert string to lowercase
    string to_lower(string str);
    // add info
    void addInfo();
    // view info
    void viewInfo(string file);
    // search info
    void searchInfo(string file);
    // edit info
    void editInfo(string file);
    // save info
    void saveInfo();
};
#endif