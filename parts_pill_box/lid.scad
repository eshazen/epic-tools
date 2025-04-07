//
// 10 position parts box with lid for soldering kit
//
include <roundedcube.scad>

$fn = 32;
e = 0.1;
mm = 25.4;

// compartment inner dimensions
c_wid = 0.75*mm;
c_len = 1.5*mm;
c_dep = 0.5*mm;
c_rad = 0.25*mm;		/* rounding radius */

c_spc = 2.5;			/* space between compartments */
wall = 2;
c_floor = 2.5;

pitch = c_wid + c_spc;
ntray = 10;

label_wid = 0.5*mm;

wid_over = 0.4;
len_over = 0.0;

t_wid = pitch*ntray + 2*wall-c_spc+wid_over*2;
t_len = c_len + 2*wall + label_wid + len_over*2;
t_dep = c_dep + c_floor;

lid_thk = 1;
lid_hgt = 5;
lid_wall = 1;

lid_wid = t_wid + lid_wall*2;
lid_len = t_len + lid_wall*2;

module lid() {
     difference() {
	  cube( [lid_wid, lid_len, lid_hgt]);
	  translate( [lid_wall, lid_wall, lid_wall])
	       cube( [t_wid, t_len, lid_hgt]);
     }
}

lid();
