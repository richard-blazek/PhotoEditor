#pragma once

class Actions
{
private:
	ToolList tools;
	ActiveTool tool;
public:
	Actions(std::initializer_list<Tool*> init)
		:tools(init), tool(tools.Select(0)) {}
	std::vector<std::string> Options()const
	{
		return func::Move(tools.Options());
	}
    SelfDrawingImage Select(size_t i, SelfDrawingImage image)
    {
    	return tool.Set(tools.Select(i), func::Move(image));
    }
    Tool* operator->()
    {
        return tool.operator->();
    }
};