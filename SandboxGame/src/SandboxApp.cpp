#include <PeanutButter.h>

class Sandbox : public PeanutButter::Application {
public:
	Sandbox() {}
	~Sandbox() override {}
};

PeanutButter::Application* PeanutButter::CreateApplication() {
	return new Sandbox();
}