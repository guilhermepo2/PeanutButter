#pragma once
#include <random>

// Source: https://github.com/TheCherno/OneHourParticleSystem/
// TODO: Make a random system that actually allows for different implementation and replication of values.

namespace PeanutButter {
	class Random {
	public:
		static void Init() {
			s_RandomEngine.seed(std::random_device()());
		}

		static float Float() {
			float Value = (float)s_Distribution(s_RandomEngine) / (float)UINT32_MAX;
			if (s_Distribution(s_RandomEngine) % 2 == 0) {
				return -Value;
			}
			else {
				return Value;
			}
		}

		static int Int() {
			return s_Distribution(s_RandomEngine);
		}
	private:
		static std::mt19937 s_RandomEngine;
		static std::uniform_int_distribution<std::mt19937::result_type> s_Distribution;
	};
}