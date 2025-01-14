#include <cstdio>

#include "Tabs.hh"

double Tabs::kerf;
double Tabs::thick;

Tabs::Tabs() { };

Tabs::~Tabs() { };

Tabs::Tabs( double k, double t) {
  kerf = k;
  thick = t;
}

void Tabs::setKerf( double k) { kerf = k; };
double Tabs::getKerf() { return kerf; }

void Tabs::setThick( double t) { thick = t; };
double Tabs::getThick() { return thick; };

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


// draw a rectangle with 4 sides with tabs
// slen = length in X;  swid = width in Y
// nt, nr, nb, nl = # tabs top, right, bottom, left
//
void tabbedSide( Boxy* b, double slen, double swid, 
		 int nt, int nr, int nb, int nl) {
  Tabs top( Tabs::kerf, Tabs::thick);
  b->rotate( 0);
  top.drawTabs( b, nt, slen);

  Tabs right( Tabs::kerf, Tabs::thick);
  b->rotate( 270);
  right.drawTabs( b, nr, swid);
 
  Tabs bottom( Tabs::kerf, Tabs::thick);
  b->rotate( 180);
  bottom.drawTabs( b, nb, slen);
 
  Tabs left( Tabs::kerf, Tabs::thick);
  b->rotate( 90);
  left.drawTabs( b, nl, swid);
}

// draw a rectangle with 4 sides with tabs
// but as an opening in a larger surface
//
void tabbedInside( Boxy* b, double slen, double swid, 
		 int nt, int nr, int nb, int nl) {
  Tabs top( Tabs::kerf, Tabs::thick+Tabs::kerf);
  b->rotate( 180);
  top.drawTabs( b, nt, slen);

  Tabs right( Tabs::kerf, Tabs::thick+Tabs::kerf);
  b->rotate( 90);
  right.drawTabs( b, nr, swid);
 
  Tabs bottom( Tabs::kerf, Tabs::thick+Tabs::kerf);
  b->rotate( 0);
  bottom.drawTabs( b, nb, slen);
 
  Tabs left( Tabs::kerf, Tabs::thick+Tabs::kerf);
  b->rotate( 270);
  left.drawTabs( b, nl, swid);
}

