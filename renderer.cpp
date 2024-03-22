internal void
clear_screen(u32 color) {
	u32* pixel = (unsigned int*)render_state.memory;
	for (int y = 0; y < render_state.height; y++) {
		for (int x = 0; x < render_state.width; x++) {
			*pixel++ = color;
		}
	}
}

internal void
draw_grid(int xs, int ys, u32 color) {

	int x1 = render_state.width;
	int y1 = render_state.height;

	int xdiv = render_state.width / xs;
	int ydiv = render_state.height / ys;

	u32* pixel = (unsigned int*)render_state.memory;
	for (int y = 0; y < render_state.height; y++) {
		for (int x = 0; x < render_state.width; x++) {
			if (x % xdiv == 0 || y % ydiv == 0) {
				*pixel++ = color;
			}
			else {
				*pixel++;
			}
		}
	}
}

internal void
draw_rect_in_pixels(int x0, int y0, int x1, int y1, u32 color) {

	x0 = clamp(0, x0, render_state.width);
	y0 = clamp(0, y0, render_state.height);
	x1 = clamp(0, x1, render_state.width);
	y1 = clamp(0, y1, render_state.height);
	
	for (int y = y0; y < y1; y++) {
		u32* pixel = (u32*)render_state.memory + x0 + y*render_state.width;
		for (int x = x0; x < x1; x++) {
			*pixel++ = color;
		}
	}
}

internal void
draw_rect_xywh(int x0, int y0, int w, int h, u32 color) {

	int x1 = x0 + w;
	int y1 = y0 + h;

	x0 = clamp(0, x0, render_state.width);
	y0 = clamp(0, y0, render_state.height);
	x1 = clamp(0, x1, render_state.width);
	y1 = clamp(0, y1, render_state.height);

	for (int y = y0; y < y1; y++) {
		u32* pixel = (u32*)render_state.memory + x0 + y * render_state.width;
		for (int x = x0; x < x1; x++) {
			*pixel++ = color;
		}
	}
}


internal void
draw_rect(float x, float y, float half_size_x, float half_size_y, u32 color) {

	x *= render_state.width;
	y *= render_state.height;
	half_size_x *= render_state.width;
	half_size_y *= render_state.height;

	// Change to pixels
	int x0 = x - half_size_x;
	int x1 = x + half_size_x;
	int y0 = y - half_size_y;
	int y1 = y + half_size_y;

	draw_rect_in_pixels(x0, y0, x1, y1, color);
}


internal void put_pixel(int x, int y, u32 color) {
	if (0 < y && y * render_state.width < render_state.width * render_state.height 
		&& 0 < x < render_state.width) {
		u32* pixel = (u32*)render_state.memory + y * render_state.width + x;
		*pixel = color;
	}
}

void plotLineLow(int x0, int y0, int x1, int y1, u32 color) {	
	int dx = x1 - x0;
	int dy = y1 - y0;
	int yi = 1;
	if (dy < 0) {
		yi = -1;
		dy = -dy;
	}
	int D = (2 * dy) - dx;
	int y = y0;

	for (int x = x0; x < x1; x++) {
		put_pixel(x, y, color);
		if (D > 0) {
			y = y + yi;
			D = D + (2 * (dy - dx));
		}
		else {
			D = D + 2 * dy;
		}
	}

}

void plotLineHigh(int x0, int y0, int x1, int y1, u32 color) {	
	int dx = x1 - x0;
	int dy = y1 - y0;
	int xi = 1;
	if (dx < 0) {
		xi = -1;
		dx = -dx;
	}
	int D = (2 * dx) - dy;
	int x = x0;

	for (int y = y0; y < y1; y++) {
		put_pixel(x, y, color);
		if (D > 0) {
			x = x + xi;
			D = D + (2 * (dx - dy));
		}
		else {
			D = D + 2 * dx;
		}
	}
}

// Fucntion for "plotting" a line
void plotLine(int x0, int y0, int x1, int y1, u32 color) {
	// If the distance between the y values is less than the distance between the x values
	// i.e. the line is more horizontal than vertical
	if (abs(y1 - y0) < abs(x1 - x0)) {
	// plot a mostly horizontal line
		// if the initial x coord is greater than the final x coord, swap the initial and final coords
		// else plot as normal
		if (x0 > x1) {
			plotLineLow(x1, y1, x0, y0, color);
		}
		else {
			plotLineLow(x0, y0, x1, y1, color);
		}
	}
	// else plot a mostly vertical line		
	else {
		// if the initial y coord is greater than the final y coord, swap the initial and final coords
		// else plot as normal
		if (y0 > y1) {
			plotLineHigh(x1, y1, x0, y0, color);
		}
		else {
			plotLineHigh(x0, y0, x1, y1, color);
		}
	}
}

void plotLineLowbp(int x0, int y0, int x1, int y1, u32 color) {
	int dx = x1 - x0;
	int dy = y1 - y0;
	int yi = 20;
	if (dy < 0) {
		yi = -20;
		dy = -dy;
	}
	int D = (2 * dy) - dx;
	int y = y0;

	for (int x = x0; x < x1; x+= 20) {
		draw_rect_in_pixels(x - 10, y-10, x+10, y+10, color);
		put_pixel(x, y, color);
		if (D > 0) {
			y = y + yi;
			D = D + (2 * (dy - dx));
		}
		else {
			D = D + 2 * dy;
		}
	}
}

void plotLineHighbp(int x0, int y0, int x1, int y1, u32 color) {
	int dx = x1 - x0;
	int dy = y1 - y0;
	int xi = 20;
	if (dx < 0) {
		xi = -20;
		dx = -dx;
	}
	int D = (2 * dx) + dy;
	int x = x0;
	for (int y = y0; y > y1; y-= 20) {
		draw_rect_in_pixels(x - 10, y - 10, x + 10, y + 10, color);
		if (D > 0) {
			x = x + xi;
			D = D + (2 * (dx + dy));
		}
		else {
			D = D + 2 * dx;
		}
	}
}

void draw_line(int x0, int y0, int x1, int y1, u32 color) {
	plotLine(x0, y0, x1, y1, color);
}


void draw_circle(int x0, int y0, int r, u32 color) {
	for (int y = y0 - r; y < y0 + r; y++) {
		for (int x = x0 - r; x < x0 + r; x++) {
			int xp = x - x0;
			int yp = y - y0;
			int sqrSides = xp * xp + yp * yp;
			int sqrRad = r * r;
			if (sqrSides < sqrRad) {
				put_pixel(x, y, color);
			}
		}
	}
	draw_line(x0 - r, y0, x0 + r, y0, 0x000000);
	draw_line(x0, y0 - r, x0, y0 + r, 0x000000);
}


void draw_grid() {

	for (int x = 0; x < render_state.width; x += 20) {
		draw_line(x, 0, x, render_state.height, 0x0000ff);
	}

	for (int y = 0; y < render_state.height; y += 20) {
		draw_line(0, y, render_state.width, y, 0x0000ff);
	}

}

void big_pixel(int x, int y, u32 color) {
	draw_rect_in_pixels(x * 20, y * 20, (x * 20) + 20, (y * 20) + 20, color);
}

void swapPoints(int &x0, int &y0, int &x1, int &y1) {
	int temp_x0 = x0;
	int temp_y0 = y0;

	x0 = x1;
	y0 = y1;
	x1 = temp_x0;
	y1 = temp_y0;
}


void plotTrianglebp(int x0, int y0, int x1, int y1, int x2, int y2, u32 color) {

	// sort points get highest first
	if (y1 > y0) {
		swapPoints(x0, y0, x1, y1);
	}

	if (y2 > y0) {
		swapPoints(x0, y0, x2, y2);
	}

	// sort last two points from left ot right
	if (x2 < x1) {
		swapPoints(x1, y1, x2, y2);
	}

	big_pixel(x0, y0, 0xff0000); // Red square
	big_pixel(x1, y1, 0x00ff00); // Green Square
	big_pixel(x2, y2, 0x0000ff); // Blue square

	x0 = (x0 * 20) + 10;
	y0 = (y0 * 20) + 10;
	x1 = (x1 * 20) + 10;
	y1 = (y1 * 20) + 10;
	x2 = (x2 * 20) + 10;
	y2 = (y2 * 20) + 10;	
	
}



struct Vec2D {
	float x, y;
};

struct triangle {
	Vec2D p[3];
};


void draw_triangle(int x0, int y0, int x1, int y1, int x2, int y2, u32 color) {
	draw_line(x0, y0, x1, y1, color);
	draw_line(x1, y1, x2, y2, color);
	draw_line(x2, y2, x0, y0, color);
}

void draw_trianglebp(int x0, int y0, int x1, int y1, int x2, int y2, u32 color) {
	draw_line((x0 * 20) + 10, (y0 * 20) + 10, (x1 * 20) + 10, (y1 * 20) + 10, color);
	draw_line((x1 * 20) + 10, (y1 * 20) + 10, (x2 * 20) + 10, (y2 * 20) + 10, color);
	draw_line((x2 * 20) + 10, (y2 * 20) + 10, (x0 * 20) + 10, (y0 * 20) + 10, color);
}


void draw_filled_triangle(int x0, int y0, int x1, int y1, int x2, int y2, u32 color) {

	// sort points, get heighest first
	if (y0 < y1) {
		x0, y0, x1, y1 = x1, y1, x0, y0;
	}
	if (y0 < y2) {
		x0, y0, x2, y2 = x2, y2, x0, y0;
	}

	draw_line(x0, y0, x1, y1, color);
	draw_line(x1, y1, x2, y2, color);
	draw_line(x2, y2, x0, y0, color);
}