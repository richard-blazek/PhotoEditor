#pragma once

class Loader
{
private:
	ImagePath file;
public:
	Loader(ImagePath file) :file(file) {}
	std::string Path()const
	{
		return file.String();
	}
	Loader Moved(int change)const
    {
    	return Loader(file.AnotherImage(change));
    }
	void Save(Image& images)const
	{
		images.Save(file.String());
	}
	void Delete()
	{
		file.Delete();
	}
	Image Load()const
	{
		return std::move(Image(SDL::Surface::LoadImg(file.String())));
	}
};