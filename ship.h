class Ship {
public:
	int x = 500;
	int y = 500;
	int w = 50;
	int h = 50;
	float speed = 10.0f;
	float xvel = 0;
	float yvel = 0;
	bool m_up = false;
	bool m_left = false;
	bool m_down = false;
	bool m_right = false;
	bool le = false;
	u32 color = 0x00ff00;

public:
	void move();
	void up(bool state);
	void left(bool state);
	void down(bool state);
	void right(bool state);
	void draw();
};

void Ship::up(bool state) {
	m_up = state;
}
void Ship::left(bool state) {
	m_left = state;
}
void Ship::down(bool state) {
	m_down = state;
}
void Ship::right(bool state) {
	m_right = state;
}

void Ship::move() {
	if (m_right == true) {
		xvel = speed;
	}
	else if (m_left == true) {
		xvel = -speed;
	}
	else {
		xvel = 0.0f;
	}

	if (m_up == true) {
		yvel = speed;
	}
	else if (m_down == true) {
		yvel = -speed;
	}
	else {
		yvel = 0.0f;
	}


	if (x + w + xvel >= render_state.width || x + xvel < 0) {
		if (x + w + xvel >= render_state.width) {
			x = render_state.width - w;
		}
		if (x + xvel < 0) {
			x = 0;
		}
		xvel = 0.0f;
	}

	if (y + h + yvel >= render_state.height || y + yvel < 0) {
		if (y + h + yvel >= render_state.height) {
			y = render_state.height - h;
		}
		if (y + yvel < 0) {
			y = 0;
		}
		yvel = 0.0f;
	}

	x += xvel;
	y += yvel;
}

void Ship::draw() {
	move();
	draw_rect_xywh(x, y, w, h, color);
}



