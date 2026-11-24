#include <iostream>
#include <student.h>

using namespace std;

void Student::print() const{
    cout<<"学生姓名:"<<this->_name<<" 学生成绩:"<<this->_score<<endl;
}
