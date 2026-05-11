#include<iostream>
using namespace std;

class Student{
public: 
// Attributes
int id;
int age;
string name;
int nos;

// Constructor : default constructor
Student(){
    cout<<"Student default constructor"<<endl;
}
Student(int id,int age,string name,int nos){
cout<<"Student Parameterized constructor"<<endl;
this->id=id;
this->age=age;
this->name=name;
this->nos=nos;
}
// Behaviour /methods/functions
void study(){
    cout<<this->name<<"Studying "<<endl;
}
void sleep(){
    cout<<this->name<< "Sleeping" <<endl;
}

void bunk(){
    cout<<this->name<<"Bunking" <<endl;
}
~Student()
{
    cout<<"Student default Destructor"<<endl; 
}
};
int main(){
// Student A;
// A.id=1;
// A.age=15;
// A.name="Ranu";
// A.nos=6;

// A.study();

// Student B;
// B.id=2;
// B.age=15;
// B.name="Rahul";
// B.nos=5;
// B.bunk();

Student A(1,15,"Rama",6);
// Student B(5,19,"Ra",7);
// Student C(3,18,"RamaAAA",8);
// Student D(4,19,"Ramaaa",9);
// Student E(4,12,"RamaA",1);
// cout<< A.name <<" " << A.age <<endl;



return 0;
}