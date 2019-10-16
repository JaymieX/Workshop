#ifndef I_WINDOW_H
#define I_WINDOW_H

#include <string>

namespace Workshop
{
	struct WinInfo
	{
		int x;
		int y;

		int width;
		int height;

		std::string title;

		inline explicit WinInfo(
			const int x_				= 0,
			const int y_				= 0,
			const int width_			= 800,
			const int height_			= 600,
			const std::string& title_	= "Game Engine Workshop"
		) noexcept :
		x(x_),
		y(y_),
		width(width_),
		height(height_),
		title(title_)
		{
		}
	};
	
	class IWindow
	{
	public:
		IWindow() = default;

		virtual ~IWindow() = default;

		virtual void CreateWindow(const WinInfo& window_info_) = 0;

		virtual void SetThisWindowAsContext() = 0;
	};
}

#endif // I_WINDOW_H
