#pragma once

namespace events
{
struct MouseWheel
{
	Point Move;
};
struct MouseMotion
{
	Point Relative;
};
struct MouseButton
{
	Point Position;
};
struct Keyboard
{
	Keycode Key;
};
}