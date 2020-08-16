#pragma once

extern PeanutButter::Application* PeanutButter::CreateApplication();

int main(int argc, char** argv) {
	PeanutButter::Log::Initialize();
	PB_CORE_WARNING("[ENTRY POINT] Initialized Log!");

	PeanutButter::Application* app = PeanutButter::CreateApplication();
	app->Run();
	delete app;
	return 0;
}
