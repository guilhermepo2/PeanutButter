#pragma once
#include "PeanutButter/Core.h"
#include "PeanutButter/Entity/Component/Component.h"
#include "PeanutButter/Math/Math.h"
#include "PeanutButter/Utils/TextureManager.h"
#include "PeanutButter/Utils/AssetManager.h"

// TODO: Bad Dependency
#include <SDL.h>

namespace PeanutButter {
	class Tile : public Component {
	public:
		SDL_Texture* Texture;
		SDL_Rect SourceRectangle;
		SDL_Rect DestinationRectangle;
		Vector2 Position;

		Tile(int SourceX, int SourceY, int X, int Y, int TileSize, int TileScale, const char* TextureID) {
			Texture = Application::s_AssetManager->GetTexture(TextureID);
			SourceRectangle.x = SourceX;
			SourceRectangle.y = SourceY;
			SourceRectangle.w = TileSize;
			SourceRectangle.h = TileSize;

			DestinationRectangle.x = X;
			DestinationRectangle.y = Y;
			DestinationRectangle.w = TileSize * TileScale;
			DestinationRectangle.h = TileSize * TileScale;

			Position.x = X;
			Position.y = Y;
		}

		~Tile() {
			SDL_DestroyTexture(Texture);
		}

		void Update(float DeltaTime) override {
			DestinationRectangle.x = Position.x - Application::s_Camera.x;
			DestinationRectangle.y = Position.y - Application::s_Camera.y;
		}

		void Render() override {
			TextureManager::Draw(Texture, SourceRectangle, DestinationRectangle, SDL_FLIP_NONE);
		}
	};
}