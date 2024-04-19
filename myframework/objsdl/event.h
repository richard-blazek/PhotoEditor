#pragma once

#include "events/type.h"

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
	int MouseWheel()const
	{
		return event.wheel.y * (event.wheel.direction==SDL_MOUSEWHEEL_FLIPPED?-1:1);
	}
	Point MouseMotion()const
	{
		return Point(event.motion.xrel, event.motion.yrel);
	}
	Point MouseButton()const
	{
		return Point(event.button.x, event.button.y);
	}
	Keycode Keyboard()const
	{
		return Keycode(event.key.keysym.sym);
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