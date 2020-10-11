#include <algorithm>
#include "raymarching.h"

namespace raymarch{

// sdfSphere
	VECT_FLOAT sdfSphere::GetDist(vector::vector point){
		return vector::dist(position, point) - radius;
	}
	vector::vector sdfSphere::GetColor(vector::vector point){
		return color;
	}
	sdfSphere::sdfSphere(VECT_FLOAT r, vector::vector pos){
		radius = r;
		position = pos;
		color = vector::set(1,1,1);
	}

// RaymarchObjectLILI
	void RaymarchObjectLILI::add(RaymarchObject *object){
		RaymarchObjectLILI * current = this;
		while(next != nullptr){
			current = current -> next;
		}
		current -> next = new RaymarchObjectLILI;
		current -> next -> data = object;
	}

// raymarch scene
	void RaymarchScene::addObject(RaymarchObject *object){

		if(objects == nullptr){
			// probably a better way to initalise such a list
			objects = new RaymarchObjectLILI;
			objects -> data = object;
			tail = objects;
		}
		else{
			tail -> add(object);
		}
	}
	VECT_FLOAT RaymarchScene::GetSceneDist(vector::vector point){
		// mabey let the LILI index its self?
		VECT_FLOAT distance = MAX_DIST;
		RaymarchObjectLILI *current = objects;
		while(current != nullptr){

			distance = std::min(distance, current -> data -> GetDist(point));
			current = current -> next;
		}
		return distance;
	}
	vector::vector RaymarchScene::raymarch(vector::vector ro, vector::vector rd){
		VECT_FLOAT dO = 0;
		vector::vector p;
		int i;
		for(i=0; i<=MAX_STEPS; ++i){
			p = vector::add(ro, vector::scale(rd,dO));
			VECT_FLOAT ds = GetSceneDist(p);
			dO = dO + ds;
			if(ds < SURFACE_DIST or dO > MAX_DIST){
				break;
			}
		}
		glow = i;
		return p;
	}
	int RaymarchScene::raymarchGlow(vector::vector ro, vector::vector rd){ //deprecated
		VECT_FLOAT dO = 0;
		vector::vector p;
		int i;
		for(i=0; i<=MAX_STEPS; ++i){
			p = vector::add(ro, vector::scale(rd,dO));
			VECT_FLOAT ds = GetSceneDist(p);
			dO = dO + ds;
			if(ds < SURFACE_DIST or dO > MAX_DIST){
				break;
			}
		}
		return i;
	}
}
