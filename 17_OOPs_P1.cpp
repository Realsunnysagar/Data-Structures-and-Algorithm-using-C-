/*
Object Oriented programming
- style of writing code
1.Classes(blueprint of obj, group of these entities) & Objects(entities in the real world)
    -propertise/attribute and Functions/ member function / methods
    - 
2.Access Modifiers
    1.Private : data & methods accessible inside class (also accessible in friend function) {sesitive data needs to be here}
    2.Public : data & methods accessible to everyone 
    3.Protected : data & methods accessible inside class & to its derived class
    -By default everything is private
3.Getters & Setters
    - special methods with class 
    - we dont want to give direct access of some properties(like cgpa) to main function therefore for to get that indirectly we create a function generally called as getters and setters
    - 
4.Four pillars of OOPs
    Encapsulation -*is wrapping up of data & member functions (methods) in a single unit. It also implements data hiding(using access modifiers).
                  -binding the data and methods all together like a capsule
    Abstraction - hidding the irrelevant data
    Inheritence - inheriting the properities of different  classes in java multiple inheritence is not there.
    Polymorphism - having different forms at different point of time. Two types compile time and runtime polymorphism.
5.Constructor
    -Special method invoked automatically at time of object creation. Used for Initialisation.
    *Same name as Class
    *Constructor doesn't have a return type
    *Only called once (automatically), at object creation
    *Memory allocation  happens when constructor is called
    -during creation of obj it is called
6.this pointer
    - this is a special pointer in C++ that points to the current object.
    - this->prop is same as *(this).prop
    - c1.name == *this.name
    - this pointer created automatically 
7.Types of Constructors
    1.Non parameterized constructors
    2.Parameterized constuctors
    - In a class it is possible to write multiple constructors with different in parameters
    - this is called Constructor Overloading
    3.Copy constructors
        -Special Constructor (default) used to copy properties of one object into another object.
        -Car c2(c1)
        -In memory same size of space will be created and features will be copied
        -We can custom copy constructor
            Car(Car &original){             //& original is reference of obj original
                cout <<"coping..\n";
                name = original.name;
                price = original.price;
                }
8.Shallow & Deep Copy
    - Shallow copy copies references to original array/dynamically allc mem. But array remains same. {like pointing to the same address of an array created in heap memory}
    - Deep copy created a brand new copy of the array.
    - Compiler generally creates a shallow copy for array or for anything dynamically allocated.
    - if we will make changes to address or reference of one then it will be reflected to other
    - We need to define own copy constructor when deep copy is needed i.e. when classs contains pointers to dynamically allocated memory.
    - In deep copy -> we will 1st make copy of arr in heap memory itself and address will be pointed by copied obj
            mileage = new int;
            *mileage = *original.mileage;    //we will write it in copied const. instead of general statement
9.Destructor
    ~ClassName(){ }
    - deallocate memory from the object 
    - opposite of constructor, it is also done automatically
    - custom destructor for : dynamically allocated memory to deallocate it explicitly
    - static memory will be deleted automatically but in heap memory the dynamic allocation will not be deleted automatically which leads to a Memory Leak
10.Inheritance
    -When properties & member function of base class are passed on to the derived class.
    -
*/

#include <bits/stdc++.h>
using namespace std;

class Student { //class is a blueprint for the object
    //propertise
    string name;
    float cgpa;

    //method
    public:
    void getPercentage(){
        cout<<(cgpa*10)<< "% \n";
    }

    // setters
    void setName(string nameVal){
        name = nameVal;
    }
    void setCgpa(float cgpaVal){
        cgpa = cgpaVal;
    }

    // getters
    string getName(){
        return name;
    }
    float getCgpa(){
        return cgpa;
    }
};

class Car{
    string name;
    string color;
    int *mileage;
public: 
    Car(string name, string color){
        cout<<"Construction is callled, object being created..\n";
        // name = nameValue;
        this->name = name; //here this will point to object 
        // color = colorValue;
        this->color = color;
        mileage = new int; //Dynamic allocation
        *mileage = 12;
    }

    Car(Car &original){
        cout<<"copying original to new..\n";
        name = original.name;
        color = original.color;
        mileage = original.mileage; // here it means that memory address of mileage will be copied to the copied obj there will no new memory allocation
    }
    void start(){
        cout<<"car has started..\n";
    }
    void step(){
        cout<<"car has stopped.\n";
    }
    //getter
    string getName(){
        return name;
    }
    ~Car(){     //Destructor
        cout<<"deleting object..\n";
        if(mileage != NULL){
            delete mileage;
            mileage = NULL;
        }
    }
};

int main() {
    Student s1; // object
    // we set 
    s1.setName("Sunny");
    s1.setCgpa(9.1); 

    // we get
    cout<<s1.getName()<<endl;
    cout<<s1.getCgpa()<<endl;

    cout<<sizeof(s1)<<endl;

    Car c1("maruti 800", "white");
    cout<<"car name is:"<<c1.getName()<<endl;

    Car c2(c1); //copy constructor 
    cout<<c2.getName()<<endl;


return 0; 
}