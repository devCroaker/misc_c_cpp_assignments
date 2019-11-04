#include "Matrix.h"

void populate(std::string file);
void getMatrixFromFile(std::string file);

int main(int argc, char* argv[]) {
	float num = 2.1;
	num++;
	std::string file = "";

	if (argc > 1) {
		file = argv[1];
	}

	populate(file);

	return 0;
}

void populate(std::string file) {
	Input input;
	char option = 'n';

	if (file == "") {
		do {
			option = input.get("Get matrix from a file? (Y/N)", option);
			option = toupper(option);
			if (option != 'Y' && option != 'N') {
				std::cout << "Invalid Input" << std::endl;
			}
		} while (option != 'Y' && option != 'N');

		if (option == 'N') {
			std::cout << "Just kidding I dont want to build this..." << std::endl;
		}

		file = input.getStr("Please input the file name:");
		getMatrixFromFile(file);
	}
	else {
		getMatrixFromFile(file);
	}
}

void getMatrixFromFile(std::string file) {

	std::ifstream matrixFile(file);
	std::string line, token;
	size_t pos = 0;

	std::getline(matrixFile, line);

	int size = stoi(line);
	Matrix matrix1(size), matrix2(size);

	for (int i = 0; i < size; i++) {
		std::getline(matrixFile, line);
		for (int j = 0; j < size; j++) {

			pos = line.find(" ");
			matrix1.matrix[i][j] = stoi(line.substr(0, pos));
			line.erase(0, pos + 1);

		}
	}

	std::getline(matrixFile, line);
	pos = line.find(" ");
	line.erase(0, pos + 1);
	matrix1.operation = stoi(line);
	if (stoi(line) < 4 || stoi(line) == 7) {
		for (int i = 0; i < size; i++) {
			std::getline(matrixFile, line);
			for (int j = 0; j < size; j++) {

				pos = line.find(" ");
				matrix2.matrix[i][j] = stoi(line.substr(0, pos));
				line.erase(0, pos + 1);

			}
		}
		matrix1.next = &matrix2;
	}

	switch(matrix1.operation) {
		case 1:
		{
			Matrix matrix3 = matrix1 + matrix2;
			std::cout << matrix3;
			break;
		}
		case 2:
		{
			Matrix matrix3 = matrix1 - matrix2;
			std::cout << matrix3;
			break;
		}
		case 3:
		{
			Matrix matrix3 = matrix1 * matrix2;
			std::cout << matrix3;
			break;
		}
		case 4:
		{
			matrix1++;
			std::cout << matrix1;
			break;
		}
		case 5:
		{
			matrix1--;
			std::cout << matrix1;
			break;
		}
		case 6:
		{
			Matrix matrix3 = ~matrix1;
			std::cout << matrix3;
			break;
		}
		case 7:
		{
			Matrix matrix3 = matrix1 ^ matrix2;
			std::cout << matrix3;
			break;
		}
		case 8:
			std::cout << matrix1;
			break;
		default:
			break;
	}

}