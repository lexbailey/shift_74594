#include "shift_74594.h"		

shift_74594::shift_74594(int SER, int SCK, int RCK, int SCLR, int RCLR){
	_SER = SER;
	_SCK = SCK;
	_RCK = RCK;
	_RCLR = RCLR;
	_SCLR = SCLR;

}

void shift_74594::init(){
	pinMode(_SER, OUTPUT);
	pinMode(_SCK, OUTPUT);
	pinMode(_RCK, OUTPUT);
	pinMode(_RCLR, OUTPUT);
	pinMode(_SCLR, OUTPUT);
	
	digitalWrite(_RCLR, HIGH);
	digitalWrite(_SCLR, HIGH);
	digitalWrite(_SCK, LOW);
	digitalWrite(_RCK, LOW);
}

shift_74594::~shift_74594(){
}

void shift_74594::latch(){
	digitalWrite(_RCK, HIGH);
	delayMicroseconds(DELAY);
	digitalWrite(_RCK, LOW);
	delayMicroseconds(DELAY);
}

void shift_74594::clear(){
	digitalWrite(_SCLR, LOW);
	delayMicroseconds(DELAY);
	digitalWrite(_SCLR, HIGH);
	delayMicroseconds(DELAY);

	digitalWrite(_RCLR, LOW);
	delayMicroseconds(DELAY);
	digitalWrite(_RCLR, HIGH);
	delayMicroseconds(DELAY);
}

void shift_74594::setByte(char input){
	for (int i = 0; i <= 7; i++){
		if (input & (1<<(7-i))) {digitalWrite(_SER, HIGH);} else {digitalWrite(_SER, LOW);}
		digitalWrite(_SCK, HIGH);
		delayMicroseconds(DELAY);
		digitalWrite(_SCK, LOW);
		delayMicroseconds(DELAY);
	}
}

void shift_74594::setByteReverse(char input){
	for (int i = 0; i <= 7; i++){
		if (input & (1<<(i))) {digitalWrite(_SER, HIGH);} else {digitalWrite(_SER, LOW);}
		digitalWrite(_SCK, HIGH);
		delayMicroseconds(DELAY);
		digitalWrite(_SCK, LOW);
		delayMicroseconds(DELAY);
	}
}
