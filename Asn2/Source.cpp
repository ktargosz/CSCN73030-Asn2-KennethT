// CSCN73030-Asn2-KennethT
// September 2023

#include <iostream>
#include "Source.h"

#define PRE_RELEASE

int studentDataToVector()
{
    // Student Data Vector
    std::vector<STUDENT_DATA> studentVector;

    // Open StudentData.txt

#ifdef PRE_RELEASE
    std::ifstream inputFile("StudentData_Emails.txt");
#else
    std::ifstream inputFile("StudentData.txt");
#endif

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
        std::string firstName = line.substr(0, commaPosition);
        std::string lastName = line.substr(commaPosition + 1);

        // Create a student object and add the data
        STUDENT_DATA student;
        student.firstName = firstName;
        student.lastName = lastName;

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
#ifdef PRE_RELEASE
    std::cout << "Running Pre-Release Source Code" << std::endl;
#else
    std::cout << "Running Standard Source Code" << std::endl;
#endif

    studentDataToVector();

	return 1;
}
