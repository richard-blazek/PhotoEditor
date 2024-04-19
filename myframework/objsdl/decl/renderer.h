#pragma once

///Object Renderer
class Renderer: public NonCopyable, public DrawBase
{
public:
	enum class Flags: uint32
	{
		Nothing=0x0,
		Software=SDL_RENDERER_SOFTWARE,
		Accelerated=SDL_RENDERER_ACCELERATED,
		PresentVSync=SDL_RENDERER_PRESENTVSYNC,
		TargetTexture=SDL_RENDERER_TARGETTEXTURE
	};
	enum class Flip
	{
		Nothing=SDL_FLIP_NONE,
		Horizontal=SDL_FLIP_HORIZONTAL,
		Vertical=SDL_FLIP_VERTICAL
	};
private:
	SDL_Renderer* renderer=nullptr;

	void SetDrawColor(const Color& col)
	{
		Error::IfNegative(SDL_SetRenderDrawColor(renderer,col.r,col.g,col.b,col.a));
	}

public:
	using DrawBase::Draw;
	using DrawBase::DrawBorder;
	friend Texture;
	friend Window;
	Texture LoadImg(const std::string& file);
	Texture MakeTexture(Surface src)
	{
		Texture result;
		result.texture=Error::IfZero(SDL_CreateTextureFromSurface(renderer, src.surface));
		return std::move(result);
	}
	Texture MakeTexture(Pixel::Format format, Texture::Access access, Point size)
	{
		Texture result;
		result.texture=Error::IfZero(SDL_CreateTexture(renderer, uint32(format), int(access), size.x, size.y));
		return std::move(result);
	}
	Renderer()=default;
	Renderer(Renderer&& init):renderer(init.renderer)
	{
		init.renderer=nullptr;
	}
	Renderer& operator=(Renderer&& init)
	{
		Close();
		renderer=init.renderer;
		init.renderer=nullptr;
		return *this;
	}

	Renderer(const Window& window, Flags flags=Flags::Nothing, int index=-1);
	Renderer(Surface& surf)
		:renderer(Error::IfZero(SDL_CreateSoftwareRenderer(surf.surface))) {}

	bool IsOpened()const noexcept
	{
		return bool(renderer);
	}
	void Close()noexcept
	{
		if(renderer)
		{
			SDL_DestroyRenderer(renderer);
			renderer=nullptr;
		}
	}

	~Renderer()noexcept
	{
		Close();
	}

	//Drawing--------------------------------------------------------
	void Draw(const Point& point, const Color& col)
	{
		SetDrawColor(col);
		Error::IfNegative(SDL_RenderDrawPoint(renderer, point.x, point.y));
	}
	void Draw(const Line& line, const Color& col)
	{
		SetDrawColor(col);
		Error::IfNegative(SDL_RenderDrawLine(renderer, line.begin.x,line.begin.y, line.end.x,line.end.y));
	}
	void DrawBorder(const Rect& rectangle, const Color& col)
	{
		SetDrawColor(col);
		SDL_Rect rect=Surface::RectSDL(rectangle);
		Error::IfNegative(SDL_RenderDrawRect(renderer, &rect));
	}
	void Draw(const Rect& rectangle, const Color& col)
	{
		SetDrawColor(col);
		SDL_Rect rect=Surface::RectSDL(rectangle);
		Error::IfNegative(SDL_RenderFillRect(renderer, &rect));
	}
	void Repaint(const Color& col)
	{
		SetDrawColor(col);
		Error::IfNegative(SDL_RenderClear(renderer));
	}
	///Draw image to Renderer
	void Draw(Texture& texture, Rect source, Rect destination);
	void Draw(Surface& surface, Rect source, Rect destination);


	void Draw(Texture& texture, Rect source, Rect destination, double angle, Point center, Flip flip);
	void Draw(Surface& surface, Rect source, Rect destination, double angle, Point center, Flip flip);

	void Draw(Texture& texture, Rect source, Rect destination, double angle, Flip flip);
	void Draw(Surface& surface, Rect source, Rect destination, double angle, Flip flip);

	//Other----------------------------------------------------------
	void Show()noexcept
	{
		SDL_RenderPresent(renderer);
	}
	void SetTarget(Texture& texture);
	void SetBlendMode(SDL::BlendMode mode)
	{
		Error::IfNegative(SDL_SetRenderDrawBlendMode(renderer, SDL_BlendMode(mode)));
	}
	SDL::BlendMode BlendMode()
	{
		SDL_BlendMode mode;
		Error::IfNegative(SDL_GetRenderDrawBlendMode(renderer, &mode));
		return SDL::BlendMode(mode);
	}
	void SetViewport(const Rect& rectangle)
	{
		SDL_Rect rect=Surface::RectSDL(rectangle);
		Error::IfNegative(SDL_RenderSetViewport(renderer, &rect));
	}
	void SetViewportToDefault()
	{
		Error::IfNegative(SDL_RenderSetViewport(renderer, nullptr));
	}
	Rect Viewport()noexcept
	{
		SDL_Rect result;
		SDL_RenderGetViewport(renderer, &result);
		return Surface::RectSDL(result);
	}
	Point Size()
	{
		Point result;
		Error::IfNegative(SDL_GetRendererOutputSize(renderer, &result.x, &result.y));
		return result;
	}
};
