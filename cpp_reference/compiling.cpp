/*
reference on optimizing c++ code
* optimization: https://www.tantalon.com/pete/cppopt/main.htm 


What is a compiler?
-------------------
A computer can only understand machine language and humans wish to write in high level languages high level languages have to 
be re-written (translated) into machine language at some point. This is done by special programs called compilers, interpreters, 
or assemblers that are built into the various programming applications.

C++ is a compiled language
--------------------------
C++ is designed to be a compiled language, meaning that it is generally translated into machine language that can be understood 
directly by the system, making the generated program highly efficient. For that, a set of tools are needed, known as the development 
toolchain, whose core are a compiler and its linker.

What is a console program?
--------------------------
Console programs are programs that use text to communicate with the user and the environment, such as printing text to the 
screen or reading input from a keyboard.

Why console programs
--------------------
1- Console programs are easy to interact with, and generally have a predictable behavior that is identical across all platforms.
2- They are also simple to implement and thus are very useful to learn the basics of a programming language: The examples in these 
tutorials are all console programs.

Commandline to compile c++ programs on unix
-------------------------------------------
g++ -std=c++0x example.cpp -o example_program

what is a compiler, again
-------------------------
A compiler tool chain is a pipeline of software tools that convert code in a few big steps.
There are three cases of compiler input I want to show you. Now think of these three cases as
three important parts of a single software development project.

case 1:
1- The first case is when you write your C++ source files. Then you feed those files to the compiler,
which is the first big program the code goes through.

2- The compiler translates your C++ code into assembly language, which is a human readable version of the native language of the target CPU.
So a new file with assembly code is created.

3- This file is fed to a second program known as the assembler. The assembler produces an object file, which is almost executable,
but it may contain just pieces of the code you want to use in your final executable.

case 2:
The second input case is when you write your own assembly code. Although this can be a hassle, sometimes you have no choice but to write
some low level code. This is often the case when you need to write a peripheral driver.
So in this case, you may feed an assembly file to the assembler and it will produce another object file.

case 3:
The third case is when you include libraries for which you don't have access to the source code.In fact, libraries are often distributed
as object files or some compatible variant.But you may include these just like we've been including I/O stream or string in our examples.
Now we're left with a handful of object files, which are correlated pieces of your project.
These files are sent to a third program known as the linker.The linker's job is to stitch these object files together to produce an executable
binary file. This is the program you finally get to run.
Specifying all the files to compile is fairly easy if you use an integrated development environment, or IDE.

However, at some point you may have to work with a compiler in the command line and it can get complicated. All this information is orderly 
specified in a text file known as a make file. Once again, IDEs take care of this for you. Now let's focus on the C++ source files.
C++ code is usually written as a header and implementation file pair.These two files have the same name, but the header file usually has 
the.h extension, while the implementation file has the.cpp extension.Header files contain class definitionsand function declarations.
They may also contain macros, but no executable code.Implementation files contain, well, the implementation of all functions declared in the header file.
That's the executable code. Implementation files must include their corresponding header files because the compiler needs to see the class 
definitions and function declarations before seeing the code in your implementation file. Your external code, the one that uses your classes, 
should only include the header files, not the implementation files. And lastly, all implementation files must be compiled. So let's take our
cow class and take it to its own cow.h and cow.cpp files.I'll add the files in Visual Studio, but it's just as simple in pretty much every other IDE.
I'll start with the CPP file. So let's go to the Solution Explorer, right - click on Source Files and add a new item.It will be a C++ file, 
and I'll name it cow.cpp This action will include this CPP file in the list of files to be compiled. Here's our new empty file.And now for the header file,
let's go back to the Solution Explorer, right-click on Header Files and add a new item. This will be a header file and I'll name it cow.h.Notice that the
new header file starts with the directive pragma once.This is telling the compiler to only include this header file once.It's very common to include the 
same header file in multiple source files, and this is not necessarily a bad practice. So this pragma directive prevents an error where the compiler 
finds definitions it has seen before. That being said, the use of pragma once is not standard. We can see that Visual Studio supports it, but not all compilers do. 
So an alternative for this is using an include guard. An include guard is a simple trick using the ifndef directive. It works like this. You start your header 
files with ifndef, some macro, which usually mimics the file name. This one is called COW_H. The directive means if the COW_H macro is not defined, then 
include the following code. We close the statement with endif, usually with the macro name as a comment. And the first thing in the body of the conditional block 
is the definition of the macro. So that's define COW_H.Again, this is called an include guardand it is supported by all compilers.I'll leave the pragma 
and the include guard for this file, but usually only one is used. Now let me cut and paste the class and enumeration definitions from the main source file
called CodeDemo.cpp to cow.h. Notice in lines 10 and 15, that the string class has a red underline indicating that it is not recognized. 
Let me fix that by including the string header. Also, since I haven't used the using namespace STD line, I must specify the scope of string.
The using keyword is considered a bad practice inside header files, because header files are going to be included by external code.So adding the line 
using namespace STD in a header file would force the whole project to use that namespace.That may cause ambiguities.So let me specify that I 
mean STD::string now in lines 11 and 16. We're almost done. The only problem is that the header file contains the implementation of the member functions. 
So we'll moved the implementations to the CPP file, but I'll leave the declarations of these functions. Basically, I have to leave the header of the 
functions ending each line with a semi-colon. So first, let me copy the implementations and paste them to the CPP file. Now, let me get rid of 
the implementations in the header file. There, our header file is looking good. Now let's tidy up cow.cpp.First, I need to include cow.h.And now I 
need to resolve the scope of all the members of cow in this file.It's very simple. I just have to type cow:: before the name of each function. 
The first one is the constructor. Then we have get_name, and so on and so forth. Finally, let me include cow.h in the main source file. 
And now let's compile and run just to make sure we didn't break anything. It's all looking good.
*/

/**********************************************************************
*                              directives                             *
***********************************************************************/
// get the version of the compiler
#if defined __clang__
constexpr char compiler[] = "Clang";
constexpr char version_string[] = __clang_version__;
constexpr unsigned int version_int = 0;
#elif defined _MSC_VER
constexpr char compiler[] = "Microsoft C++";
constexpr unsigned int version_int = _MSC_VER;
constexpr char version_string[] = "";
#elif defined __GNUG__
constexpr char compiler[] = "gcc";
constexpr char version_string[] = __VERSION__;
constexpr unsigned int version_int = 0;
#else
constexpr char compiler[] = "unk";
constexpr char version_string[] = "unk";
constexpr unsigned int version_int = 0;
#endif // lang

#include <iostream>
#include <windows.h> // needed for the sleep
#include <chrono>
#include <thread>
#include <cstdint>

/*
purpose of the directives:
1- preporcess directives code is preprocessed prior to compiling
2- directives tell the preprocessor what to add or remove in the code
3- useful for libraries, constants, selecting code blocks
*/

// include directives 
#include <iostream> // is a directive. iostream has no dir path so it will search for it in the default location defined in dev env or includes dir.
                    // (standard lib and installed libs)
                    // this whole line will be replaced with the lib iostream 
#include <string> 
#include <cstdint>  // fixed length definition of integer types so doesn't depend on the implementation of primitive types like int or char.
                    // this is a standard c lib so has c code in it. som c libs are made available in c++ and used by c in the beginning of the name

// def directives to define symbols to mean whatever in the right of the symbol. they are called macros.
// be careful to define constants with this because it will search and replace.
#define CAPACITY 5000 // whenever the CAPACITY is found, it will be replaced with the value. naming the define constant is by convention is capital
                      // can be used to define constants but sometimes it is considered as bad practice, because directives don't check for types 
                      // and not in context. instead use regular variables to define constants with constant qualifier.
                      // constants using regular definitions are better because: 
                      //             1) it use regular definition 
                      //             2) declarations specify type 
                      //             3) scope encapsulation is enforced
                      //  constant in c are not the same as in c++, in c lacks a lot of features, that why directives are mostly used in c.
#define DEBUG         // if not defined line 27 to 29 will not run.

// Example using #define/#ifdef/#ifndef directives
int practive_using_ifdef_directive()
{
    int32_t large = CAPACITY;
    uint8_t smallv = 30;

#ifdef DEBUG 
    std::cout << "doing the sum now: \n";
#endif

    large += smallv;
    std::cout << "large: " << large << std::endl;

    return 0;
}

// a number of features can be learned from the simple program of main: 
#include <iostream> // Input and output are not part of the core language but are provided by the library.They must be included explicitly; otherwise we cannot read or write.
                    // The standard I/O has a stream model and is therefore named <iostream>. To enable its functionality, we #include <iostream> in the first line.

// the basic strucutre of a c++ program.
int practive_basic_structure()  // Every C++ program starts by calling the function main. It does return an integer value where 0 represents a successful termination.
{
    std::cout << "The answer  to the Ultimate Question of Life,\n" // The operator << can be used to pass objects to an output stream such as std::cout for performing an output operation.
        << "the Universe, and Everything is:"                      // std:: denotes that the type or function is used from the standard Namespace. Namespaces help us organize our names and deal with naming conflicts.
        << std::endl << 6 * 7 << std::endl;                        // using namespace std; to avoid using std::
    return 0;
}

// The main function is called by the os.
int practice_main_args(int argc, char** argv) {
    return 0;
}

// get the version of the compiler
int practice_get_the_version_of_the_compiler()
{
    if (version_int) {
        printf("%s version %d\n", compiler, version_int);
    }
    else {
        printf("%s version %s\n", compiler, version_string);
    }
    return 0;
}

// using sleep 
int practice_using_sleep()
{
    std::cout << "hello world!" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1)); // to give more time before the program exit.
    return 0;
}


/**********************************************************************
*                              input and output to console            *
***********************************************************************/
// input/output ways 
int practice_out_console()
{
    // 1: cout example
    std::cout << "Hello, World!" << std::endl; // using the c++ standard library <iostream>

    // 2: using puts
    puts("Hello, World!"); // using cstdio c-inherited standard library <cstdio>

    // 3: using printf
    printf("Hello world"); // using <cstdio>
    return 0;

    // 4: printing out err
    std::cerr << "error message" << std::endl;
}

int practice_in_console()
{
    // basic cin 
    int age;
    std::cin >> age;

    // basic cin to two vars
    int a, b;
    std::cin >> a >> b;
    std::cin >> a;
    std::cin >> b;

    // cin string
    std::string mystring;
    std::cin >> mystring;

    // get entire line 
    std::string mystr;
    std::cout << "What's your name? ";
    std::getline(std::cin, mystr);

    return 0;
}

int practice_out___f()
{
    int intVal;
    long longVal;
    char charVal;
    float floatVal;
    double doubleVal;

    //scanf("%d %ld %c %f %lf", &intVal, &longVal, &charVal, &floatVal, &doubleVal);

    /*
    printf("%d\n", intVal);
    printf("%ld\n", longVal);
    printf("%c\n", charVal);
    printf("%f\n", floatVal);
    printf("%lf\n", doubleVal);
    */
    return 0;
}
// using header
#pragma once // to make the compiler only parse that header file once even if it is included multiple times in the source
#ifndef COW_H // this is called include guard
#define COW_H 
#include <iostream> 
#include <string>  // but don't put using namespace std inside the header file because it is considered bad practice, the header file maybe included in other source files and causes ambiguity.

class cow {
public:
    cow(std::string name_i, int age_i, unsigned char purpose_1);
};

#endif
