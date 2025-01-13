#include <cstdio>

#include "Tabs.hh"

Tabs::Tabs() { };

Tabs::~Tabs() { };

Tabs::Tabs( double k, double t) {
  kerf = k;
  thick = t;
}

void Tabs::setKerf( double k) { kerf = k; };

double Tabs::getKerf() { return kerf; }

int Tabs::drawTabs( Boxy* box, int ntabs, double len) {
  int n = (ntabs<0) ? -ntabs : ntabs;
  double spc = len / ((double)n * 2.0 - 1.0);
  if( ntabs > 0) {
    for( int i=0; i<n; i++) {
      box->drawr( 0., thick);
      box->drawr( spc, 0.);
      box->drawr( 0., -thick);
      if( i != n-1)
	box->drawr( spc, 0.);
    }
  }
  if( ntabs < 0) {
    for( int i=0; i<n-1; i++) {
      if( i == 0)		// first section
	box->drawr( spc+kerf, 0.);
      box->drawr( 0., thick);
      box->drawr( spc-2*kerf, 0.);
      box->drawr( 0., -thick);
      if( i == n-2)
	box->drawr( spc+kerf, 0);	
      else
	box->drawr( spc+2*kerf, 0);
    }
  }

  return 0;
}
