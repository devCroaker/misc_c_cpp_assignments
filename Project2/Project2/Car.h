#ifndef CAR_H
#define CAR_H

class Car
{
public:
	Car();
	Car(double speed);

	void set_max_speed();
	double get_speed()const;

private:
	double speed1;
};

#endif