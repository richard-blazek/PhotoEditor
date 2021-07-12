#pragma once

class ToolList: public NonCopyable
{
private:
	std::vector<Tool*> tools;
public:
	ToolList(std::initializer_list<Tool*> tools):tools(tools) {}
	std::vector<std::string> Options()const
	{
        std::vector<std::string> opt;
        for(auto& tool:tools)
		{
			opt.push_back(tool->Name());
		}
		return func::Move(opt);
	}
	ActiveTool Select(size_t i)
	{
		return tools[i];
	}
	~ToolList()
	{
		for(auto& tool:tools)
		{
			delete tool;
		}
	}
};