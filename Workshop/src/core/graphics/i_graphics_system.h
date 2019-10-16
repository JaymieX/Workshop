#ifndef I_GRAPHICS_SYSTEM_H
#define I_GRAPHICS_SYSTEM_H

#include "../system/i_window.h"

#include <memory>

namespace Workshop
{
	class IGraphicsSystem
	{
	protected:
		// Pointer to window
		std::unique_ptr<IWindow> window_system;
		
	public:
		IGraphicsSystem() = default;

		virtual ~IGraphicsSystem() = default;
		
		virtual void InitializeGraphicsSystem(const WinInfo& window_info_) = 0;

		virtual void BeginRenderProtocol() = 0;

		virtual void EndRenderProtocol() = 0;

		virtual void StopGraphicsSystem() = 0;
	};
}

#endif // I_GRAPHICS_SYSTEM_H
