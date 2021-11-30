#pragma once
// outputs a pseudo-random number 0 or 1 from time
bool rand_number();

// scanf stucks in a loop on wrong type of user input, this is a fix
// scans for a int value, if the inputted value is not int, sets error to true
int scan_1int(bool& error);

// for 2 user inputted numbers
// scanf stucks in a loop on wrong type of user input, this is a fix
// scans for a int value, if the inputted value is not int, sets error to true

void scan_2int(bool& error, int& lrows, int& lcols);