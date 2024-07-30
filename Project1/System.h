#pragma once
#include "Employee.h"
#include <vector>

class System {
public:
	System() { mainLoop = true; }
	~System(){}

	bool mainLoop;
	std::vector<Employee*> employeeIDs;
	void CleanUpRAM();
	void PushEmployeeID(Employee* id);
	void WriteOut();
	void WriteIn();

};


class Editor{
public:
	Editor() {}
	~Editor(){}
	
	Employee* CreateNewEmployee();
	void ViewEmployeeNumber(int &command, System &system);
	void DeleteEmployee(int& command, System& system);

};
