#pragma once

Renderer::Renderer(const Window& window, Flags flags, int index)
	:renderer(Error::IfZero(SDL_CreateRenderer(window.window, index, uint32(flags)))) {}

Texture Renderer::LoadImg(const std::string& file)
{
	Texture tmp;
	tmp.texture=Error::IfZero(IMG_LoadTexture(renderer, file.c_str()));
	return (Texture&&)tmp;
}

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


void Renderer::Draw(Texture& texture, Rect source, Rect destination, double angle, Point center, Flip flip)
{
	SDL_Rect src=Surface::RectSDL(source), dst=Surface::RectSDL(destination);
	SDL_Point tmp{center.x, center.y};
    Error::Condition(SDL_RenderCopyEx(renderer, texture.texture, &src, &dst, angle, &tmp, SDL_RendererFlip(flip))!=0);
}
void Renderer::Draw(Surface& surface, Rect source, Rect destination, double angle, Point center, Flip flip)
{
	auto texture=MakeTexture(surface);
	Draw(texture, source, destination, angle, center, flip);
}
void Renderer::Draw(Texture& texture, Rect source, Rect destination, double angle, Flip flip)
{
	SDL_Rect src=Surface::RectSDL(source), dst=Surface::RectSDL(destination);
    Error::Condition(SDL_RenderCopyEx(renderer, texture.texture, &src, &dst, angle, nullptr, SDL_RendererFlip(flip))!=0);
}
void Renderer::Draw(Surface& surface, Rect source, Rect destination, double angle, Flip flip)
{
	auto texture=MakeTexture(surface);
	Draw(texture, source, destination, angle, flip);
}
void Renderer::SetTarget(Texture& texture)
{
	Error::IfNegative(SDL_SetRenderTarget(renderer, texture.texture));
}