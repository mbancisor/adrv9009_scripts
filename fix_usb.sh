#!/bin/bash
if [ ! -d "/sys/class/gpio/gpio35" ]; then
	echo "exporting GPIOs"
	echo 35 > /sys/class/gpio/export
	echo 36 > /sys/class/gpio/export
	echo 37 > /sys/class/gpio/export
	echo 38 > /sys/class/gpio/export
fi

if [ "$5" = "" ]; then
	echo out > /sys/class/gpio/gpio35/direction
	echo out > /sys/class/gpio/gpio36/direction
	echo out > /sys/class/gpio/gpio37/direction
	echo out > /sys/class/gpio/gpio38/direction
	echo $1 > /sys/class/gpio/gpio35/value
	echo $2 > /sys/class/gpio/gpio36/value
	echo $3 > /sys/class/gpio/gpio37/value
	echo $4 > /sys/class/gpio/gpio38/value
else
 	echo "input"
	echo in > /sys/class/gpio/gpio35/direction
	echo in > /sys/class/gpio/gpio36/direction
	echo in > /sys/class/gpio/gpio37/direction
	echo in > /sys/class/gpio/gpio38/direction
fi
