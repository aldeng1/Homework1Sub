#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int num_of_front_so, num_of_rear_so;
	double empty_weight, empty_weight_mom, front_seat_moma, weight_of_rear_so, rear_seat_ma, number_of_usable_gal, weight_of_usuablef, fuel_tank_moma, bag_weight, bag_moma, weight_of_front_so;

	std::cout << "What is the Airplane empty weight in pounds?" << std::endl;
	std::cin >> empty_weight;

	std::cout << "What is the Airplane empty-weight moment in pounds-inches?" << std::endl;
	std::cin >> empty_weight_mom;

	std::cout << "What is the number of front seat occupants?" << std::endl;
	std::cin >> num_of_front_so;

	std::vector<double> wofsoa(num_of_front_so);

	for (int i=0; i< num_of_front_so;++i)		//Allows to determine jhow many pasengers and the total weight 
	{

		std::cout << "What is the weight of each front seat occupant in pounds enter each one individually?" << std::endl;
		std::cin >> wofsoa[i];

	}

	double sum = 0.0;

	for (int i = 0; i < num_of_front_so; ++i) {		//Allows to determine jhow many pasengers and the total weight 
		sum += wofsoa[i];
	}

	weight_of_front_so = sum;

	std::cout << "What is the front seat moment arm in inches?" << std::endl;
	std::cin >> front_seat_moma;

	std::cout << "What is the number of rear seat occupants?" << std::endl;
	std::cin >> num_of_rear_so;

	std::vector<double> worsoa(num_of_rear_so);

	for (int i = 0; i < num_of_rear_so; ++i)		//Allows to determine jhow many pasengers and the total weight 
	{

		std::cout << "What is the weight of each rear seat occupant in pounds enter each one individually?" << std::endl;
		std::cin >> worsoa[i];

	}

	double sum1 = 0.0;

	for (int i = 0; i < num_of_rear_so; ++i) {			//Allows to determine jhow many pasengers and the total weight 
		sum1 += worsoa[i];
	}

	weight_of_rear_so = sum1;

	std::cout << "What is the rear seat moment arm in inches?" << std::endl;
	std::cin >> rear_seat_ma;

	std::cout << "What is the number of gallons of usable fuel in gallons?" << std::endl;
	std::cin >> number_of_usable_gal;

	std::cout << "What is the usable fuel weight per gallon in pounds?" << std::endl;
	std::cin >> weight_of_usuablef;

	std::cout << "What is the fuel tank moment arm in inches?" << std::endl;
	std::cin >> fuel_tank_moma;

	std::cout << "What is the baggage weight in pounds?" << std::endl;
	std::cin >> bag_weight;

	std::cout << "What is the baggage moment arm in inches?" << std::endl;
	std::cin >> bag_moma;

	double gross_weight, cg, total_mom;

	gross_weight = empty_weight + (weight_of_front_so) + (weight_of_rear_so) + (number_of_usable_gal * weight_of_usuablef) + bag_weight;

	total_mom = empty_weight_mom + (front_seat_moma * weight_of_front_so) + (rear_seat_ma * weight_of_rear_so) + (fuel_tank_moma * weight_of_usuablef * number_of_usable_gal) + (bag_weight * bag_moma);

	cg = total_mom / gross_weight;

	double fuel_weight;

	fuel_weight = (number_of_usable_gal * weight_of_usuablef);

	//std::cout << "First value is " << gw << "   " << cg << std::endl;

	if (gross_weight > 2950 || cg > 84.7 || cg < 82.1)			//Runs when these conditions are not met
	{

		for (int i=0; gross_weight > 2950; i++)			//runs when the gross weight is not within range
		{
			
			fuel_weight = fuel_weight - 0.01;

				gross_weight = empty_weight + (weight_of_front_so) + (weight_of_rear_so) + (fuel_weight) +bag_weight;

				total_mom = empty_weight_mom + (front_seat_moma * weight_of_front_so) + (rear_seat_ma * weight_of_rear_so) + (fuel_tank_moma * fuel_weight) + (bag_weight * bag_moma);

				cg = total_mom / gross_weight;

				//std::cout << gw << "     " << cg << std::endl;

		}

		for (int i = 0; cg > 84.7 || cg < 82.1; i++)		//Runs when cg is not within range 
		{
			if (cg > 84.7)					//calcuates fuel when cg is higher than desiered
			{
				fuel_weight = fuel_weight + 0.01;

				gross_weight = empty_weight + (weight_of_front_so)+(weight_of_rear_so)+(fuel_weight)+bag_weight;

				total_mom = empty_weight_mom + (front_seat_moma * weight_of_front_so) + (rear_seat_ma * weight_of_rear_so) + (fuel_tank_moma * fuel_weight) + (bag_weight * bag_moma);

				cg = total_mom / gross_weight;

				//std::cout << gw << "     " << cg << std::endl;

			}
			else if (cg<82.1)		//calcuates fuel when cg is lower than desiered
			{
				fuel_weight = fuel_weight - 0.01;

				gross_weight = empty_weight + (weight_of_front_so)+(weight_of_rear_so)+(fuel_weight)+bag_weight;

				total_mom = empty_weight_mom + (front_seat_moma * weight_of_front_so) + (rear_seat_ma * weight_of_rear_so) + (fuel_tank_moma * fuel_weight) + (bag_weight * bag_moma);

				cg = total_mom / gross_weight;

				//std::cout << gw << "     " << cg << std::endl;
			}

		}

		std::cout << "The new value of gross weight is "<< gross_weight <<" and the C.G. location is " << cg << "." << std::endl;
		std::cout << "The new fuel weight is " << fuel_weight << " with the difference being " <<abs((weight_of_usuablef * number_of_usable_gal)- fuel_weight)<<"." << std::endl;
	}
	else
	{

		std::cout << "The gross weight and the C.G. location are within the airplane design limits!" << std::endl;

	}

	return 0;

}







