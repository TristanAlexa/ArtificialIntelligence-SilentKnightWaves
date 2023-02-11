#ifndef CHARACTER_H
#define CHARACTER_H

#include <vector>

#include "Scene.h"
#include "KinematicBody.h"
#include "Seek.h"
#include "Flee.h"
#include "Arrive.h"

using namespace std;

class Character  //NPC
{
private:
	class KinematicBody* body;
	class Scene* scene;

	void SteerToSeekPlayer(SteeringOutput* steering);     
	void SteerToFleePlayer(SteeringOutput* steering);
	void SteerToArriveToPlayer(SteeringOutput* steering);

	int steerType;

public:

	// Construct char defining an int that selects a steering algorithm
	Character(int steerType_)
	{
		body = NULL;
		scene = NULL;
		steerType = steerType_;
	};

	~Character()
	{
		if (body) delete body;
	};

	bool OnCreate(Scene* scene_);
	void OnDestroy() {};
	bool setTextureWidth(string file);
	void Update(float time);
	void HandleEvents(const SDL_Event& event);
	void render(float scale = 1.0f);

};

#endif

