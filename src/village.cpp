#include "village.h"
#include "assets.h"

void Village::Start()
{
  LoadAsset(TextureName::MK1K);

  AddPlayer(200.0f, 300.0f);
  AddPlayer(500.0f, 300.0f);

  Loop();
}

entt::entity Village::LoadAsset(TextureName const &name)
{
  auto spriteEntt = m_registry.create();

  m_registry.emplace<TextureName>(spriteEntt, name);
  auto &txt = m_registry.emplace<sf::Texture>(spriteEntt);
  auto &spr = m_registry.emplace<sf::Sprite>(spriteEntt);

  txt.loadFromFile(Assets::GetTextureFullPath(TextureName::MK1K));

  spr.setTexture(txt);
  spr.setOrigin(txt.getSize().x / 2, txt.getSize().y / 2);
  spr.setScale(0.1f, 0.1f);

  return spriteEntt;
}

void Village::AddPlayer(float x, float y)
{
  auto playerEntt = m_registry.create();
  auto &player = m_registry.emplace<Player>(playerEntt);

  auto view = m_registry.view<TextureName>();
  for (auto const [enttSprite, name] : view.each())
  {
    if (name == TextureName::MK1K)
    {
      player.sprite = enttSprite;
      break;
    }
  }

  player.pos.x = x;
  player.pos.y = y;
}
/*
void Village::AddEntity(TextureName const &name)
{
  //LoadAsset(name);
  auto spriteEntt = m_registry.create();

  auto &txt = m_registry.emplace<sf::Texture>(spriteEntt);
  auto &spr = m_registry.emplace<sf::Sprite>(spriteEntt);
  txt.loadFromFile(Assets::GetTextureFullPath(TextureName::MK1K));

  //auto imgview = m_registry.view<TextureName, sf::Image>();
  //for (auto [imgEntt, txtname, img] : imgview.each())
  //{
  //  if (txtname == TextureName::MK1K)
  //  {
  //    txt.loadFromStream(inS);
  //  }
  //}

  spr.setTexture(txt);
  spr.setPosition(x, y);
  spr.setOrigin(txt.getSize().x / 2, txt.getSize().y / 2);
  spr.setScale(0.1f, 0.1f);
}
*/
void Village::Loop()
{
  bool gameover = false;

  // create the window
  sf::RenderWindow window(sf::VideoMode(800, 600), "The village");

  while (window.isOpen() && !gameover)
  {
    auto now = std::chrono::steady_clock::now();
    auto const elapsed = now - m_last_call;
    m_last_call = now;

    // check all the window's events that were triggered since the last iteration of the loop
    sf::Event event;
    while (window.pollEvent(event))
    {
      // "close requested" event: we close the window
      if (event.type == sf::Event::Closed)
      {
        window.close();
      }
    }

    // clear the window with black color
    window.clear(sf::Color::Black);

    //Collects entities to render on the screen:

    //Render:
    auto playerView = m_registry.view<Player>();
    auto spView = m_registry.view<sf::Sprite>();
    for (auto const [entity, player] : playerView.each())
    {
      auto sp = spView.get<sf::Sprite>(player.sprite);
      sp.setPosition(player.pos);
      window.draw(sp);
    }

    //sf::Text fps;
    // end the current frame
    window.display();
  }
}