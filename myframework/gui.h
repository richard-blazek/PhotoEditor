#pragma once

#include "objsdl.h"

namespace gui
{
	class Init
	{
	private:
		SDL::Init sdl;
		SDL::Font font;
	public:
		SDL::Color text_color=SDL::Color(0,0,0), bg_color=SDL::Color(255,255,255), button_color=SDL::Color(240,240,240),
				button_hover_color=SDL::Color(210,220,240), button_clicked_color=SDL::Color(180,200,255), border_color=SDL::Color(0,0,0),
				selection_color=SDL::Color(15,190,255);
		Init(std::string file, uint32 size=12)
			:sdl(), font(file, size) {}
		void Draw(SDL::DrawBase& rend, const std::string& text, const SDL::Color& color, const SDL::Rect& position)
		{
			rend.Draw(font, text, color, position);
		}
		SDL::Point TextSize(const std::string& text)
		{
            return font.TextSize(text);
		}
	};
	#include "gui/widget.h"
	#include "gui/label.h"
	#include "gui/button.h"
	#include "gui/chars.h"
	#include "gui/textinputbox.h"
	#include "gui/textinput.h"
	#include "gui/select.h"
}