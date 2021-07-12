#pragma once

class Image: public NonCopyable
{
private:
	SDL::Surface source, result;
public:
	Image(SDL::Surface image):source(image), result(image) {}
	Image(Image&& src):source(func::Move(src.source)), result(source) {}
	Image& operator=(Image&& src)
	{
		source=func::Move(src.source);
		result=func::Move(src.result);
		return *this;
	}
	SDL::Color operator[](SDL::Point xy)const
    {
    	return source[xy];
    }
    template<typename... T>
    void Draw(T&&... args)
    {
    	result.Draw(args...);
    }
    void Confirm()
    {
    	source=result;
    }
    SDL::Point Size()const
    {
    	return source.Size();
    }
	void Resize(SDL::Point size)
	{
		result=func::Move(source.Format().IsIndexed()?
				SDL::Surface(size, source.Palette(), source.Format()):
				SDL::Surface(size, source.Format())
		);
	}
	SDL::Texture Update(SDL::Texture texture, SDL::Renderer& rend, SDL::Rect area)
	{
		return UpdateTexture(func::Move(texture), result, rend, area);
	}
	void Convert(SDL::Pixel::Format format)
	{
		if(result.Format()!=format)
		{
			result=func::Move(result.Convert(format));
		}
	}
	void Save(Path file)
	{
		if(file.IsJpg())
		{
			source.SaveAsJPG(file, 95);
		}
		else if(file.IsBmp())
		{
			source.SaveAsBMP(file);
		}
		else
		{
			source.SaveAsPNG(file);
		}
	}
	SDL::Texture MakeTexture(SDL::Renderer& rend)
	{
		return rend.MakeTexture(result);
	}
};