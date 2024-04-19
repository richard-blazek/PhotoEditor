#pragma once

class Window: public NonCopyable
{
private:
	//Intern C window
	SDL_Window* window=nullptr;
public:
	friend Renderer;
	friend Cursor;
	enum class Flags:uint32
	{
		Nothing=0,
		Fullscreen=SDL_WINDOW_FULLSCREEN,		///fullscreen window
		OpenGL=SDL_WINDOW_OPENGL,				///window usable with OpenGL context
		Shown=SDL_WINDOW_SHOWN,					///window is visible
		Hidden=SDL_WINDOW_HIDDEN,				///window is not visible
		Borderless=SDL_WINDOW_BORDERLESS,		///no window decoration
		Resizable=SDL_WINDOW_RESIZABLE,			///window can be resized
		Minimized=SDL_WINDOW_MINIMIZED,			///window is minimized
		Maximized=SDL_WINDOW_MAXIMIZED,			///window is maximized
		InputGrabbed=SDL_WINDOW_INPUT_GRABBED,	///window has grabbed input focus
		Focus=SDL_WINDOW_INPUT_FOCUS,		///window has input focus
		MouseFocus=SDL_WINDOW_MOUSE_FOCUS,		///window has mouse focus
		FullscreenDesktop=SDL_WINDOW_FULLSCREEN_DESKTOP,
		Foreign=SDL_WINDOW_FOREIGN,				///window not created by SDL
		AllowHighDPI=SDL_WINDOW_ALLOW_HIGHDPI,	///window should be created in high-DPI mode if supported
		MouseCapture=SDL_WINDOW_MOUSE_CAPTURE,	///window has mouse captured (unrelated to INPUT_GRABBED)
		AllwaysOnTop=SDL_WINDOW_ALWAYS_ON_TOP,	/// window should always be above others
		SkipTaskbar=SDL_WINDOW_SKIP_TASKBAR,	/// window should not be added to the taskbar
		Utility=SDL_WINDOW_UTILITY,				/// window should be treated as a utility window
		Tooltip=SDL_WINDOW_TOOLTIP,				/// window should be treated as a tooltip
		PopupMenu=SDL_WINDOW_POPUP_MENU			/// window should be treated as a popup menu
	};
	//Constructor
	Window()=default;
	//Constructor with parameters
	Window(const std::string& title, Rect pos, Flags flags=Flags::Nothing);
	//Move
	Window(Window&&)noexcept;
	Window& operator=(Window&&)noexcept;
	//Destroying Window
	void Close()noexcept;
	//Destructor
	~Window()noexcept
	{
		Close();
	}
	Point Size()noexcept
	{
		Point result;
		SDL_GetWindowSize(window, &result.x, &result.y);
		return result;
	}
};
Window::Flags operator|(Window::Flags first, Window::Flags second)noexcept
{
	return Window::Flags(uint32(first)|uint32(second));
}
Window::Flags operator&(Window::Flags first, Window::Flags second)noexcept
{
	return Window::Flags(uint32(first)&uint32(second));
}
Window::Flags operator^(Window::Flags first, Window::Flags second)noexcept
{
	return Window::Flags(uint32(first)^uint32(second));
}
Window::Flags operator|=(Window::Flags& first, Window::Flags second)noexcept
{
	return first=(first|second);
}
Window::Flags operator&=(Window::Flags& first, Window::Flags second)noexcept
{
	return first=(first&second);
}
Window::Flags operator^=(Window::Flags& first, Window::Flags second)noexcept
{
	return first=(first^second);
}
Window::Flags operator~(Window::Flags param)noexcept
{
	return Window::Flags(~uint32(param));
}