#include<iostream>
using namespace std;

class Student {
	char* name;
	int age;
public:
	Student();
	Student(const char* name, int age);
	~Student();
	Student(const Student& obj2);
	int getAge();
	int setAge();
	void setName();
	void getName();
	void Print();
	void Input();
	Student& operator=(const Student& b);
};
Student::Student(const char* _name, int _age)
{
	age = _age;
	name = new char[strlen(_name) + 1];
	strcpy_s(name, strlen(_name) + 1, _name);
}
Student::Student()
{
	name = nullptr;
	age = 0;
}
Student::Student(const Student& obj2)
{
	age = obj2.age;
	if (name != nullptr) {
		delete[]name;
	}
	name = new char[strlen(obj2.name) + 1];
	strcpy_s(name, strlen(obj2.name) + 1, obj2.name);
	cout << "Copy const" << endl;
}
Student& Student::operator=(const Student& b) {
	if (this == &b) {
		return *this;
	}
	if (name != nullptr) {
		delete[]name;
	}
	age = b.age;
	name = new char[strlen(b.name) + 1];
	strcpy_s(name, strlen(b.name) + 1, b.name);
	cout << "Copy const" << endl;
}
Student::~Student()
{
	cout << "DESTRUCTOR" << endl;
	delete[] name;
}

void Student::Print()
{
	cout << "Name: " << name << endl << "Age: " << age << endl;
}

void Student::Input()
{
	char buff[100];
	cout << "Введите свое имя: ";
	cin >> buff;
	cout << "Введите свой возраст: ";
	cin >> age;
	if (name != nullptr) {
		delete[] name;
	}
	name = new char[strlen(buff) + 1];
	strcpy_s(name, strlen(buff) + 1, buff);
}
int Student::getAge()
{
	return age;
}
int Student::setAge()
{
	cout << "Ваш возраст: ";
	cin >> age;
	return 0;
}

void Student::setName()
{
	char buff[100];
	cout << "Ваше имя: ";
	cin >> buff;
	if (name != nullptr) {
		delete[] name;
	}
	name = new char[strlen(buff) + 1];
	strcpy_s(name, strlen(buff) + 1, buff);
}

void Student::getName()
{
	cout << "Name: " << name;
}

int main()
{
	Student a("Zachry", 17);
	Student b = a;
	b.Print();
}