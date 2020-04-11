#pragma once

#ifdef PB_PLATFORM_WINDOWS
	#ifdef PB_BUILD_DLL
		#define PB_API __declspec(dllexport)
	#else
		#define PB_API __declspec(dllimport)
	#endif
#endif