#include "students.h"

int main()
{
    // variables
    student s;
    int choice;
    string response;
    bool running = true;
    // introduction
    cout << "" << endl
         << "Weclome to Student records" << endl
         << "" << endl;
    while (running)
    {
        cout << "What would you like to do?: " << endl;
        cout << "1) Add Student Info" << endl;
        cout << "2) View Student Info" << endl;
        cout << "3) Search Student Info" << endl;
        cout << "4) Edit Student Info" << endl;
        cout << "Enter here: ";
        cin >> choice;
        // decision
        switch (choice)
        {
        case 1:
            cout << "" << endl;
            s.addInfo();
            cout << "" << endl;
            break;
        case 2:
            cout << "" << endl;
            s.viewInfo("Info.txt");
            cout << "" << endl;
            break;
        case 3:
            cout << "" << endl;
            s.searchInfo("Info.txt");
            cout << "" << endl;
            break;
        case 4:
            cout << "" << endl;
            s.editInfo("Info.txt");
            cout << "" << endl;
            break;

        default:
            break;
        }
        // ask if the user would like to pick another option
        cout << "Choose another option? (Y/N): ";
        cin >> response;
        response = s.to_lower(response);
        if (response == "y")
        {
            running = true;
        }
        else
        {
            running = false;
        }
    }
}