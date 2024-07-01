#include "ClassAnimationManager.h"



Animation::Animation(sf::Texture &t, int x, int y,  int w, int h, int count, float speed, int step)
{
	Speed = speed;
	sprite.setTexture(t);
	
	currentFrame = 0;
	isPlaying = true;
	flip = false;

	for (int i = 0; i < count; i++)
	{
		frames.push_back(sf::IntRect(x + i*step, y, w, h));
		frames_flip.push_back(sf::IntRect(x + i*step+w, y, -w, h));
	}

}

void Animation::tick(float time)
{
	if (!isPlaying) return;

	currentFrame += Speed * time;
	if (currentFrame > frames.size())
		currentFrame -= frames.size();
	int i = currentFrame;

	if(!flip) sprite.setTextureRect(frames[i]);
	if(flip)  sprite.setTextureRect(frames_flip[i]);
}

sf::Sprite Animation::GetSprite(){ return sprite; }

void Animation::SetFlip(bool b) { flip = b; }
void Animation::SetIsPl(bool b) { isPlaying = b; }
void Animation::SetPos(float x, float y) { sprite.setPosition(x, y); }

bool Animation::getFlip() { return flip; }





void AnimManager::create(sf::String name, sf::Texture &t, int x, int y,  int w, int h, int count, float speed, int step)
{
	animlist[name] = Animation(t, x, y, w, h, count, speed, step);
	currentAnim = name;
}


void AnimManager::draw(sf::RenderWindow &window, float x, float y)
{
	animlist[currentAnim].SetPos(x, y);
	window.draw(animlist[currentAnim].GetSprite());
}

void AnimManager::set(sf::String name) { currentAnim = name; }
void AnimManager::flip(bool b) { animlist[currentAnim].SetFlip(b); }
void AnimManager::tick(float time) { animlist[currentAnim].tick(time); }
void AnimManager::pause() { animlist[currentAnim].SetIsPl(false); }
void AnimManager::play() { animlist[currentAnim].SetIsPl(true); }

bool AnimManager::getAnimFlip() { return animlist[currentAnim].getFlip(); }



