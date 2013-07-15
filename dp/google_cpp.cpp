/*
 * google_cpp.cpp
 *
 *  Created on: 2013Äê7ÔÂ14ÈÕ
 *      Author: luo
 */

class Fruit{};

class Google{
public:
	class Moto{

	};
public:
	static Fruit fruit;
	Google::Moto moto;
};

Google* obj = new Google();
Fruit fruit;
Fruit Google::fruit;
Google::Moto* moto;
const int* const zero = 0;
