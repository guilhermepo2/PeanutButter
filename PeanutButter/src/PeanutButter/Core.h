#pragma once
#include <SDL.h> // oh no

// Peanut Butter Data Types ---------------- |
typedef unsigned char pb_uint8;
typedef unsigned short int pb_uint16;
typedef unsigned int pb_uint32;
typedef unsigned long long pb_uint64;
typedef char pb_int8;
typedef short int pb_int16;
typedef int pb_int32;
typedef long long pb_int64;
// -------------------------------------------|


// Render Layers ------------------------
enum ELayerType {
	ELT_TilemapLayer = 0,
	ELT_VegetationLayer = 1,
	ELT_EnemyLayer = 2,
	ELT_PlayerLayer = 3,
	ELT_ProjectileLayer = 4,
	ELT_UILayer = 5
};

#define NUMBER_OF_LAYERS  6
// -------------------------------------------|

// Collision Layers ----------------------
enum ECollisionType {
	ECL_NoCollision = 0,
	ECL_Collision = 1
};
// -------------------------------------------|

// Colors -------------------------------
const SDL_Color PB_COLOR_WHITE = { 255, 255, 255, 255 };
const SDL_Color PB_COLOR_RED = { 255, 0, 0, 255 };
const SDL_Color PB_COLOR_GREEN = { 0, 255, 0, 255 };
const SDL_Color PB_COLOR_BLUE = { 0, 0, 255, 255 };
#define PB_COLOR(...) SDL_Color { __VA_ARGS__ }
// -------------------------------------------|

#ifdef PB_PLATFORM_WINDOWS
	#ifdef PB_BUILD_DYNAMIC
		#ifdef PB_BUILD_DLL
			#define PB_API __declspec(dllexport)
		#else
			#define PB_API __declspec(dllimport)
	#endif
	#else
		#define PB_API
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