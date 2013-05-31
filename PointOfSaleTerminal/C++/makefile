Win32: Release
	mv PointOfSaleTerminal.exe win32\PointOfSaleTerminal.exe

Win32Debug: Debug
	mv PointOfSaleTerminal.exe win32\PointOfSaleTerminal_DEBUG.exe
    
Linux: Release
	mv PointOfSaleTerminal linux/PointOfSaleTerminal

LinuxDebug: Debug
	mv PointOfSaleTerminal linux/PointOfSaleTerminal_DEBUG

Debug: PointOfSaleTerminalLog

Release: PointOfSaleTerminal

PointOfSaleTerminal: TestMain.o Logger.o_Release PointOfSaleTerminal.o Item.o PricingManager.o
	g++ TestMain.o Logger.o PointOfSaleTerminal.o Item.o PricingManager.o -o PointOfSaleTerminal

PointOfSaleTerminalLog: TestMain.o Logger.o_Debug PointOfSaleTerminal.o Item.o PricingManager.o
	g++ TestMain.o Logger.o PointOfSaleTerminal.o Item.o PricingManager.o -o PointOfSaleTerminal

TestMain.o: TestMain.cpp
	g++ -I. -c TestMain.cpp

Logger.o_Release:
	g++ -I. -c Logger.cpp

Logger.o_Debug:
	g++ -I. -c Logger.cpp -DLOGGING_ENABLED
	
PointOfSaleTerminal.o:
	g++ -I. -c PointOfSaleTerminal.cpp
	
Item.o:
	g++ -I. -c Item.cpp
	
PricingManager.o:
	g++ -I. -c PricingManager.cpp

cleanLinux: clean
	rm -rf linux/PointOfSaleTerminal linux/PointOfSaleTerminal_DEBUG

cleanWin32: clean
	rm -rf win32\PointOfSaleTerminal.exe win32\PointOfSaleTerminal_DEBUG.exe

clean:
	rm -rf *.o