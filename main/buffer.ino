
char *  pbOledFontUser;
char * pbOledFontCur;

void moveCursor(int coloumn, int row, int game){
  txt=&(menuBuffer[0][0]);
  txt += row * ccolOledMax * NUM_GAMES + coloumn + game *  128;
}

void putChar(char ch){
  char *	pbFont;
	int		ib;
  if ((ch & 0x80) != 0) {
		return;
  }
	if (ch < chOledUserMax) {
		pbFont = pbOledFontUser + ch*cbOledChar;
	}
	else if ((ch & 0x80) == 0) {
		pbFont = pbOledFontCur + (ch-chOledUserMax) * cbOledChar;
	}
	for (ib = 0; ib < 8; ib++){
		*txt++ = *pbFont++;
	}
}

void putString(char *ch){
    while (*ch != '\0') {
    putChar(*ch);
    ch += 1;
  }
}

