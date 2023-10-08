#include <iostream>;
// #include "headerFile.h"; // to include the header file defined in the headers

/**************************************************************************
*                                structs                                  *
***************************************************************************/
using namespace std;
// useful for implementing simple models
// members in struct are public by default.
struct Employee {
	int id;
	const char* name;
	const char* role;
};

// define a struct object and use it.
int practice_struct() {
	Employee joe = { 42, "Joe", "Boss" };
	Employee empty = {};

	printf("%s is the %s and has id %d\n", joe.name, joe.role, joe.id);

	return 0;
}

/**************************************************************************
*                                enumerations                             *
***************************************************************************/
/*
A: The cool thing about enums is that methods or classes that use them are protected from any values not defined in the enum.
So you can't misspell or mistype an enum without getting a compiler error. 
It's a great way to get not only type safety, but value safety; 
you can avoid getting bad data for anything that has a standard range or set of legal values.
*/

// a consecutive list of constants 
// provides encapsulations for 

enum cow_purpose { diary, meat, pet, hide };

struct cow {
	string name;
	int age;
	unsigned char purpose;
	cow_purpose purpose_name;
};

int practice_struct_with_enum() {
	cow Cow;
	Cow.age = 12;
	Cow.name = "Betsy";
	Cow.purpose = 0;
	Cow.purpose_name = diary; // cannot assign int. should use the enum value 
	cout << "Cow name: " << Cow.name
		<< " Cow age: " << Cow.age
		<< " Cow purpose: " << (int)Cow.purpose
		<< " Cow purpose name: " << Cow.purpose_name
		<< endl;
	cout << "Cow name: " << Cow.name
		<< " Cow age: " << Cow.age
		<< " Cow purpose: "
		<< (cow purpose)Cow.purpose
		<< " Cow purpose name: " << Cow.purpose_name
		<< endl;
	return 0;
}



/**********************************************************************
*                                    union                            *
**********************************************************************/
union ipv4 {
	uint32_t i32;
	struct {
		uint8 t a;
		uint8 t b;
		uint8 t c;
		uint8 t d;
	} octets;
};

int practice_union() {
	union ipv4 addr;
	addr.octets = { 192, 168, 73, 42 };
	printf("addr is %d.%d.%d.%d is %08x\n",
		addr.octets.a, addr.octets.b, addr.octets.c, addr.octets.d, addr.i32);
	return 0;
}

/************************************************************************
*                   			class                                   *
*************************************************************************/
// basic elements of object-oriented programming 
// useful for implementing models 
// classes have two members: data, functions 
// there is implicitly a constructor that allocates memory for data members 


class C {
private:
	int i = 0; // (classifier) members without classifier are by default private in classes.
	const char* myString = ""; // (const) can assign to it from outside the class multiple times only through setter.. 
	// ..cannot assign to it directly from outside if it is const... I tried that it still can change.

public:
	void setvalue(int value) { i = value; } // setter 
	int getvalue() { return i; }            // getter
	int getvalue() const { return i; } // (const safe function). means it can be used in a const context from the object interface.
	void setMyString(const char* str) { myString = str; };
	const char* getMyString() const { return myString; };
};
	
class B {
private:
	int a;
	int b;
	const char* c = "";

public:
	void setA(int av) { a = av; };
	void setB(int bv) { b = bv; };
	void setC(const char* cv) { c = cv; };
	int getA() { return a; };
	int getB() { return b; };
	const char* getC() { return c; };
	const char* getC() const { return c; }
	/* (const safe function) you have to create two getters for the data members if
	   you want to get the data members of a const instance of the class..
	   bottom line is that a getter with const safe qualifier can be used with getting
	   data member of const instance or not const instance
	   whereas a const object data member can only be get with const get qualifier
	   (you have to create a const getter if you want to create a const object)
	*/
};

	   
class A {
private:
	int i;

public:
	explicit A(int); // explicit constructor. the explicit keyword is to prevent any explicit conversion. 
	int geti();
};

A::A(int j) 
{ 
	i = j; 
}

int A::geti() {
	return i;
}

int practiceclassl() {
	// class c 
	int i = 47;
	C ol; // (creating instance) can create an object of the class without the new key word but this will be 
	// created in the stack memory not the dynamic memory of the program.
	// (implicit constructor) in fact this is using the implicit constructor.
	ol.setvalue(i);
	printf("value is %d\n", ol.getvalue());

	C c2;
	c2.setMyString("My name is Raid");
	cout << "class 2 string: " << c2.getMyString() << endl;
	c2.setMyString("Changine it");
	cout << "class 2 string: " << c2.getMyString() << endl;

	// class b 
	B bl;
	bl.setA(1);
	bl.setB(1);
	bl.setC("Raid");

	const B b2 = b1;       // copy constructor using the implicit copy constructor.
	// b2.setA(1)          // (const) will not work because the qualifier of the object is const so needs setters and getters and functions to be coast safe (with coast qualifier).   
	// b2.setB(1);         // (const) will not work also. 
	// b2.setC("Basheer.); // (const) will not work also. 
	cout << "b2 string getter: " << b2.getC() << endl; // it works because there is a getter with const. 
	const B b3 = bl;       // (copy operator) implicit copy operator 

	// at the end of the program running, the objects will be destructed using the implicit destructor. 

	return 0;
}

int practice_class_2() {
	A a m A(1); // = 'x'; // implicit conversion from char to int (if there is only one data member). to stop this use explicit to prevent the implicit conversion. 
	cout << "a value: " << a.geti() << endl;
	return 0;
}
	
// **************
// Example 2    *
// **************
const string unk = "unknown"; 
const string clone_prefix = "clone-";

// -- interface ---
class Animal {
	string _type = "";
	string _name = "";
	string _sound = "";

public:
	Animal(); // default constructor // usually implicit 
	Animal(const string& type, const string& name, const string& sound); // explici constructor // with arguments // check the implementation. 
	Animal(const Animal&); // copy constructor // usually implicit 
	Animal& operator = (const Animal&); // copy operator // usually implicit 
	~Animal(); // destructor 

	void print() const;
};

// -- implementation -- 
Animal::Animal() : _type(unk), _name(unk), _sound(unk) {
	puts("default constructor");
}					  

Animal::Animal(const string& type, const string& name, const string& sound) // implementation of the explicit constructor. 
	: _type(type), _name(name), _sound(sound) {
	puts("constructor with arguments");
}

Animal::Animal(const Animal& rhs) {
	puts("copy constructor");
	_name = clone_prefix + rhs._name;
	_type = rhs._type;
	_sound = rhs._sound;
}

Animal:: ~Animal() {
	printf("destructor: %s On the %s\n", _name.c_str(), _type.c_str());
}

void Animal::print() const {
		printf("%s the %s says %s\n", _name.c_str(), _type.c_str(), _sound.c_str()); 
} 

Animal& Animal::operator = (const Animal& rhs) {
	puts("copy operator");
	if (this != &rhs) {
		_name = clone_prefix + rhs._named;
		_type = rhs._type;
		_sound = rhs._sound;
	}
	return *this;
}

int practice_class_3() {
	Animal a;
	a.print();

	const Animal b("cat", "fluffy", "meow");
	b.print();

	const Animal c = b;
	c.print();

	// using new and delete. 
	Animal* al = new Animal;
	Animal* aarr = new Animal[4]; // the constructor will be called 4 times. 
	delete al;
	delete[] aarr; // destructor will be called 4 times. have to use the delete, otherwise it will leak memory
	Animal* a2 = new(nothrow) Animal; // to avoid throwing error if constructing failed. 
	if (a2 = nullptr) {
		cout << " it is empty" « endl;
	}

	return 0;
}

// Inheritance 
// simple-inheritance.cpp by Bill Weinman <http://bw.org/> 
// 2018-10-08 

#include <iostream> 
#include <string> 

using namespace std;

// Fur  
class Fur {

	string fur_name;

};

// Animal class (base) 
class Animal3 {
	string _name;
	string _type;
	string _sound;

	// private constructor prevents construction of base class 
	Animal3() {}

	friend class Dog; // friend classifier grants friend classes access to private members. // not recommended though 
	friend class Cat;
protected:
	// protected constructor for use by derived classes 
	Animal3(const string& n, const string& t, const string& s)
		: _name(n), _type(t), _sound(s) {}

public:
	void speak() const;
	const string& name() const { return _name; }
	const string& type() const { return _type; }
	const string& sound() const { return _sound; }
};

void Animal3::speak() const {
	printf("%s the %s says %s\n", _name.c_str(), _type.c_str(), _sound.c_str());
}

// Dog class - derived from Animal 
class Dog : public Animal3, public Fur { // multiple inheritance. you need to consider if this is used because it adds complexity to your program. 
	int _walked;

public:
	Dog(string n) : Animal3(n, "dog", "woof"), _walked(0) {};
	int walk() { return ++_walked; }
};

// Cat class - derived from Animal 
class Cat : public Animal3 {
	int _petted;
public:
	Cat(string n) : Animal3(n, "cat", "meow"), _petted(0) {};
	int pet() { return ++_petted; }
};

// Pig class - derived from Animal 
class Pig : public Animal3 {
	int _fed;
public:
	Pig(string n) : Animal3(n, "pig", "oink"), _fed(0) {};
	int feed() { return ++_fed; }
};

int main_dt_complex_inheritance() {
	Dog d("Rover");
	Cat c("Fluffy");
	Pig p("Arnold");

	d.speak();
	c.speak();
	p.speak();

	cout << "the " << d.type() << " has been walked " << d.walk() << " times" << endl;
	cout << "the " << c.type() << " has been petted " << c.pet() << " times" << endl;
	cout << "the " << p.type() << " has been fed " << p.feed() << " times" << endl;

	return 0;
}

/************************************************************************
*                   	   Global Function                              *
*************************************************************************/
/* commented to avoid conflict with header for example 
void initialize();

StudentRecords SR; 
int id;

int main() { 
	initialize();

	cout << "Enter a student ID: "; 
	cin >> id; 
	
	SR.report_card(id); 
	
	return (0);
}

void initialize() { 
	SR.add_student(1, "George P. Burdell"); 
	SR.add_student(2, "Nancy Rhodes");

	SR.add_course(1, "Algebra", 5); 
	SR.add_course(2, "Physics", 4); 
	SR.addcourse(3, "English", 3); 
	SR.addcourse(4,"Economics",4);

	SR.add_grade(1, 1, 'B'); 
	SR.add_grade(1, 2, 'A'); 
	SR.add_grade(1, 3, 'C'); 
	SR.add_grade(2, 1, 'A'); 
	SR.add_grade(2, 2, 'A'); 
	SR.add grade(2, 4, 'B');
	}
*/
