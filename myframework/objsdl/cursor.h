#pragma once

namespace Cursor
{
    //Schová kurzor
	void Hide()noexcept
	{
		SDL_ShowCursor(0);
	}
	///Zobrazí kurzor
	void Show()noexcept
	{
		SDL_ShowCursor(1);
	}
	//Je kurzor vidět?
	bool IsVisible()noexcept
	{
		return SDL_ShowCursor(-1);
	}
	void Move(Point xy)noexcept
	{
        Error::Condition(SDL_WarpMouseGlobal(xy.x, xy.y)<0);
	}
	void EnableCapturing()
	{
		Error::IfNegative(SDL_CaptureMouse(SDL_TRUE));
	}
	void DisableCapturing()
	{
		Error::IfNegative(SDL_CaptureMouse(SDL_FALSE));
	}
	Point Position()
	{
		Point result;
		SDL_GetMouseState(&result.x, &result.y);
		return result;
	}
	Point GlobalPosition()
	{
		Point result;
		SDL_GetGlobalMouseState(&result.x, &result.y);
		return result;
	}
	Point RelativePosition()
	{
		Point result;
		SDL_GetRelativeMouseState(&result.x, &result.y);
		return result;
	}
	MouseButtonMask PressedButtons()
	{
		return MouseButtonMask(SDL_GetMouseState(0,0));
	}
	bool IsPressed()
	{
		return PressedButtons()!=MouseButtonMask::Nothing;
	}
	bool IsPressed(MouseButtonMask button)
	{
		return (PressedButtons()&button)==button;
	}
}