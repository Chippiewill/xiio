#include "gpio.h"

void GPIO::setMode(Mode mode) {
	if (mode == Mode::Read) {
		setDirection(0xFFFFFFFF);
	} else {
		setDirection(0x00000000);
	}
}

u32 GPIO::getDirection() const {
	return XGpio_GetDataDirection(&io, channel);
}

void GPIO::setDirection(u32 mask) {
	XGpio_SetDataDirection(&io, channel, mask);
}

u32 GPIO::value() const {
	return XGpio_DiscreteRead(&io, channel);
}

GPIO::operator u32() const {
	return value();
}

GPIO& GPIO::operator=(u32 value) {
	XGpio_DiscreteWrite(&io, channel, value);
	return *this;
}
