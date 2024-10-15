//-Casting in inheritance:
    //1.the process of converting a pointer or reference of a
    //base class to a pointer or reference of a derived
    //class, or vice versa.
    //2.
    //3.this allows us to treat objects of different types
    //in a uniform manner.
//-Upcasting
    //converting a derived class ptr to a base class ptr.
        //generally safe & done implicitly by compiler.
    //can use operator static_cast.
    //cannot use operator dynamic_cast.
//-Downcasting
    //converting a base class ptr to a derived class ptr.
        //dangerous bc compiler cannot always guarantee the
        //validity of the conversion.
        //explicit casting operators required.
    //can use operator static_cast for safe downcasting.
    //can use operator dynamic_cast for safe downcasting.
#include <iostream>
#include <typeinfo>
using namespace std;

class Person
{
public:
    string name;
    int age;
public:
    //constructor:
    Person(string n, int a)
    {
        name = n;
        age = a;
    }
    //deconstructor:
    ~Person()
    {
        cout << "Person deconstructor called." << endl;
    }
    //function that will be overridden in children:
    virtual void degreeLevel()
    {
        cout << "high school degree" << endl;
    }
    
}; //close Person class.

class Student: virtual public Person
{
public:
    float gpa;
public:
    //constructor:
    Student(string n, int a, float g): Person(n, a)
    {
        gpa = g;
    }
    //deconstructor:
    ~Student()
    {
        cout << "Student deconstructor called." << endl;
    }
    //function has to be override/specialized:
    void degreeLevel() override
    {
        cout << "associates degree" << endl;
    }
    //eat() function:
    void eat()
    {
        cout << "Student just ate." << endl;
    }
}; //close Student class.

class Professor: virtual public Person
{
public:
    int tenure;
public:
    //constructor:
    Professor(string n, int a, int t): Person(n, a)
    {
        tenure = t;
    }
    //deconstructor:
    ~Professor()
    {
        cout << "Professor deconstructor called." << endl;
    }
    //function has to be override/specialized:
    void degreeLevel() override
    {
        cout << "PHD degree" << endl;
    }
    //eat() function:
    void eat()
    {
        cout << "Professor just ate." << endl;
    }
    
}; //close Professor class.

class TeachingAssistant: public Student, public Professor
{
public:
    int program;
public:
    //constructor:
    TeachingAssistant(string n, int a, int g, int t, int p): Person(n, a), Student(n, a, g), Professor(n, a, t)
    {
        program = p;
    }
    //deconstructor:
    ~TeachingAssistant()
    {
        cout << "TA deconstructor called" << endl;
    }
    //function has to be override/specialized:
    void degreeLevel() override
    {
        cout << "BA degree" << endl;
    }
}; //close TeachingAssistant class.

int main()
{
    //upcasting example:
    Person *ptrBase; //ptr pointing to undefined Person object.
    Student alex("alex", 25, 3.2); //create Student object.
    ptrBase = &alex; //base ptr is now pointing to a child object.
    ptrBase->degreeLevel(); //gets function from Student class.
    
    //downcasting example:
    Person *ptrBaseTwo = new Student("milo", 20, 2.3);
    //Base ptr points to a Child object(legal).
    Student *ptrChildTwo = dynamic_cast<Student*>(ptrBaseTwo);
    //Child ptr points to Base object (illegal but dynamic_cast makes exception)
    //convert a Student ptr to a Base one.
    //allow a child ptr to point to a Base object.
    //ptrChildTwo not points to whatever ptrBaseTwo is pointing to.
    ptrChildTwo->degreeLevel(); //gets Student version.
    ptrBaseTwo->degreeLevel(); //gets Student version, thought it'd get Person version.
    cout << ptrChildTwo->gpa << endl; //2.3
    cout << ptrBaseTwo->name << endl; //milo
    
    //**important: if a program needs to use downcasting, it probably is a improperly designed. 
    return 0;
}
