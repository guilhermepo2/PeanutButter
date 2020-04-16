#pragma once
#include <math.h>
#include <string>

namespace PeanutButter {
	class Vector2 {
	public:

		/** X Component for the vector */
		float x;

		/** Y Component for the vector */
		float y;

		/** Constructors */
		Vector2() : x(0), y(0) {}
		Vector2(float InX, float InY) : x(InX), y(InY) {}
		Vector2(const Vector2& Other) : x(Other.x), y(Other.y) {}

		/** Static properties */
		/*
		static const Vector2 Zero;
		static const Vector2 One;
		static const Vector2 Up;
		static const Vector2 Right;
		static const Vector2 Down;
		static const Vector2 Left;
		*/

	public:

		/** -- */
		inline float GetLength() const { return sqrt( (x * x) + (y * y) ); }

		/** - */
		void Normalize() {
			float Length = GetLength();

			if (Length > 0) {
				(*this) /= Length;
			}
		}

		/** - */
		Vector2 GetNormalized() {
			float Length = GetLength();
			return Vector2(x / Length, y / Length);
		}

		/** Vector2 + Vector2 */
		Vector2 operator+(const Vector2& Other) const {
			return Vector2(x + Other.x, y + Other.y);
		}

		/** Vector2 - Vector2 */
		Vector2 operator-(const Vector2& Other) const {
			return Vector2(x - Other.x, y - Other.y);
		}

		/** Vector2 * Scalar */
		template<typename T>
		Vector2 operator*(const T& Scalar) const {
			return Vector2(x * Scalar, y * Scalar);
		}

		/** Vector / Scalar */
		template<typename T>
		Vector2 operator/(const T& Scalar) const {
			return Vector2(x / Scalar, y / Scalar);
		}

		/** Vector2 += Vector2 */
		Vector2& operator+=(const Vector2& Other) {
			x += Other.x;
			y += Other.y;
			return *this;
		}

		/** Vector2 -= Vector2 */
		Vector2 operator-=(const Vector2& Other) {
			x -= Other.x;
			y -= Other.y;
			return *this;
		}

		/** Vector2 *= Scalar */
		template<typename T>
		Vector2& operator*=(const T& Scalar) {
			x *= Scalar;
			y *= Scalar;
			return *this;
		}

		/** Vector2 /= Scalar */
		template<typename T>
		Vector2& operator/=(const T& Scalar) {
			x /= Scalar;
			y /= Scalar;
			return *this;
		}

		/** Equality */
		bool operator==(const Vector2& Other) const {
			return (x == Other.x && y == Other.y);
		}

		/** Inequality */
		bool operator!=(const Vector2& Other) const {
			return (x != Other.x || y != Other.y);
		}

		/** Negative Copy (-Vector2) */
		Vector2 operator-() const {
			return Vector2(-x, -y);
		}

		/** To String */
		std::string ToString() const {
			return std::string("(" + std::to_string(x) + "," + std::to_string(y) + ")");
		}
	};

	/** Scalar * Vector */
	template<typename T>
	inline Vector2 operator*(const T& Scalar, const Vector2& Other) {
		return Vector2(Scalar * Other.x, Scalar * Other.y);
	}

	/** Scalar / Vector */
	template<typename T>
	inline Vector2 operator/(const T& Scalar, const Vector2& Other) {
		return Vector2(Scalar / Other.x, Scalar / Other.y);
	}

	/*
	const Vector2 Vector2::Zero = Vector2(0, 0);
	const Vector2 Vector2::One = Vector2(1, 1);
	const Vector2 Vector2::Up = Vector2(1, 0);
	const Vector2 Vector2::Right = Vector2(0, 1);
	const Vector2 Vector2::Down = Vector2(-1, 0);
	const Vector2 Vector2::Left = Vector2(0, -1);
	*/
}