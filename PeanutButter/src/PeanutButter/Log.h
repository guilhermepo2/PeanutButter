#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace PeanutButter {
	class PB_API Log {
	public:
		static void Initialize();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core Log Macros
#define PB_CORE_TRACE(...)   ::PeanutButter::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PB_CORE_INFO(...)    ::PeanutButter::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PB_CORE_WARNING(...) ::PeanutButter::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PB_CORE_ERROR(...)   ::PeanutButter::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PB_CORE_FATAL(...)   ::PeanutButter::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client Log Macros
#define PB_TRACE(...)   ::PeanutButter::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PB_INFO(...)    ::PeanutButter::Log::GetClientLogger()->info(__VA_ARGS__)
#define PB_WARNING(...) ::PeanutButter::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PB_ERROR(...)   ::PeanutButter::Log::GetClientLogger()->error(__VA_ARGS__)
#define PB_FATAL(...)   ::PeanutButter::Log::GetClientLogger()->fatal(__VA_ARGS__)
