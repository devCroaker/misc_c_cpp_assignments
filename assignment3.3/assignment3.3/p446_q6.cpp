#include <iostream>
#include <string>

template<typename T>
T maxn(T[], int);

template<>
const char* maxn<const char*>(const char*[], int);

int main(int argc, char *argv[]) {

	int intArr[6] = {
		2,4,6,1,3,5
	};
	double dubArr[4] = {
		3.44,1.22,4.55,2.33
	};
	const char *strArr[] = {
		"One",
		"Two",
		"Three",
		"Four",
		"Five"
	};

	std::cout << "Max int is: " << maxn(intArr, 6) << std::endl;
	std::cout << "Max Double is: " << maxn(dubArr, 4) << std::endl;
	std::cout << "Longest String Address is: " << maxn(strArr, 5) << std::endl;

	return 0;
}

template<typename T>
T maxn(T arr[], int num) {

	T max = arr[0];
	for (int i = 0; i < num; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}

	return max;

}

template<>
const char* maxn<const char*>(const char * arr[], int num) {

	const char* max = arr[0];

	for (int i = 0; i < num; i++) {
		if (strlen(arr[i]) > strlen(max)) {
			max = arr[i];
		}
	}

	return max;

}
