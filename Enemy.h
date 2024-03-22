class Enemy {
public:
	int x = 500;
	int y = 500;
	int w = 50;
	int h = 50;
	float xvel = 0;
	float yvel = 0;
	bool m_up = false;
	bool m_left = false;
	bool m_down = false;
	bool m_right = false;
	bool le = false;
	u32 color = 0x550055;

public:
	void move();
	void up(bool state);
	void left(bool state);
	void down(bool state);
	void right(bool state);
	void draw();
};

void Enemy::up(bool state) {
	m_up = state;
}
void Enemy::left(bool state) { 
	m_left = state; 
}
void Enemy::down(bool state) { 
	m_down = state;
}
void Enemy::right(bool state) {
	m_right = state;
}

void Enemy::move() {

	if (m_right == true) {
		xvel = 10.0f;
	}
	else if (m_left == true) {
		xvel = -10.0f;
	}
	else { 
		xvel = 0.0f;
	}

	if (m_up == true) {
		yvel = 10.0f;
	}
	else if (m_down == true) {
		yvel = -10.0f;
	}
	else {
		yvel = 0.0f;
	}

	if (x + w + xvel >= render_state.width || x + xvel < 0) {
		xvel = 0.0f;
	}
	if (y + h + yvel >= render_state.height || y + yvel < 0) {
		yvel = 0.0f;
	}
	x += xvel;
	y += yvel;
}


void Enemy::draw() {
	move();
	draw_rect_in_pixels(x, y, x + w, y + h, color);
}
