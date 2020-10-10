#include "raymarching.h"
#define MAX_DIST 250.0
#define MAX_STEPS 250
#define SURFACE_DIST 0.02



namespace raymarch{
	VECT_FLOAT RaymarchScene::GetSceneDist(vector::vector point){
		return 10;
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
