#include <iostream>

#define DEG2MIN 60
#define SEC2MIN 3600

int main(int argc, int *argv[]) {
	
	int degrees, minutes, seconds;
	double lat;
	std::cout << "Enter a latitude in degrees, minutes, and seconds:" << std::endl;
	std::cout << "First, enter the degrees: ";
	std::cin >> degrees;
	std::cout << "Second, enther the minutes of arc: ";
	std::cin >> minutes;
	std::cout << "Finally, enter the seconds of arc: ";
	std::cin >> seconds;

	lat = (double)degrees + ((double)minutes / DEG2MIN) + ((double)seconds / SEC2MIN);

	std::cout << degrees << " degrees, " << minutes << " minutes, " << seconds << " seconds = " << lat << " degrees";

	return 0;
}