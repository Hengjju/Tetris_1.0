#ifndef SMOOTHGAME_H
#define SMOTTHGAME_H
#define CONSOLE_SCREEN_COLS_BYTES (50 * 3 + 1)


void Backgroundunit();
void PrintBackground(vector<wstring>& screen);
void smoothgame(const vector<wstring>& screen);
void Dbuff();

#endif
