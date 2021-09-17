#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Ginga {
	class GINGA_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};

}

//Core log macros
#define GINGA_CORE_TRACE(...)	::Ginga::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define GINGA_CORE_INFO(...)	::Ginga::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GINGA_CORE_WARN(...)	::Ginga::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GINGA_CORE_ERROR(...)	::Ginga::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GINGA_CORE_FATAL(...)	::Ginga::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define GINGA_TRACE(...)	::Ginga::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define GINGA_INFO(...)	::Ginga::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GINGA_WARN(...)	::Ginga::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GINGA_ERROR(...)	::Ginga::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GINGA_FATAL(...)	::Ginga::Log::GetCoreLogger()->fatal(__VA_ARGS__)

