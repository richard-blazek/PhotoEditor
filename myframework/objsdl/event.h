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
		return events::MouseWheel{Point(event.wheel.x, event.wheel.y)* (event.wheel.direction==SDL_MOUSEWHEEL_FLIPPED?-1:1)};
	}
	events::MouseMotion MouseMotion()const
	{
		return events::MouseMotion{Point(event.motion.xrel, event.motion.yrel)};
	}
	events::MouseButton MouseButton()const
	{
		return events::MouseButton{Point(event.button.x, event.button.y)};
	}
	events::Keyboard Keyboard()const
	{
		return events::Keyboard{Keycode(event.key.keysym.sym)};
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