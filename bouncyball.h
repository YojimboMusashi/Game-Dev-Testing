class BouncyBall {
public:
	int x = 500;
	int y = 500;
	int r = 20;
	float xvel = 50.0f;
	float yvel = 50.0f;
	u32 color = 0x550000;

public:
	void move();
	void draw();
};


void BouncyBall::move() {
	if (x + r + xvel >= render_state.width || x - r + xvel < 0) {
		xvel = xvel * -1;
	}
	if (y + r + yvel >= render_state.height || y - r + yvel < 0) {
		yvel = yvel * -1;
	}
	x += xvel;
	y += yvel;
}

void BouncyBall::draw() {
	move();
	draw_circle(x, y, r, color);
}