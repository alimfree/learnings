# Programming: A General overview
## Mohammed Ali
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