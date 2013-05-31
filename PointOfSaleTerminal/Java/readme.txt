PointOfSaleTerminal Code Sample:

This is a Java version of the Point Of Sale Terminal code sample.
Eclipse was used for the development and that project file is included.
A simple makefile is also included to compile the files from a command line as well.
In the dist folder there is a jar file created in Eclipse as well as the test files and a batch file to run the jar with the 4 provided 
test files.

=============
Program Usage
=============
The program is currently writen for testing ( see TestMain.java ), but the main() function is all that needs to change for this to be
used in some other system with say a GUI, or removing the main() and compiling this as a library.
The program takes one argument that is a commands file ( ex. abcd.txt ) with the first line specifying the price list file.
The subsequent lines are items to be scanned by the program.

If the pricing file is empty then the result of the final calculation will be $0.00 
( and if the debug build is used a message is displayed that no price information was entered )

If an item is scanned that does not have pricing information it is ignored and the existing items are counted in the total.
( If the DEBUG builds are used then a message is displayed for invalid item scans ).

The current executable build, controlled through TestMain.java, has no interactivity with a user, only with the command files.
If interaction with a user is needed then only the main function ( in TestMain.java ) would need to be changed.

==========================
Building with the makefile
==========================
The included makefile was used to build on both a Windows machine using MinGw and a Linux machine using gcc ( version 4.4.4 ).
The following options are available in the makefile.

Release and Debug executables for both platforms are provided in the win32 and linux folders.

- all                : Compiles all the Java files, class files are stored in bin folder.
- clean              : Removes all .class files from the bin folder.
- TestMain           : Compiles the TestMain.java file.
- Logger             : Compiles the Logger.java file.
- PointOfSaleTerminal: Compiles the PointOfSaleTerminal.java file.
- Item               : Compiles the Item.java file.
- PriceManager       : Compiles the PriceManager.java file.
	
PriceManager         
===============
Packaged Files
===============
The following files are included in the dist directory to assist with testing.

- pricefile.txt     - This is an example file used to set the pricing for items.
                      Found in win32 and linux directories.
- abcd.txt          - This is a test file comtaining the pricing file to use to set the prices as well as a series of items to scan.  
                      Found in win32 and linux directories.
                      Returns a total price of $7.25
- efghi.txt         - This is a test file comtaining the pricing file to use to set the prices as well as a series of items to scan, 
                      all product codes in this file are invalid ( no pricing information provided ).
                      Returns a total price of $0.00
                      Found in win32 and linux directories.
- abcdaba.txt       - This is a test file comtaining the pricing file to use to set the prices as well as a series of items to scan.
                      Found in win32 and linux directories.
                      Returns a total price of $13.25
- ccccccc.txt       - This is a test file comtaining the pricing file to use to set the prices as well as a series of items to scan.
                      Found in win32 and linux directories.
                      Returns a total price of $6.00
- autorun.cmd       - Test script for Windows that runs the program with the above 4 test files.

=================
Program Internals
=================
This is a short description of the classes used in this program

Item 
- This class is a simple container for the information about an item including the single unit price, the volume price 
  and the volume quantity 

Logger
- A simple wrapper class around the C++ standard cout.  The purpose of this is to provide a simple nterface to log messages 
  about the system and to disable them in a single place if desired.  This also provides a single class that can be changed if the 
  logging needed to be written to a file or send over a network, without requiring extensive changes to the other classes.

PointOfSaleTerminal
- this is the main interface class to the outside world, containg the calls needed to set the pricing, scan items, 
  and calculate the total.

PricingManager
- This is the class responsable for reading the price file and maintaining a mapping of product codes to pricing objects ( Item classes ).
  This class also provides methods for retreiving the single unit and volume price and quantity for a specified product code.

TestMain
- This is a testing file containing the main() function.  The command line is parsed here for the command filename.  
  This file is opened and the pricing filename is passed onto the PointOfSaleTerminal object.  The rest of the command file is read 
  and the product codes are used in calls to PointOfSaleTerminal.scan(), where they are added to the scanned items.  Finally the 
  calculateTotal() method is called to get the final dollar ammount, this is displayed to the console using std::cout ( as we always 
  want to see this anyway ).












