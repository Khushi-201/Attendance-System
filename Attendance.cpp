#include<string>
#include<algorithm>
#include<iostream>
#include<iomanip>
#include<vector>
#include<fstream>
        
using namespace std;

void systemCommand() {
    system("clear");
}
void adminShow() {
    systemCommand();
    cout << setfill(' ') << setw(50) << "ADMIN\n\n" << endl;
}
void studentAttendanceSystemShow() {
    cout << endl << endl;
    cout << setfill(' ') << setw(50) << "STUDENT ATTENDANCE SYSTEM!\n\n\n" << endl;
}
int tries;
int overall_days;

vector<pair<int, string> >student_list;
vector<pair<int, string> >::iterator it;
vector<pair<int, string> >::reverse_iterator itt;

vector<pair<int, int> >student_attendance;
vector<pair<int, int> >::iterator sa;
vector<pair<int, int> >::reverse_iterator rsa;

int admin();
int adminCheck();
int student();
int studentList();
int attendanceRecord();
int addStudent();
int removeAStudent();
int removeAllStudents();
int attendanceCall();

bool cmp(pair<int, string>p, pair<int, string>q) {
    return p.first < q.first;
}
void sortStudentList() {
    sort(student_list.begin(), student_list.end(), cmp);
}
bool cmp1(pair<int, int>p, pair<int, int>q) {
    return p.first < q.first;
}
void sortStudentAttendance() {
    sort(student_attendance.begin(), student_attendance.end(), cmp1);
}

int home() {
home:
    systemCommand;
    studentAttendanceSystemShow();
    sortStudentList();
    sortStudentAttendance();
    cout << "\t\t\t _____________________" << endl;
    cout << "\t\t\t|                     |" << endl;
    cout << "\t\t\t| ADMIN---------->Ad  |" << endl;
    cout << "\t\t\t| STUDENT-------->Stu |" << endl;
    cout << "\t\t\t| EXIT----------->Ex  |" << endl;
    cout << "\t\t\t|_____________________|" << endl;
    cout << "\n\n\tChoose an option(Ad,Stu,Ex): ";

    string choice;
    cin >> choice;

    if (choice != "Ad" && choice != "Stu" && choice != "Ex") {
        if (tries == 5) {
            system("clear");
            
            cout << endl << endl;
            cout << "U crossed limited attempt!\n\t";
            return 0;
        }
        else {
            cout << "\n\nWrong Option!\n\tTry again.........." << endl;
            
            system("clear");
            ++tries;
            goto home;
        }
    }
    else if (choice == "Ex") {
        systemCommand();
        cout << "\n\n\nLogging Out......." << endl;
        
        cout << "\tLogging Out......." << endl;
        
        systemCommand();
        cout << "\n\n\tLOGGED OUT!\n\n\n" << endl;
        
        return 0;
    }
    else if (choice == "Ad") {
        adminCheck();
    }
    else if (choice == "Stu") {
        student();
    }

}

int main() {

    systemCommand();
    home();

    return 0;
}

int adminCheck() {
adminCheck:
    adminShow();
    string user_name;
    cout << "Enter the Username: ";
    cin >> user_name;
    if (user_name == "Rishabh") {
        adminShow();
        string password;
        cout << "Enter the Password: ";
        cin >> password;
        if (password == "2002") {
            admin();
        }
        else {
            cout << "\n\n\n\tWrong Password!\n\t\tTry Again.......\n\n" << endl;
            
            goto adminCheck;
        }
    }
    else {
        cout << "\n\n\n\tWrong Username!\n\t\tTry Again.......\n\n" << endl;
        
        goto adminCheck;
    }
}
int admin() {
admin:

    adminShow();
    cout << "1. Student List" << endl;
    cout << "2. Add a Student" << endl;
    cout << "3. Remove a Student" << endl;
    cout << "4. Remove All Students" << endl;
    cout << "5. Attendance Call" << endl;
    cout << "6. Exit" << endl<<endl;
    cout<<"Press '0' to generate the attendance report"<<endl;

    int choice;
    cout << "\n\n\tChoose an Option(0-6) :";
    cin >> choice;

    if (choice > 6 || choice < 0) {
        cout << "\n\nIncorrect Option!\n\tTry again.........." << endl;
        
        system("clear");
        goto admin;
    }
    else if (choice == 6) {
        systemCommand();
         return home();
    }
    else if (choice == 1) {
        studentList();
    }
    else if (choice == 0) {
        attendanceRecord();
    }
    else if (choice == 2) {
        addStudent();
    }
    else if (choice == 3) {
        removeAStudent();
    }
    else if (choice == 4) {
        removeAllStudents();
    }
    else if (choice == 5) {
        attendanceCall();
    }
}

int studentList() {

    systemCommand();
    fstream s;
    sortStudentList();
    sortStudentAttendance();

    cout << setfill(' ') << setw(50) << "STUDENT LIST\n\n\n" << endl;
    cout << "Searching for result......." << endl;
    
    systemCommand();
     s.open("studentlist.txt",ios::app|ios::out);
    s <<  "                                    STUDENT LIST\n\n\n" << endl;
    s.close();
    if (student_list.empty()) {
        s.open("studentlist.txt",ios::app|ios::out);
        s << "No Student!" << endl;
        s.close();
    }
    else {
        int serial_no = 1;
        s.open("studentlist.txt",ios::app|ios::out);
        s << "  ROLL\t\tNAME" << endl;
        s.close();
        for (it = student_list.begin();it != student_list.end();++it) {
            s.open("studentlist.txt",ios::app|ios::out);
            s << serial_no << ". ";
            s << it->first << "\t\t" << it->second << endl;
            s.close();
            ++serial_no;
        }
    }
    char c;
    cout << "\n\n\nPress any key to go back :";
    cin >> c;
     return admin();
     
}
int attendanceRecord() {
    systemCommand();
     int dd,mm,yyyy;
   cout<<"Year:";
   cin>>yyyy;
   month:
   cout<<"Month:";
   cin>>mm;
   if(mm>0 && mm<=12)
   {
       if(mm==1 || mm==3 ||mm==5 || mm==7 || mm==8 ||mm==10||mm==12)
       {
           invalid:
           cout<<"Date:";
           cin>>dd;
           if(dd<=31){
               goto valid;
           }
           else{
               cout<<"Invalid date.Enter again...."<<endl;
               goto invalid;
           }
       }
       else if(mm==4||mm==6||mm==9||mm==11)
       {
           invalid1:
           cout<<"Date:";
           cin>>dd;
           if(dd<=30){
               goto valid;
           }
           else{
               cout<<"Invalid date. Enter again...."<<endl;
               goto invalid1;
           }
       }
       else{
           if (((yyyy % 4 == 0) && (yyyy % 100 != 0)) || (yyyy % 400 == 0))
           {
               invalid2:
               cout<<"Date:";
               cin>>dd;
               if(dd<=29)
               {
                   goto valid;
               }
               else{
               cout<<"Invalid date.Enter again...."<<endl;
               goto invalid2;
           }
       }
       else{
           invalid3:
           cout<<"Date:";
           cin>>dd;
               if(dd<=28)
               {
                   goto valid;
               }
               else{
               cout<<"Invalid date. Enter again...."<<endl;
               goto invalid3;
               
           }
       }
   }}
   else{
       cout<<"Invalid date. Enter again...."<<endl;
       goto month;
   }
   valid:
   
    fstream f;
    f.open("AttendanceSheet.txt",ios::app|ios::out);
    f << setfill(' ') << setw(50) << "-----STUDENT ATTENDANCE RECORD!-----\n\n" << endl<<endl;
    f<<"\t\tDate :"<<dd<<"/"<<mm<<"/"<<yyyy<<endl;
    f.close();
    if (student_attendance.empty()) {
        f.open("AttendanceSheet.txt",ios::app|ios::out);
        f << "Sorry,no Students!\n\n" << endl;
        f.close();
        cout << "Press any key to go back :";
        char c;
        cin >> c;
         return admin();
         
    }
    else {
        int serial_no = 1;
        f.open("AttendanceSheet.txt",ios::app|ios::out);
        f << "Total attendance called :" << overall_days << "\n\n" << endl;
        f << "  ROLL\t\tATTENDANCE" << endl;
        f.close();
        for (sa = student_attendance.begin();sa != student_attendance.end();++sa) {
            f.open("AttendanceSheet.txt",ios::app|ios::out);
            f << serial_no << ". ";
            f << sa->first << "\t|\t" << sa->second << endl;
            f.close();
            ++serial_no;
        }
        cout << "\n\nPress any key to go back :";
        char c;
        cin >> c;
        return admin();
    }
    
}
int addStudent() {
add:
    systemCommand();
    while (1) {

        cout << setfill(' ') << setw(50) << "ADD A STUDENT\n\n\n" << endl;
        cout << "1. Add student" << endl;
        cout << "0. Go back\n\n" << endl;

        cout << "Choose an Option :";
        int choice;
        cin >> choice;
        switch(choice)
        {
        case 0: admin();
             break;
             
        
        case 1: {
            systemCommand();
            cout << setfill(' ') << setw(50) << "ADD A STUDENT\n\n\n" << endl;
            int roll_number;
            string student_name;
            cout << "Enter the roll number :";
            cin >> roll_number;
            cout << "\nEnter the Student Name :";
            cin >> ws;
            getline(cin, student_name);
            
            student_list.push_back(make_pair(roll_number, student_name));
            student_attendance.push_back(make_pair(roll_number, 0));

            cout << "\n\n\n\t\tSaving Information......." << endl;
            
             goto add;
             break;
            }
        
        default: {
            cout << "\n\nIncorrect Option!\n\tTry again.........." << endl;
            
             goto add;
        }
    }
}}
int removeAStudent() {
removed:
    systemCommand();
    cout << setfill(' ') << setw(50) << "REMOVE A STUDENT!\n\n" << endl;
    if (student_list.empty()) {
        cout << "Sorry,No Students\n\n" << endl;
        cout << "Press any key to go back :";
        char c;
        cin >> c;
         admin();
         
    }
    else {
        while (1) {
            cout << "1. Remove Student" << endl;
            cout << "0. Go back\n\n" << endl;
            cout << "Choose an Option :";
            int choice;
            cin >> choice;
            if (choice == 0) {
                return admin();
                 
            }
            else if (choice == 1) {
                systemCommand();
                cout << setfill(' ') << setw(50) << "REMOVE A STUDENT!\n\n" << endl;
                cout << "Enter roll number :";
                int roll_no;
                cin >> roll_no;

                it = student_list.begin();
                sa = student_attendance.begin();

                while (it != student_list.end() && sa != student_attendance.end()) {

                    if (it->first == roll_no) {

                        student_list.erase(it);
                        student_attendance.erase(sa);
                        systemCommand();
                        cout << setfill(' ') << setw(50) << "REMOVE A STUDENT!\n\n" << endl;
                        cout << "\n\n\tRemoving Student.......\n" << endl;
                        
                        cout << "Student Removed!\n\n" << endl;
                        cout << "Press any key to go back. :";
                        char c;
                        cin >> c;
                        goto removed;
                    }
                    ++it;
                    ++sa;
                }
                systemCommand();
                cout << setfill(' ') << setw(50) << "REMOVE A STUDENT!\n\n" << endl;
                cout << "Sorry,No such roll number exist!\n\n" << endl;
                cout << "Press any key to go back. :";
                char c;
                cin >> c;
                goto removed;
            }
            else {
                systemCommand();
                cout << setfill(' ') << setw(50) << "REMOVE A STUDENT!\n\n" << endl;
                cout << "\n\nIncorrect Option!\n\tTry again.........." << endl;
                
                goto removed;
            }
        }
    }

}
int removeAllStudents() {

    systemCommand();
    cout << setfill(' ') << setw(50) << "REMOVE ALL STUDENTS!\n\n" << endl;
    cout << "Removing all students......." << endl;
    
    cout << "\tRemoving all students........" << endl;
    student_list.clear();
    student_attendance.clear();
    
    systemCommand();
    cout << setfill(' ') << setw(50) << "REMOVE ALL STUDENTS!\n\n" << endl;
    cout << "\t\tRemoved all students.\n\n" << endl;

    cout << "Press any key to go back. :";
    char c;
    cin >> c;

     return admin();
     
}
int attendanceCall() {
    systemCommand();
    cout << setfill(' ') << setw(50) << "ATTENDANCE CALL\n\n" << endl;

    if (student_attendance.empty()) {
        cout << "Sorry,no Students!\n\n" << endl;
        cout << "Press any key to go back :";
        char c;
        cin >> c;
         return admin();
         
    }
    else {
        ++overall_days;

        it = student_list.begin();
        sa = student_attendance.begin();
        while (it != student_list.end() && sa != student_attendance.end()) {
            systemCommand();
            cout << setfill(' ') << setw(50) << "ATTENDANCE CALL\n\n" << endl;
            cout << "P---->Present\nA---->Absent\nL---->Leave\n" << endl;
            cout << it->first << "\t";
            char c;
            cin >> c;

            if (c == 'P') {
                ++sa->second;
            }
            ++it;
            ++sa;
        }
        cout << "\n\n\t\tEnd of call!" << endl;
        cout << "\n\n\n\t\tSaving Information......." << endl;
        
        systemCommand();
        cout << setfill(' ') << setw(50) << "ATTENDANCE CALL\n\n" << endl;
        cout << "\n\n\n\t\tSaved Information!\n\n" << endl;
        cout << "Press any key to go back :";
        char c;
        cin >> c;

     return admin();
     
    }
}

int student() {
    systemCommand();
    cout << setfill(' ') << setw(50) << "STUDENT\n\n" << endl;
    if (student_list.empty()) {
        cout << "Sorry,no students!\n\n" << endl; 
        cout << "Press any key to go back :";
        char c;
        cin >> c;
        systemCommand();
       return home();
    
    }
    else {
        cout << "Enter the roll number :";
        int roll_no;
        cin >> roll_no;

        it = student_list.begin();
        sa = student_attendance.begin();

        int serial_no = 0;
        while (it != student_list.end() && sa != student_attendance.end()) {
            if (it->first == roll_no) {
                ++serial_no;
                systemCommand();
                cout << setfill(' ') << setw(50) << "STUDENT\n\n" << endl;
                cout<<"S.no."<<"\t"<<"ROLL.NO"<<"\t"<<" NAME"<<"\t"<<"ATTENDANCE"<<endl<<endl;
                cout << serial_no << ".  " <<"\t"<< roll_no << "\t" << it->second << "\t" << sa->second << endl;
                cout << "\n\n\nPress any key to go back :";
                char c;
                cin >> c;
                systemCommand();
                return home();
                 
            }
            ++it;
            ++sa;
        }
        cout << "\n\nSorry,no such roll number!\n\n" << endl;
        cout << "Press any key to go back :";
        char c;
        cin >> c;
        systemCommand();
         return home();
         
    }
}
