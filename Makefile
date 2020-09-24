# Makefile
#
# Makefile for Intro to Processes implementation.
#
# Wontha Kyaw San

list: main.c
	gcc -o main mymain.c
	
clean:
	rm main