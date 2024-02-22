#include <iostream>
#include <vector>


#include "Hw1Problem3-4.h"

using namespace std;


int main() 
{
	double speed,step,iter,travel;

	speed = 450.0 / 3600.0;					//Between 400 and 500  mph
											
	step = 15;			//Between 10 and 100 seconds

	iter = 1500;		//Between 1000 and 2000 iterations

	Plane obj;			//In your main function, instantiate an object from the “Plane” class written in Question 3 & 4

	obj.setvel(speed);   //Sets the Speed in the class

	for (int i = 0; i < iter*step; i=i+step)		//loop to iterate each step to determine position at each step
	{

		if (i == 0)				// To have initial position be zero
		{
			obj.operate(0);  // Calls the operate class
		}
		else 
		{
			obj.operate(step);			// gets the position value at step
		}

		std::cout << "Time: " << i << " seconds, Position: " << obj.getpos() << " miles." << std::endl;		

	}

	return 0;

}