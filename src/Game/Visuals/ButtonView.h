#pragma once

#include <functional>

#include "View.h"

class ButtonView : public View {
	private:
		std::function<void()> onHoverListener;
		std::function<void()> onHoverReleaseListener;

		std::function<void()> onClickListener;

	public:
		ButtonView(SDL_Texture* texture, SDL_Rect destrect);
		ButtonView(SDL_Texture* texture, int x, int y, int sizeMultiplier);

		void setOnHoverListener(std::function<void()> onHoverListener, std::function<void()> onHoverReleaseListener);
		void setOnClickListener(std::function<void()> onClickListener);

		bool hasHoverListener();
		bool hasClickListener();

		bool mouseIsHovering(int x, int y);

		void onHover();
		void onHoverRelease();
		void onClick();
};

