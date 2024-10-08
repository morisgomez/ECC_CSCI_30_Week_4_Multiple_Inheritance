//multiple inheritance concepts:

//- 1 class derives from many base classes.
//e.g Student & Professor = bases.
//Studious Professor = derived class.

//- 2 ex. code of StudiousProfessor class"
//class StudiousProfessor: public Student, public Professor
//{};

//- characteristics:
//derived class objects has member variables of 1st base, followed by 2nd base.
//derived class = both sets of member functions.
//base constructors run in declaration order.
//class A, Class B, Class C:BA
    //constructors: CBA
//base destructors in reverse declaration order.
    //deconstructors: ABC

#include <iostream>
using namespace std;

class Mother
{
public:
    int age;
public:
    //constructor:
    Mother(int a)
    {
        
        age = a;
        cout << "Mother constructor called." << endl;
    }
    //deconstructor:
    ~Mother()
    {
        cout << "Mother deconstructor called." << endl;
    }
}; //close Mother base class.

class Father
{
public:
    int height;
public:
    //constructor:
    Father(int h)
    {
        height = h;
        cout << "Father constructor called." << endl;
    }
    //deconstructor:
    ~Father()
    {
        cout << "Father deconstructor called." << endl;
    }
    //func
    virtual void fatherMove()
    {
        cout << "father just moved" << endl;
    }
}; //close Father base class.

//derived class:
class Child: public Father, public Mother
{
public:
    string eyes;
public:
    //constructor:
    Child(string e, int h, int a): Father(h), Mother(a)
    {
        eyes = e;
        cout << "child constructor called" << endl;
    }
    //deconstructor:
    ~Child()
    {
        cout << "child deconstructor called" << endl;
    }
    //overriding fatherMove() function:
    void fatherMove() override
    {
        cout << "child just moved" << endl;
    }
}; //close Child derived class.

int main()
{
    Child childOne("green", 25, 182);
    cout << childOne.height << endl;
    cout << childOne.age << endl;
    cout << childOne.eyes << endl;
    childOne.fatherMove(); //can make a func from a base class a virtual one for specializaion in child.
    childOne.Father::fatherMove();
    //constructors called in Father, Mother and Child
    //order.
    //bc Child class declared in Child, Father, Mother
    //order.
    //deconstructors called in Child, Mother and Father
    //order.
    
    
    //NOTE:* Mix-in / combination:
    //1. bases are orthogonal (nothing in common)
    //2. Base are used to add functionialy to child.
    //3. we can combine / mix the derivation of classes to
    //change functionality of a child class.
    
    
    
    //questions for professor?
    //what is the dynamic_cast topic about?
}
