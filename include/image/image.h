#pragma once

class Image: public NonCopyable
{
private:
	SDL::Surface source, result;
public:
	Image(SDL::Surface image):source(image), result(image) {}
	Image(Image&& src):source(std::move(src.source)), result(source) {}
	Image& operator=(Image&& src)
	{
		source=std::move(src.source);
		result=std::move(src.result);
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
		result=std::move(source.Format().IsIndexed()?
				SDL::Surface(size, source.Palette(), source.Format()):
				SDL::Surface(size, source.Format())
		);
	}
	SDL::Texture Update(SDL::Texture texture, SDL::Renderer& rend, SDL::Rect area)
	{
		return UpdateTexture(std::move(texture), result, rend, area);
	}
	void Convert(SDL::Pixel::Format format)
	{
		if(result.Format()!=format)
		{
			result=std::move(result.Convert(format));
		}
	}
	void Save(fs::path file)
	{
		if(ImagePath::IsJpg(file))
		{
			source.SaveAsJPG(file, 95);
		}
		else if(ImagePath::IsBmp(file))
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