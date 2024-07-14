#ifndef TEXTURE_H
#define TEXTURE_H

#define PNG 0
#define JPG 1

#include "melon.h"

namespace mln {
	class texture {
	private:
		unsigned int ID;
		int width, height, nrChannels;
		unsigned char* data;
	public:
		texture(const char* path, int filetype);
		~texture();
		void activate();
		void deactivate();
	};
}

#endif