/*
 * ________________________________________________________________________________
 * |  File: README.md
 * |  Project: t0d0
 * |  File Created: Wednesday, 20th November 2024 10:46 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

![hypersphere-in-banner-TUT](https://github.com/pippin-29/t0d0/blob/%3Cvine_2.0%3E/hypershphere-in-banner-TUT.png?raw=true)


# [t0d0_4]
 
### Installation
 - ``` sudo apt install libncurses-dev ```
 - ``` make ```
 - ``` ./t0d0 ``` this will open or make the b.BEEP file
 - ``` ./t0d0 filename ``` this will open a filename.BEEP file
	Should run on ubuntu or maybe windows with bash, if not install ncurses.


### Current Functionality [Still to be updated]
 - Last verse no longer does a reach around to first location of last verse last location (constraints added for input)
 - Loads 16384 128-character lines from a .BEEP file.
 - Saves 16384 128-character lines into a .BEEP file. [.BEEP file is never terminated]
 - Current state of array is printed in each of the correct locations, with each row aligned with a 2048 line (64 verse) page.
 - Input can be assigned to array and is then printed in the correct location, and then moves the cursor across to the right.
 - Enter key adds a newline character to cursor location and moves to start of next line. Stops at line 32 on verse. Does not go to a new verse.
 - Delete key removes character from cursor location, does not remove whats ahead.
 - Backspace key removes characters from behind, and continues up until top of verse, does not go to previous verse.
 - All characters that can be entered are defined by inclusion using the protable function isprint().
 - Verse Numbers Change (Using md number set system)
 - Next Verse with control+n
 - Previous Verse with control+b
 - [BOOK_SIZE = 8]
 - Page Numbers Change on odd verse sets going up and even verse sets going down. [PAGE_SIZE = 2048]
 - Line Numbers Iterate correctly and reset on new page. [LINE_SIZE = 128]
 - Quit with control+q [confirmation with 'y']
 - Refresh with control+r
 - Next Page with control+o
 - Previous Page with control+u
 - cursor moves correctly[no buffer issues with previously stored input] and is not too slow.
 - _T0_D0_3.xxx_ complains if your window is not large enough [complaint seated in top left if you happen to make your windows 
 	the size of a large caterpillar]... Since ncurses seems to have been updated, the terminal now no longer chops the output buffer.
		Now shows ++RESIZE_WINDOW++
 - Colour pair is set to green on black

 #### Rapper functionality was disabled


## Screenshots

### _T0_D0_3.B_2_ ForcePush2
![blackandgreen](https://github.com/pippin-29/t0d0/blob/%3Cvine_2.0%3E/Screenshots/_T0_D0_3.B_2_.folder/blackandgreen.png?raw=true)

### _T0_D0_3.B_2_
![rap-engine](https://github.com/pippin-29/t0d0/blob/%3Cvine_2.0%3E/Screenshots/_T0_D0_3.B_2_.folder/rap-engine.png?raw=true)
![rapper](https://github.com/pippin-29/t0d0/blob/%3Cvine_2.0%3E/Screenshots/_T0_D0_3.B_2_.folder/rapper.png?raw=true)
![lab-language-compiler-early-revise](https://github.com/pippin-29/t0d0/blob/%3Cvine_2.0%3E/Screenshots/_T0_D0_3.B_2_.folder/lab-language-compiler-early-revise.png?raw=true)

### _T0_D0_3.A_2_ Functionality
![after-load](https://github.com/pippin-29/t0d0/blob/%3Cvine_2.0%3E/Screenshots/_T0_D0_3.A_2_.folder/after-load.png?raw=true)

### _T0_D0_3.P__
![confused](https://github.com/pippin-29/t0d0/blob/%3Cvine_2.0%3E/Screenshots/_T0_D0_3.P__.folder/confused.png?raw=true)
![off-by-8](https://github.com/pippin-29/t0d0/blob/%3Cvine_2.0%3E/Screenshots/_T0_D0_3.P__.folder/off-by-8.png?raw=true)

### T0_D0_3.O_ Functionality
![checking-cursor-constraints](https://github.com/pippin-29/t0d0/blob/%3Cvine_2.0%3E/Screenshots/T0_D0_3.O_.folder/checking-cursor-constraints.png?raw=true)
![takes-input](https://github.com/pippin-29/Tt0d0/blob/%3Cvine_2.0%3E/Screenshots/T0_D0_3.O_.folder/takes-input.png?raw=true)
![state-of-third-set](https://github.com/pippin-29/t0d0/blob/%3Cvine_2.0%3E/Screenshots/T0_D0_3.O_.folder/start-of-third-set.png?raw=true)
![end-of-array](https://github.com/pippin-29/t0d0/blob/%3Cvine_2.0%3E/Screenshots/T0_D0_3.O_.folder/end-of-array.png?raw=true)

#### to_do_3.0 functionality and early design
[to_do_3.0.folder](https://github.com/pippin-29/t0d0/tree/%3Cvine_2.0%3E/Screenshots/to_do_3.0.folder)

