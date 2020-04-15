#include <PeanutButter.h>

class Sandbox : public PeanutButter::Application {
public:
	Sandbox() {}
	Sandbox(const char* WindowTitle, pb_int16 WindowWidth, pb_int16 WindowHeight) : PeanutButter::Application(WindowTitle, WindowWidth, WindowHeight) {}
	~Sandbox() override {}
};

PeanutButter::Application* PeanutButter::CreateApplication() {
	return new Sandbox("My Fancy Game", 640, 360);
}