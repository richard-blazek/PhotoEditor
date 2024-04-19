#pragma once

class DrawBase;
class Error;
class Font;
class Renderer;
class Surface;
class Texture;
class Display;
class Window;

#include "decl/messagebox.h"
#include "decl/drawbase.h"
#include "decl/surface.h"
#include "decl/texture.h"
#include "decl/renderer.h"
#include "decl/window.h"
#include "decl/font.h"

void Error::Show()const
{
	Message("SDL-Error", message);
}