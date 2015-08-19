# LSU to WAV Converter.

This simple (simple!) utility converts all the LSU files in a directory
to wave files. LSUs are used largely by microcontrollers (especially 
lightsabers) and are raw 16 bit, mono, 44100Hz data. This utility 
adds the WAV wrapper and writes a new file.

## NOTE
If you get an error about a missing DLL, you probably need the
Microsoft Redistributables. You can download and install here:

http://www.microsoft.com/en-us/download/details.aspx?id=40784
You will need the 32 bit version, even if you are on a 64 bit OS.

The original lsu files won't be changed. wav files will be created 
and placed in the same directory.

## Download

Click on the "releases" tab in github, and download 'lsuToWave.exe'.
It's an excutable, not an installer.

## Using
### The easy way
Place the .exe file in the directory with your LSU files. Double
click to run it. WAV files will be generated.

### The command line
- Open up the command line.
- Change directory to your .LSU files.
- \path\to\exe\lsuToWav

## Credits
- By Lee Thomason (www.grinninglizard.com)
- Wave converter from: https://github.com/leethomason/wave_reader_and_writer



