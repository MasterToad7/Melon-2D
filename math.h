#ifndef MATH_H
#define MATH_H

namespace mln
{
	struct Vec2 {
		float x, y;
		Vec2 Normalize();
	};
	struct Vec3 {
		float x, y, z;
	};
	struct Vec4 {
		float x, y, z, w;
	};
	Vec2 AddVec2(Vec2 a, Vec2 b);
	Vec3 AddVec3(Vec3 a, Vec3 b);
	Vec4 AddVec4(Vec4 a, Vec4 b);
}

#endif