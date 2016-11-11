//ch 7. inheritance

#include <iostream>

using namespace std;

//base class ( = super class, parent class)
class SoBase {
private:
	int base_num;
public:
	SoBase() : base_num(20) {
		cout << "SoBase()" << endl;
	}

	SoBase(int n) : base_num(n) {
		cout << "Sobase(int n)" << endl;
	}

	void ShowBaseData() {
		cout << base_num << endl;
	}

	~SoBase() {
		cout << "~SoBase() : " << base_num << endl;
	}
};

//derived class ( = sub class, child class)
class SoDerived : public SoBase {
private:
	int derive_num;
public:
	SoDerived() : derive_num(30) {
		cout << "SoDerived()" << endl;
	}

	SoDerived(int n) : derive_num(n) {
		cout << "SoDerived(int n)" << endl;
	}

	SoDerived(int n1, int n2) : SoBase(n1), derive_num(n2) {
		cout << "SoDerived(int n1, int n2)" << endl;
	}

	void ShowDeriveData() {
		cout << derive_num << endl;
	}

	~SoDerived() {
		cout << "~SoDerived() : " << derive_num << endl;
	}
};

int main(void) {
	
	cout << "case 1 " << endl;
	SoDerived dr1;
	dr1.ShowDeriveData();
	//dr1.ShowBaseData();
	cout << endl;

	cout << "case 2 " << endl;
	SoDerived dr2(12);
	dr2.ShowDeriveData();
	//dr2.ShowBaseData();
	cout << endl;

	cout << "case 3 " << endl;
	SoDerived dr3(22, 33);
	dr3.ShowDeriveData();
	//dr3.ShowBaseData();
	cout << endl;

	return 0;
}

//derived class call base class's constructor and derived class's constructor