//  Created by Afiq Hafiz on 20/11/2021.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Assessment {
public:
    string type;
    float mark = 0;
    Assessment* next;
};
class Student {
public:
    string ID;
    float cmark;
    Assessment* head = NULL;
};
class List {
public:
    int index = 0;
    Student record[100];
};
int menu() {
    int choice;
    cout << "\nCARRY MARK PROGRAM\n";
    cout << "1. Add New Student\n";
    cout << "2. Update Assesment\n";
    cout << "3. Carry Mark Summary\n";
    cout << "4. Carry Mark Summary (save to file)\n";
    cout << "5. Exit\n";
    cout << "Select Menu: ";
    cin >> choice;
    return choice;
}

int add_new_student_menu() {
    int choice;
    cout << "ASSESSMENT MENU:\n";
    cout << "1. Quiz\n";
    cout << "2. Assignment\n";
    cout << "3. Mid Term Test\n";
    cout << "4. Lab Exercise\n";
    cout << "Select Option: ";
    cin >> choice;
    return choice;
}

void markMenu() {
    cout << "\nASSESSMENT MENU " << endl;
    cout << "1. Quiz" << endl;
    cout << "2. Assignment" << endl;
    cout << "3. Mid Term Test" << endl;
    cout << "4. Lab Exercise" << endl;
}

void carrymark(List& s, int index) {
    Assessment* p = s.record[index].head;
    float carrymark = 0;
    while (p != NULL) {
        carrymark = carrymark + p->mark;
        p = p->next;
    }
    s.record[index].cmark = carrymark;
}

void add_new_student(List& s, int index) {
    cout << "Enter student ID : ";
    cin >> s.record[index].ID;
    char loop;
    float mark, percentage;
    
    do {
        int assessment_option;
        markMenu();
        cout << "Select option : ";
        cin >> assessment_option;
        if (s.record[index].head == NULL) {
            Assessment* n = new Assessment();
            if (assessment_option == 1) {
                s.record[index].head = n;
                n->type = "Quiz";
                cout << "Enter Quiz mark (40) : ";
                cin >> mark;
                percentage = (mark / 40) * 15;
                cout << "Percentage: " << percentage << "%\n";
                n->mark = percentage;
            }
            else if (assessment_option == 2) {
                s.record[index].head = n;
                n->type = "Assignment";
                cout << "Enter Assignment mark (10) : ";
                cin >> mark;
                percentage = (mark / 10) * 10;
                cout << "Percentage: " << percentage << "%\n";
                n->mark = percentage;
            }
            else if (assessment_option == 3) {
                s.record[index].head = n;
                n->type = "Midterm";
                cout << "Enter Midterm mark (50) : ";
                cin >> mark;
                percentage = (mark / 50) * 20;
                cout << "Percentage: " << percentage << "%\n";
                n->mark = percentage;
            }
            else if (assessment_option == 4) {
                s.record[index].head = n;
                n->type = "Lab Exercise";
                cout << "Enter Lab Exercise mark (14) : ";
                cin >> mark;
                percentage = (mark / 14) * 15;
                cout << "Percentage: " << percentage << "%\n";
                n->mark = percentage;
            }
            carrymark(s, index);
            cout << "Enter another assessment [Y/N] :";
            cin >> loop;
        }
        else if (s.record[index].head != NULL) {
            Assessment* p = s.record[index].head;
            Assessment* n = new Assessment();
            if (assessment_option == 1) {
                while (p->next != NULL) {
                    n->type = "Quiz";
                    if (n->type == p->type) {
                        cout << "Quiz mark already exist.\nChoose UPDATE option in Menu to update mark." << endl;
                        break;
                    }
                    p = p->next;
                }
                cout << "Enter Quiz mark (40) : ";
                cin >> mark;
                percentage = (mark / 40) * 15;
                n->mark = percentage;
                cout << "Percentage: " << percentage << "%\n";
                p->next = n;
                n->next = NULL;
            }
            else if (assessment_option == 2) {
                n->type = "Assignment";
                while (p->next != NULL) {
                    if (n->type == p->type) {
                        cout << "Assignment mark already exist.\nChoose UPDATE option in Menu to update mark." << endl;
                        break;
                    }
                    p = p->next;
                }
                cout << "Enter Assignment mark (10) : ";
                cin >> mark;
                percentage = (mark / 10) * 10;
                n->mark = percentage;
                cout << "Percentage: " << percentage << "%\n";
                p->next = n;
                n->next = NULL;
            }
            else if (assessment_option == 3) {
                while (p->next != NULL) {
                    n->type = "Midterm Test";
                    if (n->type == p->type) {
                        cout << "Midterm mark already exist.\nChoose UPDATE option in Menu to update mark." << endl;
                        break;
                    }
                    p = p->next;
                }
                cout << "Enter Midterm mark (50) : ";
                cin >> mark;
                percentage = (mark / 50) * 20;
                n->mark = percentage;
                cout << "Percentage: " << percentage << "%\n";
                p->next = n;
                n->next = NULL;
            }
            else if (assessment_option == 4) {
                while (p->next != NULL) {
                    n->type = "Lab Exercise";
                    if (n->type == p->type) {
                        cout << "Lab Test mark already exist.\nChoose UPDATE option in Menu to update mark." << endl;
                        break;
                    }
                    p = p->next;
                }
                cout << "Enter Lab Test mark (14) : ";
                cin >> mark;
                percentage = (mark / 14) * 15;
                n->mark = percentage;
                cout << "Percentage: " << percentage << "%\n";
                p->next = n;
                n->next = NULL;
            }
            else if (assessment_option > 4) {
                cout << "\nWarning! Incorrect input.";
            }
            carrymark(s, index);
            cout << "Enter another assessment [Y/N] :";
            cin >> loop;
        }
    } while (loop == 'y'|| loop == 'Y');
}

int findStudent(List& s, int index, string id) {
    int i = -1;
    if (s.record[index].ID == id) {
        i = index;
    }
    return i;
}

void update_assessment(List& s, int index) {
    string search_id;
    char update_loop;
    int update_opt;
    float newMark, percentage;
    int i;
  
    cout << "Enter student ID : ";
    cin >> search_id;
    for (int a = 0; a < index; a++) {
        i = findStudent(s, a, search_id);
        if (i >= 0) {
            break;
        }
    }
    if (i >= 0) {
        do {
            markMenu();
            cout << "Select Option : ";
            cin >> update_opt;
            Assessment* p = s.record[i].head;
            Assessment* n = new Assessment();
            if (update_opt == 1) {
                n->type = "Quiz";
                while (p->next != NULL) {
                    n->type = "Quiz";
                    if (n->type == p->type) {
                        cout << "Current percentage of " << p->type << " : " << p->mark <<"%"<< endl;
                        cout << "Enter new " << p->type << " mark (40) : ";
                        cin >> newMark;
                        percentage = (newMark / 40) * 15;
                        p->mark = percentage;
                        cout << "Percentage: " << percentage << "%\n";
                        break;
                    }
                    p = p->next;
                }
                if (p->next == NULL) {
                    cout << "Enter Quiz mark (40) : ";
                    cin >> newMark;
                    percentage = (newMark / 40) * 15;
                    n->mark = percentage;
                    cout << "Percentage: " << percentage << "%\n";
                    p->next = n;
                    n->next = NULL;
                }
              
            }
            else if (update_opt == 2) {
                n->type = "Assignment";
                while (p->next != NULL) {
                    if (n->type == p->type) {
                        cout << "Current percentage of " << p->type << " : " << p->mark << "%" << endl;
                        cout << "Enter new " << p->type << " mark (10) : ";
                        cin >> newMark;
                        percentage = (newMark / 10) * 10;
                        p->mark = percentage;
                        cout << "Percentage: " << percentage << "%\n";
                        break;
                    }
                    p = p->next;
                }
                if (p->next == NULL) {
                    cout << "Enter Assignment mark (10) : ";
                    cin >> newMark;
                    percentage = (newMark / 10) * 10;
                    n->mark = percentage;
                    cout << "Percentage: " << percentage << "%\n";
                    p->next = n;
                    n->next = NULL;
                }
               
            }
            else if (update_opt == 3) {
                while (p->next != NULL) {
                    n->type = "Midterm";
                    if (n->type == p->type) {
                        cout << "Current percentage of" << p->type << " : " << p->mark << "%" << endl;
                        cout << "Enter new " << p->type << " mark (50) : ";
                        cin >> newMark;
                        percentage = (newMark / 50) * 20;
                        p->mark = percentage;
                        cout << "Percentage: " << percentage << "%\n";
                    }
                    p = p->next;
                }
                if (p->next == NULL) {
                    cout << "Enter Midterm mark (50) : ";
                    cin >> newMark;
                    percentage = (newMark / 50) * 20;
                    n->mark = percentage;
                    cout << "Percentage: " << percentage << "%\n";
                    p->next = n;
                    n->next = NULL;
                }
            }
            else if (update_opt == 4) {
                while (p->next != NULL) {
                    n->type = "Lab Exercise";
                    if (n->type == p->type) {
                        cout << "Current percentage of" << p->type << " : " << p->mark << "%" << endl;
                        cout << "Enter new " << p->type << " mark (14) : ";
                        cin >> newMark;
                        percentage = (newMark / 14) * 15;
                        cout << "Percentage: " << percentage << "%\n";
                        p->mark = newMark;
                    }
                    p = p->next;
                }
                if (p->next == NULL) {
                    cout << "Enter Lab Test mark (14) : ";
                    cin >> newMark;
                    percentage = (newMark / 14) * 15;
                    n->mark = percentage;
                    cout << "Percentage: " << percentage << "%\n";
                    p->next = n;
                    n->next = NULL;
                }
            }
            carrymark(s, i);
            cout << "Update another assessment [Y/N] : ";
            cin >> update_loop;
        } while (update_loop == 'y'|| update_loop == 'Y');
    }
}

void carry_mark_summary(List& s, int index) {
    int display_opt;
    float temp = 0;
    string id;
    string search_student;
    cout << "\nDisplay Menu :\n";
    cout << "1. Individual\n";
    cout << "2. All\n";
    cout << "3. Highest carry mark\n";
    cout << "Select option: ";
    cin >> display_opt;

    if (display_opt == 1) {
        cout << "Enter student ID : ";
        cin >> search_student;
        cout << ":: CARRY MARK DETAIL ::" << endl;
        for (int a = 0; a < index; a++) {
            if (s.record[a].ID == search_student) {
                Assessment* student = s.record[a].head;
                while (student != NULL) {
                    cout << student->type << ": " << student->mark << "%" << endl;
                    student = student->next;
                }
                cout << "Total Carry mark : " << s.record[a].cmark << "%" << endl << endl;
            }
        }
    }
    else if (display_opt == 2) {
        cout << ":: CARRY MARK DETAIL ::" << endl;
        for (int a = 0; a < index; a++) {
            Assessment* student = s.record[a].head;
            cout << "Student ID : " << s.record[a].ID << endl;
            while (student != NULL) {
                cout << student->type << ": " << student->mark << "%" << endl;
                student = student->next;
            }
            cout << "Total Carry mark : " << s.record[a].cmark << "%" << endl << endl;
        }
    }
    else if (display_opt == 3) {
        for (int a = 0; a < index; a++) {
            if (s.record[a].cmark > temp) {
                temp = s.record[a].cmark;
                id = s.record[a].ID;
            }
        }
            for (int a = 0; a < index; a++) {
                if (s.record[a].ID == id) {
                    Assessment* student = s.record[a].head;
                    cout << "Student ID : " << s.record[a].ID << endl;
                    while (student != NULL) {
                        cout << student->type << ": " << student->mark << "%" << endl;
                        student = student->next;
                    }
                    cout << "Total Carry mark : " << s.record[a].cmark << "%" << endl << endl;
                }
            }

    }
}

int main() {
    List students;
    int line = 0;
    while (true) {
        int choice = menu();
        if (choice == 1) {
            // Add new student
            add_new_student(students, line);
            line++;
        }
        else if (choice == 2) {
            // update assessment
            update_assessment(students, line);
        }
        else if (choice == 3) {
            // carry mark summary
            carry_mark_summary(students, line);
        }
           // Save to file
        else if (choice == 4) {
            ofstream myfile;
            myfile.open("StudentCarryMark.txt");
            myfile << "Writing this to a file.\n";
            for (int a = 0; a < line; a++) {
                Assessment* student = students.record[a].head;
                myfile << ":: CARRY MARK DETAIL ::" << endl;
                myfile << "Student ID : " << students.record[a].ID << endl;
                while (student != NULL) {
                    myfile << student->type << ": " << student->mark << "%" << endl;
                    student = student->next;
                }
                myfile << "Total Carry mark : " << students.record[a].cmark << "%" << endl << endl;
            }
            myfile.close();
        }
        else if (choice == 5) {
            // exit
            break;
        }
        else {
            // invalid option
            cout << "Invalid Option\n";
        }
    }
    return 0;
}
