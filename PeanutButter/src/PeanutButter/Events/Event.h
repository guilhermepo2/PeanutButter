#pragma once

#include "PeanutButter/Core.h"

namespace PeanutButter {
	
	/**
	* Blocking Event System - Events have to be handled immediately after they happen
	*/

	enum class EEventType {
		ET_None = 0,

		/** Window Events */
		ET_WindowClose, ET_WindowResize, ET_WindowFocus, ET_WindowLostFocus, ET_WindowMoved,

		/** Key Events */
		ET_KeyPressed, ET_KeyReleased,

		/** Mouse Events */
		ET_MouseButtonPressed, ET_MouseButtonReleased, ET_MouseMoved, ET_MouseScrolled
	};

	enum class EEventCategory {
		EC_None        = 0,
		EC_Application = BIT(0),
		EC_Input       = BIT(1),
		EC_Keyboard    = BIT(2),
		EC_Mouse       = BIT(3),
		EC_MouseButton = BIT(4)
	};

#define EVENT_CLASS_TYPE(Type) static EEventType GetStaticType() { return EEventType::##Type; }\
                                                                  virtual EEventType GetEventType() const override { return GetStaticType(); }\
                                                                  virtual const char* GetName() const override { return #Type; }
#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return static_cast<int>(category); }

	class PB_API Event {
	public:
		virtual EEventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual pb_int32 GetCategoryFlags() const = 0;

	protected:
		bool m_WasHandled = false;

	private:
		friend class EventDispatcher;
	
	public:
		virtual std::string ToString() const { return GetName(); }

		/** 
		* Checks if the event is in a given category 
		* @param TODO
		* @return TODO
		*/
		inline bool IsInCategory(EEventCategory Category) { return GetCategoryFlags() & static_cast<int>(Category); }

	};

	class EventDispatcher {
	public:
		EventDispatcher(Event& Event) : m_Event(Event) {}

	private:
		/** Event Function is a standard function that returns bool and receives T as a parameter */
		template<typename T>
		using EventFunction = std::function<bool(T&)>;

	protected:
		Event& m_Event;

	public:
		template<typename T>
		bool Dispatch(EventFunction<T> Function) {
			if (m_Event.GetEventType() == T::GetStaticType()) {
				m_Event.m_WasHandled = Function(*(T*)&m_Event);
				return true;
			}
			
			return false;
		}
	};

	/**
	* Overloading << for ostream and custom-made events
	*/
	inline std::ostream& operator<<(std::ostream& os, const Event& e) {
		return os << e.ToString();
	}
}