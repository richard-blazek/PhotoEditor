#pragma once

Surface::Surface(Point size, const std::vector<Color>& colors, uint8 depth)
{
    surface=Error::IfZero(SDL_CreateRGBSurface(0,size.x,size.y,depth, 0, 0, 0, 0));
	SetPalette(colors);
}
Surface::Surface(Point size, const std::vector<Color>& colors, Pixel::Format format)
{
    surface=Error::IfZero(SDL_CreateRGBSurfaceWithFormat(0,size.x,size.y, format.BitsPexPixel(), uint32(format)));
	SetPalette(colors);
}
Surface::Surface(Point size, Pixel::Format format)
{
	if(format.IsIndexed())
	{
		throw Error("Surface::Create>No palette given, but format needs palette");
	}
    surface=Error::IfZero(SDL_CreateRGBSurfaceWithFormat(0,size.x,size.y, format.BitsPexPixel(), uint32(format)));
}
void Surface::Blit(Surface& second, Rect source, Rect destination)
{
	SDL_Rect src=Surface::RectSDL(source), dst=Surface::RectSDL(destination);
    Error::IfNegative(SDL_BlitSurface(second.surface, &src, surface, &dst));
}
void Surface::Draw(Surface& second, Rect source, Rect destination)
{
	SDL_Rect src=Surface::RectSDL(source), dst=Surface::RectSDL(destination);
    Error::IfNegative(SDL_BlitScaled(second.surface, &src, surface, &dst));
}
void Surface::Repaint(const Color& col)
{
	Error::IfNegative(SDL_FillRect(surface, nullptr, SDL_MapRGBA(surface->format, col.r, col.g, col.b, col.a)));
}
void Surface::DrawBorder(const Rect& rect, const Color& col)
{
	Draw(SDL::Rect(rect.x, rect.y, 1, rect.h), col);
	Draw(SDL::Rect(rect.Right(), rect.y, 1, rect.h), col);
	Draw(SDL::Rect(rect.x, rect.y, rect.w, 1), col);
	Draw(SDL::Rect(rect.x, rect.Down(), rect.w, 1), col);
}
void Surface::Draw(const Rect& rect, const Color& col)
{
	SDL_Rect r=Surface::RectSDL(rect);
	Error::IfNegative(SDL_FillRect(surface, &r, SDL_MapRGBA(surface->format, col.r, col.g, col.b, col.a)));
}