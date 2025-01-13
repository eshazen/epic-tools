
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
};

Boxy::~Boxy() {
}

int Boxy::init( int n) {
  maxp = n;  
  xout = (double *)calloc( n, sizeof(double));
  yout = (double *)calloc( n, sizeof(double));
  xp = xout;
  yp = yout;
  if( xout && yout)
    return n;
  else
    return 0;
}

Boxy::Boxy( int n) {
  Boxy::init( n);
}

int Boxy::draw( double xd, double yd) {
  double x, y;
  if( maxp) {
    switch( angl) {		// select quadrant
    case 0:			// quadrant I
      x = xd;
      y = yd;
      break;
    case 1:			// quadrant II
      y = xd;
      x = -yd;
      break;
    case 2:			// quadrant III
      x = -xd;
      y = -yd;
      break;
    case 3:
      x = yd;
      y = -xd;
      break;
    default:
      ;
    }
    *xp++ = x;
    *yp++ = y;
    cur_x = x;
    cur_y = y;
    --maxp;
  }
  return maxp;
}

int Boxy::drawr( double x, double y) {
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
}

int Boxy::npt() {
  if( xout)
    return( xp - xout);
  else
    return 0;
}

void Boxy::print() {
  printf("# %d points\n", npt());
  for( int i=0; i<npt(); i++)
    printf("%d,%f,%f\n", i, get_x()[i], get_y()[i]);
}

double* Boxy::get_x() { return xout; };

double* Boxy::get_y() { return yout; };

