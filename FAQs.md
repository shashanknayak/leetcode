# Frequently asked questions (by me)

## Is it a good practice to place C++ definitions in header files?

If you want to use a function in multiple source files (or rather, translation units), then you place a function declaration (i.e. a function prototype) in the header file, and the definition in one source file.

Then when you build, you first compile the source files to object files, and then you link the object files into the final executable.

There is occasionally some merit to putting code in the header, this can allow more clever inlining by the compiler. But at the same time, it can destroy your compile times since all code has to be processed every time it is included by the compiler.

Finally, it is often annoying to have circular object relationships (sometimes desired) when all the code is the headers.

Many newer "modern" libraries such as boost make heavy use of templates and often are "header only." However, this should only be done when dealing with templates as it is the only way to do it when dealing with them.

Boost is library, not user level code. so it doesn't change that often. In user code, if you put everything in headers, every little change will cause you to have to recompile the entire project. That's a monumental waste of time (and is not the case for libraries that don't change from compile to compile). When you split things between header/source and better yet, use forward declarations to reduce includes, you can save hours of recompiling when added up across a day.