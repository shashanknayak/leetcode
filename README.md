# Overview
My solution\musings\notes for leetcode problems

# Useful guidelines

* Pair up your interfaces with implementations. If you have foo.cxx, everything defined in there had better be declared in foo.h.
* Ensure that every header file #includes all other necessary headers or forward-declarations necessary for independent compilation.
* Resist the temptation to create an "everything" header. They're always trouble down the road.
* Put a set of related (and interdependent) functionality into a single file. Java and other environments encourage one-class-per-file. With C++, you often want one set of classes per file. It depends on the structure of your code.
* Prefer forward declaration over #includes whenever possible. This allows you to break the cyclic header dependencies. Essentially, for cyclical dependencies across separate files, you want a file-dependency graph that looks something like this:
A.cxx requires A.h and B.h
B.cxx requires A.h and B.h
A.h requires B.h
B.h is independent (and forward-declares classes defined in A.h)

### If your code is intended to be a library consumed by other developers, there are some additional steps that are important to take:

* If necessary, use the concept of "private headers". That is, header files that are required by several source files, but never required by the public interface. This could be a file with common inline functions, macros, or internal constants.
Separate your public interface from your private implementation at the filesystem level. I tend to use include/ and src/ subdirectories in my C or C++ projects, where include/ has all of my public headers, and src/ has all of my sources. and private headers.

# Books

1. Large-Scale C++ Software Design