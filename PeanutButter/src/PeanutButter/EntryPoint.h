#pragma once

#ifdef PB_PLATFORM_WINDOWS

extern PeanutButter::Application* PeanutButter::CreateApplication();

int main(int argc, char** argv) {
	PeanutButter::Log::Initialize();
	PB_CORE_WARNING("Initialized Log!");
	PB_INFO("Hello from client!");

	auto app = PeanutButter::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif