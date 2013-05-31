all: TestMain
	javac -d bin -sourcepath src src/com/sandbox/TestMain.java
    
TestMain:
	javac -d bin -sourcepath src src/com/sandbox/TestMain.java

Logger:
	javac -d bin -sourcepath src src/com/sandbox/Logger.java
	
PointOfSaleTerminal:
	javac -d bin -sourcepath src src/com/sandbox/PointOfSaleTerminal.java
	
Item:
	javac -d bin -sourcepath src src/com/sandbox/Item.java
	
PriceManager: Item.class Logger.class
	javac -d bin -sourcepath src src/com/sandbox/PriceManager.java

clean:
	rm -rf bin/com/sandbox/*.class