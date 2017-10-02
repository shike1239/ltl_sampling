#include "trajectory/dubins_steer.h"

#include <iostream>
#include <cmath>

std::vector<double> LinSpace_test(double a, double b, int n) {
	std::vector<double> array;
	// std::cout << "NUMBER is: " << n << std::endl; 
	if (n==1){
		array.push_back(a);
		array.push_back(b);
		return array;
	}
   // if (a > b) {
   // 	std::swap(a, b);
   // }
	double step = (b-a) / (n-1);
	// std::cout << "in linspace: " << step << std::endl; 
	// while(a <= b) {
	// 	array.push_back(a);
   //     a += step;           // could recode to better handle rounding errors
   //     // std::cout << step << std::endl; 
   // }
   
   if (a <= b) {
	   double step = (b-a) / (n-1);
	   // std::cout << "in linspace: " << step << std::endl; 
	   while(a <= b) {
		   array.push_back(a);
		   a += step;           // could recode to better handle rounding errors
		  // std::cout << step << std::endl; 
	  }
	  array.push_back(b);
	  
   }
   else {
	   double step = (a-b) / (n-1);
	   // std::cout << "in linspace: " << step << std::endl; 
	   while(b <= a) {
		   array.push_back(a);
		   a -= step;           // could recode to better handle rounding errors
		  // std::cout << step << std::endl; 
	  }
	  array.push_back(b);
   }

   return array;
}


int main()
{
	std::vector<double> test_lin = LinSpace_test(1, 0, 10);
	for (int i = 0; i < test_lin.size(); i++) {
		std::cout << test_lin[i] << std::endl;
	}
	std::vector<std::vector<double> > traj_desc(3, std::vector<double>(7, INFINITY));
	// std::vector<double> z_0 = {0, 0, 0};
	// std::vector<double> z_f = {5, 5, M_PI/2};
	std::vector<double> z_0 = {32.9858, 44.5592, 2.28927};
	std::vector<double> z_f = {41.3234, 54.6644, 0.324527};

	double radius_L = 5;
	double radius_R = 5;
	double min_length;
	DubinsSteer::SteerData dubins_steer_data;
	min_length = DubinsSteer::GetDubinsCurveLength(z_0, z_f, radius_L, radius_R);
	// std::cout << "min length is " << min_length << std::endl;
	dubins_steer_data = DubinsSteer::GetDubinsTrajectoryPointWise(z_0, z_f, radius_L, radius_R);
	std::vector<std::vector<double>> test_traj_point_wise = dubins_steer_data.traj_point_wise;
	std::vector<double> test_lens_map = dubins_steer_data.traj_len_map;
	for (int i = 0; i < test_traj_point_wise.size(); i++) {
		std::cout << "piece_wise " << i << ": " << test_traj_point_wise[i][0] << ", " << test_traj_point_wise[i][1] << ", " << test_traj_point_wise[i][2] << std::endl; 
	}
	// for (int i = 0; i < test_lens_map.size(); i++) {
	// 	std::cout << "test_lens_map: " << test_lens_map[i] << std::endl; 
	// }
	// std::cout << "piece_wise: " << test_traj_point_wise[0] << ", " << test_traj_point_wise[1] << ", " << test_traj_point_wise[2] << std::endl; 
	std::cout << "Min curve length is " << dubins_steer_data.traj_length << std::endl;
	// for (int i = 0; i < dubins_steer_data.traj_len_map.size(); i++) {
	// 	std::cout << "traj_len_map: " << dubins_steer_data.traj_len_map[i] << std::endl;
	// }

    return 0;
}