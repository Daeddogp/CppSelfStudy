//chapter 7. inheritance

#include <iostream>
#include <cstring>

using namespace std;

class Person {
private:
	//int age;
	char *name;

public:
	/*
	Person(int myage, char *myname) : age(myage) {
		strcpy(name, myname);
	}
	*/
	Person(char *myname) {
		name = new char[strlen(myname) + 1];
		strcpy(name, myname);
	}


	void WhatYourName() const {
		cout << "my name is " << name << endl;
	}

	~Person() {
		delete[]name;
	}

	/*
	void HowOldAreYou() const {
		cout << "I'm " << age << " years old" << endl;
	}
	*/
};

//inheritance example
class UnivStudent : public Person {
private:
	char *major;
public:
	UnivStudent(char *myname, char *mymajor)
		: Person(myname) {
		major = new char[strlen(mymajor) + 1];
		strcpy(major, mymajor);
	}

	void WhoAreYou() const {
		WhatYourName();
		//HowOldAreYou();
		cout << "my major is " << major << endl;
	}

	~UnivStudent() {
		delete[]major;
	}
};

int main(void) {
	/*
	UnivStudent ustd1("Jung", 22, "cse");
	ustd1.WhoAreYou();

	UnivStudent ustd2("mono", 21, "eee");
	ustd2.WhoAreYou();
	*/

	UnivStudent ustd1("manho", "cse");
	ustd1.WhoAreYou();

	UnivStudent ustd2("sangho", "physic");
	ustd2.WhoAreYou();

	return 0;
}