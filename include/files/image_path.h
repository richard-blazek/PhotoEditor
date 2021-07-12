#pragma once

class ImagePath
{
private:
	std::vector<Path> dir;
	size_t file;
public:
	ImagePath(Path path):dir(), file(0)
	{
		auto all_files=path.Parent().FilesInDirectory();
		std::copy_if(all_files.begin(), all_files.end(), back_inserter(dir), [](auto file)
		{
			return file.IsImage();
		});
		file=std::find(dir.begin(), dir.end(), path)-dir.begin();
		for(size_t i=0; i<dir.size(); ++i)
		{
			dir[i]=Path(ConvertDefaultWindowsEncodingToUtf8(dir[i]));
		}
	}
	operator Path()const
	{
		return dir[file];
	}
	operator std::string()const
	{
		return std::string(dir[file]);
	}
	ImagePath AnotherImage(int32 change)const
	{
		auto result=*this;
		result.file=(dir.size()+file+change)%dir.size();
		return func::Move(result);
	}
	void Delete()
	{
		remove(std::string(dir[file]).c_str());
		dir.erase(dir.begin()+file);
		file%=dir.size();
	}
};
