#ifndef STDINCLUDE_H_
#define STDINCLUDE_H_


#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>

#include <sys/types.h>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define _gerr(x) { fputs(x, stderr); /*system("pause");*/ exit(-1); }

#ifndef ASDLIBRARY_DEBUG_ON
#define ASDLIBRARY_DEBUG_ON false
#endif

#define __DEBUG(msg) { if ( ASDLIBRARY_DEBUG_ON ) { fputs(msg, stderr); fputs("\n", stderr); } }


#endif /*STDINCLUDE_H_*/
