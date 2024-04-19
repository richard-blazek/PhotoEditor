#pragma once

class ImagePath
{
private:
	std::vector<fs::path> dir;
	size_t file;
public:
	static bool IsJpg(fs::path p)
	{
		auto e = p.extension().string();
		return e==".jpg"||e==".JPG"||e==".jpeg"||e==".JPEG";
	}
	static bool IsPng(fs::path p)
	{
		auto e = p.extension().string();
		return e==".png"||e==".PNG";
	}
	static bool IsBmp(fs::path p)
	{
		auto e = p.extension().string();
		return e==".bmp"||e==".BMP";
	}
	static bool IsImg(fs::path p)
	{
		return IsJpg(p) || IsPng(p) || IsBmp(p);
	}
	ImagePath(fs::path path):dir(), file(0)
	{
		for (auto& entry : fs::directory_iterator(path.parent_path()))
		{
			if (IsImg(entry.path()))
			{
				dir.push_back(entry.path());
			}
		}
		file = std::find(dir.begin(), dir.end(), path) - dir.begin();
	}
	std::string String()const
	{
		return dir[file].string();
	}
	ImagePath AnotherImage(int change)const
	{
		auto result=*this;
		result.file=(dir.size()+file+change)%dir.size();
		return std::move(result);
	}
	void Delete()
	{
		remove(std::string(dir[file]).c_str());
		dir.erase(dir.begin()+file);
		file%=dir.size();
	}
};
