#pragma once

#include "core.h"

enum class TextureName
{
  MK1K = 0
};

namespace Assets
{
  std::string GetTextureFullPath(TextureName const &name);
  std::string GetTexturePath(TextureName const &name);
  std::string GetFileName(TextureName const &name);
}