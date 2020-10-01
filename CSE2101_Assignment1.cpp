#include<iostream>
using namespace std;
class Student{
public:
    int Id;
    float CGPA;
    void SetData(int id,float c1,float c2,float c3){
        Id = id;
        CGPA = (c1+c2+c3)/3;
    }
};
int main()
{
    cout<<"Number of Students: ";
    int StudentNumber;
    cin>>StudentNumber;
    Student students[StudentNumber];
    int id;
    float c1,c2,c3;
    for(int i=0;i<StudentNumber;i++){
        cout<<"\nStudent Id: ";;
        cin>>id;
        cout<<"Course 1 GPA: ";
        cin>>c1;
        cout<<"Course 2 GPA: ";
        cin>>c2;
        cout<<"Course 3 GPA: ";
        cin>>c3;
        students[i].SetData(id,c1,c2,c3);
    }
    Student temp;
    for(int i=0;i<StudentNumber;i++){
        for(int j=i+1;j<StudentNumber;j++){
            if(students[i].CGPA<students[j].CGPA){
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    cout<<"\nEnter Student ID for result:";
    int ResultId;
    bool y=false;
    cin>>ResultId;
    for(int i=0;i<StudentNumber;i++){
        if(students[i].Id == ResultId){
            cout<<"\n\nCGPA of Student ID "<<ResultId<<" is "<<students[i].CGPA<<endl;
            cout<<"Merit position: "<<i+1;
            y=true;
        }
    }
    if(y==false){
        cout<<"Invalid ID "<<ResultId<<"!";
    }
}
