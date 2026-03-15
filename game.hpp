#pragma once
#include<iostream>
#include<new>
using namespace std;
char** createCourt(const int n);
void releaseCourt(char** court, const int n);
void showCourt(char** court, const int n);
int** createSecondDown(const int n);
void releaseSecond(int** second, const int n);
int check0Win(char** court, const int n, int x, int y, int victoryNum);
int check1Win(char** court, const int n, int x, int y, int victoryNum);