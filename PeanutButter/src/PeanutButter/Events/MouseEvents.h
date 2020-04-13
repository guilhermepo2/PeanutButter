#pragma once
#include "Event.h"

namespace PeanutButter {
	/**
	* Mouse Moved Event Class
	*/
	class PB_API MouseMovedEvent : public Event {
	public:
		MouseMovedEvent(float X, float Y) : m_MouseX(X), m_MouseY(Y) {}
		inline float GetX() const { return m_MouseX; }
		inline float GetY() const { return m_MouseY; }

		EVENT_CLASS_TYPE(ET_MouseMoved);
		EVENT_CLASS_CATEGORY(static_cast<int>(EEventCategory::EC_Mouse) | static_cast<int>(EEventCategory::EC_Input));

	protected:
		float m_MouseX;
		float m_MouseY;

	public:
		std::string ToString() const override {
			std::stringstream ss;
			ss << "Mouse Moved Event: " << m_MouseX << ", " << m_MouseY;
			return ss.str();
		}
	};

	/**
	* Mouse Scrolled Event Class
	*/
	class PB_API MouseScrolledEvent : public Event {
	public:
		MouseScrolledEvent(float XOffset, float YOffset) : m_XOffset(XOffset), m_YOffset(YOffset) {}
		inline float GetXOffset() const { return m_XOffset; }
		inline float GetYOffset() const { return m_YOffset; }

		EVENT_CLASS_TYPE(ET_MouseScrolled);
		EVENT_CLASS_CATEGORY(static_cast<int>(EEventCategory::EC_Mouse) | static_cast<int>(EEventCategory::EC_Input));

	protected:
		float m_XOffset;
		float m_YOffset;

	public:
		std::string ToString() const override {
			std::stringstream ss;
			ss << "Mouse Moved Event: " << m_XOffset << ", " << m_YOffset;
			return ss.str();
		}
	};

	/**
	* Mouse Button Event Class
	*/
	class PB_API MouseButtonEvent : public Event {
	public:
		inline pb_int32 GetMouseButton() const { return m_Button; }
		EVENT_CLASS_CATEGORY(static_cast<int>(EEventCategory::EC_Mouse) | static_cast<int>(EEventCategory::EC_Input))

	protected:
		MouseButtonEvent(pb_int32 Button) : m_Button(Button) {}
		pb_int32 m_Button;
	};

	/**
	* Mouse Button Pressed Event Class
	*/
	class PB_API MouseButtonPressedEvent : public MouseButtonEvent {
	public:
		MouseButtonPressedEvent(pb_int32 Button) : MouseButtonEvent(Button) {}
		EVENT_CLASS_TYPE(ET_MouseButtonPressed);

		std::string ToString() const override {
			std::stringstream ss;
			ss << "Mouse Button Pressed Event: " << m_Button;
			return ss.str();
		}
	};

	/**
	* Mouse Button Released Event
	*/
	class PB_API MouseButtonReleasedEvent : public MouseButtonEvent {
	public:
		MouseButtonReleasedEvent(pb_int32 Button) : MouseButtonEvent(Button) {}
		EVENT_CLASS_TYPE(ET_MouseButtonReleased);

		std::string ToString() const override {
			std::stringstream ss;
			ss << "Mouse Button Released Event: " << m_Button;
			return ss.str();
		}
	};

}