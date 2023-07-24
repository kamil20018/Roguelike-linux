#include "TextField2.h"

TextField2::TextField2(std::string text) : text(text) {
	processText();
}

void TextField2::processText() {
	std::vector<std::string> words;
	std::string word;
	for (auto letter : text) {

		if (letter != ' ' && letter != '\n') {
			word += letter;
		}
		else {
			words.push_back(word);
			word.clear();
		}

	}

	int letterCap = 50;

	std::string line;

	for (auto word : words) {
		if (line.length() + word.length() > letterCap) {
			std::cout << line << std::endl;
			line.clear();
		}
		else {
			line += word + " ";
		}

	}
}
