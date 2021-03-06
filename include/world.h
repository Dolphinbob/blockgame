#pragma once
#include "core.h"
#include <map>
#include <deque>
#include "chunk.h"
#include "resource_manager.h"
#include "perlin.h"

class Chunk;

class World {
  private:
    std::map<std::tuple<int, int>, Chunk> chunks;
    ResourceManager *resourceManager;
    siv::PerlinNoise perlin;
    std::deque<std::tuple<int, int>> chunkUpdateQueue;
    std::deque<std::tuple<int, int>> chunkGenerationQueue;
  public:
    World(ResourceManager *resourceManager);
    void loadChunk(int cx, int cy);
    void unloadChunk(std::tuple<int, int>);
    void autoLoadChunks(int cx, int cy, int renderDistance);
    void draw();
    std::string getBlock(int x, int y, int z);
    void setBlock(int x, int y, int z, std::string block);
    bool isChunkLoaded(int cx, int cy);
    bool isChunkLoaded(std::tuple<int, int>);
    std::tuple<int, int> getChunkCoords(int x, int z);
    int getUnmappedBlock(int x, int y, int z);
    Chunk* getChunk(int cx, int cy);
    void update();
    void generateChunk(int cx, int cy);
};