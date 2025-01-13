
$fn = 64;
e = 1;
mm = 25.4;

kerf = mm*0.005;

wthk = 1.6;			/* wall thickness */

// outer dims
tlen = 18.125*mm;		/* total length of two halves */
hlen = tlen/2;			/* length of one half */
wid = 8.5*mm;			/* tray width */

toff = 0.625*mm;		/* outer to tray offset */

wall = 1.0*mm;			/* wall height */

// inner dims for foam
iwid = wid-2*toff;

// generate tabs in xy plane along x in +y direction
// widen each upward tab by kerf
// generate positive (ntab>0) or negative (ntab<0) tabs
module tabs( xlen, thk, stab, kerf) {
     ntab = abs( stab);
     dx = xlen / (ntab*2-1);
     if( stab > 0) {
	  for( i=[0:ntab-1]) {
	       translate( [i*2*dx, 0, 0])
		    cube( [dx, thk, thk]);
	  }
     }
     if( stab < 0) {
	  for( i=[0:ntab-2]) {
	       translate( [dx+i*2*dx+kerf, 0, 0])
		    cube( [dx-2*kerf, thk, thk]);
	  }
     }
     // (NOP if ntab == 0)
}

//
// generate a plate with tabs for connecting to adjacent parts
//   xsize, ysize - outer dimensions *not) including tabs
//   zsize - thickness (also used for depth of tabs)
//   x0tabs, x1tabs - number of tabs on left/right sides
//                    (positive for male, negative for female)
//   y0tabs, y1tabs - number of tabs on botton/top sides
//
module tabbed_plate( xsize, ysize, zsize,
		     x0tabs, x1tabs, y0tabs, y1tabs, kerf) {
     cube( [xsize, ysize, zsize]);
     translate( [0, -zsize, 0])	/* bottom tabs */
	  tabs( xsize, zsize, y0tabs, kerf);
     translate( [0, ysize, 0])	/* top tabs */
	  tabs( xsize, zsize, y1tabs, kerf);
     rotate( [0, 0, 90])
	  tabs( ysize, zsize, x0tabs, kerf);
     translate( [xsize+zsize, 0, 0])
     rotate( [0, 0, 90])
	  tabs( ysize, zsize, x1tabs, kerf);
     
}

module top_plate() {
     difference() {
	  cube( [hlen, wid, wthk]);
	  translate( [toff, toff, -e])
	       tabbed_plate( hlen, iwid, wthk+2*e,
			     3, 0, 3 , 3);
     }
}

module box_sides() {
     tabbed_plate( hlen-toff, wall, wthk, 3, -3, 3, -3, kerf);
}

// top_plate();
box_sides();

