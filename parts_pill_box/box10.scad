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

label_wid = 0.5*mm;
label_txt = label_wid*0.35;

text_thk = 1.0;

// text, two lines
labels1 = ["330R ", "10k", "750R", "0.1u", "RED ", "GRN ", "MCU ",
	  "PB", "PD", "HDR" ];
labels2 = ["R5-12", "R1,2,4", "R3", "C1", "D1-8", "D11", "U1",
	   "SW1", "D9-10", "BATT"];

pitch = c_wid + c_spc;
ntray = 3;

t_wid = pitch*ntray + 2*wall-c_spc;
t_len = c_len + 2*wall + label_wid;
t_dep = c_dep + c_floor;

module label( txt) {
     text( halign="center", text=txt, size=label_txt, font="DejaVu Sans");
}

difference() {
     cube( [t_wid, t_len, t_dep]);
     // cavities for parts
     translate( [wall, wall, wall]) {
	  for( i=[0:ntray-1]) {
	       translate( [i*pitch, 0, 0])
		    roundedcube( [c_wid, c_len, 50], false, c_rad, "zmin");
	  }
     }
     // recessed area for labels
     translate( [wall, wall+c_len+1, t_dep-text_thk])
	  cube( [pitch*ntray-wall, label_wid, text_thk+e]);
}

// text labels
translate( [wall+pitch/2, wall+c_len+1, t_dep-text_thk-e]) {
     color("red")
     for( i=[0:ntray-1]) {
	  translate( [i*pitch, 1, 0]) {
	       linear_extrude( text_thk) label( labels1[i]);
	       translate( [0, label_txt*1.5, 0])
		    linear_extrude( text_thk) label( labels2[i]);
	  }
     }
}
