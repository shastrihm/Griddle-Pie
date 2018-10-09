// Name: Hrishee Shastri
// Calculating pi using grid method.
// This time with constexpr. Note that we do not use a Point constructor this time.
// I made some helper functions that are called in gridpi2 to make it more manageable.

#include <iostream>     // for cout 
#include <cmath>       // for hypot()
#include <array>     // to model point
using namespace std;  


// simple distance formula that calculate distance between two points.
constexpr double distanceBtwnTwoPoints(double pt1_x, double pt1_y, double pt2_x, double pt2_y)
{   
    // calculate and store x2-x1 and y2-y1 in constant variables 
    const double x_diff = pt2_x - pt1_x, y_diff = pt2_y - pt1_y;

    // return sqrt root of (x2-x1)^2 + (y2-y1)^2, which is the distance between pt1 and pt2
    return std::hypot(x_diff, y_diff);
}


// takes a point and returns true if it lies in the quarter circle else false.
constexpr bool inCircle(double testpoint_x, double testpoint_y)
{
    // if the distance between testpoint and (0,0) is greater than the radius of the circle,
    // then it is outside the quarter circle

    if(distanceBtwnTwoPoints(testpoint_x, testpoint_y, 0.0, 0.0) > 1) //1 is radius of quarter circle
    {
        return false;
    }
    else
    {
        return true;
    }
}
 

// gridpi takes in a positive number npoints that is the number of grid points per dimension 
//(npoints x npoints) sees if each point lies within a unit quarter circle inscribes in a unit square.
// 4*(num of points in circle)/(total num of points in grid) is returned, which estimates pi.
constexpr double gridpi2(unsigned npoints)
{
    double x = 0, y = 0;                                 // declare x,y coords
    double numPointsInsideQuarterCircle = 0;    // declare counter
    double n = static_cast<unsigned>(npoints); // turn n into double so division preserves type
    double totalNumPoints = n*n;                // total number of points is n squared

    for (unsigned i = 0; i < npoints; ++i)
    {
        for (unsigned j = 0; j < npoints; ++j)
        {   

            x = (1.0/n)*i;                      // we use steps of 1/npoints for each x and y coord
            y = (1.0/n)*j;
            if(inCircle(x,y))
            {
                ++numPointsInsideQuarterCircle;
            }

        }
    }  

    return (numPointsInsideQuarterCircle/totalNumPoints)*4; // this is our estimate of pi
}


int main()
{   
    // See README.txt for further answers
    cout << gridpi2(500) << "\n"; // prints 3.14938

    return 0;             // success code
}