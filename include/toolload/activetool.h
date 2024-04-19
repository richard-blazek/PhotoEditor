#pragma once

class ActiveTool
{
private:
	Tool* tool;
public:
	ActiveTool(Tool* init):tool(init){}
	Tool* operator->()
	{
		return tool;
	}
	SelfDrawingImage Set(const ActiveTool& init, SelfDrawingImage image)
	{
		image=tool->Disable(std::move(image));
		tool=init.tool;
		image=tool->Enable(std::move(image));
		return image;
	}
};