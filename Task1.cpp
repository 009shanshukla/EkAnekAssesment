#include <bits/stdc++.h>

class Student
{
public:
    std::string name;
    int age;
    int marks;
    int rollnumber;        
};

// sort function based on criteria
/*
"sorting by multiple criteria" means. It means that two objects are first compared by one criteria. 
Then, if those criteria are the same, ties will be broken by the next criteria, and so on until you get the desired ordering.

Time Complexity O(l*nlogn)

l = size of criteria
n = total students

Auxilary Space Complexity O(1)
*/

std::vector<std::string> criteria;

bool compareTwoStudents(Student a, Student b)
{
    for(int i = 0; i < criteria.size(); i++)
    {
        if(criteria[i] == "age")
        {
            if(a.age != b.age)
                return a.age > b.age;
        }
        else if(criteria[i] == "marks")
        {
            if(a.marks != b.marks)
                return a.marks > b.marks;
        }
        else if(criteria[i] == "rollnumber")
        {
            if(a.rollnumber != b.rollnumber)
                return a.rollnumber > b.rollnumber;
        }
        else if(criteria[i] == "name")
        {
            if(a.name != b.name)
                return strcmp(a.name.c_str(), b.name.c_str());
        }
    }
    return true;
}

std::vector<Student> sorting(std::vector<Student> students)
{
    std::sort(students.begin(), students.end(), compareTwoStudents);
    return students;
}

int main()
{
    std::vector<Student> students;             //student array object

    std::vector<std::string> criteria;         // criteria string array

    /********************************************************************************/

    //input students
    Student s;
    s.name = "Ram", s.age = 11, s.marks = 87, s.rollnumber = 1;                                       
    students.push_back(s);
    s.name = "Shyam", s.age = 13, s.marks = 83, s.rollnumber = 2;   
    students.push_back(s);
    s.name = "Ram", s.age = 11, s.marks = 87, s.rollnumber = 3;   
    students.push_back(s);
    s.name = "Sita", s.age = 10, s.marks = 86, s.rollnumber = 4;   
    students.push_back(s);
    s.name = "Ram", s.age = 11, s.marks = 87, s.rollnumber = 5;                                       
    students.push_back(s);
    //input criteria
    criteria.push_back("name");
    criteria.push_back("marks");
    criteria.push_back("rollnumber");
    criteria.push_back("age");
  
    /********************************************************************************/


    std::vector<Student> sorted_student = sorting(students);

    //print sorted students

    for(int i = 0; i < sorted_student.size(); i++)
    {
        std::cout << sorted_student[i].name << " " << sorted_student[i].rollnumber << " " << sorted_student[i].marks << " " << sorted_student[i].age << std::endl; 
    }

    return 0;
}