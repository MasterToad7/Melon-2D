#include "vecmath.h"
#include <iostream>

namespace mln
{
	Vec2 Vec2::Normalize() {
		float a = x;
		float b = y;
		if (a != 0) {
			a = pow(a, 2);
		}
		if (b != 0) {
			b = pow(b, 2);
		}
		float c_SQR = a + b;
		float c = sqrt(c_SQR);
		if (a != 0) {
			a = x / c;
		}
		if (b != 0) {
			b = y / c;
		}
		return { a , b };
	};
	Vec2 AddVec2(Vec2 a, Vec2 b) {
		Vec2 c;
		c.x = a.x + b.x;
		c.y = a.y + b.y;
		return c;
	}
	Vec3 AddVec3(Vec3 a, Vec3 b) {
		Vec3 c;
		c.x = a.x + b.x;
		c.y = a.y + b.y;
		c.z = a.z + b.z;
		return c;
	}
	Vec4 AddVec4(Vec4 a, Vec4 b) {
		Vec4 c;
		c.x = a.x + b.x;
		c.y = a.y + b.y;
		c.z = a.z + b.z;
		c.w = a.w + b.w;
		return c;
	}
}