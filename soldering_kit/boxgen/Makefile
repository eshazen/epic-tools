all: boxy_test solder_tray

CXX = g++

boxy_test: boxy_test.o Boxy.o Tabs.o
	$(CXX) -o boxy_test $^

solder_tray: solder_tray.o Boxy.o Tabs.o
	$(CXX) -o solder_tray $^
