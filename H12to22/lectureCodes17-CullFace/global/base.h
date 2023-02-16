#pragma once

#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<assert.h>

#define PI					3.14159265358979323
#define DEG2RAD(theta)		(0.01745329251994329 * (theta))
#define FRACTION(v)			((v) - (int)(v))

using byte = unsigned char;

struct RGBA {
	byte mB;
	byte mG;
	byte mR;
	byte mA;

	RGBA(
		byte r = 255,
		byte g = 255,
		byte b = 255,
		byte a = 255)
	{
		mR = r;
		mG = g;
		mB = b;
		mA = a;
	}
};

#define ARRAY_BUFFER 0
#define ELEMENT_ARRAY_BUFFER 1

#define DRAW_LINES 0
#define DRAW_TRIANGLES 1

#define CULL_FACE 1

#define FRONT_FACE 0
#define BACK_FACE 1
#define FRONT_FACE_CW 0
#define FRONT_FACE_CCW 1