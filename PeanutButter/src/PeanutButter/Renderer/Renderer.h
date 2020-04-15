#pragma once

#include "pbpch.h"
#include "PeanutButter/Core.h"
#include "PeanutButter/Window.h"

namespace PeanutButter {
	class PB_API Renderer {
	public:
		virtual ~Renderer() {}
		virtual void Update() = 0;
		static Renderer* Create(Window* RendererWindow);
	};
}