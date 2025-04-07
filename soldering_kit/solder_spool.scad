
mm = 25.4;
e = 0.1;
$fn = 64;

outer_dia = 2.2*mm;
lip_thk = 1.6;
core_dia = 1.25*mm;
height = 1*mm;
core_thk = 1.6;

core_open = core_dia - 2*core_thk;

hole_dia = 1.5;

module core() {
  difference() {
    cylinder( d=core_dia, h=height);
    translate( [0, 0, -e]) cylinder( d=core_open, h=height+2*e);
    translate( [0, core_dia/2+1, lip_thk*2])
      rotate( [90, 0, 0])
      cylinder( h=5, d=hole_dia);
  }
}

module lip() {
  difference() {
    cylinder( d=outer_dia, h=lip_thk);
    translate( [0, 0, -e]) cylinder( d=core_open, h=lip_thk+2*e);
  }
}

core();
lip();
translate( [0, 0, height-lip_thk]) lip();
