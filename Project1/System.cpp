#include "System.h"
#include <random>
#include <fstream>
#include <string>
#include <sstream>

Employee* Editor::CreateNewEmployee() {

	int random;
	std::array<int, 3> data{};
	std::array<std::string, 2> info;

	std::cout << "Insert Employee's First Name: ";
	std::cin >> info[0];
	std::cout << "\nInsert Employee's Last Name: ";
	std::cin >> info[1];
	std::cout << "\nSelect Job Title: [0]Worker, [1]Manager: ";
	std::cin >> data[1];
	std::cout << "\nWhich Building?: ";
	std::cin >> data[2];
	std::cout << "\nGenerating new employee ID...";

	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(10000, 99999);
	random = dist6(rng);

	std::cout << "\nNew Employee ID: " << random << std::endl;
	data[0] = random;


	
	Employee* pEmployee = new Employee(data, info);
	
	return pEmployee;
}


void Editor::DeleteEmployee(int& command, System& system) {

	command -= 1;
	if (command < 0) command = 0;

	if (command > system.employeeIDs.size()) {
		std::cout << "\n Error cannot reference ID\n";
	}
	else if (system.employeeIDs.size() == 0) {
	}else{
		Employee* employeeID = system.employeeIDs[command];
		system.employeeIDs.erase(system.employeeIDs.begin()+command);
		delete employeeID;
	}


}


void Editor::ViewEmployeeNumber(int &command, System &system ) {

	command -= 1;
	if (command < 0) command = 0;

	if (command > system.employeeIDs.size()) {
		std::cout << "\nError: cannot reference ID\n";
	}
	else if (system.employeeIDs.size() == 0) {
	}else{
		Employee* employeeID = system.employeeIDs[command];

		std::cout << "\nFirst Name: " << employeeID->info[0];
		std::cout << "\nLast Name: " << employeeID->info[1];
		std::cout << "\nID: " << employeeID->data[0];
		std::cout << "\nJob Title: ";
		if (employeeID->data[1] == 0) std::cout << "Worker";
		else if (employeeID->data[1] == 1) std::cout << "Manager";
		std::cout << "\nBuilding Number: " << employeeID->data[2] << std::endl;
	}
}

void System::PushEmployeeID(Employee* id) {

	employeeIDs.push_back(id);
}

void System::CleanUpRAM() {
	 
	if (this->employeeIDs.size() != 0) {
		for (int i = 0; i < this->employeeIDs.size(); i++)
		{
			if (!this->employeeIDs[i] == 0) delete this->employeeIDs[i];
		}
	}
}

void System::WriteOut() {

	Employee* employeePtr = nullptr;

	std::ofstream outFile;
	outFile.open("data.txt");
	
	if (this->employeeIDs.size() == 0) {

	}
	else {

		for (int i = 0; i < this->employeeIDs.size(); i++)
		{
			employeePtr = employeeIDs[i];

			outFile << employeePtr->info[0] << std::endl
				<< employeePtr->info[1] << std::endl
				<< employeePtr->data[0] << std::endl
				<< employeePtr->data[1] << std::endl
				<< employeePtr->data[2] << std::endl;


		}

		employeePtr = nullptr;
	}
}

void System::WriteIn() {

	// Local Variables

	Employee* employeePtr = nullptr;
	std::string line;
	int i = 0;
	int dat;
	std::ifstream inFile;

	// ===========================


	inFile.open("data.txt");

	while(std::getline(inFile, line))
		if (line[0] == '#')
		{

		}
		else {
			
			std::stringstream stream(line);
			std::string chunk;
			

			while (stream >> chunk)
			{
		
				switch (i)
				{
				case 0:
					
					employeePtr = new Employee;
					this->PushEmployeeID(employeePtr);
					employeePtr->info[0] = chunk;
					break;

				case 1:

					employeePtr->info[1] = chunk;
					break;

				case 2:

					dat = std::stoi(chunk);
					employeePtr->data[0] = dat;
					break;

				case 3:

					dat = std::stoi(chunk);
					employeePtr->data[1] = dat;
					break;

				case 4:

					dat = std::stoi(chunk);
					employeePtr->data[2] = dat;
					break;

				}
				

				i++;
				if (i == 5) i = 0;

			}

		}


}