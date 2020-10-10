#include "raymarching.h"
#define MAX_DIST 100.0
#define MAX_STEPS 1000
#define SURFACE_DIST 0.01



namespace raymarch{

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


	VECT_FLOAT RaymarchScene::GetSceneDist(vector::vector point){
		//to test the renderer there is only one object for now
		return  objects->GetDist(point);
	}
	vector::vector RaymarchScene::raymarch(vector::vector ro, vector::vector rd){
		VECT_FLOAT dO = 0;
		vector::vector p;
		for(int i=0; i<=MAX_STEPS; ++i){
			p = vector::add(ro, vector::scale(rd,dO));
			VECT_FLOAT ds = GetSceneDist(p);
			dO = dO + ds;
			if(ds < SURFACE_DIST or dO > MAX_DIST){
				break;
			}
		}
		return p;
	}
}
