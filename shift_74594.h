#ifndef SHIFT_74594_INCLUDE
#define SHIFT_74594_INCLUDE

#if (ARDUINO >= 100)
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#define DELAY 10

class shift_74594{
	private:
		int _SER, _SCK, _RCK, _RCLR, _SCLR;

	public:
		shift_74594(int SER, int SCK, int RCK, int SCLR, int RCLR);
		~shift_74594();

		void init();
		void clear();
		void latch();
		void setByte(char);
		void setByteReverse(char);

};

#endif /*74597_INCLUDE*/
