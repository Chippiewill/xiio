#pragma once

#include "xgpio.h"

class GPIO {
public:
	enum class Mode {
		Read,
		Write
	};

	/**
	 * @param device_id ID of the GPIO device
	 * @param channel Channel ID of the GPIO desired on the device
	 */
	GPIO(u16 device_id, unsigned channel)
	    : channel(channel) {
		XGpio_Initialize(&io, device_id);
	}

	/**
	 * Sets all pins for GPIO to specified direction
	 *
	 * @param Mode to set GPIO device to
	 */
	void setMode(Mode mode);

	/**
	 * @return The direction mask of the pins (0=write, 1=read)
	 */
	u32 getDirection() const;

	/**
	 * @param mask The direction mask to set (0=write, 1=read)
	 */
	void setDirection(u32 mask);

	/**
	 * @return The current state of the GPIO
	 */
	u32 value() const;

	/**
	 * @return The current state of the GPIO
	 */
	explicit operator u32() const;

	/**
	 * @param value The value to set the GPIO to
	 */
	GPIO& operator=(u32 value);
private:
	mutable XGpio io;
	unsigned channel;
};
