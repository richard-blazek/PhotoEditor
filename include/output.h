#pragma once

class Output
{
private:
	SDL::Window screen;
	SDL::Renderer rend;
	int menu_height;
public:
	Output(SDL::Point size, int menu_height)
		:screen("", SDL::Rect(40, 40, size), SDL::Window::Flags::Maximized|SDL::Window::Flags::Borderless), rend(screen), menu_height(menu_height)
	{
		rend.SetBlendMode(SDL::BlendMode::Blend);
	}
	void Draw(SelfDrawingImage& sdi, Actions& tool, Menu menu, SDL::Font& menu_font)
	{
		rend.Repaint(SDL::Color(30,200,0));
		rend.SetViewport(SDL::Rect(0, menu_height, rend.Size()-SDL::Point(0, menu_height)));
		sdi.DrawOn(rend);
		tool->DrawOn(sdi, rend);
		rend.SetViewportToDefault();
		menu.DrawOn(rend, SDL::Rect(0,0, rend.Size().x, menu_height), menu_font, SDL::Color(255,255,255), 4, SDL::Color(0,0,0));
		rend.Show();
	}
	SDL::Point ScreenSize()
	{
		return screen.Size()-SDL::Point(0, menu_height);
	}
	int MenuHeight()
	{
		return menu_height;
	}
	SelfDrawingImage MakeSDI(Image img)
	{
		return std::move(SelfDrawingImage(std::move(img), SDL::Rect(0, menu_height, ScreenSize()), rend));
	}
};