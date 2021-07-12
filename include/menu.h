#pragma once

class Menu
{
private:
	std::vector<std::string> buttons;
public:
	Menu(std::vector<std::string> buttons):buttons(func::Move(buttons)) {}
	void DrawOn(SDL::Renderer& rend, SDL::Rect area, SDL::Font& font, SDL::Color text_color, int separator_h, SDL::Color separator_color)const
	{
		for(size_t i=0; i<buttons.size(); ++i)
		{
			rend.Draw(font, buttons[i], text_color, SDL::Rect(area.x+i*area.w/buttons.size(), area.y, area.w/buttons.size(), area.h-separator_h));
		}
		rend.Draw(SDL::Rect(area.x, area.Down()-separator_h, area.w, separator_h), separator_color);
	}
	size_t ChosenButton(SDL::Rect area, SDL::Point pos)const
	{
		return area.Encloses(pos)?buttons.size()*(pos.x-area.x)/area.w:buttons.size();
	}
};