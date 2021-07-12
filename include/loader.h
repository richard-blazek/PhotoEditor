#pragma once

class Loader
{
private:
	ImagePath file;
public:
	Loader(ImagePath file) :file(file) {}
	std::string Path()const
	{
		return std::string(file);
	}
	Loader Moved(int32 change)const
    {
    	return Loader(file.AnotherImage(change));
    }
	void Save(Image& images)const
	{
		images.Save(file);
	}
	void Delete()
	{
		file.Delete();
	}
	Image Load()const
	{
		return func::Move(Image(SDL::Surface::LoadImg(std::string(file))));
	}
};