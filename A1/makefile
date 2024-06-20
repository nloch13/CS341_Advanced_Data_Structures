GPA.exe: Driver.o Student.o
	g++ Driver.o Student.o -o GPA.exe

Driver.o: driver.cpp
	g++ -c driver.cpp -o Driver.o
	
Student.o: Student.cpp
	g++ -c Student.cpp -o Student.o

clean:
	rm *.o *.exe