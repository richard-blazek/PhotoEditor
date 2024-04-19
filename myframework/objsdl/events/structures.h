#pragma once

namespace events
{
struct MouseWheel
{
	uint32 WindowID;
	bool IsMouse;
	Point Move;
};
struct MouseMotion
{
	uint32 WindowID;
	bool IsMouse;
	MouseButtonMask Buttons;
	Point Absolute;
	Point Relative;
};
struct MouseButton
{
	uint32 WindowID;
	bool IsMouse;
	SDL::MouseButton Button;
	Point Position;
	uint8 Clicks;
};
struct Keyboard
{
	uint32 WindowID;
	bool Repeat;
	Scancode Code;
	Keycode Key;
	Keymod Mod;
};
struct TextEditing
{
	uint32 WindowID;
	std::string Text;
	int32 Start;
	int32 Lenght;
};
struct TextInput
{
	uint32 WindowID;
	std::string Text;
};
}