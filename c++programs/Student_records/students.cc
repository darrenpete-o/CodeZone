#include "students.h"

// functions
// default constructor
student::student() {};
// destructor
student::~student() {};
// write to file
void student::write_to_file(string file)
{
    // open file for writing
    ofstream fout;
    fout.open(file, ios::app);
    // show error if file doesnt open
    if (!fout)
    {
        cout << "Could not open file" << endl;
    }
    // write all info to file
    for (size_t i = 0; i < my_student.size(); i++)
    {
        // write all students into file
        fout << setw(20) << left << my_student[i].id << setw(20) << left << my_student[i].first_name << setw(20) << left << my_student[i].last_name << setw(20) << left << my_student[i].age << setw(20) << left << my_student[i].gender << endl;
    }
};
// read from file
void student::read_from_file(string file)
{
    // open file for reading
    ifstream fin;
    fin.open(file);
    // variables
    string line;
    string _id, _first_name, _last_name, _age, _gender;
    // write each line of file into the vector
    while (getline(fin, line))
    {
        // make temp vector object to take in all the student attributes
        student_Info temp;
        stringstream ss(line);
        ss >> _id >> _first_name >> _last_name >> _age >> _gender;
        temp.id = stoi(_id);
        temp.first_name = _first_name;
        temp.last_name = _last_name;
        temp.age = stoi(_age);
        temp.gender = _gender;
        // push them into the vector
        my_student.push_back(temp);
    }
};
string student::to_lower(string str)
{
    // convert every letter in given string to lowercase
    for (size_t i = 0; i < str.length(); i++)
    {
        str[i] = tolower(str[i]);
    }
    return str;
};
// add info
void student::addInfo()
{
    // temprary student object
    student_Info temp;
    // variables
    bool running = true;
    // loop to add students
    while (running)
    {
        // prompts user for info
        // add that info to vector
        cout << "Enter new Students information: " << endl
             << " " << endl;
        cout << "ID: ";
        cin >> temp.id;
        cout << "First name: ";
        cin >> temp.first_name;
        cout << "Last name: ";
        cin >> temp.last_name;
        cout << "Age: ";
        cin >> temp.age;
        cout << "Gender: ";
        cin >> temp.gender;
        // push all of those to the fector
        my_student.push_back(temp);
        // ask if user wants to add another
        cout << "" << endl
             << "Add another student? (Y/N) : ";
        char response;
        cin >> response;
        // make sure response is always lowercase
        response = tolower(response);
        if (response == 'y')
        {
            running = true;
        }
        else
        {
            running = false;
        }
    }
    // write the new student to file
    write_to_file("Info.txt");
};
// view info
void student::viewInfo(string file)
{
    // variables
    string line;
    // open file for reading
    ifstream fin;
    fin.open(file);
    // show error if it doesnt open
    if (!fin)
    {
        cout << "Could not open file" << endl;
    }
    // write each line from file to console
    while (!fin.eof() && getline(fin, line))
    {
        cout << line << endl;
    }
};
// search info
void student::searchInfo(string file)
{
    // variables
    string line;
    // open file for reading
    ifstream fin;
    fin.open(file);
    // show error if it doesnt open
    if (!fin)
    {
        cout << "Could not open file" << endl;
    }
    // prompt user to search for a student
    bool running = true;
    string search;
    string _id, _first_name, _last_name, _age, _gender;
    while (running)
    {
        // check if found
        bool found = false;
        cout << "" << endl
             << "Search for student: ";
        cin >> search;
        // convert to lowercase
        search = to_lower(search);
        while (getline(fin, line))
        {
            // separate the elements in the line
            stringstream ss(line);
            ss >> _id >> _first_name >> _last_name >> _age >> _gender;
            _id = to_lower(_id);
            _first_name = to_lower(_first_name);
            _last_name = to_lower(_last_name);
            _age = to_lower(_age);
            _gender = to_lower(_gender);
            // search for student
            if (search == _id || search == _first_name || search == _last_name || search == _age || search == _gender)
            {
                cout << line << endl;
                found = true;
            }
        }
        // display student not found if there is no mathces
        if (!found)
        {
            cout << "Could not find student" << endl;
        }
        // prompt if they would like to search for another student
        cout << "" << endl
             << "Search for another student? (Y/N) : ";
        char response;
        cin >> response;
        // make sure response is always lowercase
        response = tolower(response);
        if (response == 'y')
        {
            running = true;
        }
        else
        {
            running = false;
        }
        // go back to the top of file
        fin.clear();
        fin.seekg(0, ios::beg);
    }
    fin.close();
};
// edit info
void student::editInfo(string file)
{
    // variables
    int num_of_line = 1;
    int choice;
    string new_first_name, new_last_name, new_gender;
    int new_id, new_age;
    // clear the vector first before writing to it again
    my_student.clear();
    // read in from file to the vector
    read_from_file(file);
    // Display all students to be chosen from
    cout << "Choose a number of the student you would like to alter: " << endl
         << "" << endl;
    for (size_t i = 0; i < my_student.size(); i++)
    {
        cout << left << num_of_line << setw(20) << ")" << setw(20) << left << my_student[i].id << setw(20) << left << my_student[i].first_name << setw(20) << left << my_student[i].last_name << setw(20) << left << my_student[i].age << setw(20) << left << my_student[i].gender << endl;
        num_of_line++;
    }
    // get input from user
    cout << "Enter here: ";
    cin >> choice;
    // display line
    cout << "" << endl
         << "Your choice: " << setw(20) << left << my_student[choice - 1].id << setw(20) << left << my_student[choice - 1].first_name << setw(20) << left << my_student[choice - 1].last_name << setw(20) << left << my_student[choice - 1].age << setw(20) << left << my_student[choice - 1].gender << endl;
    // get new info
    cout << "" << endl
         << "Enter new information:" << endl;
    cout << "ID = ";
    cin >> new_id;
    cout << "First name = ";
    cin >> new_first_name;
    cout << "Last name = ";
    cin >> new_last_name;
    cout << "Age = ";
    cin >> new_age;
    cout << "Gender = ";
    cin >> new_gender;
    // change it in the vector
    my_student[choice - 1].id = new_id;
    my_student[choice - 1].first_name = new_first_name;
    my_student[choice - 1].last_name = new_last_name;
    my_student[choice - 1].age = new_age;
    my_student[choice - 1].gender = new_gender;
    // print new line
    // display line
    cout << "" << endl
         << "New line: " << setw(20) << left << my_student[choice - 1].id << setw(20) << left << my_student[choice - 1].first_name << setw(20) << left << my_student[choice - 1].last_name << setw(20) << left << my_student[choice - 1].age << setw(20) << left << my_student[choice - 1].gender << endl;
    // change it in the file
    write_to_file("Temp.txt");
    remove("Info.txt");
    rename("Temp.txt", "Info.txt");
};
// save info
void student::saveInfo() {};