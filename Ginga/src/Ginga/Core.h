#pragma once

#ifdef GINGA_PLATFORM_WINDOWS
	#ifdef GINGA_BUILD_DLL
		#define GINGA_API __declspec(dllexport)
	#else
		#define GINGA_API __declspec(dllimport)
	#endif
#else
	#error Ginga only support Windows!
#endif

#ifdef GINGA_ENABLE_ASSERTS
	#define GINGA_ASSERT(x, ...) { if(!(x)) {GINGA_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define GINGA_CORE_ASSERT(x, ...) { if(!(x)) {GINGA_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define GINGA_ASSERT(x, ...)
	#define GINGA_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define GINGA_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)