//single inheritance concepts:

//- Inheritance creates an is-a relationship between
//data structres.

//- The 2 types of inheritance are Single and
//Multiple.

//- Single Inheritance:
//1 or 2 classes derive from 1 base class.
//Version 1: Person -> Student -> Geekystudent
//Version 2:
//Shape -> Circle
//Shape -> Square

#include <iostream>
using namespace std;

//single inheritance bc 1 base class, 1 sub class, & 1 sub-sub class.
class Person //BASE CLASS.
{
protected:
    int age;
    string name;
public:
    //constructor:
    Person(int a, string n)
    {
        age = a;
        name = n;
    }
    //virtual deconstructor:
    virtual ~Person()
    {
        cout << "Calling Person parent deconstructor" << endl;
    }
    //funtion to be overriden:
    virtual void sayWhat() //will be overidden.
    {
        cout << "i am Person named " << name << " & age of " << age << endl;
    }
}; //END BASE CLASS.

class Student: public Person //SUB CLASS.
{
protected:
    double gpa;
public:
    //constructor:
    Student(int a, string n, double g): Person(a, n)
    {
        gpa = g;
    }
    //virtual deconstructor:
    ~Student()
    {
        cout << "Calling Student child deconstructor" << endl;
    }
    void sayWhat() override
    //will have compiler check things / more strict than using pure virtual..
    //Would I have to make sayWhat() in base pure? -> yes, but no need.
    {
        cout << "i am Student named " << name << " & age of " << age << " w/ gpa of " << gpa << endl;
    }
}; //END SUB CLASS.

class GeekyStudent : public Student //SUB-SUB CLASS.
{
private: //no need for protected bc final sub class.
    bool hasPocketProtector;
public:
    //constructor:
    GeekyStudent(int a, string n, double g, bool p): Student(a, n, g)
    {
        hasPocketProtector = p;
    }
    //virtual deconstructor:
    ~GeekyStudent()
    {
        cout << "Calling GeekyStudent child deconstructor" << endl;
    }
    void sayWhat() override final
    //also overridden from base class.
    //final keyword to let c++ know that it is the
    //last derived class.
    //no one should inherit from this sub class.
    {
        cout << "i am GeekyStudent named " << name << " & age of " << age << " w/ gpa of " << gpa << "& a pocket protector" << endl;
    }
}; //END SUB-SUB CLASS.

class Shape //single inheritance bc 2 sub classes derived from same base.
{
private:
    string name;
public:
    //constructor for Shape class.
    Shape(string n)
    {
        name = n;
    }
    //virtual deconstructor
    virtual ~Shape()
    //w/o 'vritual,' only base constructor called.
    //if we delete a child data type, we need to call both
    //base and child deconstrucor for proper deletion.
    {
        cout << "Calling Shape parent deconstructor" << endl;
    }
    //dummy/abstract/pure virtual function:
    virtual double getArea() = 0;
    
    //function conducting polymorphism.
    void printPricesSq(Shape &k)
    {
        cout << "cost is: $" << k.getArea() * 3.25 << endl;
    }
}; //close Shape class.

class Square: public Shape
{
private:
    int side;
public:
    //square constructor:
    Square(string x, int s):Shape(x)
    {
        side = s;
    }
    //Square deconstructor:
    ~Square()
    {
        cout << "Calling Square child deconstructor" << endl;
    }
    //overriding getArea() function from base.
    virtual double getArea()
    {
        return side * side;
    }
}; //close Square child class.

class Circle: public Shape
{
private:
    float radius;
public:
    //circle constructor:
    Circle(string x, float r):Shape(x)
    {
        radius = r;
    }
    //Circle deconstructor:
    ~Circle()
    {
        cout << "Calling Circle child deconstructor" << endl;
    }
    //overriding getArea from base.
    virtual double getArea()
    {
        return (3.14 * radius * radius);
    }
}; //close Circle child class.

int main()
{
    //1.1) create geekystudent object:
    GeekyStudent anthony(22, "Anthony", 3.8, true);
    
    //1.2) call anthony's say whatfunction:
    anthony.sayWhat();
     
    //divider:
    cout << "----------" << endl;
    
    //2.1) create circle object via ptr:
    Circle *cirOnePtr = new Circle("circleOne", 2);
    cout << cirOnePtr << endl; //0x6000028844e0
    cout << cirOnePtr->getArea() << endl; //12.56
    
    //2.2) polymorphism:
    cirOnePtr->printPricesSq(*cirOnePtr); //cost is: $40.82
    
    
    //2.3) use "delete" bc dynamic memory allocated via "new"
    Shape *shapePtr = cirOnePtr;
    delete shapePtr;
    
    return 0;
    //deconstructor for anthony object automatically called bc not using dynamically
    //allocated memory.
}
