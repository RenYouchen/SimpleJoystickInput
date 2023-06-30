#define _JOYSTICK_H_
#ifdef _JOYSTICK_H_

#include <string>
#include <fcntl.h>
#include <unistd.h>
#include <linux/joystick.h>
#include <stdio.h>
class Joystick {
	public:
		Joystick(std::string path);
		void init();
		void update();
		int getAxis(int axis);
		int getButton(int button);
	private:
		struct js_event e;
		int fd;
		std::string path;
		int buttonData[20][1];
		int axisData[10][1];
};
#endif
