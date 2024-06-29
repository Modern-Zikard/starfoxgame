#pragma once

#include "ClassPers.h"

class Animation
{
private:
	std::vector <sf::IntRect> frames, frames_flip;

	sf::Sprite sprite;

	bool flip;
	bool isPlaying;

	float currentFrame;
	float Speed;
public:
	Animation(sf::Texture& t, int x, int y, int w, int h, int count, float speed, int step);
	Animation(){}

	void tick(float time); 

	sf::Sprite GetSprite();
	void SetFlip(bool b);
	void SetIsPl(bool b);
	

};

class AnimManager
{
private:
	sf::String currentAnim;
	std::map<sf::String, Animation> animlist;

public:

	AnimManager(){}

	void create(sf::String name, sf::Texture &t, int x, int y,  int w ,int h , int count, float speed, int step);
	void draw(sf::RenderWindow &window, int x = 0, int y = 0);
	void set(sf::String name);
	void flip(bool b);
	void tick(float time);
	void pause();
	void play();


};