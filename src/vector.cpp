#include <math.h>
#include "vector.h"



namespace vector{

	vector set(VECT_FLOAT x, VECT_FLOAT y, VECT_FLOAT z){
		vector result;
		result.x = x;
		result.y = y;
		result.z = z;
		return result;
	}

 	vector add(vector A, vector B){
		return set(A.x+B.x, A.y+B.y, A.z+B.z);
 	}

	vector scale(vector A, VECT_FLOAT scalar){
		return set(A.x*scalar, A.y*scalar, A.z*scalar);
	}

	VECT_FLOAT dist(vector A, vector B){
		return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y)+(A.z-B.z)*(A.z-B.z));
	}

	vector normalize(vector A){
		return scale(A, 1/dist(set(0,0,0),A));
	}

}
