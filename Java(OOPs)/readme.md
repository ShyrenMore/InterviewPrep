# Features of Java

## 1] platform independent
    
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

# Variables and datatypes in Java

- variables are a way of accessing and storing the data 
- the data can be of different types hence we have different datatypes
- datatypes also specify the memory needed for allocation
- variable naming can also have $, numerics, _ <br>
but variable name cannot begin with numeric
- common conventions:
    - camelCase for naming
    - uppercase for contant/final variables 
- types of variables
    - primitives(int, char, boolean, byte)
    - non-primitive (String, Array..., any user defined class types)
        - basically object of some classes, class could be pre-defined or user-defined 

Datatype | Possible values | Usage 
------------- | :----------------: | :--:
boolean | true or false | isMarried
byte | -128 to 127 <br> (or -2^7 to 2^7-1) | Student's marks from 0 to 100, 1 is for signbit, rest 7 bits can be used
short | -32768 to 32767 <br> (or -2^15 to 2^15-1) | 1 bit for sign, rest 15 bits can be used
int | -2147483648 to 2147483647 <br> (or -2^31 to 2^31-1) |
long | -2^63 to 2^63-1 |
float | Single Precision 32 bit | 10.81 (weight, price)
double | Double Precision 32 bit | 9.23 (div, /)
char | 16 bit Unicode Characters ('\40000' to '\4ffff') | bigger range than c++(8 bits), range is from 0 to 2^16-1

## Primitive vs Non - primitives

In Java, Primitive and non-primitive data-types are treated differently in many ways

1] Non-primitive type variables are always references 
- by reference, we mean it just holds the memory reference where the object is stored

2] Memory for non-primitive is always allocated on Heap

```
Point p1 = new Point();
Point p2 = p1;
```
in the above code, p2 will not have a seperate block of memory allocated, it will point to same block of memory where p1 is pointing 

3] Member of non-primitives get default values(like int variable get 0, boolean get 0) if not initialised, for primitive types we get compilation error 

# Wrapper classes in Java

- Java allows you to have non-primitive type for every primitive type. There are  built-in classes in Java, where every such class corresponds to a primitive type. These classes are called wrapper classes 

- Need of wrapper classes: when you are programming in an object-oriented way, many times you want to deal with objects only 

- eg: java Generics expect a class object to work, so on generics we have things like collections, hashset, etc <br>
eg: I want ArrayList of integers, so you have to create an ArrayList of Integer type rather than int type 

- so why Java has primitive type if everything is object oriented? <br>
These features were inherited from c/c++ legacy. If I just want an array of integers in the program, I can use int to avoid the overhead caused by dealing with objects 

Primitive Type | Wrapper Class | 
------------- | :----------------: | 
Char | Character | 
byte | Byte | 
short | Short | 
int | Integer | 
long | Long | 
float | Float | 
double | Double | 
boolean | Boolean | 
