# Features of Java

## 1]platform independent
    
- platform: A platform is a combination of OS and architecture that you are using 
    - eg windows+intel, windows+amd, etc 

###  before Java
- write a C++ program
- if you want to run this on a particular platform, you needed to compile this program so an executable file is generated for that platform. Executable generated on platform 1 cannot be used platform 2
- if we wanted this program to run on another platform, we need to have a compiler of that platform, and compile the code

### After Java 
- write a Java Program
- Java compiler complies your program into an intermediate code called as Java ByteCode. This bytecode can run on any platform which has that platform specific Java Virtual Machine (JVM) pre-installed
- JVM: JVM is software responsible for running bytecode on that machine. So JVM takes the bytecode and converts it to machine or platform specific instructions. and this JVM is pre-installed in many machines
-  So as a programmer, you do not have to worry about machine specific things, you write your program once, compile and generate the bytecode and it can run on any particular platform 
- hence Java is platform independent

- Java has simple compilation and complex running process but C/C++ they have complex compilation since we generate machine specific binary code 

## 2] Popularity
- 3 billion devices
- 9 million developers
- language of android 
according to wikipedia

## 3] Simple
- absence of concepts like ptrs
- there are multiple ways of doing things in c/c++
    - eg: passing an object to a function. We can do it by passing it as reference, pass it by pointers or by value. In Java, non-primitives are always passed as references and primitives are always passed as value 
- one more feature which makes C/C++ complex to understand is operator overloading which is absent in Java

## 4] Security
- JVM works as a monitoring manager also, it can make you java byte code more secure by ensuring that non-secure things are not run on machine 
- since Java does not have ptrs, there is no way of directly accessing memory in Java

## 5] Statically Typed
- this is where Java becomes similar to C++ and different from Python
- if you want to use a variable, you have to declare the variable with some specific datatype
- Since type is not defined at run-time, statically typed programs run faster as compared to python programs 

## 6] Automatic garbage collection
- as a programmer, you do not have to worry about de-allocating the dynamically allocated memory
- there is IndexOutOfBound checking, you get exception

## 7] there is better multi-threading and exception handling 

## 8] difficult to write bad code in Java as compared to C/C++
- hence Java code are more maintainable and more preferred by industries 