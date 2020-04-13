#pragma once

#include "Event.h"

namespace PeanutButter {
	/**
	* Key Event Class
	*/
	class PB_API KeyEvent : public Event {
	public:
		inline pb_int32 GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EEventCategory::EC_Keyboard | EEventCategory::EC_Input);

	protected:
		KeyEvent(pb_int32 KeyCode) : m_KeyCode(KeyCode) {}
		pb_int32 m_KeyCode;
	};

	/**
	* Key Pressed Event Class
	*/
	class PB_API KeyPressedEvent : public KeyEvent {
	public:
		KeyPressedEvent(pb_int32 KeyCode, pb_uint32 RepeatCount) : KeyEvent(KeyCode), m_RepeatCount(RepeatCount) {}
		inline int GetRepeateCount() const { return m_RepeatCount; }
		EVENT_CLASS_TYPE(EEventType::ET_KeyPressed);

	protected:
		pb_uint32 m_RepeatCount;

	public:
		std::string ToString() const override {
			std::stringstream ss;
			ss << "Key Pressed Event: " << m_KeyCode << "(" << m_RepeatCount << " repeats)";
			return ss.str();
		}
	};

	/**
	* Key Released Event Class
	*/
	class PB_API KeyReleasedEvent : public KeyEvent {
	public:
		KeyReleasedEvent(pb_int32 KeyCode) : KeyEvent(KeyCode) {}
		EVENT_CLASS_TYPE(EEventType::ET_KeyReleased);

		std::string ToString() const override {
			std::stringstream ss;
			ss << "Key Released Event: " + m_KeyCode;
			return ss.str();
		}
	};
}