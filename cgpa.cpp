#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;
// Function to convert letter grades to grade points
double gradeToPoint(char grade){
    switch(toupper(grade)){
        case 'A':return 4.0;
        case 'B':return 3.0;
        case 'C':return 2.0;
        case 'D':return 1.0;
        case 'F':return 0.0;
        default:return -1;
    }
}
int main() {
    int numSemesters;
    cout<<"Enter the no of semesters :";
    cin>>numSemesters;

    double totalCGPA_Points = 0, totalCGPA_Credits =0;
    ofstream file("cgpa_record.txt", ios::app );
    if(!file) {
        cout<<"Error opening file!"<<endl;
        return 1;
    }
    file<<"\n ---CGPA Calculation ---\n";
    for(int sem = 1; sem <=numSemesters; sem++){
        int numSubjects;
        cout<<"\nEnter the number of subjects for Semester"<<sem<<":";
        cin>>numSubjects;

        double semesterPoints = 0, semesterCredits = 0;
        for(int i=0; i<numSubjects;i++){
            char grade;
            double credits;
            cout<<"Enter grade for subject"<<i+1<<"(A/B/C/D/F) :";
            cin>>grade;
            cout<<"Enter credit hours for subjects"<<i+1<<" :";
            cin>>credits;
            double gradepoint = gradeToPoint(grade);
            if(gradepoint ==-1){
                cout<<"Invalid grade entered. Please use A,B,C,D,E or F"<<endl;
                i--;//repeat this subjects
                continue;
            }
            semesterPoints += gradepoint*credits;
            semesterCredits+=credits;
        }

        double sgpa = semesterCredits ?(semesterPoints/semesterCredits) : 0;
        cout<<fixed <<setprecision(2);
        cout<<"SGPA for semester"<<sem<<" :"<<sgpa<<"\n";
        file<<"semester"<<sem<<"SGPA: "<<sgpa<<"\n";
        totalCGPA_Points +=semesterPoints;
        totalCGPA_Credits +=semesterCredits;
    }
    double cgpa = totalCGPA_Credits?(totalCGPA_Points / totalCGPA_Credits):0;
    cout<<"\nYour Overall CGPA is: "<<cgpa<<endl;
    file<<"oOverall CGPA :"<<cgpa<<"\n";
    file.close();
    cout<<"CGPA record saved in 'cgpa_record.txt'"<<endl;
    return 0;
}
