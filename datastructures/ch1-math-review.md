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

## l.5.3 Parameter Passing

C++ has three ways to pass parameters, and C++11 includes a fourth.

The first history way is call-by-value, e.g below

```
double average( double a, double b );     // returns average of a and b
void swap( double a, double b ;           // swaps a and b; wrong parameter types
string randomItem( vector<string> arr );  // returns a random item in arr; inefficient
```

if we call average, the call-by-value copies the first parameter passed into a, and second parameter into y, then executes the code for teh average function specified elsewhere. It is gauranteed when average returns, the original parameters are unchanged, which is a often desirable. But, this property is also why call-by-value cannot work for swap, where the intention is to modify the original parameters.

```
swap(x, y)

void swap(double & a, double & b)   // swaps a and b; correct parameter types
```

Changes to a and b, in the implementation of swap, can now change the x and y parameters. This form of paramter passing is call-by-reference in C++. In C++11 this is technically call-by-lvalue-reference, but call-by-reference is used throughout the book.

Another problem with call-by-value is the parameter-passing mechanism forces a copy of a potentially large object. The cost of computing and returning a random array index is much cheaper than copying in the randomItem example above.

Only benefit of copying an object is to keep the orignal while modifying the copy. The randomItem doesn't intend to make changes to the copy at all, but is instead reading the array passed. Instead of call-by-value here, we can use call-by-constant reference shown below.

```
string randomItem(const vector<string> & arr); // returns a random item in arr
```


1. Call-by-value is appropriate for small objects that should not be altered by function
2. call-by-constant-reference is appropriate for large objects that should not be altered by teh function and are expensive to copy
3. Call-by-reference is appropriate for all objects that may be altered by the function.

Since C++11 adds rvalue reference, the fourth way to pass parameters is call-by-rvalue-reference. Moving an objects state is much easier than copying it as it is a simple pointer change. x=y can be a copy if y is an lvalue, but a move if y is an rvalue, or temporary variable. Primary use case is that we can overload a fucntion based on wheather a parameter is an lvalue or rvalue.


```
string randomItem( const vector<string> & arr ); // returns random item in lvalue arr
string randomItem( vector<string> && arr );   // returns random item in rvalue arr

vector<string> v { "hello", "world" };
cout << randomItem( v ) << endl;  // invokes lvalue method
cout << randomItem( { "hello", "world" } ) << endl; invokes rvalue method
```

## 1.5.4 Return Passing

There are also several ways to return from a function in C++. The first is return-by-value, as shown below:

```
double average( dobule a, double b ); // returns average of a and b
LargeType randomItem( const vector<LargeType> & arr);   // potentially inefficient
vector<int> partialSum( const vector<int> & arr );  // efficient in C++11
```

All these methods return an object of appropriate type, and in all cases the result of the function call is an rvalue. The call to randomItem has some inefficiences. The call to partialSum also has some potential inefficiencies, but is efficient in C++11.


### Figure 1.12 Two versions to obtain a random item in an array; second version avoids creation of a temporary LargeType object, but only if the caller access it with a constant reference.
```
LargeType randomItem( const vector<LargeType> & arr )
{
  return arr[ randomInt( 0, arr.size() -1 ) ];
}

const LargeType & randomItem2( const Vector<LargeType> & arr)
{
  return arr[ randomInt( 0, arr.size( ) - 1 ) ];
}

  vector<LargeType> vec;
  ...
  LargeType item1 = randomItem1( vec);          // copy
  LargeType item2 = randomItem2( vec );         //copy
  const LargeType & item3 = randomItem2( vec ); // no copy
```

The parameters in the first implementation of randomItem uses return-by-value. LargeType at the random array index will be copied as a part of the return sequence. This is because return expressions can be rvalues, and may not exist by the time the function call returns at line 13. But in this example the return typ eis an lvalue that will exist long after the function call returns, since arr is the same as vec.

The second implementation uses return-by-constant-reference to avoid an immediate copy. The catch, though, is the caller must also use a constant reference to access the return value, as shown on line 15. The constant reference signals we do not want to allow changes to be made by the caller using the return value. An alternative is to use auto & at line 15 to declare item3.

Historically C++ programmers spent considerable effort writing code using pointers or additional parameters which decreased readability and maintainability, eventually leading to many programming errors. Figure 1.13 introduces some solutions to these problems.


Figure 1.13 Returning of a stack-allocated rvalue in C++11
```
vectors<int> partialSum( const vector<int> & arr )
{
  vector<int> result( arr.sive( ) );

  result[ 0 ] = arr[ 0 ];
  for( int i = 1; i <  arr.size( ); ++i )
    result[ i ] = result[ i - 1 ] + arr[ i ];

  return result;
}

  vector<int> vec;
  ...
  vector<int> sums = partialSum( vec ); // Copy in old C++; move in C++11
```

In addition to return-by-value and return-by-constant-reference idioms, function can also use return-by-reference. This allows the caller of a function to have modifiable access to the internal data representation of a class

# Questions

1. What are move symantics mentioned on Page 28?
2. How does return-by-reference work and what are its advantages


## 1.5.5 std::swap and std::move

This section shows how C++11 allows easily replacing expensive copies with moves. Another exampel of th is is the implementation of a swap routine. Swapping doubles is implemented with three copies in Figure 1.14. Though this works, it comes with a significant cost; since copies are expensive the larger our objects are. Often there is no need to copy; what we want is to move instead of copies.


In C++11 if the right hand side of an assignment operator (or constructor) is an rvalue, then if the object supports moving, we can automatically avoid copies. Remember if an object has a name, it is an lvalue. So Figure 1.14 uses lvalues so copies are used.  Figure 1.15 shows how this problem is solved by using cast to treat the right-hand side of lines 10-12 as rvalues.

The syntax of a static cast is daunting, however, std::move exists and converts any lvalue (or rvalue) into an rvalue.

Note std::move doesn't move anything; rather makes a value subject to be moved. Use of std::move is also shown in figure 1.15 in a revised implementation of swap at lines 8-13. The swap function std::swap is also part of the Standard Library and will work for any type.


### Figure 1.14 Swapping by three copies
```
void swap( double & x, double & y)
{
  double tmp = x;
  x = y;
  y = tmp;
}

void swap( vector<string> & x, vector<string> & y )
{
  vector<string> tmp = x;
  x = y;
  y= tmp;
}

```

### Figure 1.15 Swapping by three moves; first with a type cast, second using std:

```
void swap( vector<string> & x, vector<string> & y )
{
  vector<string> tmp = static_cast<vector><string> &&>( x );
  x = static_cast<vector<string> &&>( y );
  y = static_cast<vector<string> &&>( tmp );
}

// Copies are avoided, moves used instead
void swap( vector<string> & x, vector<string> & y )
{
  vector<string> tmp = std::move(x);
  x = std::move( y );
  y = std::move( tmp);
}
```

## 1.5.6 The Big-five: Desctructor, Copy Constructor, Move Constructor, Copy Assignment operator=, Move assignment operator=

In C++11, classes have five special functions already available to you. These are the destructor, copy constructor, move constructor, copy assignment operator, and move assignement operator. These are collectively called the big-five. In many cases the default behavior is fine, but sometimes you may need to reimplement them.

### destructor

A destructor is called whenver an object is subjected to a delete or is garbage collected. The only responsibility of destructor is to free up the resources used by the object. This may include, calling delete for any instances of the class, closing opened files, etc. The default simply applies the destructor on each member data. 

### Copy Constructor and Move Constructor

There are two special constructors that are required to construct a new object, that is initialized to the same state of an existing object. 

The copy constructor if the existing object is an lvalue, and the move constructor if the existing object is an rvalue ( i.e. a temporary that is about to be destroyed). For any object, a copy constructor or move constructor is called in these scenarios: 

- a declaration with initialization, such as

```
    IntCell B = C;        // Copy construct if C is an lvalue; Move construct if C is an rvalue

    IntCell B { C };      // Copy construct if C is an lvalue; Move construct if C is an rvalue

    but not
    B = C;                // Assignment operator, discussed later
```

- an object passed using call-by-value (instead of by & or const &), which, as mentioned earlier should rarely be done.
- an object returned by value (instead of by & or const &). A copy constructor is invoked if the object being return is an lvalue, and move constructor if the object return is an rvalue.

By default, the copy constructor is implemented by applying copy constructors to each data member. For data members that are primitive ( int, double, or pointers), simple assignemnt is done. Data members that are objects, the copy constructor or move constructor is applied for each data member's class is applied to that data member.

### Copy Assignment and Move  Assignment (operator=)

The assignment operator is called when = is applied to two objects the already exist. lhs=rhs is intended to copy the state of rhs into lhs. If rhs is an lvalue, the copy assignment operator is used, if rhs is an rvalue (temporary), this is done using hte move assignment operator. By default the copy assignment operator is implememnted by applying the copy assignment operator to each member.

### Defaults

Often a class is composed of data members that are exclusively primitive types and objects for which defaults make sense, the class defaults will make sense. A class then can accept defaults.

When a class containers a data member that is a pointer, we must write our own delete these data members ourselves by implementing the big-five ourselves. The default destructor does nothing to data members that are pointers. As a rule we either accept all five default operations, or define all five operations. 


Generally we define the signatures of the big-five operations like so:

```
~IntCell( );                                // Destructor
IntCell( const IntCell & rhs );             // Copy constructor
IntCell( IntCell && rhs );                  // Move constructor
IntCell & operator= ( const IntCell & rhs ) // Copy assignment 
IntCell & operator= ( const IntCell && rhs ) // Move assignment 
```

The return type of operator= is a reference to the invoking object, which allows chained assignments a=b=c.

Even when simplying adding debugging logic to a single one of the big-five operations, its a good practice to rewrite all five. There is no gaurantee that unspecified operations are generated, as this gaurantee is deprecated and might not be available in future versions of the language.

Also, we can disallaw copying and moving instances of our class by


// No C
```
IntCell( const IntCell & rhs ) = delete;             // No Copy constructor
IntCell( IntCell && rhs ) = delete;                  // No Move constructor
IntCell & operator= ( const IntCell & rhs )  = delete // No Copy assignment 
IntCell & operator= ( const IntCell && rhs ) = delete // No Move assignment 
```

### When the defaults do not work

Figure 1.16 shows a few problems when data members are a pointer type and the pointer is allocated by some object member function.

The problem is the default copy assignment operator and copy cunstructor copy the pointer stored value. Thus a.storedValue, b.storedValue, and c.storedValue all point at the same int value. These copies are shallow; the pointers rather than the pointees are copied. Another problem is a memory leak. The int initially allocated by a's constructor remains allocated and it's resources need to be reclaimed. The int allocated by c's constructor is no longer referenced by any pointer variable and also needs to be reclaimed. 

To fix these problems, we implement the big-five.

### Figure 1.16 Data member is a pointer; defaults are no good
```
class IntCell
{
  public:
    explicit IntCell( int initialValue = 0 )
      { storedValue = new int { initialValue }; }

    int read( ) const
      { return *storedVaue; }
    void write( int x )
      { *storedValue = x; }

  private: 
    int *storedValue;
};
```


### Figure 1.17 Simple function that exposes problems in Figure 1.16 
```
int f( )
{
  IntCell a { 2 };
  IntCell b = a;
  IntCell c;

  c = b;
  a.write ( 4 );
  cout << a.read( ) << endl << b.read( ) << endl << c.read( ) << endl;

  return 0;
}
```

### Figure 1.8 Data member is a pointer; big-five is written

```
class IntCell
{
  public IntCell( int initialValue = 0 )
    { storedValue = new int { initialValue }; }

    ~IntCell( )                                               // Descturctor
    { delete storedValue; }

    IntCell( const IntCell & rhs )                            // Copy Constructor
    { storedValue = new int{ * rhs.storedvalue }; }

    IntCell( IntCell && rhs ) : storedValue{ rhs.storedValue} // Move Constructor
    { rhs.storedValue = nullptr; }

    IntCell & operator= ( const IntCell & rhs )               // Copy assignment
    {
      if(this != &rhs )
        *storedValue, *rhs.storedValue;
      return *this;
    }

    IntCell & operator= ( IntCell && rhs )                    // Move assignemnt
    {
      std::swap( storedValue, rhs.storedValue );
      return *this;
    }

    int read( ) const
      { return *storedValue; }
    void write( int x )
      { *storedValue = x; }

  private:
    int *storedValue 
}
```

# Questions
1. Why is std::swap used in the move assignemnt
2. what is this and *this in the copy assignment
3. Need to talk through how each of these big five.