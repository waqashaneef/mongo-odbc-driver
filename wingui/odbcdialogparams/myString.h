#ifndef __MYSTRING_H__

#define __MYSTRING_H__

#ifndef _DO_NOT_USE_STRING_

/** Type definitions and includes if _use_ string class*/
#include <xstring>
typedef std::wstring		myString;

#else

/** Type definitions and includes if _do_not_ use string class*/

#include <sqltypes.h>

typedef SQLWCHAR*			myString;

#endif /*using wstring or wchar_t **/

/*myString & operator += ( myString & lhs, const wchar_t * rhs);*/
static const size_t InvalidSize = size_t(-1);

#ifndef _ODBCPARAMDLL
#ifdef ODBCDIALOGPARAMS_EXPORTS
#define _ODBCPARAMDLL __declspec(dllexport)
#else
#define _ODBCPARAMDLL __declspec(dllimport)
#endif
#endif

size_t      myReserveMemory ( myString &oldptr, size_t newLen );
myString &  concat          ( myString &left, const myString &right );

size_t      myStrlen        ( const myString & str );

myString &  strAssign       ( myString &dest, const myString & src );
myString &  strAssign       ( myString &dest, const wchar_t * src );

/*** List related functions */
void        add2list	    ( WCHAR ** & list, const wchar_t * newmember );
void        clearList	    ( WCHAR ** & list );
size_t      listSize	    ( const WCHAR ** list );

#endif /* __MYSTRING__*/