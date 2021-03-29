#pragma once

#include "core.h"
#include "assets.h"

struct Player
{
  sf::Vector2f pos;
  entt::entity sprite;
};

class Village
{
public:
  void Start();

private:
  void Loop();
  entt::entity LoadAsset(TextureName const& name);
  void AddPlayer(float x, float y);
  
  std::chrono::time_point<std::chrono::steady_clock> m_last_call;

  entt::registry m_registry;
};