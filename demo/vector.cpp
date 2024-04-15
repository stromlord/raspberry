#include <cmath>
#include "vector.h"
using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR{
    const double Rad_to_deg = 45.0 / atan(1.0);		// 度数转换 
    // private方法实现
	void Vector::set_mag(){mag=sqrt(x*x+y*y);}
	void Vector::set_ang(){
		if (x==0.0&&y==0.0)
			ang = 0.0;
		else
			ang = atan2(y, x);
	}
	void Vector::set_x(){x = mag * cos(ang);}
	void Vector::set_y(){y = mag * sin(ang);}
	
	// public方法实现
	Vector::Vector(){
		x = y = mag = ang = 0.0;
		mode = RECT;
	}
}
