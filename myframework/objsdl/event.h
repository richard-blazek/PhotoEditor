#pragma once

#include "events/type.h"
#include "events/structures.h"

namespace events
{
class Event
{
private:
	SDL_Event event;
	Event(const SDL_Event& evt):event(evt){}
public:
	friend class Iterator;
	Event()noexcept=default;
	events::MouseWheel MouseWheel()const
	{
		return events::MouseWheel{event.wheel.windowID, event.wheel.which!=SDL_TOUCH_MOUSEID, Point(event.wheel.x, event.wheel.y)* (event.wheel.direction==SDL_MOUSEWHEEL_FLIPPED?-1:1)};
	}
	events::MouseMotion MouseMotion()const
	{
		return events::MouseMotion{event.motion.windowID, event.motion.which!=SDL_TOUCH_MOUSEID, MouseButtonMask(event.motion.state), Point(event.motion.x, event.motion.y), Point(event.motion.xrel, event.motion.yrel)};
	}
	events::MouseButton MouseButton()const
	{
		return events::MouseButton{event.button.windowID, event.button.which!=SDL_TOUCH_MOUSEID, SDL::MouseButton(event.button.button), Point(event.button.x, event.button.y), event.button.clicks};
	}
	events::Keyboard Keyboard()const
	{
		return events::Keyboard{event.key.windowID, event.key.repeat != 0, Scancode(event.key.keysym.scancode), Keycode(event.key.keysym.sym), Keymod(event.key.keysym.mod)};
	}
	events::TextEditing TextEditing()const
	{
		return events::TextEditing{event.edit.windowID, event.edit.text, event.edit.start, event.edit.length};
	}
	events::TextInput TextInput()const
	{
		return events::TextInput{event.text.windowID, event.text.text};
	}
	events::Type Type()const noexcept
	{
		auto tmp=event.type;
		tmp=(tmp>=(uint32)SDL_USEREVENT)?(uint32)SDL_USEREVENT:tmp;
		return events::Type(tmp==SDL_WINDOWEVENT?0x201+event.window.event:tmp);
	}
};
}
#include "events/iterator.h"