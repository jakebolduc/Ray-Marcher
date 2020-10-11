#ifndef __RAYMARCHING_H_INCLUDED__ //test if included
#define __RAYMARCHING_H_INCLUDED__ //mark as included

#include "vector.h"

#define MAX_DIST 200.0
#define MAX_STEPS 250
#define SURFACE_DIST 0.01


namespace raymarch{

	class RaymarchObject{
	public:
		virtual VECT_FLOAT GetDist(vector::vector point) =0;
		virtual vector::vector GetColor(vector::vector point) =0;
	};
	class RaymarchObjectLILI{
		friend class RaymarchScene;
		RaymarchObjectLILI *next = nullptr;
		RaymarchObject *data = nullptr;
	public:
		void add(RaymarchObject *object);
		RaymarchObject *index(int index);
	};

	class sdfSphere: public RaymarchObject{
		vector::vector position;
		VECT_FLOAT radius;
		vector::vector color;
	public:
		VECT_FLOAT GetDist(vector::vector point);
		vector::vector GetColor(vector::vector point);
		sdfSphere(VECT_FLOAT r, vector::vector pos);
	};
	class sdfPlane: public RaymarchObject{};

	class sdfU: public RaymarchObject{};
	class sdfI: public RaymarchObject{};
	class sdfD: public RaymarchObject{};

	class sdfMeta: public RaymarchObject{};

	class RaymarchScene{
		//a linked list might be better...
		RaymarchObjectLILI *objects = nullptr;
		RaymarchObjectLILI *tail = nullptr;
	public:
		int glow;
		void addObject(RaymarchObject *object);
		VECT_FLOAT GetSceneDist(vector::vector point);
		VECT_FLOAT GetObject(vector::vector point);
		vector::vector raymarch(vector::vector ro, vector::vector rd);
		int raymarchGlow(vector::vector ro, vector::vector rd);
	};
}

#endif
