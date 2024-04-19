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
		return std::move(tools.Options());
	}
    SelfDrawingImage Select(size_t i, SelfDrawingImage image)
    {
    	return tool.Set(tools.Select(i), std::move(image));
    }
    Tool* operator->()
    {
        return tool.operator->();
    }
};