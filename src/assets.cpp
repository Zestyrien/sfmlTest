#include "assets.h"

float constexpr defaultScale = 0.1f;
float constexpr defaultOrigin = 0.5f;

std::string const shipsPath = "../assets/invaders2d/SpaceGame/Ships/";

std::string Assets::GetTextureFullPath(TextureName const &name)
{
  return GetTexturePath(name) + GetFileName(name);
}

std::string Assets::GetTexturePath(TextureName const &name)
{
  switch (name)
  {
  case TextureName::MK1K:
    return shipsPath;
  }

  return "";
}

std::string Assets::GetFileName(TextureName const &name)
{
  switch (name)
  {
  case TextureName::MK1K:
    return "MK 1K.png";
  }

  return "";
}