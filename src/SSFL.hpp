#include <string>

// Author: https://github.com/yaylucasf

namespace ssfl {

	int string_length(const char* string) {

		int length{ 0 };

		while (*string != '\0') {

			++length;
			++string;

		}

		return length;

	}

	std::string trim(const char* string) {

		int length{ string_length(string) };

		int first_char_position{ 0 };
		int last_char_position{ length - 1 };

		for (int i = 0; i < length; ++i) {

			if (string[i] != ' ' && string[i] != '\0') {

				first_char_position = i;
				break;

			}

		}

		for (int i = length; i > 0; --i) {

			if (string[i] != ' ' && string[i] != '\0') {

				last_char_position = i;
				break;

			}

		}

		std::string new_string{ "" };

		for (int i = 0; i < length; ++i) {

			if (i >= first_char_position && i <= last_char_position) {

				new_string += string[i];

			}

		}

		return new_string;

	}

	std::string to_uppercase(const char* string) {

		int length{ string_length(string) };

		std::string new_string = "";

		for (int i = 0; i < length; ++i) {

			if (string[i] >= 97 && string[i] <= 122) {

				new_string += string[i] - 32;

			} else {

				new_string += string[i];

			}

		}

		return new_string;

	}

	std::string to_lowercase(const char* string) {

		int length{ string_length(string) };

		std::string new_string = "";

		for (int i = 0; i < length; ++i) {

			if (string[i] >= 65 && string[i] <= 90) {

				new_string += string[i] + 32;

			} else {

				new_string += string[i];

			}

		}

		return new_string;

	}

	int to_integer(const char* string) {

		int length{ string_length(string) };

		if (length == 0) {

			return 0;

		}

		int result{ 0 };

		for (int i = 0; i < length; ++i) {

			if (string[i] < 48 && string[i] > 57) {

				return 0;

			}

		}

		int k = length;

		for (int i = 0; i < length; ++i) {

			if (k >= 0) {

				result += (string[k - 1] - 48) * static_cast<int>(pow(10, i));
				--k;

			} else {

				break;

			}

		}

		return result;

	}

}
