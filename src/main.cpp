#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <student.h>
#include <stdexcept>
#include <algorithm>

using namespace std;

bool inputfile(const string& filename,vector<Student>& student){
    ifstream csvfile(filename);
    if(!csvfile.is_open()){
        cout<<"文件打开失败"<<endl;
        return false;
    }

    string line;
    if (!getline(csvfile, line)) {
        cerr << "无法读取CSV表头" << endl;
        return false;
    }
    while(getline(csvfile,line)){
        size_t i = line.find(",");
        if(i==string::npos){
            cout<<"数据中没有逗号，需核对原数据"<<endl;
            continue;
        }
        string sub1=line.substr(0,i);
        string sub2=line.substr(i+1);
        if(!sub2.empty()&&sub2.back()=='\r'){
            sub2.pop_back();
        }
        try{
            size_t pos=0;
            int sub2_int=stoi(sub2,&pos);
            if(pos!=sub2.size()){
                cout<<"成绩包含非法字符"<<endl;
                continue;
            }
            if(sub2_int<=100&&sub2_int>=0){
                student.emplace_back(sub1,sub2_int);
            }
            else{
                cout<<"成绩不在0-100范围"<<endl;
            }
        }
        catch(const invalid_argument& e){
            cout<<"成绩不是有效数字，错误是： "<<e.what()<<endl;
        }
        catch(const out_of_range& d){
            cout<<"成绩超出有效范围，错误是："<<d.what()<<endl;
        }
    }
    return csvfile.eof() && !csvfile.bad();
}

void sortStudents(vector<Student>& student){
    sort(student.begin(),student.end(),
        [](const Student& a,const Student& b){
            return a.getScore()>b.getScore();
        }
    );
}

void printStudent(const vector<Student>& student){
    cout<<"总共有"<<student.size()<<"名学生"<<endl;
    for(const Student& s:student){
        s.print();
    }
}

void printStatistics(const vector<Student>& student){
    if(student.empty()){
        cout<<"学生人数为0,无法进行统计"<<endl;
    }else{
        cout<<"最高分为:"<<student.front().getScore()<<endl;
        cout<<"最低分为:"<<student.back().getScore()<<endl;
        int sum=0;
        for(const Student& s : student){
            sum+=s.getScore();
        }
        double mean=sum*1.0/student.size();
        cout<<"平均分为:S"<<mean<<endl;
    }
}

bool outputfile(const string& filename,const vector<Student>& student){
    ofstream resultfile(filename);
    if(!resultfile.is_open()){
        cout<<"文件打开失败"<<endl;
        return false;
    }
    resultfile<<"name,score"<<endl;
    for(const Student& s : student){
        resultfile<<s.getName()<<","<<s.getScore()<<endl;
    }
    resultfile.close();
    return resultfile.good();
}

int main(){
	vector<Student> student;
    if(!inputfile("data/student.csv",student)){
        cout<<"csv文件输入失败"<<endl;
        return 1;
    }

    sortStudents(student);
    printStudent(student);
    printStatistics(student);

    if(!outputfile("output/resulSSt.csv",student)){
        cout<<"csv文件输出失败"<<endl;
        return 1;
    }
    //程序结束
    return 0;
}