all : Main.exe

Main.exe : Main.o Function_Admin.o Function_Employee.o Function_Customer.o Function_Account.o Menu_Main.o Menu_Admin.o Menu_Employee.o Menu_Customer.o Menu_Account.o Menu_Account_High.o
	g++ -o Main.exe Main.o Function_Admin.o Function_Employee.o Function_Customer.o Function_Account.o Menu_Main.o Menu_Admin.o Menu_Employee.o Menu_Customer.o Menu_Account.o Menu_Account_High.o

#================================== CLASS : FUNCTION ==================================

Main.o : ../Src/Main.cpp
	g++ -c ../Src/Main.cpp

Function_Admin.o : ../Src/Function_Admin.cpp
	g++ -c ../Src/Function_Admin.cpp

Function_Employee.o : ../Src/Function_Employee.cpp
	g++ -c ../Src/Function_Employee.cpp

Function_Customer.o : ../Src/Function_Customer.cpp
	g++ -c ../Src/Function_Customer.cpp

Function_Account.o : ../Src/Function_Account.cpp
	g++ -c ../Src/Function_Account.cpp

#================================== MENU ==================================
	
Menu_Main.o : ../Src/Menu_Main.cpp ../Lib/Menu.hpp
	g++ -c ../Src/Menu_Main.cpp

Menu_Admin.o : ../Src/Menu_Admin.cpp ../Lib/Menu.hpp
	g++ -c ../Src/Menu_Admin.cpp

Menu_Employee.o : ../Src/Menu_Employee.cpp ../Lib/Menu.hpp
	g++ -c ../Src/Menu_Employee.cpp

Menu_Customer.o : ../Src/Menu_Customer.cpp ../Lib/Menu.hpp
	g++ -c ../Src/Menu_Customer.cpp

Menu_Account.o : ../Src/Menu_Account.cpp ../Lib/Menu.hpp
	g++ -c ../Src/Menu_Account.cpp

Menu_Account_High.o : ../Src/Menu_Account_High.cpp ../Lib/Menu.hpp
	g++ -c ../Src/Menu_Account_High.cpp

#===========================================================================

# Main.exe : 
# 	g++ -o Main.exe Main.cpp Function_Admin.cpp Function_Employee.cpp Function_Customer.cpp Function_Account.cpp Menu_Main.cpp Menu_Admin.cpp Menu_Employee.cpp Menu_Customer.cpp Menu_Account.cpp
