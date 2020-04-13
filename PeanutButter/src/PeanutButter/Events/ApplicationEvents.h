#pragma once

#include "Event.h"

namespace PeanutButter {
	/**
	* Window Resize Event Class
	*/
	class PB_API WindowResizeEvent : public Event {
	public:
		WindowResizeEvent(pb_uint16 Width, pb_uint16 Height) : m_Width(Width), m_Height(Height) {}

		inline pb_uint16 GetWidth() const { return m_Width; }
		inline pb_uint16 GetHeight() const { return m_Height; }
		EVENT_CLASS_TYPE(ET_WindowResize);
		EVENT_CLASS_CATEGORY(EEventCategory::EC_Application);

	protected:
		pb_uint16 m_Width;
		pb_uint16 m_Height;

	public:
		std::string ToString() const override {
			std::stringstream ss;
			ss << "Window Resize Event: " << m_Width << ", " << m_Height;
			return ss.str();
		}
	};

	/**
	* Window Close Event Class
	*/
	class PB_API WindowCloseEvent : public Event {
	public:
		WindowCloseEvent();

		EVENT_CLASS_TYPE(ET_WindowClose);
		EVENT_CLASS_CATEGORY(EEventCategory::EC_Application);
	};
}
