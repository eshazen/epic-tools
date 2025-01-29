//
// 1-piece handle, insert from bottom
//

e = 0.1;
mm = 25.4;
$fn = 64;

// slot
slot_len = 4*mm-0.1*mm;
slot_wid = 0.125*mm - 0.005*mm;

foam_thk = (7/8)*mm;		/* thickness of tray bottom plus foam */
headroom = 2.5*mm;		/* space above foam to box lid */

bot_len = slot_len + 1*mm;
bot_wid = 1*mm;
bot_thk = 3.5;

handle_open_hgt = 1.4*mm;
handle_open_wid = 3.5*mm;

rnd = 5;			/* round edge dia */

// generate a cube rounded in x, y using minkowski
// origin at xyz=0
module rounded_cube( dx, dy, dz, dia) {
     translate( [dia/2, dia/2, 0]) {
       	  minkowski() {
	       cube( [dx-dia, dy-dia, .01]);
	       cylinder( h=dz, d=dia);
	  }
     }
}

module bottom_base() {
     translate( [-bot_len/2, -bot_wid/2, -foam_thk+1]) {
	  rounded_cube( bot_len, bot_wid, bot_thk, rnd);
     }
     rotate( [90, 0, 0])
	  translate( [-slot_len/2, -foam_thk+bot_thk-1, -slot_wid])
	  rounded_cube( slot_len, headroom, slot_wid, rnd);
}

// draw handle opening from center
handle_cut_offset = 5;
module handle_opening() {
     translate( [-handle_open_wid/2+handle_open_hgt/2, 0, -handle_cut_offset])
	  cylinder( h=handle_cut_offset*2, d=handle_open_hgt);
     translate( [handle_open_wid/2-handle_open_hgt/2, 0, -handle_cut_offset])
	  cylinder( h=handle_cut_offset*2, d=handle_open_hgt);
     translate( [-handle_open_wid/2+handle_open_hgt/2, -handle_open_hgt/2, -handle_cut_offset])
	  cube( [handle_open_wid-handle_open_hgt, handle_open_hgt, 2*handle_cut_offset]);
}

module bottom() {
     difference() {
	  bottom_base();
	  rotate( [90, 0, 0]) {
	       translate( [0, 20, 0])
		    handle_opening();
	  }
     }
}

bottom();

