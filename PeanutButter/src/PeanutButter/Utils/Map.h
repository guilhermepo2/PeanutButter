#pragma once
#include "PeanutButter/Core.h"
#include "PeanutButter/Math/Math.h"

namespace PeanutButter {
	class PB_API Map {
	public:
		Map(std::string InTextureID, int InScale, int InTileSize);
		~Map();

	private:
		std::string TextureID;
		int Scale;
		int TileSize;

	public:
		void LoadMap(std::string Filepath, int MapX, int MapY);
		void AddTile(int SourceX, int SourceY, int X, int Y);
	};
}