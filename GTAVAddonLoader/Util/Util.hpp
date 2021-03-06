#pragma once

#include <string>
#include <vector>
#include "inc/types.h"
#include <algorithm>

struct Color {
	int R;
	int G;
	int B;
	int A;
};

const Color solidWhite = {
	255, 255, 255, 255
};

// Natives called
void showText(float x, float y, float scale, const char* text, int font = 0, const Color &rgba = solidWhite, bool outline = false);
void showNotification(std::string message, int *prevNotification = nullptr);
void showSubtitle(std::string message, int duration = 2500);

//https://github.com/CamxxCore/AirSuperiority
class GameSound {
public:
	GameSound(char *sound, char *soundSet);
	~GameSound();
	void Load(char *audioBank);
	void Play(Entity ent);
	void Stop();

	bool Active;

private:
	char *m_soundSet;
	char *m_sound;
	int m_soundID;
	int m_prevNotification;
};

bool GetIMGDimensions(std::string file, unsigned *width, unsigned *height);

bool GetPNGDimensions(std::string file, unsigned *width, unsigned *height);
bool GetJPGDimensions(std::string file, unsigned *width, unsigned *height);

Hash joaat(std::string s);
std::string removeSpecialChars(std::string input);
std::string getGxtName(Hash hash); // gxt name from model
std::string to_lower(std::string data);

/*
* stl search thingy for checking if a *thing* is in a vector of *things*,
* based on the public member named "HashedName".
*/
template<typename T>
bool isHashInImgVector(Hash hash, std::vector<T> things, T *result) {
	auto addonImage = std::find_if(things.begin(), things.end(), [&hash](const T& element) {
		return element.ModelHash == hash;
	});
	if (things.end() != addonImage) {
		if (result != nullptr)
			*result = *addonImage;
		return true;
	}
	return false;
}

bool FileExists(const std::string& name);

