// CSCN73030-Asn2-KennethT
// September 2023

#include <iostream>
#include "Source.h"

int studentDataToVector()
{
    // Student Data Vector
    std::vector<STUDENT_DATA> studentVector;

    // Open StudentData.txt
    std::ifstream inputFile("StudentData.txt");

    // Error check for the file
    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open input file." << std::endl;
        return 1; // Exit with an error code
    }

    std::string line; // Variable to store each line temporarily 

    // Parse each line in the file
    while (std::getline(inputFile, line)) {

        // Find each comma
        size_t commaPosition = line.find(',');

        // Split the line into first and last name
        std::string first_name = line.substr(0, commaPosition);
        std::string last_name = line.substr(commaPosition + 1);

        // Create a student object and add the data
        STUDENT_DATA student;
        student.firstName = first_name;
        student.lastName = last_name;

#ifdef _DEBUG
        // Display Student Data
        std::cout << student.firstName << student.lastName << std::endl;
#endif

        // Push into vector space
        studentVector.push_back(student);
    }

    // Close the input file
    inputFile.close();

    return 0;
}


int main()
{
    studentDataToVector();

	return 1;
}
