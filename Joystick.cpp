#include <Joystick.h>

Joystick::Joystick(std::string path) {
	this->path = path;
}

Joystick::~Joystick() {
	close(fd);
}

Joystick::init() {
	fd = open(path.c_str(), O_RDONLY | O_NONBLOCK);
	if (fd == -1) {
		perror("Could not open joystick");
	}
}

Joystick::update() {
	read(fd, &e, sizeof(e));

	switch (e.type) {
		case JS_EVENT_AXIS:
			axisData[e.number][0] = e.value;
			break;
		case JS_EVENT_BUTTON:
			buttonData[e.number][0] = e.value;
			break;
	}
}

Joystick::getAxis(int axis) {
	return axisData[axis][0];
}

Joystick::getButton(int button) {
	return buttonData[button][0];
}
