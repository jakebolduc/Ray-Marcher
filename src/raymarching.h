#ifndef __RAYMARCHING_H_INCLUDED__ //test if included
#define __RAYMARCHING_H_INCLUDED__ //mark as included

#include "vector.h"

namespace raymarch{

	class RaymarchObject{
	public:
		VECT_FLOAT GetDist(vector::vector point);
		vector::vector GetColor(vector::vector point);
	};

	class sdfSphere: public RaymarchObject{
		vector::vector position;
		VECT_FLOAT radius;
		vector::vector color;

	};

	class sdfPlane: public RaymarchObject{};
	class sdfU: public RaymarchObject{};
	class sdfI: public RaymarchObject{};
	class sdfD: public RaymarchObject{};
	class sdfMeta: public RaymarchObject{};

	class RaymarchScene{
		//a linked list might be better...
		RaymarchObject objects[100];
		VECT_FLOAT GetSceneDist(vector::vector point);
		VECT_FLOAT GetObject(vector::vector point);
		vector::vector raymarch(vector::vector ro, vector::vector rd);
	};
}

#endif
