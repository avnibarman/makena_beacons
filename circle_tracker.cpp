#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <cmath>
//#include <array.h>
#include "beacon.cpp"

#define NUM_BEACONS 7
#define EPSILON 0.00001

Beacon *beacons[NUM_BEACONS];

int calculateThreeCircleIntersection(double x0, double y0, double r0, double x1, double y1, double r1, double x2, double y2, double r2)
{
  double a, dx, dy, d, h, rx, ry;
  double point2_x, point2_y;

  /* dx and dy are the vertical and horizontal distances between                                                                                                                                          
   * the circle centers.                                                                                                                                                                                  
   */
  dx = x1 - x0;
  dy = y1 - y0;

  /* Determine the straight-line distance between the centers. */
  d = sqrt((dy*dy) + (dx*dx));

  /* Check for solvability. */
  if (d > (r0 + r1))
    {
      /* no solution. circles do not intersect. */
      return false;
    }

  if (d < abs(r0 - r1))
    {
      /* no solution. one circle is contained in the other */
      return false;
    }
    
  /* 'point 2' is the point where the line through the circle                                                                                                                                             
   * intersection points crosses the line between the circle                                                                                                                                              
   * centers.                                                                                                                                                                                             
   */



  /* Determine the distance from point 0 to point 2. */
  a = ((r0*r0) - (r1*r1) + (d*d)) / (2.0 * d) ;

  /* Determine the coordinates of point 2. */
  point2_x = x0 + (dx * a/d);
  point2_y = y0 + (dy * a/d);

  /* Determine the distance from point 2 to either of the                                                                                                                                                 
   * intersection points.                                                                                                                                                                                 
   */
  h = sqrt((r0*r0) - (a*a));

  /* Now determine the offsets of the intersection points from                                                                                                                                            
   * point 2.                                                                                                                                                                                             
   */
  rx = -dy * (h/d);
  ry = dx * (h/d);

  /* Determine the absolute intersection points. */
  double intersectionPoint1_x = point2_x + rx;
  double intersectionPoint2_x = point2_x - rx;
  double intersectionPoint1_y = point2_y + ry;
  double intersectionPoint2_y = point2_y - ry;
 
  cout << "INTERSECTION Circle1 AND Circle2: (" << intersectionPoint1_x << ", " << intersectionPoint1_y << "),  (" 
                                               << intersectionPoint2_x << ", " << intersectionPoint2_y << endl; 
  
  /* Lets determine if circle 3 intersects at either of the above intersection points. */
  dx = intersectionPoint1_x - x2;
  dy = intersectionPoint1_y - y2;
  double d1 = sqrt((dy*dy) + (dx*dx));

  dx = intersectionPoint2_x - x2;
  dy = intersectionPoint2_y - y2;
  double d2 = sqrt((dy*dy) + (dx*dx));

  if(abs(d1 - r2) < EPSILON) {
     cout << "INTERSECTION Circle1 AND Circle2 AND Circle3: (" << intersectionPoint1_x << ", " << intersectionPoint1_y << ")" << endl; 
  }
  else if(abs(d2 - r2) < EPSILON) {
    cout << "INTERSECTION Circle1 AND Circle2 AND Circle3: (" << intersectionPoint2_x << ", " << intersectionPoint2_y << ")" << endl; //here was an error                                                                   
  }
  else {
    cout << "INTERSECTION Circle1 AND Circle2 AND Circle3: NONE" << endl;
  }
  return 1;
}


int main() {

    // Map Initialization
    double map_length = -1;  
      cout << "Enter map length" << endl; 
      cin >> map_length; 
      while(map_length < 0){
        cout << "Please enter a positivie map length" << endl; 
        cin >> map_length; 
      }
      double map_width = -1; 
      cout <<"Enter map width" << endl; 
      cin >> map_width; 
      while(map_width < 0){
        cout << "Please enter a positivie map width" << endl; 
        cin >> map_width; 
      }
      cout << "Map dimensions: (" << map_length << ", " << map_width << ")" << endl; 

  //build map       

  
  //Initialize the beacons 

    for(int i=0; i<NUM_BEACONS; i++){                                                                                                                                                                       
        double bx = -1;                                                                                                                                                                                        
      cout << "Enter x coordinate for beacon " << i << ":" << endl; 
      cin >> bx;  
      while(bx < 0 || bx > map_width){
         cout << "Beacon " << i << " out of bounds, please enter valid x coordinate" << endl;
         cin >> bx;  
      }
      double by = -1;                                                                                                                                                                                        
      cout << "Enter y coordinate for beacon " << i << ":" << endl; 
      cin >> by;   
      while(by < 0 || by > map_length){
          cout << "Beacon " << i << " out of bounds, please enter valid y coordinate" << endl;
          cin >> by;    
     }                                                                                                                                                                       
      beacons[i] = new Beacon(i, bx, by);    
    }          

  for(int i =0; i<NUM_BEACONS; i++){
    cout << *beacons[i]; 
  }                                                                                                                                                                                           

  //wait for user to be ready for tracking                                                                                                                                                                
  //system("pause");

  while(true){
      //get beacon numbers and radii from app                                                                                                                                                                                                                                                                                                                                                                
      int b0, b1, b2;                                                                                                                                                                                     
      double r0, r1, r2;                                                                                                                                                                                  
      //get data                                                                                                                                                                                          
      calculateThreeCircleIntersection(beacons[b0]->get_x(), beacons[b0]->get_y(), 10, beacons[b1]->get_x(), beacons[b1]->get_y(), 10, beacons[b2]->get_x(), beacons[b2]->get_y(), 10);                               
      // graphics                                                                                                                                                                                     
 }                                                                                                                                                                                                                                                                                                                                                                       
  return 1;
=======
        while(bx < 0 || bx > map_width) {
            cout << "Beacon " << i << " out of bounds." << endl;
            cin >> bx;
        }

        double by = -1;

        cout << "Enter y-coordinate for beacon " << i << ":" << endl;
        cin >> by;

        while(by < 0 || by > map_length) {
            cout << "Nope." << endl;
            cin >> by;
        }
        
        beacons[i] = new Beacon(i, bx, by);
    }

    for(int i = 0; i < NUM_BEACONS; i++) {
        cout << *beacons[i];
    }
    
    // Wait for user to be ready for tracking.
    //system("pause")

    while(true) {
        // Get beacon numbers and radii from app

        int b0, b1, b2;
        double r0, r1, r2;

        //get data

        //calculateThreeCircleIntersection(beacons[b0].getx(), beacons[b0].gety(), r0, beacons[b1].getx(), beacons[b1].gety(), r1, beacons[b2].getx(), beacons[b2].gety(), r2);

        //graphics

    }
>>>>>>> d90161b9049e18ae06898da1c2c775e01b3e2658
}

