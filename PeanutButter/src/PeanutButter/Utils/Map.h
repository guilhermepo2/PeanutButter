#pragma once
#include "PeanutButter/Core.h"
#include "PeanutButter/Math/Math.h"

namespace PeanutButter {
	class PB_API Map {
	public:
		Map(const char* InTextureID, int InScale, int InTileSize);
		~Map();

	private:
		const char* TextureID;
		int Scale;
		int TileSize;

	public:
		void LoadMap(const char* Filepath, int MapX, int MapY);
		void AddTile(int SourceX, int SourceY, int X, int Y);
	};
}