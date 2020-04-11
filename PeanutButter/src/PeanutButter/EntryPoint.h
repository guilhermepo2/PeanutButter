#pragma once

#ifdef PB_PLATFORM_WINDOWS

extern PeanutButter::Application* PeanutButter::CreateApplication();

int main(int argc, char** argv) {
	auto app = PeanutButter::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif