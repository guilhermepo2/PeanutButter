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

#ifdef PB_ENABLE_ASSERTS
	#define PB_ASSERT(x, ...) { if (!(x)) { PB_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define PB_CORE_ASSERT(x, ...) { if (!(x)) { PB_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define PB_ASSERT(x, ...)
	#define PB_CORE_ASSERT(x, ...)
#endif




#define BIT(x) (1 << x)