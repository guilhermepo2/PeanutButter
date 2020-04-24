#include "pbpch.h"
#include "Map.h"
#include "PeanutButter/Log.h"
#include "PeanutButter/Entity/Entity.h"
#include "PeanutButter/Entity/Component/Tile.h"

namespace PeanutButter {
	Map::Map(const char* InTextureID, int InScale, int InTileSize) {
		TextureID = InTextureID;
		Scale = InScale;
		TileSize = InTileSize;
	}

	
	void Map::LoadMap(const char* Filepath, int MapX, int MapY) {
		std::fstream MapFile;
		MapFile.open(Filepath);

		for (int y = 0; y < MapY; y++) {
			for (int x = 0; x < MapX; x++) {
				char ch;
				MapFile.get(ch);
				int SourceY = atoi(&ch) * TileSize;
				MapFile.get(ch);
				int SourceX = atoi(&ch) * TileSize;
				PB_CORE_INFO("Tile {0},{1} on position {2},{3}", SourceX / TileSize, SourceY / TileSize, x * (Scale * TileSize), y * (Scale * TileSize));
				AddTile(SourceX, SourceY, x * (Scale * TileSize), y * (Scale * TileSize));
				MapFile.ignore();
			}
		}

		MapFile.close();
	}

	void Map::AddTile(int SourceX, int SourceY, int X, int Y) {
		Entity& NewTile(Application::s_EManager->AddEntity("Tile", ELT_TilemapLayer));
		NewTile.AddComponentOfType<Tile>(SourceX, SourceY, X, Y, TileSize, Scale, TextureID);
	}
}