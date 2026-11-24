#pragma once
#include <iostream>
#include <string>

using namespace std;

class Student{
private:
    string  _name;
    int _score;
public:
    Student(string name,int score){
        this->_name=name;
        this->_score=score;
    }
    void print() const;
    int getScore() const{
        return _score;
    }
    string getName() const{
        return _name;
    }
};