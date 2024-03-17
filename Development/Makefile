.PHONY: build 
build: main.o application.o delay.o button.o led.o dio.o timer.o interrupts.o
	avr-gcc -mmcu=atmega32 main.o application.o delay.o button.o led.o dio.o timer.o interrupts.o -o trafficApp
	avr-objcopy -O ihex trafficApp trafficApp.hex
	rm -f *.o
	rm -f trafficApp

.PHONY: clean 
clean: 
	rm -f *.o
	rm -f trafficApp
	rm -f trafficAppTest


#---------------------------------------------------------------
#build all object files
#---------------------------------------------------------------

main.o: main.c Application/application.h 
	avr-gcc -c -mmcu=atmega32 main.c -o main.o


application.o:  Application/application.c \
				Application/application.h \
				Service/Delay/delay.h \
				ECUAL/LED/led.h \
				ECUAL/BUTTON/button.h \
				MCAL/Interrupts/interrupts.h 
	avr-gcc -c -mmcu=atmega32 Application/application.c

delay.o:Service/Delay/delay.c \
		  Service/Delay/delay.h  \
		  MCAL/Timer/timer.h \
		  Utilities/registers.h \
		  Utilities/bit_manipulation.h
		avr-gcc -c -mmcu=atmega32 Service/Delay/delay.c


button.o:ECUAL/Button/button.c \
		 ECUAL/Button/button.h \
		 MCAL/DIO/dio.h \
		 Utilities/types.h
	avr-gcc -c -mmcu=atmega32 ECUAL/Button/button.c
	
led.o:ECUAL/LED/led.c \
	  ECUAL/LED/led.h \
	  MCAL/DIO/dio.h 
	avr-gcc -c -mmcu=atmega32 ECUAL/LED/led.c

dio.o:MCAL/DIO/dio.c \
	  MCAL/DIO/dio.h \
	  Utilities/registers.h \
	  Utilities/types.h  \
	  Utilities/bit_manipulation.h
	avr-gcc -c -mmcu=atmega32 MCAL/DIO/dio.c

timer.o:MCAL/Timer/timer.c \
	  MCAL/Timer/timer.h \
	  Utilities/registers.h \
	  Utilities/types.h \
	  Utilities/bit_manipulation.h
	avr-gcc -c -mmcu=atmega32 MCAL/Timer/timer.c

interrupts.o:MCAL/Interrupts/interrupts.c \
	  MCAL/Interrupts/interrupts.h \
	  Utilities/registers.h \
	  Utilities/types.h \
	  Utilities/bit_manipulation.h
	avr-gcc -c -mmcu=atmega32 MCAL/Interrupts/interrupts.c


#---------------------------------------------------------------
# Testing Mode
#---------------------------------------------------------------

#Build in test mode
.PHONY: test 
test: testMain.o application.o delay.o button.o led.o dio.o timer.o interrupts.o \
	   buttonTest.o ledTest.o dioTest.o interruptsTest.o 

	avr-gcc -mmcu=atmega32 testMain.o application.o delay.o button.o led.o dio.o timer.o interrupts.o \
	buttonTest.o ledTest.o dioTest.o interruptsTest.o  \
	-o trafficAppTest

	avr-objcopy -O ihex trafficAppTest trafficAppTest.hex
	rm -f *.o
	rm -f trafficAppTest



#Build testing object files
testMain.o: main.c  \
			Test/test.h \
			MCAL/DIO/dio.h \
			MCAL/Interrupts/interrupts.h \
			ECUAL/LED/led.h \
			ECUAL/Button/button.h 
	avr-gcc -c -mmcu=atmega32 -DTESTMODE main.c -o testMain.o


dioTest.o: Test/MCAL/dioTest.c  MCAL/DIO/dio.h \
		   Utilities/types.h
	avr-gcc -c -mmcu=atmega32 Test/MCAL/dioTest.c -o dioTest.o

interruptsTest.o: Test/MCAL/interruptsTest.c  MCAL/Interrupts/interrupts.h
	avr-gcc -c -mmcu=atmega32 Test/MCAL/interruptsTest.c -o interruptsTest.o

ledTest.o: Test/ECUAL/ledTest.c ECUAL/LED/led.h 
	avr-gcc -c -mmcu=atmega32 Test/ECUAL/ledTest.c -o ledTest.o

buttonTest.o: Test/ECUAL/buttonTest.c ECUAL/Button/button.h \
			  Utilities/types.h
	avr-gcc -c -mmcu=atmega32 Test/ECUAL/buttonTest.c -o buttonTest.o

