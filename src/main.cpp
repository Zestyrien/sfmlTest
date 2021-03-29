
#include "core.h"
#include "village.h"

int main()
{
  entt::registry registry;

  spdlog::info("The Village, version {}.{}.{}", 0, 0, 1);

  Village village;

  village.Start();

  return 0;
}