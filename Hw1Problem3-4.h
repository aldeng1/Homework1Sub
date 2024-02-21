#pragma once

#include <iostream>
#include <map>

#include "Hw1Problem2.h"

using namespace std;

class Plane
{
private:

	double pos, vel, distance;
	bool at_SCE;
	string origin, destination;
	dist Hw1Problem2;								//This is in a different h file but it is still a container.

public:

	Plane()     
	{
		string from, to;

		std::cout << "Please Enter where the plane is starting?" << from << std::endl;
		std::cin >> from;

		std::cout << "Please Enter where the plane is going to?" << to << std::endl;
		std::cin >> to;

		origin = from;
		destination = to;

		pos = 0; vel = 0; at_SCE = 0;

		dist obj2;

		distance = obj2.distan(origin, destination);   //Container is called here

		cout << "Plane Created at " << this << endl;					   

	}

	~Plane()     //Check
	{
		cout << "Plane destroyed" << endl;
	}

	double operate(double dt)        //Check
	{

		string rand, rand1;

		if (dt < 0)
		{
			dt = 0;
		}

		if (pos < distance)
		{
			pos += vel * dt;
			at_SCE = 0;
		}
		else if (destination == "SCE")
		{
			at_SCE = 1;

			rand = origin;
			origin = destination;
			destination = rand;

			pos = 0.0;

		}
		else
		{
			rand1 = origin;
			origin = destination;
			destination = rand1;

			pos = 0.0;

		}

		return pos;				//Is this allowed
	}

	double getpos()
	{
		return pos;
	}

	string getorgin()
	{
		return origin;
	}

	string getdestination()
	{
		return destination;
	}

	bool getat_SCE()
	{
		return at_SCE;
	}

	double getvel()
	{
		return vel;
	}

	void setvel(double v)
	{
		vel = v;
	}


};
