#pragma once

class Texture: public NonCopyable
{
private:
    SDL_Texture* texture=nullptr;
public:
	friend Renderer;
    Texture()=default;
    ~Texture()noexcept
	{
		Close();
	}
    Texture(Texture&& src)noexcept
		:texture(src.texture)
	{
		src.texture=nullptr;
	}
    Texture& operator=(Texture&& src)noexcept
    {
    	Close();
    	texture=src.texture;
    	src.texture=nullptr;
		return *this;
	}
    void Close()noexcept
	{
		if(texture)
		{
			SDL_DestroyTexture(texture);
			texture=nullptr;
		}
	}

	bool IsOpened()const noexcept
	{
		return bool(texture);
	}

	Point Size()const
	{
		Point result;
		Error::IfNegative(SDL_QueryTexture(texture, nullptr, nullptr, &result.x, &result.y));
		return result;
	}
    Pixel::Format Format()const
	{
		uint32 result;
		Error::IfNegative(SDL_QueryTexture(texture, &result, nullptr, nullptr, nullptr));
		return Pixel::Format(result);
	}
    void Update(const Surface& pixels, Rect area)
	{
		area=(area*Rect(pixels.Size())).ValueOr(Rect());
		SDL_Rect rectangle{area.x, area.y, int(area.w), int(area.h)};
		Error::IfNegative(SDL_UpdateTexture(texture, &rectangle, pixels.Index(area.Position()), pixels.BytesPerLine()));
	}
};
