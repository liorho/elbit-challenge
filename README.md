# Elbit Challenge

## The Challenge
Given an elbit file (`elbitsystems.elbit`), I needed to extract whatever inside it.

## The File
The file look mostly gibberish, but it has few instructions (opcode).

## The Solution
After a small investigation I managed to create a `C` language file that would open the `.elbit` file, go byte by byte, and decode it's information.
You can have a look at the output in the `output.png` file.

