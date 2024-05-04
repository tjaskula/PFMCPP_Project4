/*
Project 4: Part 4 / 9
 Chapter 4 Part 7
 Function/Constructor Overloading

 Create a branch named Part4
 
 Do not delete your previous main. you will be adding to it.

    Build/Run often with this task to make sure you're not breaking the code with each step.
    I recommend committing after you get each step working so you can revert to a working version easily if needed.
 
 1) add pow() functions, and a powInternal() function to each of your UDTs
     a) your pow() functions should call powInternal()
     b) add a pow() whose argument type is the primitive your UDT owns.  the argument should be passed by copy.
     c) for each UDT in the file, your class should have pow() overloads that take that UDT as the function argument.
         the argument should be passed as const ref
         i.e. if you had UDTs named IntType, FloatType, DoubleType
             in your IntType class, you'd have:
                 pow(const IntType&),
                 pow(const FloatType&),
                 pow(const DoubleType&),
                 and pow(int)
     d) be sure to remember the rules about what member functions can be called on const objects.
             (const objects can only call their const member functions)
     e) the pow() functions should be chainable.
 
 2) your powInternal() function should do something like this in its body:    *val = std::pow( *val, arg );
         where 'arg' is the passed-in type, converted to whatever type your object is holding.
             if your UDT owns an int, then arg would be an int.
             if your UDT owns a float, then arg would be a float.
         std::pow's documentation is found here: https://en.cppreference.com/w/cpp/numeric/math/pow so be sure to include
             the proper header file listed there.
         powInternal() should be chainable.
         powInternal() should be a private member function
 
 3) modify the Point class below to have 3 Constructors that accept your UDTs and one that accepts primitives.
     a) make the constructor that takes primitives initialize the two member variables.
     b) for each of your 3 Ctors that accept UDTs: correctly implement a Delegating Constructor that calls the constructor which takes primitives
     c) overload the multiply() function so it can accept each of your UDTs.  I've added an implementation you can mimick for this function.
     d) add a toString() function to the Point class that prints out the x and y members via std::cout.
 
 4) mark your UDT constructors as 'explicit'.  
    Adding this keyword prevents the compiler from implicitly creating instances of your UDT whenever primitives are passed to functions that take your UDT by const reference.
    This keyword means you can only create an instance of the class by Explicitly writing the type name.
    You can learn more about the explicit keyword here: 
    https://en.cppreference.com/w/cpp/language/explicit
 
 5) insert part4(); at the end of main, before the 'good to go'
 
 6) make sure it compiles without errors.
 
 You will need to use Forward Declaration and out-of-class definitions to complete this.
 */
#include <iostream>
#include <cmath>

struct FloatType;
struct DoubleType;
struct IntType;

struct Point
{
    explicit Point(const FloatType& _x, const FloatType& _y);
    explicit Point(const DoubleType& _x, const DoubleType& _y);
    explicit Point(const IntType& _x, const IntType& _y);
    explicit Point(float _x, float _y);

    Point& multiply(FloatType& f);
    Point& multiply(DoubleType& d);
    Point& multiply(IntType& i);
    Point& multiply(float m);

    void toString();

private:
    float x{0}, y{0};
};

/*
your program should generate the following output EXACTLY.
This includes the warnings.  
 The output should have zero warnings.


FloatType add result=4
FloatType subtract result=2
FloatType multiply result=4
FloatType divide result=0.25

DoubleType add result=4
DoubleType subtract result=2
DoubleType multiply result=4
DoubleType divide result=0.8

IntType add result=4
IntType subtract result=2
IntType multiply result=4
IntType divide result=1

Chain calculation = 590
New value of ft = (ft + 3.0f) * 1.5f / 5.0f = 0.975
---------------------

Initial value of dt: 0.8
Initial value of it: 590
Use of function concatenation (mixed type arguments) 
New value of dt = (dt * it) / 5.0f + ft = 95.375
---------------------

Intercept division by 0 
New value of it = it / 0 = error: integer division by zero is an error and will crash the program!
590
New value of ft = ft / 0 = warning: floating point division by zero!
inf
New value of dt = dt / 0 = warning: floating point division by zero!
inf
---------------------

The result of FloatType^4 divided by IntType is: 26.9136
The result of DoubleType times 3 plus IntType is : 67.3
The result of IntType divided by 3.14 multiplied by DoubleType minus FloatType is: 711
An operation followed by attempts to divide by 0, which are ignored and warns user: 
error: integer division by zero is an error and will crash the program!
error: integer division by zero is an error and will crash the program!
error: integer division by zero is an error and will crash the program!
505521
FloatType x IntType  =  13143546
(IntType + DoubleType + FloatType) x 24 = 315447336
Power tests with FloatType 
pow(ft1, floatExp) = 2^2 = 4
pow(ft1, itExp) = 4^2 = 16
pow(ft1, ftExp) = 16^2 = 256
pow(ft1, dtExp) = 256^2 = 65536
---------------------

Power tests with DoubleType 
pow(dt1, doubleExp) = 2^2 = 4
pow(dt1, itExp) = 4^2 = 16
pow(dt1, ftExp) = 16^2 = 256
pow(dt1, dtExp) = 256^2 = 65536
---------------------

Power tests with IntType 
pow(it1, intExp) = 2^2 = 4
pow(it1, itExp) = 4^2 = 16
pow(it1, ftExp) = 16^2 = 256
pow(it1, dtExp) = 256^2 = 65536
===============================

Point tests with float argument:
Point { x: 3, y: 6 }
Multiplication factor: 6
Point { x: 18, y: 36 }
---------------------

Point tests with FloatType argument:
Point { x: 3, y: 3 }
Multiplication factor: 3
Point { x: 9, y: 9 }
---------------------

Point tests with DoubleType argument:
Point { x: 3, y: 4 }
Multiplication factor: 4
Point { x: 12, y: 16 }
---------------------

Point tests with IntType argument:
Point { x: 3, y: 4 }
Multiplication factor: 5
Point { x: 15, y: 20 }
---------------------

good to go!

Use a service like https://www.diffchecker.com/diff to compare your output. 
*/

struct A {};
struct HeapA
{ 
    HeapA() : a(new A) {}
    ~HeapA()
    {
        delete a;
    }
    A* a = nullptr;
};



/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

// FLOAT DECLARATION

struct FloatType
{
    explicit FloatType(float v);

    FloatType& add(float a);
    FloatType& subtract(float a);
    FloatType& multiply(float a);
    FloatType& divide(float a);
    FloatType& pow(const IntType&);
    FloatType& pow(const FloatType&);
    FloatType& pow(const DoubleType&);
    FloatType& pow(float);
    operator float() const;

private:
    FloatType& powInternal(const float);
    float* value;
};

// DOUBLE DECLARATION

struct DoubleType
{
    explicit DoubleType(double v);

    DoubleType& add(double a);
    DoubleType& subtract(double a);
    DoubleType& multiply(double a);
    DoubleType& divide(double a);
    DoubleType& pow(const IntType&);
    DoubleType& pow(const FloatType&);
    DoubleType& pow(const DoubleType&);
    DoubleType& pow(double);
    operator double() const;

private:
    DoubleType& powInternal(const double);
    double* value;
};

// INT DECLARATION

struct IntType
{
    explicit IntType(int v);

    IntType& add(int a);
    IntType& subtract(int a);
    IntType& multiply(int a);
    IntType& divide(int a);
    IntType& pow(const IntType&);
    IntType& pow(const FloatType&);
    IntType& pow(const DoubleType&);
    IntType& pow(int);
    operator int() const;

private:
    IntType& powInternal(const int);
    int* value;
};

// FLOAT IMPLEMENTATION

FloatType::FloatType(float v) : value(new float(v)) {}

FloatType& FloatType::add(float a)
{
    *value += a;
    return *this;
}

FloatType& FloatType::subtract(float a)
{
    *value -= a;
    return *this;
}

FloatType& FloatType::multiply(float a)
{
    *value *= a;
    return *this;
}

FloatType& FloatType::divide(float a)
{
    if (a == .0f)
    {
        std::cout << "warning: floating point division by zero!\n";
    }
    *value /= a;
    return *this;
}

FloatType& FloatType::pow(const IntType& exp)
{
    return powInternal(static_cast<float>(exp));
}

FloatType& FloatType::pow(const FloatType& exp)
{
    return powInternal(static_cast<float>(exp));
}

FloatType& FloatType::pow(const DoubleType& exp)
{
    return powInternal(static_cast<float>(exp));
}

FloatType& FloatType::pow(const float exp)
{
    return powInternal(exp);
}

FloatType::operator float() const
{
    return *value;
}

FloatType& FloatType::powInternal(const float exp)
{
    *value = std::pow( *value, exp );
    return *this;
}

// DOUBLE IMPLEMENTATION

DoubleType::DoubleType(double v) : value(new double(v)) {}

DoubleType& DoubleType::add(double a)
{
    *value += a;
    return *this;
}

DoubleType& DoubleType::subtract(double a)
{
    *value -= a;
    return *this;
}

DoubleType& DoubleType::multiply(double a)
{
    *value *= a;
    return *this;
}

DoubleType& DoubleType::divide(double a)
{
    if (a == .0)
    {
        std::cout << "warning: floating point division by zero!\n";
    }
    *value /= a;
    return *this;
}

DoubleType& DoubleType::pow(const IntType& exp)
{
    return powInternal(static_cast<double>(exp));
}

DoubleType& DoubleType::pow(const FloatType& exp)
{
    return powInternal(static_cast<double>(exp));
}

DoubleType& DoubleType::pow(const DoubleType& exp)
{
    return powInternal(static_cast<double>(exp));
}

DoubleType& DoubleType::pow(double exp)
{
    return powInternal(exp);
}

DoubleType::operator double() const
{
    return *value;
}

DoubleType& DoubleType::powInternal(const double exp)
{
    *value = std::pow( *value, exp );
    return *this;
}

// INT IMPLEMENTATION

IntType::IntType(int v) : value(new int(v)) {}

IntType& IntType::add(int a)
{
    *value += a;
    return *this;
}

IntType& IntType::subtract(int a)
{
    *value -= a;
    return *this;
}

IntType& IntType::multiply(int a)
{
    *value *= a;
    return *this;
}

IntType& IntType::divide(int a)
{
    if (a == 0)
    {
        std::cout << "error: integer division by zero is an error and will crash the program!\n";
        return *this;
    }
    *value /= a;
    return *this;
}

IntType& IntType::pow(const IntType& exp)
{
    return powInternal(static_cast<int>(exp));
}

IntType& IntType::pow(const FloatType& exp)
{
    return powInternal(static_cast<int>(exp));
}

IntType& IntType::pow(const DoubleType& exp)
{
    return powInternal(static_cast<int>(exp));
}

IntType& IntType::pow(int exp)
{
    return powInternal(exp);
}

IntType::operator int() const
{
    return *value;
}

IntType& IntType::powInternal(int exp)
{
    *value = static_cast<int>(std::pow( *value, exp ));
    return *this;
}

// POINT IMPLEMENTATION

Point::Point(const FloatType& _x, const FloatType& _y) : x(static_cast<float>(_x)), y(static_cast<float>(_y)) { }

Point::Point(const DoubleType& _x, const DoubleType& _y) : x(static_cast<float>(_x)), y(static_cast<float>(_y)) { }

Point::Point(const IntType& _x, const IntType& _y) : x(static_cast<float>(_x)), y(static_cast<float>(_y)) { }

Point::Point(float _x, float _y) : x(_x), y(_y) { }

Point& Point::multiply(FloatType& f)
{
    return multiply(static_cast<float>(f));
}

Point& Point::multiply(DoubleType& d)
{
    return multiply(static_cast<float>(static_cast<double>(d)));
}

Point& Point::multiply(IntType& i)
{
    return multiply(static_cast<float>(static_cast<int>(i)));
}

Point& Point::multiply(float m)
{
    x *= m;
    y *= m;
    return *this;
}

void Point::toString()
{
    std::cout << "Point { x: " << x << ", y: " << y << " }" << std::endl;
}

void part3()
{
    FloatType ft( 5.5f );
    DoubleType dt( 11.1 );
    IntType it ( 34 );
    DoubleType pi( 3.14 );

    std::cout << "The result of FloatType^4 divided by IntType is: " << ft.multiply( ft ).multiply( ft ).divide( static_cast<float>(it) ) << std::endl;
    std::cout << "The result of DoubleType times 3 plus IntType is : " << dt.multiply( 3 ).add( it ) << std::endl;
    std::cout << "The result of IntType divided by 3.14 multiplied by DoubleType minus FloatType is: " << it.divide( static_cast<int>(pi) ).multiply( static_cast<int>(dt) ).subtract( static_cast<int>(ft) ) << std::endl;
    std::cout << "An operation followed by attempts to divide by 0, which are ignored and warns user: " << std::endl;
    std::cout << it.multiply(it).divide(0).divide(0.0f).divide(0.0) << std::endl;

    std::cout << "FloatType x IntType  =  " << it.multiply( int(ft) ) << std::endl;
    std::cout << "(IntType + DoubleType + FloatType) x 24 = " << it.add( int(dt) ).add( int(ft) ).multiply( int(24) ) << std::endl;
}

void part4()
{
    // ------------------------------------------------------------
    //                          Power tests
    // ------------------------------------------------------------
    FloatType ft1(2);
    DoubleType dt1(2);
    IntType it1(2);    
    float floatExp = 2.0f;
    double doubleExp = 2.0;
    int intExp = 2;
    IntType itExp(2);
    FloatType ftExp(2.0f);
    DoubleType dtExp(2.0);

    // Power tests with FloatType
    std::cout << "Power tests with FloatType" << std::endl;
    std::cout << "pow(ft1, floatExp) = " << ft1 << "^" << floatExp << " = " << ft1.pow(floatExp)  << std::endl;
    std::cout << "pow(ft1, itExp) = " << ft1 << "^" << itExp << " = " << ft1.pow(itExp)  << std::endl;
    std::cout << "pow(ft1, ftExp) = " << ft1 << "^" << ftExp << " = " << ft1.pow(ftExp)  << std::endl;    
    std::cout << "pow(ft1, dtExp) = " << ft1 << "^" << dtExp << " = " << ft1.pow(dtExp)  << std::endl;    
    std::cout << "---------------------\n" << std::endl;  

    // Power tests with DoubleType
    std::cout << "Power tests with DoubleType" << std::endl;
    std::cout << "pow(dt1, doubleExp) = " << dt1 << "^" << doubleExp << " = " << dt1.pow(intExp)  << std::endl;
    std::cout << "pow(dt1, itExp) = " << dt1 << "^" << itExp << " = " << dt1.pow(itExp)  << std::endl;
    std::cout << "pow(dt1, ftExp) = " << dt1 << "^" << ftExp << " = " << dt1.pow(ftExp)  << std::endl;    
    std::cout << "pow(dt1, dtExp) = " << dt1 << "^" << dtExp << " = " << dt1.pow(dtExp)  << std::endl;    
    std::cout << "---------------------\n" << std::endl;    

    // Power tests with IntType
    std::cout << "Power tests with IntType" << std::endl;
    std::cout << "pow(it1, intExp) = " << it1 << "^" << intExp << " = " << it1.pow(intExp)  << std::endl;
    std::cout << "pow(it1, itExp) = " << it1 << "^" << itExp << " = " << it1.pow(itExp)  << std::endl;
    std::cout << "pow(it1, ftExp) = " << it1 << "^" << ftExp << " = " << it1.pow(ftExp)  << std::endl;    
    std::cout << "pow(it1, dtExp) = " << it1 << "^" << dtExp << " = " << it1.pow(dtExp)  << std::endl;    
    std::cout << "===============================\n" << std::endl; 

    // ------------------------------------------------------------
    //                          Point tests
    // ------------------------------------------------------------
    FloatType ft2(3.0f);
    DoubleType dt2(4.0);
    IntType it2(5);
    float floatMul = 6.0f;

    // Point tests with float
    std::cout << "Point tests with float argument:" << std::endl;
    Point p0(ft2, floatMul);
    p0.toString();   
    std::cout << "Multiplication factor: " << floatMul << std::endl;
    p0.multiply(floatMul); 
    p0.toString();   
    std::cout << "---------------------\n" << std::endl;

    // Point tests with FloatType
    std::cout << "Point tests with FloatType argument:" << std::endl;
    Point p1(ft2, ft2);
    p1.toString();   
    std::cout << "Multiplication factor: " << ft2 << std::endl;
    p1.multiply(ft2); 
    p1.toString();   
    std::cout << "---------------------\n" << std::endl;

    // Point tests with DoubleType
    std::cout << "Point tests with DoubleType argument:" << std::endl;
    Point p2(ft2, static_cast<float>(dt2));
    p2.toString();   
    std::cout << "Multiplication factor: " << dt2 << std::endl;
    p2.multiply(dt2); 
    p2.toString();   
    std::cout << "---------------------\n" << std::endl;

    // Point tests with IntType
    std::cout << "Point tests with IntType argument:" << std::endl;
    Point p3(ft2, static_cast<float>(dt2));
    p3.toString();   
    std::cout << "Multiplication factor: " << it2 << std::endl;
    p3.multiply(it2); 
    p3.toString();   
    std::cout << "---------------------\n" << std::endl;
}

int main()
{   
    //testing instruction 0
    HeapA heapA; 

    //assign heap primitives
    FloatType ft ( 2.0f );
    DoubleType dt ( 2 );
    IntType it ( 2 ) ;

    std::cout << "FloatType add result=" << ft.add( 2.0f ) << std::endl;
    std::cout << "FloatType subtract result=" << ft.subtract( 2.0f ) << std::endl;
    std::cout << "FloatType multiply result=" << ft.multiply( 2.0f ) << std::endl;
    std::cout << "FloatType divide result=" << ft.divide( 16.0f) << std::endl << std::endl;

    std::cout << "DoubleType add result=" << dt.add(2.0) << std::endl;
    std::cout << "DoubleType subtract result=" << dt.subtract(2.0) << std::endl;
    std::cout << "DoubleType multiply result=" << dt.multiply(2.0) << std::endl;
    std::cout << "DoubleType divide result=" << dt.divide(static_cast<double>(5.f)) << std::endl << std::endl;

    std::cout << "IntType add result=" << it.add(2) << std::endl;
    std::cout << "IntType subtract result=" << it.subtract(2) << std::endl;
    std::cout << "IntType multiply result=" << it.multiply(2) << std::endl;
    std::cout << "IntType divide result=" << it.divide(3) << std::endl << std::endl;
    std::cout << "Chain calculation = " << (it.multiply(1000).divide(2).subtract(10).add(100)) << std::endl;

        // FloatType object instanciation and method tests
    // --------
    std::cout << "New value of ft = (ft + 3.0f) * 1.5f / 5.0f = " << ft.add( 3.0f ).multiply(1.5f).divide(5.0f) << std::endl;

    std::cout << "---------------------\n" << std::endl; 

    // DoubleType/IntType object instanciation and method tests
    // --------
    std::cout << "Initial value of dt: " << dt << std::endl;
    std::cout << "Initial value of it: " << it << std::endl;
    // --------
    std::cout << "Use of function concatenation (mixed type arguments) " << std::endl;
    std::cout << "New value of dt = (dt * it) / 5.0f + ft = " << dt.multiply(it).divide(double(5.0f)).add(double(ft)) << std::endl;

    std::cout << "---------------------\n" << std::endl; 

    // Intercept division by 0
    // --------
    std::cout << "Intercept division by 0 " << std::endl;
    std::cout << "New value of it = it / 0 = " << it.divide(0) << std::endl;
    std::cout << "New value of ft = ft / 0 = " << ft.divide(0) << std::endl;
    std::cout << "New value of dt = dt / 0 = " << dt.divide(0) << std::endl;

    std::cout << "---------------------\n" << std::endl;

    part3();
    part4();

    std::cout << "good to go!\n";

    return 0;
}

/*#include <iostream>

struct FloatType
{
    float add(float lhs, float rhs) { return lhs + rhs; }
    float subtract(float lhs, float rhs) { return lhs - rhs; }
    float multiply(float lhs, float rhs) { return lhs * rhs; }
    float divide(float lhs, float rhs)
    {
        if (rhs == 0.0f)
        {
            std::cout << std::endl << "warning, floating point division by zero returns 'inf' !" << std::endl;
        }
        return lhs / rhs;
    }
};

struct DoubleType
{
    double add(double lhs, double rhs) { return lhs + rhs; }
    double subtract(double lhs, double rhs) { return lhs - rhs; }
    double multiply(double lhs, double rhs) { return lhs * rhs; }
    double divide(double lhs, double rhs)
    {
        if (rhs == 0.0)
        {
            std::cout << std::endl << "warning, floating point division by zero returns 'inf' !" << std::endl;
        }
        return lhs / rhs;
    }
};

struct IntType
{
    int add(int lhs, int rhs) { return lhs + rhs; }
    int subtract(int lhs, int rhs) { return lhs - rhs; }
    int multiply(int lhs, int rhs) { return lhs * rhs; }
    int divide(int lhs, int rhs)
    {
        if (rhs == 0)
        {
            std::cout << "error, integer division by zero will crash the program!" << std::endl;
            std::cout << "returning lhs" << std::endl;
            return lhs; // Return zero as a safe value
        }
        return lhs / rhs;
    }
};

int main() 
{
    FloatType ft;
    std::cout << "result of ft.add(): " << ft.add( 123.456f, 432.1f) << std::endl;
    std::cout << "result of ft.subtract(): " << ft.subtract( 123.456f, 432.1f) << std::endl;
    std::cout << "result of ft.multiply(): " << ft.multiply( 123.456f, 432.1f) << std::endl;
    std::cout << "result of ft.divide(): " << ft.divide( 123.456f, 432.1f) << std::endl;

    std::cout << "result of ft.add(): " << ft.add( 4444.56f, 0.0f)  << std::endl;
    std::cout << "result of ft.subtract(): " << ft.subtract( 4444.56f, 0.0f) << std::endl;
    std::cout << "result of ft.multiply(): " << ft.multiply( 4444.56f, 0.0f) << std::endl;
    std::cout << "result of ft.divide(): " << ft.divide( 4444.56f, 0.0f) << std::endl;

    DoubleType db;
    std::cout << "result of db.add(): " << db.add( 123.456, 432.1) << std::endl;
    std::cout << "result of db.subtract(): " << db.subtract( 123.456, 432.1) << std::endl;
    std::cout << "result of db.multiply(): " << db.multiply( 123.456, 432.1) << std::endl;
    std::cout << "result of db.divide(): " << db.divide( 123.456, 432.1) << std::endl;

    std::cout << "result of db.add(): " << db.add( 123.456, 0.0) << std::endl;
    std::cout << "result of db.subtract(): " << db.subtract( 123.456, 0.0) << std::endl;
    std::cout << "result of db.multiply(): " << db.multiply( 123.456, 0.0) << std::endl;
    std::cout << "result of db.divide(): " << db.divide( 123.456, 0.0) << std::endl;

    IntType i;
    std::cout << "result of i.add(): " << i.add( 10, 20) << std::endl;
    std::cout << "result of i.subtract(): " << i.subtract( 10, 20) << std::endl;
    std::cout << "result of i.multiply(): " << i.multiply( 10, 20) << std::endl;
    std::cout << "result of i.divide(): " << i.divide( 10, 20) << std::endl;

    std::cout << "result of i.add(): " << i.add( 10, 0) << std::endl;
    std::cout << "result of i.subtract(): " << i.subtract( 10, 0) << std::endl;
    std::cout << "result of i.multiply(): " << i.multiply( 10, 0) << std::endl;
    std::cout << "result of i.divide(): " << i.divide( 10, 0) << std::endl;

    std::cout << "good to go!" << std::endl;
}*/
