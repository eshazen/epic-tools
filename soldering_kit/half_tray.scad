
$fn = 64;
e = 0.1;
mm = 25.4;

wthk = 1.6*mm;			/* wall thickness */

// outer dims
tlen = 18.125*mm;		/* total length of two halves */
hlen = mm*tlen/2;		/* length of one half */
wid = 8.5*mm;			/* tray width */

toff = 0.625*mm;		/* outer to tray offset */

// inner dims for foam
iwid = wid-2*toff;

module top_plate() {
     difference() {
	  cube( [hlen, https://github.com/eshazenwid, wthk]);
	  translate( [toff, toff, -e])
	       cube( [hlen, iwid, wthk+2*e]);
     }
}


top_plate();
