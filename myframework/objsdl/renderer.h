#pragma once

Renderer::Renderer(const Window& window)
	:renderer(Error::IfZero(SDL_CreateRenderer(window.window, -1, 0))) {}

void Renderer::Draw(Texture& texture, Rect source, Rect destination)
{
	SDL_Rect r1=Surface::RectSDL(source), r2=Surface::RectSDL(destination);
	Error::Condition(SDL_RenderCopy(renderer, texture.texture, &r1, &r2)!=0);
}

void Renderer::Draw(Surface& surface, Rect source, Rect destination)
{
	auto texture=MakeTexture(surface);
	Draw(texture, source, destination);
}
