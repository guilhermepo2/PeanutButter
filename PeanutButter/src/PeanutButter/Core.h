#pragma once

// Peanut Butter Data Types
typedef unsigned char pb_uint8;
typedef unsigned short int pb_uint16;
typedef unsigned int pb_uint32;
typedef unsigned long long pb_uint64;
typedef char pb_int8;
typedef short int pb_int16;
typedef int pb_int32;
typedef long long pb_int64;
// ------------------------

#ifdef PB_PLATFORM_WINDOWS
	#ifdef PB_BUILD_DLL
		#define PB_API __declspec(dllexport)
	#else
		#define PB_API __declspec(dllimport)
	#endif
#endif


#define BIT(x) (1 << x)