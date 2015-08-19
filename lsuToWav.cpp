extern "C" {
#include "wave_writer.h"
};

#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <stdint.h>

int main(int argc, const char* argv[])
{
	_finddata_t fileInfo;
	memset(&fileInfo, 0, sizeof(fileInfo));

	intptr_t handle = _findfirst("*.lsu", &fileInfo);
	intptr_t result = 0;

	wave_writer_format format;
	format.num_channels = 1;
	format.sample_rate = 44100;
	format.sample_bits = 16;

	while (handle > 0 && result >= 0) {
		printf("%s -> ", fileInfo.name);

		// Get the 16 bit, signed, mono data.
		FILE* fp = fopen(fileInfo.name, "rb");
		if (!fp) {
			printf("\nError opening file %s\n", fileInfo.name);
			break;
		}

		fseek(fp, 0, SEEK_END);
		long size = ftell(fp);
		fseek(fp, 0, SEEK_SET);

		uint8_t* mem = new uint8_t[size];
		fread(mem, size, 1, fp);
		fclose(fp);

		// Create the WAV file.
		std::string fname(fileInfo.name);
		fname = fname.substr(0, fname.size()-4);
		fname.append(".wav");
		printf("%s\n", fname.c_str());

		wave_writer_error error;
		wave_writer* pWriter = wave_writer_open(fname.c_str(), &format, &error);
		if (!error) {
			printf("\nError opening file %s\n", fname.c_str());
			break;
		}
		wave_writer_put_samples(pWriter, size / 2, mem);
		delete[] mem;

		wave_writer_close(pWriter, &error);
		if (!error) {
			printf("\nError writing file %s\n", fname.c_str());
			break;
		}

		result = _findnext(handle, &fileInfo);
	}
	if (handle > 0) {
		_findclose(handle);
	}
	return 0;
}