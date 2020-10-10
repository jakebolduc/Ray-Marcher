#ifndef __VECTOR_H_INCLUDED__ //test if included
#define __VECTOR_H_INCLUDED__ //mark as included
#define VECT_FLOAT float

namespace vector{

	struct vector{
		VECT_FLOAT x;
		VECT_FLOAT y;
		VECT_FLOAT z;
	};

	vector set(VECT_FLOAT x, VECT_FLOAT y, VECT_FLOAT z);
	vector add(vector A, vector B);
	vector scale(vector A, VECT_FLOAT scalar);
	VECT_FLOAT dist(vector A, vector B);
	vector normalize(vector A);
}
#endif
