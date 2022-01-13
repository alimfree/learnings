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