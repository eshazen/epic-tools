//
// generate laser-cut box for soldering kit
//

#include <stdio.h>
#include <math.h>

const double len = 18.125;	/* total length */
const double wid = 8.5;		/* width */
const double toff = 0.625;	/* lip width (outer minus inner dim) */
const double height = 1.25;	/* depth of box */

const double mat = 0.125;	/* material thickness (for tabs) */
const double kerf = 0.004;	/* kerf allowance for laser cutting */


//
// generate a set of tabs
//
// quad   - quadrant 1 (East), 2, 3, 4
// stabs  - number of tabs.  Positive for tabs, negative for slots
// kerf   - amount to enlarge slots by
// len    - overall length
// thick  - material thickness
//
int tabs( int quad, int stabs, double kerf, double len, double thick, double* x, double* y, int max) {

  double dx = len / ((double)ntabs*2.0-1.0);
  int ntabs = fabs(stabs);

  if( ntabs > 0) {		/* generate tabs */
    for( i=0; i<ntab; i++) {
      
    }
  }
  if( ntabs < 0) {		/* generate slots */

  }

}
  

//
// generate a rectangular panel with tabs
// (size does not include tabs, so overall size may be xs+2*zx)
//
// xs, ys - size in x, y
// thickness in zs
// x0tabs etc - number of tabs on left side (positive for tabs, negative for slots)
//   slots (only) are enlarged by kerf on each side
//
// output stored in x, y up to max points
// returns point count
//
int panel_with_tabs( double xs, double ys, double zx,
		     int x0tabs, int x1tabs, int y0tabs, int y1tabs,
		     double* x, double* y, int max) {

  int np = 0;
  
}

int main( int arg, char *argv[]) {
  
}
