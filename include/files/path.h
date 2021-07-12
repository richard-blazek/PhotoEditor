#pragma once

class Path
{
private:
	static bool IsJpgExtension(std::string e)
	{
		return e=="jpg"||e=="JPG"||e=="jpeg"||e=="JPEG";
	}
	static bool IsPngExtension(std::string e)
	{
		return e=="png"||e=="PNG";
	}
	static bool IsBmpExtension(std::string e)
	{
		return e=="bmp"||e=="BMP";
	}
	std::string path;
public:
	Path(std::string path):path(func::Move(path)) {}
	operator std::string()const
	{
		return path;
	}
	std::string Extension()const
	{
		return path.substr(1+path.rfind('.'));
	}
	std::string Filename()const
	{
		return path.substr(1+path.find_last_of("/\\"));
	}
	Path Parent()const
	{
		return path.substr(0, path.find_last_of("/\\"));
	}
	Path operator/(std::string filename)
	{
		return path+Separator()+filename;
	}
	bool operator==(Path second)
	{
		return path==second.path;
	}
	bool IsJpg()const
	{
		return IsJpgExtension(Extension());
	}
	bool IsBmp()const
	{
		return IsBmpExtension(Extension());
	}
	bool IsPng()const
	{
		return IsPngExtension(Extension());
	}
	bool IsImage()const
	{
		return IsJpg()||IsPng()||IsBmp();
	}
	char Separator()const
	{
		return path[path.find_last_of("/\\")];
	}
	std::vector<Path> FilesInDirectory()const
	{
		std::vector<Path> result;
		auto dir=opendir(path.c_str());
		auto entry=readdir(dir);
		while(entry)
		{
			result.push_back(path+Separator()+std::string(entry->d_name, entry->d_namlen));
			entry=readdir(dir);
		}
		closedir(dir);
		return func::Move(result);
	}
};