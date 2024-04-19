namespace events
{
enum class Type:uint32
{
	//Application events
	Quit=SDL_QUIT,//User-requested quit

	//Window events
	SysWmEvent=SDL_SYSWMEVENT,		//System specific event
    WindowShown,
	WindowHidden,
	WindowExposed,
	WindowMoved,
	WindowResized,
	WindowSizeChanged,
	WindowMinimized,
	WindowMaximized,
	WindowRestored,
	WindowEnter,
	WindowLeave,
	WindowFocusGained,
	WindowFocusLost,
	WindowClose,
	WindowTakeFocus,
	WindowHitTest,

	//Keyboard events
	Keydown=SDL_KEYDOWN,			//Key pressed
	Keyup,					//Key released
	TextEditing,			//Keyboard text editing (composition)
	TextInput,		        //Keyboard text input
	KeyMapChanged=SDL_KEYMAPCHANGED,

	//Mouse events
	MouseMotion=SDL_MOUSEMOTION,		//Mouse moved
	MouseButtonDown,		//Mouse button pressed
	MouseButtonUp,			//Mouse button released
	MouseWheel,				//Mouse wheel motion

	//Clipboard events
	ClipboardUpdate=SDL_CLIPBOARDUPDATE,		//The clipboard changed

};
}