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


/* outputs of the compilation process
User
what types of built outpot can be generated from c++

ChatGPT
From a C++ compiler, several types of output can be generated based on the compilation process:
Executable Binary: This is the primary output produced by the compiler. It's an executable file that can be directly run 
on the operating system. This file contains machine code that the CPU can execute.

Object Files (.o or .obj): Intermediate files generated during the compilation process, containing machine code in a 
relocatable format. These files are later linked together to form the final executable. They are platform-specific and 
not directly executable.

Static Libraries (.lib, .a): Collections of object files bundled together into a single file. They can be linked directly 
into an executable during the linking phase. They're useful for reusing code across multiple projects.

Dynamic Libraries (DLLs, .so, .dylib): Similar to static libraries but loaded into memory at runtime when the program 
starts or explicitly using dynamic linking. These libraries can be shared among multiple programs and loaded at runtime.

Assembly Files (.s): Intermediate files that contain assembly code generated by the compiler from the source code. 
Useful for understanding low-level code and performance analysis.

Debug Information Files (.pdb, .dSYM): Files containing debugging information, aiding in the debugging process by mapping 
machine code back to the original source code. These files help in setting breakpoints, inspecting variables, etc.

The output generated from the compilation process depends on various compiler flags, settings, and the intended use of 
the program. Different build systems and compilers may generate slightly different types of output files.
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
                    // iostream (Input/Output Stream): provides functionality for input and output operations 
                    // using the standard input/output streams (std::cin and std::cout) and basic formatting.
                    // iostream is part of the C++ Standard Library, not the C Standard Library. It is specific to C++ and provides functionality for input and output operations.
                    // iostream provides functionality for input and output operations using the standard input / output streams(std::cin and std::cout) and basic formatting.

#include <cstdio>  /*
                    <cstdio> is a header file in C++ that corresponds to the C Standard Library header <stdio.h>. 
                    It provides functionality for input and output operations in a C-style manner. 
                    The content of <cstdio> is based on the C standard I/O library and contains declarations for functions, 
                    macros, and types used for file input and output.
                    The contents of <cstdio> header include functions like fopen, fclose, fprintf, fscanf, fgets, fputs, etc., 
                    which are used for file handling, input, and output operations. It also includes FILE type definition and
                    various constants for error handling and file access modes.
                    In C++, the <cstdio> header is part of the C++ Standard Library's adaptation of the C Standard Library. 
                    It encapsulates the functionalities of the C standard I/O library in the std namespace, so functions and 
                    types are available under the std:: namespace. For instance, std::FILE, std::fopen(), std::fclose()
                    
 example of using cstdio 
 #include <cstdio>

int main() {
    FILE* file = std::fopen("example.txt", "w");
    if (file != nullptr) {
        std::fprintf(file, "This is a sample text.\n");
        std::fclose(file);
        std::puts("File written successfully.");
    } else {
        std::perror("Error opening the file.");
    }
    return 0;
}

other operations by cstdio:
1. File Operations: Functions like fopen, fclose, fwrite, fread, fprintf, fscanf, etc., are used for file I/O operations.
2. Standard Input/Output: Functions like printf, scanf, putchar, getchar, puts, gets, etc., are used for standard console 
input and output.
3. Error Handling: Macros like EOF (end-of-file indicator) and functions like perror (print error message) help with error 
handling during I/O operations.
4. Formatted Output: sprintf, snprintf, and related functions allow formatted data to be stored in strings.

[BKM] stdio vs iostream, which to use?
it is better to use iostrea for input output operations because it is more type safe and object-oriented

[BK] what is type-safe?
In programming, "type safety" refers to a language's ability to catch and prevent type-related errors during 
compile-time or runtime. It ensures that operations on data are performed with the correct types, reducing the 
likelihood of unexpected behavior or errors due to type mismatches.

In the context of C++ and <iostream>, here's what "type-safe" means:
Compile-Time Checks: With <iostream> and its stream-based approach (std::cin, std::cout, etc.), 
data types are enforced at compile time. For instance, if you try to read an integer from std::cin into 
a variable of type int, the compiler ensures that the input matches the expected type.

Type Inference: Streams in <iostream> automatically handle the conversion of different data types. 
For example, when you use << or >> with std::cout or std::cin, the stream adapts to the data type 
you're working with, providing a level of type safety.

Prevention of Undefined Behavior: By using stream operators like << and >>, you avoid certain pitfalls 
of C-style I/O functions that don't enforce type safety. For instance, if you accidentally pass an incorrect 
argument to a C-style printf format specifier, it might lead to undefined behavior or runtime errors.

Object-Oriented Approach: <iostream> employs an object-oriented paradigm with stream objects 
(std::cin, std::cout, etc.) that encapsulate data and behaviors. This approach promotes a more modular, reusable, 
and safer way to perform input and output operations.
                    */

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
