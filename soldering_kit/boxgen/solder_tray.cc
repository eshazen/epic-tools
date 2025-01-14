//
// generate laser-cut box for soldering kit
//

#include <cstdio>
#include <math.h>
#include "Tabs.hh"

#include <stdio.h>

#define SPC 0.5

static const double tlen = 18.125;	/* total length */
static const double twid = 8.5;		/* width */
static const double toff = 0.625;	/* lip width (outer minus inner dim) */
static const double height = 1.25;	/* depth of box */
static const double thick = 0.125;	/* material thickness (for tabs) */
static const double kerf = 0.004;	/* kerf allowance for laser cutting */
//static const double kerf = 0.1;	/* kerf allowance for laser cutting */

static const double len = tlen-2*toff; // inside length
static const double wid = twid-2*toff; // inside width

#define ZeroX (len/2)
#define ZeroY (wid/2)


int main( int argc, char *argv[]) {
  Boxy* b = new Boxy(10000);
  //  b->debugLevel(1);

  Tabs::kerf = kerf;
  Tabs::thick = thick;

   // bottom
   tabbedSide( b, len, wid, 5, -3, 5, -3);
 
   // upper side
   b->draw( ZeroX, ZeroY);
   b->draw( 0, height+SPC);
   tabbedSide( b, len, height, 5, 3, -5, 3);
  
   // lower side
   b->draw( ZeroX, ZeroY);
   b->draw( 0, -(SPC+wid));
   tabbedSide( b, len, height, -5, 3, 5, 3);
  
    // left side
    b->draw( ZeroX, ZeroY);
    b->draw( -(SPC+height), 0);
    tabbedSide( b, height, wid, -3, 3, -3, 3);
  
    // right side
    b->draw( ZeroX, ZeroY);
    b->draw( len+SPC, 0);
    tabbedSide( b, height, wid, -3, 3, -3, 3);

    // top ring
    b->draw( ZeroX, ZeroY);
    b->draw( len, height+toff+3*SPC);
    tabbedInside( b, len, wid, -5, -3, -5, -3);
    b->rotate( 0);
    b->draw( ZeroX, ZeroY);

    b->draw( -toff, height+3*SPC);
    b->drawr( tlen, 0);
    b->drawr( 0, twid);
    b->drawr( -tlen, 0);
    b->drawr( 0, -twid);

  b->print();
}
