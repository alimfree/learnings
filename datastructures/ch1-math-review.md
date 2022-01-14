# Programming: A General overview
## Mohammed Ali Study Notes
## 1.1 What's this book about

Writing a working program is not good enough for large data sets, then the running time is important. Analysing the running time of a program helps eliminate inefficient solutions before begining to code. Also this book explores techniques for improving speed of our programs and for determining bottleknecks. These techniques help us find and focus on improving efficiency of the parts of our programs that are too slow. 

Selection problem (finding greatest number in a list) has some naive solutions like bubble sort but as the data set of our list grows into the millions, an average computer days to resolve the largest number.

Ch 7 discusses a solution to the selection problem which gives a solution in seconds, even for a large list. 


## 1.2 Mathematics Review

There are some important formulas to memorize, or be able to derive and a brief proof methods review. Github doesn't show markdown math easily but visual studio code markdown viewer is able to do so. 

### [Intro to Mathematics Markdown](https://learninglab.gitlabpages.inria.fr/mooc-rr/mooc-rr-ressources/module1/ressources/introduction_to_markdown.html#fractions-binomial-coefficients-square-roots)

### 1.2.1 Exponent Rules

- $X^A$*$X^B$ = $X^{A+B}$

- $\frac{X^A}{X^B}$ = $X^{A-B}$

- (${X^A})^B$ = $X^{A*B}$

- $X^{N}$ + $X^{N}$ = $2X^{N}$

- $2^{N}$ + $2^{N}$ = $2^{N+1}$


### 1.2.2 Logarithms

In computer science, all logorithms are base 2 unless specified otherwise

- $X^A$ = B if and only if $log{_X}{B}$ = A

Theorom 1.1 

$log{_A}{B}$ = $\frac{log{_C}{B}}{log{_C}{A}}$;   where A, B, C > 0, A $\neq$ 1


Theorem 1.2

$log{}{AB}$ = $log{}{A}$   + $log{}{B}$;  where A,B > 0


Other Useful formulas
- $log{}{\frac{A}{B}}$ = $log{}{A}$   - $log{}{B}$

- $log{}{{A^B}}$ = B  $log{}{A}$

- $log{}{X}$ < X for all X > 0

- $log{}{(1)}$ = 0

- $log{}{(2)}$ = 1

- $log{}{(1024)}$ = 10

- $log{}  {(1,048,576)}$ = 20

### 1.2.3 Series

Try and memorize

- 	$\sum_{i=0}^{N} 2^{i}$ = $2^{N+1}$  -1

- 	$\sum_{i=0}^{N} A^{i}$ = $\frac{A^{N+1}  -1}{A-1}$

-   $\sum_{i=1}^{N} i = \frac{N(N + 1)}{2}$ $\approx$ $\frac{N^2}{2}$

- Harmonic sum and Harmonic numbers $H_{N}$ = $\sum_{i=1}^{N} \frac{1}{i}$ $\approx$ $log{_e}{N}$ approximates to Euler's Constant 0.5772...

Algebraic Manipulations

- $\sum_{i=1}^{N} f(N)$ = N $f(N)$

- $\sum_{i=n_{0}}^{N} f(i)$ = $\sum_{i=1}^{N} f(i)$ - $\sum_{i=1}^{n_{0}-1} f(i)$ 

### Modular Arithmetic


A is congruent to B modulo N, if the reminder is the same when either A or B are divided by N. 

- A $\equiv$ B (mod N), if N divides A - B
- 81 $\equiv$ 61 $\equiv$ 1 (mod 10) both have remainder of zero

If a prime number N divides a product of two numbers, then it divides at lest one of the two numbers. 

There are several other theorems mentioned and even more not mentioned in the book. Modular arithmetics is not used often in this book. 

### 1.2.5 Proofs

Common proof methods for statements in data-structure analysis are proof by induction and proof by contradiction. The best way to prove a theorem is false is by finding a counter example.

Break out your favorite discrete math book for more fun with proof methods. 

### 1.3 Recursion

A function that calls itself within its own method definition is recursive. Often, recursive implementations are easy to write in few lines. First we handle the base case, or the minimum/maximum known value. Then we make recursive calls to find all other cases. 


### Figure 1.2 A recursive function
``` int f( int x )
{
  if( x === 0 ) // Base Case
    return 0
  else
    return 2 * f( x-1 ) + x * X  // Recursive calls to f
}
```
Author note, numberical calculations are not a good use case for recursion. This is for illustrative purposes only.

Considerations when usign recursion. 
 - Base case, this must be resolve without recursion

 - Making progress, all casses using recursive calls must progress towards the base case. Otherwise program will be non terminating, looping indefinitely until memory limit of the machine is reached.

 - Assume that all the recursive calls work. In many cases complicated details are handled well by computer and more complexity is a good indication recursion may be useful. 

 - Compound interest rule. Never duplicate work by solving the same instance of a problem in separate recursive calls. This is why math funcitons are not a good use of recursion.


Bookkeeping details and tracing or debugging recursive programs is more difficult. The main benefits to recursion are in simplifying algorithm design and fewer lines of code. Recursion should not be used in lieue of a simple for loop. Section 3.6 has more about recursion.

### 1.4 C++ Classes

All data structures that store data and include functions to manipulate collections will be objects. Classes are used in C++ to define objects. 

### 1.4.1 Basic class syntax

A class consist of members. Members are either data or functions. Functions are called member functions. Each instance of a class is an object. Every object includes the data defined in the class. A member function is used to manipulate the object. Member functions are also called methods. 

Private and public labels determine visibility of class members. Information hiding, restricts access of internal details of the class. 

A constructor method describes how an instance of a class is constructed. 


### Figure 1.5 A complete declaration of an IntCell class
```
/**
 * A class for simulating an integer memory cell.
 */
Class IntCell
{
  public:
  /**
   * Construct the IntCell.
   * Initial value is 0.
   */
   IntCell()
   { storedValue = 0;}

   /**
    * Construct the IntCell
    * Initial value is initialValue.
    */
    IntCell( int initialValue )
    { storedValue = initialValue; }

    /**
     * Return the stored value.
     */
     int read()
     { return storedValue; }

     /**
      * Change the stored value to x
      */
      void write( int x )
      { storedValue = x; }

    private:
        int storedValue;
}
```


### 1.4.2 Extra Constructor Syntax and Accessor
Figure 1.5 is works but there are some optimizations possible shown below in Figure 1.6. First we can use an initialization list in our constructor and remove the zero parameter constructor. Then we make all one parameter constructors explicit to avoid implicit type conversions. And finally we use const because read examines but does not change the state of our object instances. Accessors can use constants because unlike mutator methods, they do not change the state of our object.


### Figure 1.6 IntCell revised
```
/**
 * A class for simulating an integer memory cell.
 */
Class IntCell
{
  public: 
    /**
      * Construct the IntCell.
      * Initial value is initialValue.
      */
    explicit: IntCell(int initialValue = 0 )
      : storedValue = {initialValue} {}

    int read() const
    { return storedValue; }

    void write( int x )
    { storedValue = x; }

  private: 
    int storedValue;
}
```

### 1.4.3 Separation of Interface and Implementation

Often object oriented programming and C++ allows for separation of implementation from a class interface. Interface typically has a .h file extension. There are some techniques for avoiding reading interfaces more than once in a program. The preprocessor commands #ifndef and #define allow us to do this.


### Figure 1.7 A class interface in file IntCell.h
```
/**
 * An class for simulating an integer memory cell.
 */
Class IntCell
{
  public: 
    /**
      * Construct the IntCell.
      * Initial value is initialValue.
      */
    explicit: IntCell(int initialValue = 0);

    int read() const;

    void write( int x );

  private: 
    int storedValue;
};
```


### Figure 1.8 IntCell class implementation in file IntCell.cpp
```
#include "IntCell.h"
/**
 * Construct the IntCell with initialValue
 */
intCell::IntCell( int initialValue ) : storedValue{ initialValue }{

/**
 * Return the stored value.
 */
 int IntCell::read( ) const
 {
   return storedValue;
 }

 /**
  * Store x.
  */
  void IntCell::write( int x )
  {
    storedValue = x;
  }

}
```

Scope Resolution: each member function must identify the class it belongs to using the ClassName::member syntax.

Signatures Must match exactly. The return type of the interface and whether it is mutable must match the interface.

Default paramters are omitted in the implementation but are expressed in the interface.

Objects are declared like Primitives e.g.

The following are correct
- IntCell obj1;        // Zero params constructor
- IntCell obj2( 12 );  // One param constructor
- IntCell obj3{ 12 };  // One param same as before
- IntCell obj4{ };     // Zero param same as before

### Figure 1.9 Program that uses IntCell in file TestIntCell.cpp

```
#include <iostream>
#include "IntCell.h"
using namespace std;

int main()
{
  IntCell m;

  m.write( 5 );
  cout << "Cell contents: " << m.read() << endl;

  return 0;
}
```

## 1.4.4 vector and string

### Figure 1.10 Using the vector class: stores 100 squares and outputs them
```
#include <iostream>
#include <vector>
using namespace std;

int main( )
{
    vector<int> squares( 100 );

    for( int i = 0; i < squares.size( ); ++i )
      squares[ i ] = i * i;

    for( int i = 0; i < squares.size( ); ++i)
      cout << i << " " << squares[ i ] << endl;


    return 0;
}
```

The C++ standard defines two classes: the vector and string. Vector is intended to replace built in array data structure because an array cannot be copied, does not remember how many items it can store, and its indexing operator does not check that the index is valid. Furthermore, the C++ built instances of the string datatype is cannot be easily compared using ==.

 Vectors and string classes in the STL are first class objects that can be copied, compared.

 As of C++ 11

 ```
 vector<int> daysInMonth = { 31, 28, 31, 30, 31, 30, 31,31, 30, 31, 30, 31 };
 ```

 but this violates uniform initialization so some prefer


 ```
 vector<int> daysInMonth { 31, 28, 31, 30, 31, 30, 31,31, 30, 31, 30, 31 };
 ```
 Above allows for uniform initialization.


```
 vector<int> daysInMonth( 12 ) // Must use () to call constructor that takes size.
```
Above allows overwriting the initial vector size

Iterating over an array and accessing every array index using [] is common in array manipulation. C++11 adds range "for" syntax for this reason.

```
int sum = 0;
for( int x : squares )
  sum += x;
```

Sometimes type declaration in the range for statement is redundant. Since squares is a vector<int>, it is clear that the index of each square is also an int. Therefor C++ 11 also includes the "auto" keyword to automatically infer the appropriate type:

```
int sum = 0;
for( auto x : squares )
  sum += x;
```


## 1.5.1 Pointers

A pointer variable stores the address where another object lives. Pointers are fundamental to many datastructures.

For example storing a list of items could use an array data structure. But we cannot easily insert in the middle of the array without moving many items.

Instead, we can store the collection in a separate, noncontiguous piece of memory, that is expanded or contracted dynamically as the programs runs. Along with each object in the collection is also a link to the next object. The link is a pointer variable because it stores the memory location of another object.

This describes the classic LinkedList data structure, discussed more detail in Ch. 3.

Figure 1.11 is not useful and is only to illustrate dynamic memory allocation in a simple way.

### Figure 1.11
 ```
int  main( )
{
  IntCell *m; /// * indicates that m is a pointer variable.

  m = new IntCell{ 0 };
  m->write( 5 );
  cout << "Cell contents: " << m->read( ) << endl;

  delete m;
  return 0;

}
 ```

In Figure 1.11 m is a pointer variable and is allowed to point at an IntCell object. The value of m is the address of the object it points to. C++ does not check to verify pointers are assigned values before usage. The use of uninitialized pointers crashes programs since they try to access memory locations that do not exist. Always provide an initial value or use the nullptr pointer.


Dynamic Object Creation
There are several ways to dynamically create an object pointer

- m = new IntCell( );   // ok
- m = new IntCell{ };   // C++11
- m = new IntCell;      // Preferred by Weiss

### Garbage Collection
In some languages when an object is no longer needed, it is automatically destroyed by garbage collection: the programmer does not need to worry. C++ does not have garbage collection. When an object that is allocated by new is no longer referenced, the delete operation must be used through a pointer to safely delete it. When this is not done properly memory leaks can occur.

Memory leaks can be automatically removed with some attention. A good rule is to not use new when an automatic variable can be used instead.

In the initial program figure 1.5 storedValue is a local variable and also an automatic variable - meaning automatically garbage collected.

### Assignment and comparison of pointers
Two pointer variables are equal only if they point to the same object. Otherwise, they point at different objects and are not equal, even if the objects being pointed at are equal. Assignemnt also allows for shareing the location of an object with another pointer variable (of compatible type).

### Accessing Members of an Object through a Pointer
If a pointer variable can access a public (visible) member of an object using the -> operator as shown in Figure 1.11

### Address-of Operator (&)
The address-of operator & returns the memory location where an object exists and is useful in writing alias tests.


### 1.5.2 Lvalues, Rvalues, and References

C++ also defines reference types and C++11 introduces rvalue reference. In this intro, complicated edge cases are ignored for now for simplicity.

An "lvalue" is an expression that identifies a non-temporary object. An "rvalue" is an expression that identifies a temporary object or is a value not associated with any object.

Consider the following
- vector<string> arr( 3 );
- const int x = 2;
- int y;
- int z = x + y;
- string str = "foo";
- vector<string> *ptr = &arr;

In the declarations above, arr, str, arr[x], &x, y, z, *ptr, (*ptr)[x] are all lvalues. x is also an lvalue, although it is not mutable. Generally, Any variable with a name is an lvalue, regardless if it is modifiable.

Alternatively, "foo", x+y, str.substring(0,1) are all rvalues. 2 and "foo" are rvalues because they are literals. Also, x+y is an rvalue because it is temporary; it is not x or y, but is stored somewhere before being assigned to z. If a function call computes an expression whose value does not exist before the call and does not exist after the function executes unless copied somewhere, the expression is likely an rvalue.

A reference allows us to  define a new name for an existing value. In classic C++, a reference is generally limited to the name for an lvalue, because having a reference to a temporary object might inadvertently allow for accessing it after its deletion. In C++11, there are two types of references lvalue references and rvalue references.


In C++11 an lvalue reference is declared by placing an & after some type. An lvalue reference then becomes another name or synonym for the object it referenes.

Some exampels
- string str = "hell";
- string & rstr = str;              //  another name for str
- rstr += 'o';                      // 'hello'
- bool cond = (&str == &str);       // true, same obj
- string & bad1 = "hello";          // illegal hello is not a modifiable lvalue
- string & bad2 = str + "";         // illegal str + "" is not an lvalue
- string & sub = str.substr( 0, 4 );  // illegal str.substr( 0,4 ) is not an lvalue

In C++, an rvalue reference is declared by placing an && after some type. An rvalue reference acts like an lvalue except unlike an lvalue reference, an rvalue reference can also reference an rvalue.

- string str = "hell";
- string && bad1 = "hello";            // legal
- string && bad2 = str + "";           // legal
- string && sub = str.substr( 0, 4 );  // legal


### lvalue refernces use case #1: aliasing complicated names

The simplest use, is to use a local reference variable to rename an object that is known by a complicated expression. Doing so avoids rerunning the complicated expression when accessing the renamed variable. 

### lvalue reference use case #2 range for loops
In a range for statement, when iterating over a collection using a for statement, the index for each item in a collection assumes a copy of each value in the collection.

for example

for( auto x : arr ) // broken
  ++x;

What we want is for each index "x" to be another name for each value in the vector.

for( auto & x : arr ) //works
  ++x;

### lvalue references use #3 avoiding a copy
If we dont intend to change our copy, there's no need to have duplicate resources to store each copy and a reference will work to save resources. This is especially useful when storing large objects.

example
```
auto & x = findMax( arr );
```

Normally, findMax must specify a return type that is an lvalue

important concepts
1. Reference variables copy objects accross function-call boundaries.
2. Syntax is needed in function declarations and retuns to allow passing and returning using references instead of copies.