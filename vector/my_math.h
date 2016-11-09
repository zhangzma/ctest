// my_maht.h
// ################################################################################
// #
// #   Copyright (c) 2015 www.bjfz.com. All rights reserved.
// #
// # 说明：
// ################################################################################

#ifndef _MY_MATH_H_
#define _MY_MATH_H_


#include <cstdio>
#include <cmath>

#define CONFIG_ARCH_ARM
/**
 * @brief Instance structure for the floating-point matrix structure.
 */    

typedef struct
{
    unsigned short numRows;     /**< number of rows of the matrix.     */
    unsigned short numCols;     /**< number of columns of the matrix.  */
    float *pData;     /**< points to the data of the matrix. */
} arm_matrix_instance_f32;

namespace math
{



template <unsigned int N>
class Vector;

template <unsigned int N>
class VectorBase
{
public:
	/**
	 * vector data
	 */
	float data[N];

	/**
	 * struct for using arm_math functions, represents column vector
	 */
	#ifdef CONFIG_ARCH_ARM
	arm_matrix_instance_f32 arm_col;
	#else
	eigen_matrix_instance arm_col;
	#endif


	/**
	 * trivial ctor
	 * initializes elements to zero
	 */
	VectorBase() :
		data{},
		arm_col{N, 1, &data[0]}
	{

	}

	virtual ~VectorBase() {};

	/**
	 * copy ctor
	 */
	VectorBase(const VectorBase<N> &v) :
		arm_col{N, 1, &data[0]}
	{
		memcpy(data, v.data, sizeof(data));
	}

	/**
	 * setting ctor
	 */
	VectorBase(const float d[N]) :
		arm_col{N, 1, &data[0]}
	{
		memcpy(data, d, sizeof(data));
	}

	/**
	 * set data
	 */
	void set(const float d[N]) {
		memcpy(data, d, sizeof(data));
	}

	/**
	 * access to elements by index
	 */
	float &operator()(const unsigned int i) {
		return data[i];
	}

	/**
	 * access to elements by index
	 */
	float operator()(const unsigned int i) const {
		return data[i];
	}

	/**
	 * get vector size
	 */
	unsigned int get_size() const {
		return N;
	}

	/**
	 * test for equality
	 */
	bool operator ==(const Vector<N> &v) const {
		for (unsigned int i = 0; i < N; i++)
			if (data[i] != v.data[i])
				return false;

		return true;
	}

	/**
	 * test for inequality
	 */
	bool operator !=(const Vector<N> &v) const {
		for (unsigned int i = 0; i < N; i++)
			if (data[i] != v.data[i])
				return true;

		return false;
	}

	/**
	 * set to value
	 */
	const Vector<N> &operator =(const Vector<N> &v) {
		memcpy(data, v.data, sizeof(data));
		return *static_cast<const Vector<N>*>(this);
	}

	/**
	 * negation
	 */
	const Vector<N> operator -(void) const {
		Vector<N> res;

		for (unsigned int i = 0; i < N; i++)
			res.data[i] = -data[i];

		return res;
	}

	/**
	 * addition
	 */
	const Vector<N> operator +(const Vector<N> &v) const {
		Vector<N> res;

		for (unsigned int i = 0; i < N; i++)
			res.data[i] = data[i] + v.data[i];

		return res;
	}

	/**
	 * subtraction
	 */
	const Vector<N> operator -(const Vector<N> &v) const {
		Vector<N> res;

		for (unsigned int i = 0; i < N; i++)
			res.data[i] = data[i] - v.data[i];

		return res;
	}

	/**
	 * uniform scaling
	 */
	const Vector<N> operator *(const float num) const {
		Vector<N> res;

		for (unsigned int i = 0; i < N; i++)
			res.data[i] = data[i] * num;

		return res;
	}

	/**
	 * uniform scaling
	 */
	const Vector<N> operator /(const float num) const {
		Vector<N> res;

		for (unsigned int i = 0; i < N; i++)
			res.data[i] = data[i] / num;

		return res;
	}

	/**
	 * addition
	 */
	const Vector<N> &operator +=(const Vector<N> &v) {
		for (unsigned int i = 0; i < N; i++)
			data[i] += v.data[i];

		return *static_cast<const Vector<N>*>(this);
	}

	/**
	 * subtraction
	 */
	const Vector<N> &operator -=(const Vector<N> &v) {
		for (unsigned int i = 0; i < N; i++)
			data[i] -= v.data[i];

		return *static_cast<const Vector<N>*>(this);
	}

	/**
	 * uniform scaling
	 */
	const Vector<N> &operator *=(const float num) {
		for (unsigned int i = 0; i < N; i++)
			data[i] *= num;

		return *static_cast<const Vector<N>*>(this);
	}

	/**
	 * uniform scaling
	 */
	const Vector<N> &operator /=(const float num) {
		for (unsigned int i = 0; i < N; i++)
			data[i] /= num;

		return *static_cast<const Vector<N>*>(this);
	}

	/**
	 * dot product
	 */
	float operator *(const Vector<N> &v) const {
		float res = 0.0f;

		for (unsigned int i = 0; i < N; i++)
			res += data[i] * v.data[i];

		return res;
	}

	/**
	 * element by element multiplication
	 */
	const Vector<N> emult(const Vector<N> &v) const {
		Vector<N> res;

		for (unsigned int i = 0; i < N; i++)
			res.data[i] = data[i] * v.data[i];

		return res;
	}

	/**
	 * element by element division
	 */
	const Vector<N> edivide(const Vector<N> &v) const {
		Vector<N> res;

		for (unsigned int i = 0; i < N; i++)
			res.data[i] = data[i] / v.data[i];

		return res;
	}

	/**
	 * gets the length of this vector squared
	 */
	float length_squared() const {
		float res = 0.0f;

		for (unsigned int i = 0; i < N; i++)
			res += data[i] * data[i];

		return res;
	}

	/**
	 * gets the length of this vector
	 */
	float length() const {
		float res = 0.0f;

		for (unsigned int i = 0; i < N; i++)
			res += data[i] * data[i];

		return sqrtf(res);
	}

	/**
	 * normalizes this vector
	 */
	void normalize() {
		*this /= length();
	}

	/**
	 * returns the normalized version of this vector
	 */
	Vector<N> normalized() const {
		return *this / length();
	}

	/**
	 * set zero vector
	 */
	void zero(void) {
		memset(data, 0, sizeof(data));
	}

	void print(void) {
		printf("[ ");

		for (unsigned int i = 0; i < N; i++)
			printf("%.3f\t", data[i]);

		printf("]\n");
	}
};

template <unsigned int N>
class Vector : public VectorBase<N>
{
public:
	Vector() : VectorBase<N>() {}

	Vector(const Vector<N> &v) : VectorBase<N>(v) {}

	Vector(const float d[N]) : VectorBase<N>(d) {}

	/**
	 * set to value
	 */
	const Vector<N> &operator =(const Vector<N> &v) {
		memcpy(this->data, v.data, sizeof(this->data));
		return *this;
	}
};

template <>
class  Vector<2> : public VectorBase<2>
{
public:
	Vector() : VectorBase<2>() {}

	// simple copy is 1.6 times faster than memcpy
	Vector(const Vector<2> &v) : VectorBase<2>() {
		data[0] = v.data[0];
		data[1] = v.data[1];
	}

	Vector(const float d[2]) : VectorBase<2>() {
		data[0] = d[0];
		data[1] = d[1];
	}

	Vector(const float x, const float y) : VectorBase<2>() {
		data[0] = x;
		data[1] = y;
	}

	/**
	 * set data
	 */
	void set(const float d[2]) {
		data[0] = d[0];
		data[1] = d[1];
	}

	/**
	 * set to value
	 */
	const Vector<2> &operator =(const Vector<2> &v) {
		data[0] = v.data[0];
		data[1] = v.data[1];
		return *this;
	}

	float operator %(const Vector<2> &v) const {
		return data[0] * v.data[1] - data[1] * v.data[0];
	}
};

}
#endif /* _MY_MATH_H_ */
