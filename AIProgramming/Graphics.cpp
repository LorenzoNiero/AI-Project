//#include "Graphics.h"
//
//void setTilePosition(vector<Node> &result, vector<Sprite> &sprites)
//{
//	if (!result.empty())
//	{
//		Node config = result.back();
//		result.pop_back();
//
//		for (int index = 0; index < 16; ++index)
//			if (config.getConfigurationIndexed(index) != 16)
//				sprites.at(config.getConfigurationIndexed(index) - 1).setPosition((index % 4) * 100.0f, (index / 4) * 100.0f);
//	}
//}
//
//int Graphic::Initialize(vector<Node> &result) {
//	
//	window.create(VideoMode(400, 400), "15 Puzzle", Style::Close);
//	window.setVerticalSyncEnabled(true);
//	
//	if (!texture.loadFromFile("Sprites/15.png"))
//		return -1;
//	texture.setSmooth(true);
//
//	sprite.setTexture(texture);
//
//	for (int index = 0; index < 15; ++index)
//	{
//		sprite.setTextureRect(IntRect((index % 4) * 100, (index / 4) * 100, 100, 100));
//		sprites.push_back(sprite);
//	}
//	setTilePosition(result, sprites);
//	return 0;
//}
//
//
//void Graphic::Draw(vector<Node> &result) {
//	while (window.isOpen())
//	{
//		window.clear(Color(33, 33, 33));
//
//		for (int index = 0; index < 15; ++index)
//			window.draw(sprites[index]);
//
//		Event event;
//
//		while (window.pollEvent(event))
//		{
//			if (event.type == Event::Closed)
//				window.close();
//			else if (event.type == Event::KeyPressed)
//				if (event.key.code == Keyboard::Escape)
//					window.close();
//				else if (event.key.code == Keyboard::R)
//					setTilePosition(result, sprites);
//		}
//
//		window.display();
//	}
//}