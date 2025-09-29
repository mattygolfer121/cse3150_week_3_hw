#include <iostream>
#include <cstring>   // for strlen, strcpy

// TODO: function prototypes
void addStudent(char* name, double gpa, char* names[], double gpas[], int& size, int capacity);
void updateGPA(double* gpaPtr, double newGpa);
void printStudent(const char* name, const double& gpa);
double averageGPA(const double gpas[], int size);
// TODO: implement addStudent
void addStudent(char* name, double gpa, char* names[], double gpas[], int& size, int capacity) {
	if (size >= capacity){
		const char* msg = "Too many students, gotta expel some bro.";
		throw msg;
	} else {
		names[size] = new char[std::strlen(name) + 1];
		std::strcpy(names[size], name);	
		gpas[size] = gpa;
		size++;
	}
}
// TODO: implement updateGPA
void updateGPA(double* gpaPTR, double newGPA){
	if (newGPA < 0){
		const char* msg = "New GPA value invalid.";
		throw msg;
	}
	*gpaPTR = newGPA;
}
// TODO: implement printStudent
void printStudent(const char* name, const double& gpa){
	if (name == nullptr) {
		const char* msg = "You got no students lol.";
		throw msg;
	} else {
		std::cout << name << ", " << gpa << std::endl;
	}
}
// TODO: implement averageGPA
double averageGPA(const double gpas[], int size){
	if (size <= 0) {
		const char* msg = "Not enough students to average man.";
		throw msg;
	} else {
		double sum = 0.0;
		for (int i = 0; i < size; i++){
			sum += gpas[i];
		}
		return sum / static_cast<double>(size);
	}
}
int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./program <capacity>" << std::endl;
        return 1;
    }

    int capacity = std::stoi(argv[1]);
    char* names[capacity];
    double gpas[capacity];
    int size = 0;
	
	
	
    int choice;
    do {
        std::cout << "Menu:\n";
        std::cout << "1. Add student\n";
        std::cout << "2. Update GPA\n";
        std::cout << "3. Print all students\n";
        std::cout << "4. Compute average GPA\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;
	
	
	// asked claude because my program was looping in on itself, said this line would fix it
	std::cin.ignore();
	
        switch (choice) {
            case 1: {
                // TODO: implement menu logic
		std::cout << "Enter Student Name: " << std::endl;
		std::string temp;
		std::getline(std::cin, temp);
		char *name = new char[std::strlen(temp.c_str()) + 1];
		std::strcpy(name, temp.c_str());
		
		std::cout << "Enter GPA: " <<std::endl;	
		double gpa;
		std::cin >> gpa;
		
		try {
			addStudent(name, gpa, names, gpas, size, capacity);
			delete[] name;
		} catch(const char* msg) {
			std::cout << msg << std::endl;
			delete[] name;
		}
		break;
            	}
            case 2: {
                // TODO: implement menu logic
		std::cout << "Enter Index of GPA to be Changed: " << std::endl;
		int index;
		std::cin >> index;
		if (index >= 0 && index < size){
			std::cout << "Invalid Index." << std::endl;
			break;
		}
		std::cout << "Enter New GPA: " << std::endl;
            	double newGPA;
		std::cin >> newGPA;
		
		try {
			updateGPA(&gpas[index], newGPA);
		} catch (const char* msg) {
			std::cout << msg << std::endl;
		}
		break;
		}
            case 3: {
                // TODO: implement menu logic
		try {
			for (int i = 0; i < size; i++){
				printStudent(names[i], gpas[i]);
			}
		} catch(const char* msg) {
			std::cout << msg << std::endl; 
		}
		break;	
            	}
            case 4: {
                // TODO: implement menu logic
                try {
			double avg = averageGPA(gpas, size);
			std::cout << static_cast<int>(avg) << std::endl;
		} catch(const char* msg) {
			std::cout << msg << std::endl;
		}
		break;
            }
            case 5: {
                std::cout << "Goodbye!" << std::endl;
                break;
            }
            default: {
                std::cout << "Invalid choice" << std::endl;
            }
        }
    } while (choice != 5);

    // TODO: free memory
	for (int i = 0; i < size; i++) {
		delete[] names[i];
	}
    return 0;
}
