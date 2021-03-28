//something called a "header guard"?
#ifndef VECH
#define VECH

#include <math.h>
#include <cstdlib>
#include <iostream>

struct Vec3 {
    float e[3];

    Vec3() {};
    Vec3(float e0, float e1, float e2) : 
    e {e0, e1, e2} {}

    float x() const { return e[0]; }
    float y() const { return e[1]; }
    float z() const { return e[2]; }

    float r() const { return e[0]; }
    float g() const { return e[1]; }
    float b() const { return e[2]; }

    Vec3 operator-() const { return Vec3(-e[0], -e[1], -e[2]); }
    float operator[] (int i) const { return e[i]; }
    float& operator[] (int i) { return e[i]; }

    inline Vec3& operator+=(const Vec3& v2);
    inline Vec3& operator-=(const Vec3& v2);
    inline Vec3& operator*=(const Vec3& v2);
    inline Vec3& operator/=(const Vec3& v2);

    inline Vec3& operator*=(const float t);
    inline Vec3& operator/=(const float t);

    float length() const {
        return sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]);
    }

    float sqrLength() const {
        return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
    }

    void makeUnitVector();

};

Vec3 operator+(Vec3 const& v1, Vec3 const& v2);
Vec3 operator-(Vec3 const& v1, Vec3 const& v2);
Vec3 operator*(Vec3 const& v1, Vec3 const& v2);
Vec3 operator/(Vec3 const& v1, Vec3 const& v2);

Vec3 operator*(Vec3 const& v, float t);
Vec3 operator*(float t, Vec3 const& v);
Vec3 operator/(Vec3 const& v, float t);
float dot(Vec3 const& v1, Vec3 const& v2);
Vec3 cross(Vec3 const& v1, Vec3 const& v2);

inline Vec3 unitVector(Vec3 v);

#endif