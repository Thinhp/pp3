Note:  The latest deployed version is 108.  109 is the version that was
Perry's fixes to the the work of Askan.  Ashkan's work didn't properly deal
with the control structure for routing to the various major modes.
Perry's version has pallette implemented.



NPR-GP

Directory Structure
===================
npr
  |-RMITGP.1.5  # source code for the RMITGP engine
  |-libpng      # source code for libpng library
  |-zlib        # source code for zlib library
  |-src_nnn      # source code for the NPR-GP program
  |-decals      # stores decal files
  |-input       # stores target images
  |-masks       # stores bitmaks used to determine importance maps
  |-output      # stores output folder
  |-palettes    # stores palette files

Dependencies
============
The NPR-GP program requires the "src", "RMITGP.1.5" and "libpng" directories in order to compile. "libpng" requires the "zlib" directory to compile. The NPR-GP
additionally requires all the other directories in order to run.

All the directories listed above must be located inside the "npr" directory.
None of the directories are nested within each other.

If your RMITGP folder is named differently to "RMITGP.1.5" then you will have to
edit the Makefile in the "src" directory to reflect this.

Compiling NPR-GP
================
1.  Open a terminal
2.  Navigate to the directory in which the package has been extracted 
3a. Type "./build.sh" to build the entire NPR-GP (including the RMITGP and
    libpng) dependencies from scratch
    OR
3b. Type "./compile.sh" to compile just the NPR-GP source files
    OR
3c. Type "./rebuild.sh" to compile the NPR-GP source files after new classes
    have been created and/or the src/Makefile has been edited.

Note that you the Mac version of "libpng" is different to the PC version.

Running NPR-GP
==============
Preliminary steps:
1. Place a copy of your target image in the "input" directory. If you are going
   to use a decal image, place that image in the "decals" directory.
2. Edit Painter.txt to set up your configuration options.
3. Depending on whether or not your system has Perl installed on it, follow the
   relevant instructions below.


If you have Perl installed:
4.  Open a terminal
5.  Navigate to the directory in which the package has been extracted
6a. Type "./run.pl -t"
    OR
6b. Type "./run.pl [output_dir]"
6c. Type "./run.pl -t configurations/xxxx.txt"

Options:
    -t          A directory name will be created using the current time and the
                name of the target file specified in the Painter.txt file. All
                files created during the execution of the NPR-GP process will be
                placed in that folder.
    [output_dir]  A directory corresponding to what you typed in replacement of
                [output_dir] will be created in the "output" folder and all 
                files created during the execution of the NPR-GP process will be
                placed in that folder.
    configurations/xxxx.txt
                The program will read from configurations/xxxx.txt as the 
                configuration file

If you do not have Perl installed:
4. Open a terminal
5. Navigate to the directory in which the package has been extracted
6. Type "./run.sh [output_dir]"
                A directory corresponding to what you typed in replacement of
                [output_dir] will be created in the "output" folder and all 
                files created during the execution of the NPR-GP process will be
                placed in that folder.


