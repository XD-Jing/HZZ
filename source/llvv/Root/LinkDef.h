#ifndef LLVV_LINKDEF_H
#define LLVV_LINKDEF_H

// Some common definitions:
#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;
#pragma link C++ nestedclass;

// Declare the class(es) to generate dictionaries for:
#pragma link C++ class aFactor+;

#endif // LLVV_LINKDEF_H
