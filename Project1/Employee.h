#pragma once
#include <array>
#include <iostream>

class Employee {
public:

	Employee() {}

	Employee(std::array<int, 3>& rdata, std::array<std::string, 2>& rinfo) {

		data[0] = rdata[0];
		data[1] = rdata[1];
		data[2] = rdata[2];
		info[0] = rinfo[0];
		info[1] = rinfo[1];

	}

	~Employee() {
		std::cout << "\n Employee Data Cleared: " << data[0] << " , Memory Address: " << this;
	}

	// data:	 [0] ID,	[1] JobTitle,	[2] BuildingNumber
	std::array<int, 3> data;

	// info:	 [0] FirstName,	[1] LastName
	std::array<std::string, 2> info;

};