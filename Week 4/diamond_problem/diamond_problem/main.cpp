//1- diamond problem is an issue w/ multiple
    //inheritance.
//2- Person's attributes are passed down to Student
    //class and Professor class.
//3- TeachingAssistant class also gets Person's attributes.
//4- Should TA class inherit eat() function from Professor or Student class?
//5- Solution: Virtual Inheritance allows us to choose w/ :: operator.

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
    //create person object:
    Person alex("alex", 22);
    alex.degreeLevel();
    
    //create another person object:
    Person andrew("andrew", 22);
    andrew.degreeLevel();
    
    //create student object:
    Student jake("jake", 22, 3.2);
    jake.degreeLevel();
    
    //create professor object:
    Professor ambrosio("ambrosio", 35, 4);
    ambrosio.degreeLevel();
    
    //create another professor object:
    Professor moore("moore", 32, 6);
    moore.degreeLevel();
    
    //create TA object:
    TeachingAssistant moris("moris", 24, 2.2, 6, 3);
    //moris(name, age, gpa, tenure, program);
    //moris(person, person, student, professor, TA);
    //TeachingAssistant gets functions from Person and
        //Tenure and Gpa from Student and Professor. The
        //constructor of TA has to specify.
    moris.degreeLevel();
    cout << moris.name << endl; //need to use accessero function.
    cout << moris.age << endl; //need to use accessero function.
    cout << moris.gpa << endl; //need to use accessero function.
    cout << moris.tenure << endl; //need to use accessero function.
    
    //Diamon problem:
    //moris.eat(); 
    //ERROR bc TA does not know if to get
    //inherit the eat() from Professor or Student.
    
    //solution: "virtual" in Professor + Student Classes.
    //allows for TA object to specify from which class to
        //inherit the eat() function..see below:
    moris.Student::eat(); //Student just ate.
    moris.Professor::eat(); //Professor just ate.
    
    //RTTI Usage to get Type of objects:
    //I'm assuming the numbers infront = for categorization...ask professor??
    cout << endl << typeid(moris).name() << endl; //17TeachingAssistant
    cout << endl << typeid(ambrosio).name() << endl; //9Professor
    cout << endl << typeid(alex).name() << endl; //6Person
    cout << endl << typeid(andrew).name() << endl; //6Person
    cout << endl << typeid(moore).name() << endl; //9Professor


    return 0;
}

//Run-Time Type Information(RTTI):
//-the mechanism that exposes information about object's data type at runtime.
//-allows the type of an object to be determined during program execution.
//-RTTI only available for classes that have at least 1 virtual function(i.e degreeLevel() in Person class).
    //-makes sense bc only if virtual functions are
        //present is there any issue about the type of an
        //object being unknown.
    //-am i creating a Professor, Student or TA object?
    //-RTTI helps us identify the Object type for
        //debugging purposes.
    //-use "typeid"(<object>)
    //-returns a reference to a type_info object that has
        //information about the exact typeof the object.
    //-typeid is an operator, not a function.

//static_cast in inheritance:
//-static_cast<> can cast up or down, but is not checked.
