//chapter 7. inheritance

#include <iostream>
#include <string>

using namespace std;

//worker info (data)
class PermanentWorker {
private:
	char name[100];
	int salary;

public:
	PermanentWorker(char *name, int money)
		: salary(money) {
		strcpy(this->name, name);
		}

	int GetPay() const {
		return salary;
	}

	void ShowSalaryInfo() const {
		cout << "name : " << name << endl;
		cout << "salary : " << GetPay() << endl << endl;
	}
};

//worker handler (control class = OOP key point)
class EmployeeHandler {
private:
	PermanentWorker *emp_list[50];
	int emp_num;

public:
	EmployeeHandler() : emp_num(0) {

	}

	void AddEmployee(PermanentWorker *emp) {
		emp_list[emp_num++] = emp;
	}

	void ShowAllSalaryInfo() const {
		for (int i = 0; i < emp_num; i++) {
			emp_list[i]->ShowSalaryInfo();
		}

	}

	void ShowTotalSalary() const {
		int sum = 0;
		for (int i = 0; i < emp_num; i++) {
			sum += emp_list[i]->GetPay();
			cout << "salary sum : " << sum << endl;
		}
	}

	~EmployeeHandler() {
		for (int i = 0; i < emp_num; i++) {
			delete emp_list[i];
		}
	}
};

int main(void) {

	//for managing workers, make hanler
	EmployeeHandler handler;


	handler.AddEmployee(new PermanentWorker("Jung", 1000));
	handler.AddEmployee(new PermanentWorker("Man", 2000));
	handler.AddEmployee(new PermanentWorker("Ho", 3000));

	handler.ShowAllSalaryInfo();

	handler.ShowTotalSalary();

	return 0;

}

// Problem : if you add sale worker and temporary worker, you will fix all about this source
//			 that is not good program (not flexible)
// Solution : using inheritance