#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class Animation
{
private:
	std::vector <sf::IntRect> frames;
	std::vector <sf::IntRect> frames_flip;
	sf::Sprite sprite;

	bool flip;
	bool isPlaying;

	float currentFrame;
	float Speed;
public:
	Animation(sf::Texture& t, int x, int y, int w, int h, int count, float speed, int step);
	Animation() {}

	sf::Sprite GetSprite();
	
	void tick(float time); 
	void SetFlip(bool b);
	void SetIsPl(bool b);
	void SetPos(float x, float y);
	void setNumFrame(float num);
	int getNumFrame();
	bool getFlip();
};

class AnimManager
{
private:
	sf::String currentAnim;
	std::map<sf::String, Animation> animlist;
public:
	AnimManager(){}

	void create(sf::String name, sf::Texture &t, int x, int y,  int w ,int h , int count, float speed, int step);
	void draw(sf::RenderWindow &window, float x, float y);
	void set(sf::String name);
	void flip(bool b);
	void tick(float time);
	void pause();
	void play();
	void setNumFrame(float num);
	int getNumFrame();
	bool getAnimFlip();
};