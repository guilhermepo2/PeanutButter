#pragma once
#include "sol.hpp"

#ifdef PB_PLATFORM_WINDOWS

extern PeanutButter::Application* PeanutButter::CreateApplication();

int main(int argc, char** argv) {
	PeanutButter::Log::Initialize();
	PB_CORE_WARNING("[ENTRY POINT] Initialized Log!");

	// Initialize Lua
	// sol::state lua;
	// lua.open_libraries(sol::lib::base, sol::lib::string);
	// lua.script("print('Hello World using sol & lua')");

	PeanutButter::Application* app = PeanutButter::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif