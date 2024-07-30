#include "System.h"


int main() {

	System MainSystem;
	Editor MainEditor;


	MainSystem.WriteIn();

	std::cout << "############################################\n" <<
		" Welcome to the Employee Management Systems \n" <<
		"############################################\n";

	while (MainSystem.mainLoop == true) {

		int command = 0;
		Employee* PushId = nullptr;
		std::cout << "Please enter a command: \n[0]: Save Data and Exit [1]: Create New Employee [2] View Employee [3] Delete Employee\n";
		std::cin >> command;

		switch (command)
		{
		case 0:
			MainSystem.mainLoop = false;
			break;

		case 1:
			PushId = MainEditor.CreateNewEmployee();
			MainSystem.PushEmployeeID(PushId);
			PushId = nullptr;
			break;

		case 2:
			std::cout << "Which Employee Number?: " << std::endl;
			std::cin >> command;
			MainEditor.ViewEmployeeNumber(command, MainSystem);
			break;

		case 3:
			std::cout << "Which Employee Number?: " << std::endl;
			std::cin >> command;
			MainEditor.DeleteEmployee(command, MainSystem);
			break;
		}

	}
		
		MainSystem.WriteOut();
		MainSystem.CleanUpRAM();
		return 0;

}