//
// plug/cap for winding spools using long 8-32 screw
//
// --------------------------------------------------------------------------------
// ---------------------------==+####***********####*+==---------------------------
// ----------------------=+###*+---::::::------------=+*###+=----------------------
// -------------------+###+--------::::::---------------===+###+-------------------
// -----------------*##+-----------::::::---------------======+##*-----------------
// ---------------*##+=------------::::::---------------========+##*---------------
// --------------###===------------::::::---------------==========###--------------
// ------------+###====---------=**#################*+=-===========###+------------
// ----------######====----=##############################=========######----------
// --------*#######====-=####################################+=====#######*--------
// ------+######*###==+########################################+==*##*######+------
// -----+#######**##################################################*+#######*-----
// ----=########***####################*=::--+*####################++*########+----
// ----#########******################*-------=*################*++++*#########----
// ---=##########****+++*##############*=----=*##############*===++++*#########=---
// ----##########****+++++++**##########################*+======+++++##########=---
// ----##########****++++++++++++++++++**####**+===------=======++++*##########----
// ----+###########**++++++++++++=========--------------========+++*##########+----
// -----*###########*+++++++++++++========--------------========+*###########+-----
// -----=*#############+++++++++++========--------------=======#############+=-----
// -------**##############++++++++========--------------====##############++-------
// --------+**################*+++========-----------=+*###############*++=--------
// ----------+++*#######################******#######################+===----------
// ------------=++++*############################################*====-------------
// ----------------=+++++*#################################*++=====----------------
// --------------------=+++++++++**################*++==-----=---------------------
// --------------------------=============-----------------------------------------

$fn=64;
mm=25.4;
e=0.1;

inner_dia=1.1*mm;
outer_dia =1.5*mm;
thick=1.6;

hub_len=0.25*mm;

hole_dia = 0.185*mm;

module plug() {
     difference() {
	  cylinder( h=thick, d=outer_dia);
	  translate( [0, 0, -e])
	       cylinder( d=hole_dia, h=10);
     }
     translate( [0, 0, thick-e]) {
	  difference() {
	       cylinder( d=inner_dia, h=hub_len);
	       translate( [0, 0, -e])
	       cylinder( d=inner_dia-2*thick, h=hub_len+2*e);
	  }
     }
}


plug();
