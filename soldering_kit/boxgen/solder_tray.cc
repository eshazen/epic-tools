//
// generate laser-cut box for soldering kit
//

#include <cstdio>
#include <math.h>
#include "Tabs.hh"

#include <stdio.h>

#define SPC 0.5


// #define SMALL_TEST



#ifdef SMALL_TEST

static const int TabsA = 4;	// long edge tab count
static const int TabsB = 3;	// width edge tab count
static const int TabsC = 2;	// vertical edge tab count

static const double tlen = 3;	/* total length */
static const double twid = 2;		/* width */
static const double toff = 0.625;	/* lip width (outer minus inner dim) */
static const double height = 1;	/* depth of box */

#else

static const int TabsA = 5;	// long edge tab count
static const int TabsB = 3;	// width edge tab count
static const int TabsC = 3;	// vertical edge tab count

static const double tlen = 17;	/* total length */
static const double twid = 8.5;		/* width */
static const double toff = 0.563;	/* lip width (outer minus inner dim) */
static const double height = 1.5;	/* depth of box */

#endif

static const double thick = 0.125;	/* material thickness (for tabs) */
// -7 seems good after testing
static const double kerf = -0.007;	/* kerf allowance for laser cutting */

static const double len = tlen-2*toff; // inside length
static const double wid = twid-2*toff; // inside width

#define ZeroX (-height)
#define ZeroY (height/2)


int main( int argc, char *argv[]) {
  Boxy* b = new Boxy(10000);
  //  b->debugLevel(1);

  Tabs::kerf = kerf;
  Tabs::thick = thick;

   // bottom
  tabbedSide( b, len, wid, TabsA, TabsB, TabsA, TabsB);
 
   // upper side
   b->draw( ZeroX, ZeroY);
   b->draw( 0, height+SPC);
   tabbedSide( b, len, height, -TabsA, -TabsC, -TabsA, -TabsC);
  
   // lower side
   b->draw( ZeroX, ZeroY);
   b->draw( 0, -(SPC+wid));
   tabbedSide( b, len, height, -TabsA, -TabsC, -TabsA, -TabsC);
  
    // left side
    b->draw( ZeroX, ZeroY);
    b->draw( -(SPC+height), 0);
    tabbedSide( b, height, wid, TabsC, -TabsB, TabsC, -TabsB);
  
    // right side
    b->draw( ZeroX, ZeroY);
    b->draw( len+SPC, 0);
    tabbedSide( b, height, wid, TabsC, -TabsB, TabsC, -TabsB);

    // top ring
    b->draw( ZeroX, ZeroY);
    b->draw( len, height+toff+3*SPC);
    tabbedInside( b, len, wid, -TabsA, -TabsB, -TabsA, -TabsB);
    b->rotate( 0);
    b->draw( ZeroX, ZeroY);

    b->draw( -toff, height+3*SPC);
    b->drawr( tlen, 0);
    b->drawr( 0, twid);
    b->drawr( -tlen, 0);
    b->drawr( 0, -twid);

  b->print();
}
