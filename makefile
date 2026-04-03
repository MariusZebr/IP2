CC = g++

# a) build the module .o
a: UnrolledLinkedList.o

# c) run demo
c: demo.exe
	./demo.exe

# b) build demo
b: UnrolledLinkedList.o
	
# d) build test
d: UnrolledLinkedList.o

# e) run test
e: test.exe
	./test.exe
	
# f) clean everything
f:
	del *.o *.exe

# g) rebuild from scratch
g: f a
	

test.exe: UnrolledLinkedList.o test.cpp 
	${CC} -DTEST_MODE test.cpp UnrolledLinkedList.o -o test.exe

demo.exe: UnrolledLinkedList.o demo.cpp
	${CC} -DDEMO_MODE demo.cpp UnrolledLinkedList.o -o demo.exe

UnrolledLinkedList.o: UnrolledLinkedList.cpp UnrolledLinkedList.h
	${CC} -c UnrolledLinkedList.cpp -o UnrolledLinkedList.o