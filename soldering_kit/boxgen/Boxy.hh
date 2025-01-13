#ifndef _BOXY_HH
#define _BOXY_HH

class Boxy {
public:
  Boxy();			// default constructor
  Boxy( int maxp);		// constructor with allocation
  ~Boxy();			// destructor
  int init( int maxp);		// allocate memory for points
  int draw( double x, double y); // absolute draw, return remaining point count or 0 on fail
  int drawr( double x, double y); // relative draw
  void rotate( int q);		  // rotate to 0, 90, 180, 270 degrees (or, 0,1,2,3)
  double* get_x();		  // access X output
  double* get_y();		  // access Y output
  void print();			  // print the arrays for debug
  int npt();			  // return current point count
  void debugLevel(int d);	  // set debug level
  void Dump();
private:
  double cur_x, cur_y;		// current drawing position
  double* xout;			// pointers for output array
  double* yout;
  double* xp;			// pointer to next free location in array
  double* yp;
  int maxp;			// remaining space in output arrays
  int angl;			// rotation quadrant 0, 1, 2, 3
  int debug;
};


#endif
