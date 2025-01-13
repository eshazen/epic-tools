
#include <stdio.h>
#include <stdlib.h>
#include "Boxy.hh"

Boxy::Boxy() {
  xout = NULL;
  yout = NULL;
  cur_x = 0;
  cur_y = 0;
  maxp = 0;
  angl = 0;
  debug = 0;
};

Boxy::~Boxy() {
}

void Boxy::Dump() {
  // dump the variables
  printf("Dump()\n");
  printf("cur_x=%f cur_y=%f maxp=%d angl=%d debug=%d\n",
	 cur_x, cur_y, maxp, angl, debug);
  printf("xp=%p yp=%p xout=%p yout=%p\n", xp, yp, xout, yout);
}

int Boxy::init( int n) {
  xout = NULL;
  yout = NULL;
  cur_x = 0;
  cur_y = 0;
  maxp = 0;
  angl = 0;
  debug = 0;

  maxp = n;  
  xout = (double *)calloc( n, sizeof(double));
  yout = (double *)calloc( n, sizeof(double));
  xp = xout;
  yp = yout;

  draw( 0., 0.);		// start at origin

  if( xout && yout)
    return n;
  else
    return 0;
}

Boxy::Boxy( int n) {
  Boxy::init( n);
}

int Boxy::draw( double x, double y) {
  if( maxp) {
    *xp++ = x;
    *yp++ = y;
    cur_x = x;
    cur_y = y;
    --maxp;
  }
  if( debug)
    printf("draw( %f, %f)\n", x, y);
  return maxp;
}

int Boxy::drawr( double xd, double yd) {
  double x, y;
  switch( angl) {		// select quadrant
  case 0:			// normal
    x = xd;
    y = yd;
    break;
  case 1:			// 90 deg
    y = xd;
    x = -yd;
    break;
  case 2:			// 180 deg
    x = -xd;
    y = -yd;
    break;
  case 3:			// 270 deg
    x = yd;
    y = -xd;
    break;
  default:
    fprintf( stderr, "ERROR!  angl = %d\n", angl);
    exit(1);
    ;
  }
  if( debug)
    printf("drawr( %f, %f) -> (%f, %f)\n", xd, yd, x, y);
  return draw( cur_x+x, cur_y+y);
}

void Boxy::rotate( int a) {
  switch( a) {
  case 0:
    angl = a;
    break;
  case 1:
  case 90:
    angl = 1;
    break;
  case 2:
  case 180:
    angl = 2;
    break;
  case 3:
  case 270:
  case -90:
    angl = 3;
    break;
  default:
    ;
  }
  if( debug)
    printf("rotate(%d) angl = %d\n", a, angl);
}

int Boxy::npt() {
  if( xout)
    return( xp - xout);
  else
    return 0;
}

void Boxy::print() {
  if( debug)
    printf("# %d points\n", npt());
  for( int i=0; i<npt(); i++)
    if( debug)
      printf("%d,%f,%f\n", i, get_x()[i], get_y()[i]);
    else
      printf("%f,%f\n", get_x()[i], get_y()[i]);
}

double* Boxy::get_x() { return xout; };

double* Boxy::get_y() { return yout; };

void Boxy::debugLevel( int d) {
  debug = d;
}
