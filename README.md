# C-Minus-Minus (C--)
C-- stands for C Minus Minus, which is a version developed by Sahne Dünya that is based on the Classic C language but offers fewer features. It is a very interesting idea to develop this programming language because while many programming languages ​​try to add more features than before, this programming language tried to add less features than before! At first, many people will think that the developer of this language is on the wrong path, but this is actually the opposite. Each programming language has a different purpose and programming languages ​​are shaped according to their purpose. The C-- programming language is actually considered the core of the Classic C language. Because it lacks the Standard Library, Comments feature, and does not support the switch and match features, only supports if-else! The features that are the same as Classic C are basic features, manual memory management, and the need for a header file.

# Differences between C-- programming language and Classic C/C++:
1. Lack of Standard C Library: It is one of the biggest differences in C-- programming language! Classic C/C++ language has Standard Library, but C-- does not have Standard Library, which means you need to write more code for an operation, because standard libraries provide a ready-made code collection for the programming language, which makes writing code easier!
2. Supporting only if-else statements: As you know, if-else is one of the most important commands in the history of programming, but newer switch and match statements have emerged! While if-else and switch are supported in the classical C language, C++ supports an additional match statement, but switch is usually used. The C-- programming language only supports if-else, which makes coding difficult because commands such as switch and match can do more than one operation when written once, but if-else requires more than one if-else command for more than one operation!
3. Lack of Comments feature: Comments feature, which is a basic feature in modern programming languages, allows us to write informative texts that are completely ignored by the compiler or interpreter, but this feature is not mandatory but it makes things easier!, Classic C/C++ has this feature, while C-- language lacks this feature because it asks you for every detail!
4. Basically supported paradigm: You know, paradigms in programming languages ​​directly affect programming styles! Classic C language basically supports a procedural (imperative) programming paradigm. This paradigm involves structuring the program as a series of sequential commands (called procedures or functions). The flow of the program is controlled by executing these commands in a certain order. In C++, it basically supports object-oriented programming (OOP), which is a feature found in many modern programming languages, and supports basic OOP concepts such as classes, objects, inheritance, polymorphism and encapsulation. This allows large and complex software to be developed in a more organized and manageable way. In C--, it supports the imperative paradigm, which is a lower-level approach than others. Imperative programming is based on the sequential execution of a series of commands that change the state of the program. In assembly language, the programmer specifies each step that the processor should take (loading data, performing operations, storing results, etc.) one by one. This is the basic feature of the imperative paradigm.

5.The purpose of this programming language: The main purpose of the Classic C language is to meet the needs of system programming, while C++ is to provide high performance, efficiency and flexibility, allowing the development of a wide range of applications. The purpose of C-- is different, first of all, the person who developed this programming language did not develop it with the wrong mindset! The main purpose of this language is flexibility! You can actually accept the C-- programming language as the core of the Classic C language. Let me give an example in free software, there is only one official component in the Linux operating system, that is the core, the remaining components are third-party! There is only one official component in the C-- programming language, that is itself, and the fact that it lacks some features will encourage you to use the third party! This means incredible flexibility! You can use the C-- programming language as the core when creating a new programming language! In fact, some components in the classical C and C++ languages ​​also need third parties, such as a package manager, compiler, linker, and an additional external library is needed in the C-- language!

# Basic features
* File extension: .cmm and .hmm (For C Minus Minus)
* Memory Management: Manually
* Compilation type: Ahead-of-Time
* The executable file developed for it: .cminus
* Underlying programming language: Classic C Programing Languge
* Modern language features: no
* Standard Libray: no

# Target Hello World code
```
extern void putc_lowlevel(char c);

int main() {

    putc_lowlevel('H');
    putc_lowlevel('e');
    putc_lowlevel('l');
    putc_lowlevel('l');
    putc_lowlevel('o');
    putc_lowlevel(',');
    putc_lowlevel(' ');
    putc_lowlevel('W');
    putc_lowlevel('o');
    putc_lowlevel('r');
    putc_lowlevel('l');
    putc_lowlevel('d');
    putc_lowlevel('!');
    putc_lowlevel('\n');

    return 0;
}
